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
    }

    void checkSorted(int result){
      CkPrintf("Result: %d\n",result);
      CkExit();
    }
};

class Chr: public CBase_Chr {
  Chr_SDAG_CODE

  public:
    CProxy_Main main;
    int N,step,num;

    Chr(CkMigrateMessage* msg){}

    Chr(CProxy_Main main,int N){
      this->main=main;
      this->N=N;
      srand(thisIndex);
      num=N-rand()%(N);
      step=0;
      thisProxy.run(N);
      if(thisIndex%2==0 && thisIndex<N-1)
        thisProxy(thisIndex+1).recvNumber(num);
      else
        thisProxy(thisIndex-1).recvNumber(num);
    }

    void reduce(int out){
      CkCallback cb(CkReductionTarget(Main,checkSorted),main);
      contribute(sizeof(int), &out, CkReduction::logical_and_int,cb);
    }
};

#include "oddeven.def.h"
