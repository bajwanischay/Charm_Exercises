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
      CProxy_Grid grid=CProxy_Grid::ckNew(n,dim,maxiter,thisProxy,k,k);
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
      std::map<int,std::vector<Particle>> mp;
      int n;
      int maxcount;

   public:
      Grid(int n,float dim,int maxiter,CProxy_Main main){
        countbuff=(int*)malloc(maxiter*sizeof(int));
        for(int i=0;i<maxiter;i++)countbuff[i]=0;
        srand(time(0));
        this->mainProxy=main;
        this->dim=dim;
        this->n=n;
        float basex=dim*thisIndex.x;
        float basey=dim*thisIndex.y;
        for(int i=0;i<n;i++){
          Particle p=Particle(basex+((float)rand()*dim/(float)(RAND_MAX)),basey+((float)rand()*dim/(float)(RAND_MAX)));
          particle.push_back(p);
        }
        maxcount==4;
        if(thisIndex.x==0)maxcount--;
        if(thisIndex.y==0)maxcount--;
        if(thisIndex.x==99)maxcount--;
        if(thisIndex.y==99)maxcount--;
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
            if(thisIndex.y==99) particle[j].y=dim;
            else{
            south.push_back(particle[j]);
            particle.erase(particle.begin()+j);
            }
          }
          else if(particle[j].isEast(dim)){
            if(thisIndex.x==99) particle[j].x=dim;
            else{east.push_back(particle[j]);
            particle.erase(particle.begin()+j);}
          }
          else if(particle[j].isWest(dim)){
            if(thisIndex.x==0) particle[j].x=0;
            else{west.push_back(particle[j]);
            particle.erase(particle.begin()+j);}
          }
        }

        if(thisIndex.y>0)
          thisProxy(thisIndex.x,thisIndex.y-1).Transfer(iteration,north);
        if(thisIndex.y<99)
          thisProxy(thisIndex.x,thisIndex.y+1).Transfer(iteration,south);
        if(thisIndex.x<99)
          thisProxy(thisIndex.x+1,thisIndex.y).Transfer(iteration,east);
        if(thisIndex.x>0)
          thisProxy(thisIndex.x-1,thisIndex.y).Transfer(iteration,west);
        if(iteration%10==0)reduce();
      }

      void reduce(){
        int size=particle.size();
        CkCallback cmax(CkReductionTarget(Main, printMax), mainProxy);
        contribute(sizeof(int),&size,CkReduction::max_int,cmax);
        CkCallback ctotal(CkReductionTarget(Main, printTotal), mainProxy);
        contribute(sizeof(int),&size,CkReduction::sum_int,ctotal);
      }

      void Transfer(int iter,std::vector<Particle> in){
        mp.insert(std::pair<int,std::vector<Particle>>(iter*4+countbuff[iter],in));          
        countbuff[iter]++;
        if(countbuff[iter]==maxcount){
          while(countbuff[iteration]-- > 0){
            std::vector<Particle> pv=mp.find(iteration*4+countbuff[iteration])->second;
            for(int i=0;i<pv.size();i++)
              particle.push_back(pv[i]);
            //particle.insert(particle.end(),mp.find(iteration*4+countbuff[iteration])->second.begin(),mp.find(iteration*4+countbuff[iteration])->second.end());
          }
          Move(++iteration);
        }
      }
};

#include "particle.def.h"
