#include <stdio.h>
#include "multihello.decl.h"

class Origin: public CBase_Origin {

	public:
		Origin(CkArgMsg* m){
			int key=1;
			key=atoi(m->argv[1]);
			ckout<<"Passing Key from Origin to Interim"<<endl;
			CProxy_Interim::ckNew(key);
		}
	};

class Interim: public CBase_Interim{
	public:
		Interim(int key){
		ckout<<"Passing Key from Interim to Destination"<<endl;
		CProxy_Destination::ckNew(key);
		}
	};

class Destination: public CBase_Destination{
	public:
		Destination(int key){
		ckout<<"Key Arrived at Destination"<<endl;
		ckout<<"Key="<<key<<endl;
		CkExit();
		}
	};
#include "multihello.def.h"
