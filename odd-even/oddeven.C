#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "oddeven.decl.h"
#include <time.h>

class Main: public CBase_Main {
  private:
    int N;

  public:
    Main(CkMigrateMessage* msg){}
    Main(CkArgMsg* msg){
      N=atoi(msg->argv[1]);
      CkPrintf("N: %d\n", N);
      CProxy_Chr chrarr=CProxy_Chr::ckNew(thisProxy,N,N);
      chrarr.send();
    }

    void checkSorted(int result){
    CkPrintf("Result: %d\n",result);
    CkExit();
    }
};

class Chr: public CBase_Chr {
  private:
    int step;
    int* buff;
    int* flagbuf;
    int* sentbuf;
    int num;
    int N;
    CProxy_Main main;
    int out;
    int count;
  public:
    Chr(CkMigrateMessage* msg){}
    Chr(CProxy_Main imain,int iN){
      N=iN;      
      main=imain;
      step=0;
      out=0;
      buff=(int*)malloc(N*sizeof(int));
      flagbuf=(int*)malloc(N*sizeof(int));
      for(int i=0;i<N;i++){
        flagbuf[i]=0;
      }
      srand(thisIndex);
      num=N-rand()%(N);
      CkPrintf("%d: %d\n", thisIndex, num);  
    }  
    
    void send(){
      int sendindex; 
      if(step<N){
        if(step%2==0){
          if(thisIndex==N-1 && (N-1)%2==0){
            sendNumber(num,step);
          }
          else{
            sendindex=thisIndex%2==0?thisIndex+1:thisIndex-1;
            thisProxy[sendindex].sendNumber(num,step);
            //CkPrintf("Step %d: Chare %d Sent %d to %d\n",step,thisIndex,num,sendindex);
          }
        }
        else{
          if((thisIndex==N-1 && (N-1)%2==1) || thisIndex==0){
            sendNumber(num,step);
          }
          else{
            sendindex=thisIndex%2==1?thisIndex+1:thisIndex-1;
            thisProxy[sendindex].sendNumber(num,step);
            //CkPrintf("Step %d: Chare %d Sent %d to %d\n",step,thisIndex,num,sendindex);
          }            
        }
      }

      else{
        CkPrintf("Chare %d ends with %d\n",thisIndex,num);
        thisProxy[thisIndex+1].finalsend(num,0);
        thisProxy[thisIndex-1].finalsend(num,1);
      }
    }
    
    void sendNumber(int inum,int istep){
      //CkPrintf("Step %d: %d Recieved at Chare %d \n",istep,inum,thisIndex);
      flagbuf[istep]=1;
      buff[istep]=inum;
      update();
    }
    
    void update(){
      while(flagbuf[step]==1){
        int inum=buff[step];
        if((step%2==0 && thisIndex%2==0) || (step%2==1 && thisIndex%2==1))
          num=inum<num?inum:num;
        else
          num=inum>num?inum:num;
        step++;
        send();
      }
    }

    void finalsend(int inum,int right){
      if((right && inum>=num) || (!right && inum<=num))out=1;
      else out=0;
      count++;
      if(((thisIndex==N-1 || thisIndex==0) && count==1) || count==2 || out==0 ){
        CkCallback cb(CkReductionTarget(Main,checkSorted),main);
        contribute(sizeof(int),&out, CkReduction::logical_and_int,cb);
      }
    }
};

#include "oddeven.def.h"

