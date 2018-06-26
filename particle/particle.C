#include <stdio.h>
#include <math.h>
#include "particle.decl.h"

class Main: public CBase_Main {
   private:
    int iteration;
    int maxiter;
   public:
    Main(CkArgMsg* msg){
      int n=1000;//atoi(msg->argv[1]);
      int k=10;//atoi(msg->argv[2]);
      maxiter=100;//atoi(msg->argv[3]);
      float dim=100.0/k;
      CProxy_Grid grid=CProxy_Grid::ckNew(n,k,dim,maxiter,thisProxy,k,k);
      iteration=0;
      grid.Move(1);
    }

    void printMax(int max){
      iteration+=10;
      CkPrintf("Iteration: %d\n",iteration);
      CkPrintf("Max No of Particles: %d\n",max);
    }

    void printTotal(int total){
      CkPrintf("Total No of Particles: %d\n\n",total);
      if(iteration+10>maxiter)
        CkExit();
    }
};


class Grid: public CBase_Grid{

    private:
      std::vector<Particle> particle;
      CProxy_Main mainProxy;
      int iteration;
      float dim;
      int* countbuff;
      int n,k;
      int maxcount;

   public:
      Grid(int n,int k,float dim,int maxiter,CProxy_Main main){
        countbuff=(int*)malloc(maxiter*sizeof(int));
        for(int i=0;i<maxiter;i++)countbuff[i]=0;
        srand(time(0));
        this->mainProxy=main;
        this->dim=dim;
        this->n=n;
        this->k=k;
        float basex=dim*thisIndex.x;
        float basey=dim*thisIndex.y;
        for(int i=0;i<n;i++){
          Particle p=Particle(basex+((float)rand()*dim/(float)(RAND_MAX)),basey+((float)rand()*dim/(float)(RAND_MAX)));
          particle.push_back(p);
        }
        maxcount=4;
        if(thisIndex.x==0)maxcount--;
        if(thisIndex.y==0)maxcount--;
        if(thisIndex.x==k-1)maxcount--;
        if(thisIndex.y==k-1)maxcount--;
      }
      void Move(int iteration){
        this->iteration=iteration;
        std::vector<Particle> north;
        std::vector<Particle> south;
        std::vector<Particle> east;
        std::vector<Particle> west;

        for(int j=0;j<particle.size();j++){
          particle[j].shifty(((float)rand()*dim/((float)(RAND_MAX))-0.5)/(2*n));
          particle[j].shiftx(((float)rand()*dim/((float)(RAND_MAX))-0.5)/(2*n));

          if(particle[j].isNorth(dim)){
            if(thisIndex.y==0) particle[j].y=0.0;
            else{
            north.push_back(particle[j]);
            particle.erase(particle.begin()+j);
            }
          }
          else if(particle[j].isSouth(dim)){
            if(thisIndex.y==k-1) particle[j].y=dim;
            else{
            south.push_back(particle[j]);
            particle.erase(particle.begin()+j);
            }
          }
          else if(particle[j].isEast(dim)){
            if(thisIndex.x==k-1) particle[j].x=dim;
            else{east.push_back(particle[j]);
            particle.erase(particle.begin()+j);}
          }
          else if(particle[j].isWest(dim)){
            if(thisIndex.x==0) particle[j].x=0;
            else{west.push_back(particle[j]);
            particle.erase(particle.begin()+j);}
          }
        }
//        CkPrintf("%d %d Sending\n",thisIndex.x,thisIndex.y);
        if(thisIndex.y>0)
          thisProxy(thisIndex.x,thisIndex.y-1).Transfer(north);
        if(thisIndex.y<k-1)
          thisProxy(thisIndex.x,thisIndex.y+1).Transfer(south);
        if(thisIndex.x<k-1)
          thisProxy(thisIndex.x+1,thisIndex.y).Transfer(east);
        if(thisIndex.x>0)
          thisProxy(thisIndex.x-1,thisIndex.y).Transfer(west);
        if(iteration%10==0)reduce();
      }

      void reduce(){
        int size=particle.size();
        CkCallback cmax(CkReductionTarget(Main, printMax), mainProxy);
        contribute(sizeof(int),&size,CkReduction::max_int,cmax);
        CkCallback ctotal(CkReductionTarget(Main, printTotal), mainProxy);
        contribute(sizeof(int),&size,CkReduction::sum_int,ctotal);
      }

      void Transfer(std::vector<Particle> in){
        for(int i=0;i<in.size();i++){particle.push_back(in[i]);}   
        count();
      }
               
      void count(){
        if(++countbuff[iteration]==maxcount-1){
          //CkPrintf("%d %d Recieving Count=%d\n",thisIndex.x,thisIndex.y,countbuff[iteration]);
          thisProxy(thisIndex.x,thisIndex.y).Move(++iteration);}
      }
};

#include "particle.def.h"
