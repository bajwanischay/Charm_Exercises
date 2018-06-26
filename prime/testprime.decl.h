#ifndef _DECL_testprime_H_
#define _DECL_testprime_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
void isPrime(int n, int key, const int *res);
};
 */
 class Origin;
 class CkIndex_Origin;
 class CProxy_Origin;
/* --------------- index object ------------------ */
class CkIndex_Origin:public CkIndex_Chare{
  public:
    typedef Origin local_t;
    typedef CkIndex_Origin index_t;
    typedef CProxy_Origin proxy_t;
    typedef CProxy_Origin element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Origin(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Origin_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Origin_CkArgMsg() {
      static int epidx = reg_Origin_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Origin_CkArgMsg(); }
    
    static void _call_Origin_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Origin_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void isPrime(int n, int key, const int *res);
     */
    // Entry point registration at startup
    
    static int reg_isPrime_marshall2();
    // Entry point index lookup
    
    inline static int idx_isPrime_marshall2() {
      static int epidx = reg_isPrime_marshall2();
      return epidx;
    }

    
    inline static int idx_isPrime(void (Origin::*)(int n, int key, const int *res) ) {
      return idx_isPrime_marshall2();
    }


    
    static int isPrime(int n, int key, const int *res) { return idx_isPrime_marshall2(); }
    
    static void _call_isPrime_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_isPrime_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_isPrime_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_isPrime_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Origin:public CProxy_Chare{
  public:
    typedef Origin local_t;
    typedef CkIndex_Origin index_t;
    typedef CProxy_Origin proxy_t;
    typedef CProxy_Origin element_t;

    CProxy_Origin(void) {};
    CProxy_Origin(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Origin(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Origin *ckLocal(void) const
    { return (Origin *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Origin(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Origin(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: void isPrime(int n, int key, const int *res);
 */
    
    void isPrime(int n, int key, const int *res, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Origin)
#define Origin_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Origin>CBase_Origin;

/* DECLS: chare checkPrime: Chare{
checkPrime(int n, int key, const int *val);
};
 */
 class checkPrime;
 class CkIndex_checkPrime;
 class CProxy_checkPrime;
/* --------------- index object ------------------ */
class CkIndex_checkPrime:public CkIndex_Chare{
  public:
    typedef checkPrime local_t;
    typedef CkIndex_checkPrime index_t;
    typedef CProxy_checkPrime proxy_t;
    typedef CProxy_checkPrime element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: checkPrime(int n, int key, const int *val);
     */
    // Entry point registration at startup
    
    static int reg_checkPrime_marshall1();
    // Entry point index lookup
    
    inline static int idx_checkPrime_marshall1() {
      static int epidx = reg_checkPrime_marshall1();
      return epidx;
    }

    
    static int ckNew(int n, int key, const int *val) { return idx_checkPrime_marshall1(); }
    
    static void _call_checkPrime_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_checkPrime_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_checkPrime_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_checkPrime_marshall1(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_checkPrime:public CProxy_Chare{
  public:
    typedef checkPrime local_t;
    typedef CkIndex_checkPrime index_t;
    typedef CProxy_checkPrime proxy_t;
    typedef CProxy_checkPrime element_t;

    CProxy_checkPrime(void) {};
    CProxy_checkPrime(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_checkPrime(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    checkPrime *ckLocal(void) const
    { return (checkPrime *)CkLocalChare(&ckGetChareID()); }
/* DECLS: checkPrime(int n, int key, const int *val);
 */
    static CkChareID ckNew(int n, int key, const int *val, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int n, int key, const int *val, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_checkPrime(int n, int key, const int *val, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_checkPrime)
#define checkPrime_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_checkPrime>CBase_checkPrime;

/* ---------------- method closures -------------- */
class Closure_Origin {
  public:


    struct isPrime_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_checkPrime {
  public:

};

extern void _registertestprime(void);
extern "C" void CkRegisterMainModule(void);
#endif
