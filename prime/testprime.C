#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "testprime.decl.h"

CProxy_Origin origin;

class Origin: public CBase_Origin{
	public:
		int* Prime;
		int* arr;
		int count,k,n;
		Origin(CkArgMsg* m){
      origin=thisProxy;
			srand(time(NULL));
			k=0;n=0;
			if(m->argc<3){
				ckout<<"Invalid Number of Args"<<endl;
				CkExit();
			}
			else{
				k=atoi(m->argv[1]);
        n=atoi(m->argv[2]);
			}
			int i;
			arr=(int*)malloc(sizeof(int)*k);
			Prime=(int*)malloc(sizeof(int)*k);
			count=1;
      int val[n];
			for(i=0; i<k; i++){
				arr[i]=rand()%100;
				ckout<<i<<":"<<arr[i]<<endl;
				Prime[i]=0;
        val[i%n]=arr[i];
        if(i%n==n-1 || i==k-1){
        CProxy_checkPrime::ckNew(n,i-i%n,val);
			  }
		  }
    }
	void isPrime(int n,int key,int res[]){
			for(int i=0;i<n,key<k;i++)Prime[key++]=res[i];
			count++;
			if(count==k/n+1) print();
		}
	private:
		void print(){
		for(int i=0;i<k;i++){
			if(Prime[i])
				ckout<<arr[i]<<" is Prime"<<endl;
			else
				ckout<<arr[i]<<" is not Prime"<<endl;
		}
		CkExit();
		}
	};

class checkPrime: public CBase_checkPrime{
	public:
		checkPrime(int n,int key,int val[]){
		int res[n];
    for(int i=0;i<n;i++)res[key++]=check(val[i]);
    origin.isPrime(n,key-n+1,res);
    }
  private:
    int check(int i){
    if(i<=1){
	  	return 0;
		  }
		int hi=sqrt(i);
		for(int j=2;j<=hi;j+=1){
			if(i%j==0){
    		return 0;
	  	  }
		  }
	  return 1;
	  }
  };
#include "testprime.def.h"
