#ifndef _DECL_oddeven_H_
#define _DECL_oddeven_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void checkSorted(int result);
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void checkSorted(int result);
     */
    // Entry point registration at startup
    
    static int reg_checkSorted_marshall2();
    // Entry point index lookup
    
    inline static int idx_checkSorted_marshall2() {
      static int epidx = reg_checkSorted_marshall2();
      return epidx;
    }

    
    inline static int idx_checkSorted(void (Main::*)(int result) ) {
      return idx_checkSorted_marshall2();
    }


    
    static int checkSorted(int result) { return idx_checkSorted_marshall2(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_checkSorted_marshall2();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_checkSorted_marshall2() {
      static int epidx = reg_redn_wrapper_checkSorted_marshall2();
      return epidx;
    }
    
    static int redn_wrapper_checkSorted(CkReductionMsg* impl_msg) { return idx_redn_wrapper_checkSorted_marshall2(); }
    
    static void _call_redn_wrapper_checkSorted_marshall2(void* impl_msg, void* impl_obj_void);
    
    static void _call_checkSorted_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_checkSorted_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_checkSorted_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_checkSorted_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

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
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Main(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: void checkSorted(int result);
 */
    
    void checkSorted(int result, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_Main)
#define Main_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Main>CBase_Main;

/* DECLS: array Chr: ArrayElement{
Chr(const CProxy_Main &main, int N);
void run(int N, int step);
void finalsend(int num, int right);
void recvNumber(int step, int num);
Chr(CkMigrateMessage* impl_msg);
};
 */
 class Chr;
 class CkIndex_Chr;
 class CProxy_Chr;
 class CProxyElement_Chr;
 class CProxySection_Chr;
/* --------------- index object ------------------ */
class CkIndex_Chr:public CkIndex_ArrayElement{
  public:
    typedef Chr local_t;
    typedef CkIndex_Chr index_t;
    typedef CProxy_Chr proxy_t;
    typedef CProxyElement_Chr element_t;
    typedef CProxySection_Chr section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Chr(const CProxy_Main &main, int N);
     */
    // Entry point registration at startup
    
    static int reg_Chr_marshall1();
    // Entry point index lookup
    
    inline static int idx_Chr_marshall1() {
      static int epidx = reg_Chr_marshall1();
      return epidx;
    }

    
    static int ckNew(const CProxy_Main &main, int N) { return idx_Chr_marshall1(); }
    
    static void _call_Chr_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Chr_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Chr_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Chr_marshall1(PUP::er &p,void *msg);
    /* DECLS: void run(int N, int step);
     */
    // Entry point registration at startup
    
    static int reg_run_marshall2();
    // Entry point index lookup
    
    inline static int idx_run_marshall2() {
      static int epidx = reg_run_marshall2();
      return epidx;
    }

    
    inline static int idx_run(void (Chr::*)(int N, int step) ) {
      return idx_run_marshall2();
    }


    
    static int run(int N, int step) { return idx_run_marshall2(); }
    
    static void _call_run_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_run_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_run_marshall2(PUP::er &p,void *msg);
    /* DECLS: void finalsend(int num, int right);
     */
    // Entry point registration at startup
    
    static int reg_finalsend_marshall3();
    // Entry point index lookup
    
    inline static int idx_finalsend_marshall3() {
      static int epidx = reg_finalsend_marshall3();
      return epidx;
    }

    
    inline static int idx_finalsend(void (Chr::*)(int num, int right) ) {
      return idx_finalsend_marshall3();
    }


    
    static int finalsend(int num, int right) { return idx_finalsend_marshall3(); }
    
    static void _call_finalsend_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_finalsend_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_finalsend_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_finalsend_marshall3(PUP::er &p,void *msg);
    /* DECLS: void recvNumber(int step, int num);
     */
    // Entry point registration at startup
    
    static int reg_recvNumber_marshall4();
    // Entry point index lookup
    
    inline static int idx_recvNumber_marshall4() {
      static int epidx = reg_recvNumber_marshall4();
      return epidx;
    }

    
    inline static int idx_recvNumber(void (Chr::*)(int step, int num) ) {
      return idx_recvNumber_marshall4();
    }


    
    static int recvNumber(int step, int num) { return idx_recvNumber_marshall4(); }
    
    static void _call_recvNumber_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_recvNumber_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_recvNumber_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_recvNumber_marshall4(PUP::er &p,void *msg);
    /* DECLS: Chr(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Chr_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Chr_CkMigrateMessage() {
      static int epidx = reg_Chr_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Chr_CkMigrateMessage(); }
    
    static void _call_Chr_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Chr_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Chr : public CProxyElement_ArrayElement{
  public:
    typedef Chr local_t;
    typedef CkIndex_Chr index_t;
    typedef CProxy_Chr proxy_t;
    typedef CProxyElement_Chr element_t;
    typedef CProxySection_Chr section_t;


    /* TRAM aggregators */

    CProxyElement_Chr(void) {
    }
    CProxyElement_Chr(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Chr *ckLocal(void) const
    { return (Chr *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Chr(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Chr(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Chr(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Chr(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Chr(const CProxy_Main &main, int N);
 */
    
    void insert(const CProxy_Main &main, int N, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void run(int N, int step);
 */
    
    void run(int N, int step, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalsend(int num, int right);
 */
    
    void finalsend(int num, int right, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void recvNumber(int step, int num);
 */
    
    void recvNumber(int step, int num, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Chr(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxyElement_Chr)
/* ---------------- collective proxy -------------- */
 class CProxy_Chr : public CProxy_ArrayElement{
  public:
    typedef Chr local_t;
    typedef CkIndex_Chr index_t;
    typedef CProxy_Chr proxy_t;
    typedef CProxyElement_Chr element_t;
    typedef CProxySection_Chr section_t;

    CProxy_Chr(void) {
    }
    CProxy_Chr(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Empty array construction
    static CkArrayID ckNew(CkArrayOptions opts = CkArrayOptions()) { return ckCreateEmptyArray(opts); }
    static void      ckNew(CkCallback cb, CkArrayOptions opts = CkArrayOptions()) { ckCreateEmptyArrayAsync(cb, opts); }

    // Generalized array indexing:
    CProxyElement_Chr operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Chr(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Chr operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Chr(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Chr operator [] (int idx) const 
        {return CProxyElement_Chr(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Chr operator () (int idx) const 
        {return CProxyElement_Chr(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Chr(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Chr(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Chr(const CProxy_Main &main, int N);
 */
    
    static CkArrayID ckNew(const CProxy_Main &main, int N, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const CProxy_Main &main, int N, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const CProxy_Main &main, int N, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const CProxy_Main &main, int N, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void run(int N, int step);
 */
    
    void run(int N, int step, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalsend(int num, int right);
 */
    
    void finalsend(int num, int right, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void recvNumber(int step, int num);
 */
    
    void recvNumber(int step, int num, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Chr(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxy_Chr)
/* ---------------- section proxy -------------- */
 class CProxySection_Chr : public CProxySection_ArrayElement{
  public:
    typedef Chr local_t;
    typedef CkIndex_Chr index_t;
    typedef CProxy_Chr proxy_t;
    typedef CProxyElement_Chr element_t;
    typedef CProxySection_Chr section_t;

    CProxySection_Chr(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Chr operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Chr(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Chr operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Chr(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Chr operator [] (int idx) const 
        {return CProxyElement_Chr(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Chr operator () (int idx) const 
        {return CProxyElement_Chr(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      CkVec<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.push_back(CkArrayIndex1D(i));
      return CkSectionID(aid, al.getVec(), al.size(), factor);
    } 
    CProxySection_Chr(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Chr(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Chr(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Chr(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Chr(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Chr(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Chr(const CProxy_Main &main, int N);
 */
    

/* DECLS: void run(int N, int step);
 */
    
    void run(int N, int step, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void finalsend(int num, int right);
 */
    
    void finalsend(int num, int right, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void recvNumber(int step, int num);
 */
    
    void recvNumber(int step, int num, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Chr(CkMigrateMessage* impl_msg);
 */

};
PUPmarshall(CProxySection_Chr)
#define Chr_SDAG_CODE                                                          \
public:                                                                        \
  void run(int N, int step);                                                   \
  void run(Closure_Chr::run_2_closure* gen0);                                  \
private:                                                                       \
  void run_end(Closure_Chr::run_2_closure* gen0);                              \
  void _slist_0(Closure_Chr::run_2_closure* gen0);                             \
  void _slist_0_end(Closure_Chr::run_2_closure* gen0);                         \
  void _for_0(Closure_Chr::run_2_closure* gen0);                               \
  void _for_0_end(Closure_Chr::run_2_closure* gen0);                           \
  void _slist_1(Closure_Chr::run_2_closure* gen0);                             \
  void _slist_1_end(Closure_Chr::run_2_closure* gen0);                         \
  SDAG::Continuation* _when_0(Closure_Chr::run_2_closure* gen0);               \
  SDAG::Continuation* _when_0(Closure_Chr::run_2_closure* gen0, int refnum_0); \
  void _when_0_end(Closure_Chr::run_2_closure* gen0, Closure_Chr::recvNumber_4_closure* gen1);\
  void _serial_0(Closure_Chr::run_2_closure* gen0, Closure_Chr::recvNumber_4_closure* gen1);\
  void _serial_1(Closure_Chr::run_2_closure* gen0);                            \
  void _forall_0(Closure_Chr::run_2_closure* gen0);                            \
  void _forall_0_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0);\
  void _slist_2(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0);\
  void _slist_2_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0);\
  SDAG::Continuation* _when_1(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0);\
  void _when_1_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0, Closure_Chr::finalsend_3_closure* gen3);\
  void _serial_2(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0, Closure_Chr::finalsend_3_closure* gen3);\
public:                                                                        \
  void recvNumber(Closure_Chr::recvNumber_4_closure* genClosure);              \
  void recvNumber(int istep, int inum);                                        \
  void finalsend(Closure_Chr::finalsend_3_closure* genClosure);                \
  void finalsend(int inum, int right);                                         \
public:                                                                        \
  SDAG::dep_ptr __dep;                                                         \
  void _sdag_init();                                                           \
  void __sdag_init();                                                          \
public:                                                                        \
  void _sdag_pup(PUP::er &p);                                                  \
  void __sdag_pup(PUP::er &p) { }                                              \
  static void __sdag_register();                                               \
  static int _sdag_idx_Chr_serial_0();                                         \
  static int _sdag_reg_Chr_serial_0();                                         \
  static int _sdag_idx_Chr_serial_1();                                         \
  static int _sdag_reg_Chr_serial_1();                                         \
  static int _sdag_idx_Chr_serial_2();                                         \
  static int _sdag_reg_Chr_serial_2();                                         \

typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Chr>CBase_Chr;

/* ---------------- method closures -------------- */
class Closure_Main {
  public:


    struct checkSorted_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_Chr {
  public:


    struct run_2_closure;


    struct finalsend_3_closure;


    struct recvNumber_4_closure;


};

extern void _registeroddeven(void);
extern "C" void CkRegisterMainModule(void);
#endif
