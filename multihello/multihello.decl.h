#ifndef _DECL_multihello_H_
#define _DECL_multihello_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
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

};
PUPmarshall(CProxy_Origin)
#define Origin_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Origin>CBase_Origin;

/* DECLS: chare Interim: Chare{
Interim(int x);
};
 */
 class Interim;
 class CkIndex_Interim;
 class CProxy_Interim;
/* --------------- index object ------------------ */
class CkIndex_Interim:public CkIndex_Chare{
  public:
    typedef Interim local_t;
    typedef CkIndex_Interim index_t;
    typedef CProxy_Interim proxy_t;
    typedef CProxy_Interim element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Interim(int x);
     */
    // Entry point registration at startup
    
    static int reg_Interim_marshall1();
    // Entry point index lookup
    
    inline static int idx_Interim_marshall1() {
      static int epidx = reg_Interim_marshall1();
      return epidx;
    }

    
    static int ckNew(int x) { return idx_Interim_marshall1(); }
    
    static void _call_Interim_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Interim_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Interim_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Interim_marshall1(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Interim:public CProxy_Chare{
  public:
    typedef Interim local_t;
    typedef CkIndex_Interim index_t;
    typedef CProxy_Interim proxy_t;
    typedef CProxy_Interim element_t;

    CProxy_Interim(void) {};
    CProxy_Interim(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Interim(const Chare *c) : CProxy_Chare(c){  }

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
    Interim *ckLocal(void) const
    { return (Interim *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Interim(int x);
 */
    static CkChareID ckNew(int x, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int x, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Interim(int x, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Interim)
#define Interim_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Interim>CBase_Interim;

/* DECLS: chare Destination: Chare{
Destination(int x);
};
 */
 class Destination;
 class CkIndex_Destination;
 class CProxy_Destination;
/* --------------- index object ------------------ */
class CkIndex_Destination:public CkIndex_Chare{
  public:
    typedef Destination local_t;
    typedef CkIndex_Destination index_t;
    typedef CProxy_Destination proxy_t;
    typedef CProxy_Destination element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Destination(int x);
     */
    // Entry point registration at startup
    
    static int reg_Destination_marshall1();
    // Entry point index lookup
    
    inline static int idx_Destination_marshall1() {
      static int epidx = reg_Destination_marshall1();
      return epidx;
    }

    
    static int ckNew(int x) { return idx_Destination_marshall1(); }
    
    static void _call_Destination_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Destination_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Destination_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Destination_marshall1(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Destination:public CProxy_Chare{
  public:
    typedef Destination local_t;
    typedef CkIndex_Destination index_t;
    typedef CProxy_Destination proxy_t;
    typedef CProxy_Destination element_t;

    CProxy_Destination(void) {};
    CProxy_Destination(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Destination(const Chare *c) : CProxy_Chare(c){  }

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
    Destination *ckLocal(void) const
    { return (Destination *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Destination(int x);
 */
    static CkChareID ckNew(int x, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int x, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_Destination(int x, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Destination)
#define Destination_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Destination>CBase_Destination;

/* ---------------- method closures -------------- */
class Closure_Origin {
  public:

};

/* ---------------- method closures -------------- */
class Closure_Interim {
  public:

};

/* ---------------- method closures -------------- */
class Closure_Destination {
  public:

};

extern void _registermultihello(void);
extern "C" void CkRegisterMainModule(void);
#endif
