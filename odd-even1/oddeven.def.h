/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::checkSorted_2_closure : public SDAG::Closure {
            int result;


      checkSorted_2_closure() {
        init();
      }
      checkSorted_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return result;}
      void pup(PUP::er& __p) {
        __p | result;
        packClosure(__p);
      }
      virtual ~checkSorted_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(checkSorted_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Chr::run_2_closure : public SDAG::Closure {
            int N;
            int step;


      run_2_closure() {
        init();
      }
      run_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return N;}
            int & getP1() { return step;}
      void pup(PUP::er& __p) {
        __p | N;
        __p | step;
        packClosure(__p);
      }
      virtual ~run_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Chr::finalsend_3_closure : public SDAG::Closure {
            int num;
            int right;


      finalsend_3_closure() {
        init();
      }
      finalsend_3_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return num;}
            int & getP1() { return right;}
      void pup(PUP::er& __p) {
        __p | num;
        __p | right;
        packClosure(__p);
      }
      virtual ~finalsend_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(finalsend_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Chr::recvNumber_4_closure : public SDAG::Closure {
            int step;
            int num;


      recvNumber_4_closure() {
        init();
      }
      recvNumber_4_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return step;}
            int & getP1() { return num;}
      void pup(PUP::er& __p) {
        __p | step;
        __p | num;
        packClosure(__p);
      }
      virtual ~recvNumber_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(recvNumber_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void checkSorted(int result);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Main::CProxy_Main(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      _call_Main_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}


void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void checkSorted(int result);
 */

void CProxy_Main::checkSorted(int result, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int result
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|result;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|result;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_checkSorted_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_checkSorted_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_checkSorted_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_checkSorted_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int result*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int result; implP|result;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->checkSorted(result);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_checkSorted_marshall2() {
  int epidx = CkRegisterEp("checkSorted(int result)",
      _call_checkSorted_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_checkSorted_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_checkSorted_marshall2);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_checkSorted_marshall2() {
  return CkRegisterEp("redn_wrapper_checkSorted(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_checkSorted_marshall2, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_checkSorted_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int result*/
  PUP::fromMem implP(impl_buf);
  int result; implP|result;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->checkSorted(result);
}

int CkIndex_Main::_callmarshall_checkSorted_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int result*/
  PUP::fromMem implP(impl_buf);
  int result; implP|result;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->checkSorted(result);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_checkSorted_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int result*/
  PUP::fromMem implP(impl_buf);
  int result; implP|result;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("result");
  implDestP|result;
}
PUPable_def(SINGLE_ARG(Closure_Main::checkSorted_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void checkSorted(int result);
  idx_checkSorted_marshall2();
  idx_redn_wrapper_checkSorted_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Chr: ArrayElement{
Chr(const CProxy_Main &main, int N);
void run(int N, int step);
void finalsend(int num, int right);
void recvNumber(int step, int num);
Chr(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Chr::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Chr::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

void CProxySection_Chr::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(const CProxy_Main &main, int N);
 */

void CProxyElement_Chr::insert(const CProxy_Main &main, int N, int onPE, const CkEntryOptions *impl_e_opts)
{ 
   //Marshall: const CProxy_Main &main, int N
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Chr::idx_Chr_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(int N, int step);
 */

void CProxyElement_Chr::run(int N, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int N, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|N;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|N;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_run_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void finalsend(int num, int right);
 */

void CProxyElement_Chr::finalsend(int num, int right, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int right
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|right;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|right;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_finalsend_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvNumber(int step, int num);
 */

void CProxyElement_Chr::recvNumber(int step, int num, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int step, int num
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|step;
    implP|num;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|step;
    implP|num;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_recvNumber_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(const CProxy_Main &main, int N);
 */

CkArrayID CProxy_Chr::ckNew(const CProxy_Main &main, int N, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main &main, int N
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Chr::idx_Chr_marshall1(), opts);
  return gId;
}

void CProxy_Chr::ckNew(const CProxy_Main &main, int N, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main &main, int N
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Chr::idx_Chr_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

CkArrayID CProxy_Chr::ckNew(const CProxy_Main &main, int N, const int s1, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main &main, int N
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Chr::idx_Chr_marshall1(), opts);
  return gId;
}

void CProxy_Chr::ckNew(const CProxy_Main &main, int N, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CProxy_Main &main, int N
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    implP|N;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Chr::idx_Chr_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function

int CkIndex_Chr::reg_Chr_marshall1() {
  int epidx = CkRegisterEp("Chr(const CProxy_Main &main, int N)",
      _call_Chr_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Chr_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Chr_marshall1);

  return epidx;
}


void CkIndex_Chr::_call_Chr_marshall1(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main &main, int N*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main main; implP|main;
  int N; implP|N;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Chr(main, N);
}

int CkIndex_Chr::_callmarshall_Chr_marshall1(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CProxy_Main &main, int N*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main main; implP|main;
  int N; implP|N;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Chr(main, N);
  return implP.size();
}

void CkIndex_Chr::_marshallmessagepup_Chr_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CProxy_Main &main, int N*/
  PUP::fromMem implP(impl_buf);
  CProxy_Main main; implP|main;
  int N; implP|N;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("main");
  implDestP|main;
  if (implDestP.hasComments()) implDestP.comment("N");
  implDestP|N;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(int N, int step);
 */

void CProxy_Chr::run(int N, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int N, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|N;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|N;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Chr::idx_run_marshall2(),0);
}

// Entry point registration function

int CkIndex_Chr::reg_run_marshall2() {
  int epidx = CkRegisterEp("run(int N, int step)",
      _call_run_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_run_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_run_marshall2);

  return epidx;
}


void CkIndex_Chr::_call_run_marshall2(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  PUP::fromMem implP(impl_buf);
  Closure_Chr::run_2_closure* genClosure = new Closure_Chr::run_2_closure();
  implP|genClosure->N;
  implP|genClosure->step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->run(genClosure);
  genClosure->deref();
}

int CkIndex_Chr::_callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  PUP::fromMem implP(impl_buf);
  Closure_Chr::run_2_closure* genClosure = new Closure_Chr::run_2_closure();
  implP|genClosure->N;
  implP|genClosure->step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->run(genClosure);
  genClosure->deref();
  return implP.size();
}

void CkIndex_Chr::_marshallmessagepup_run_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int N, int step*/
  PUP::fromMem implP(impl_buf);
  int N; implP|N;
  int step; implP|step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("N");
  implDestP|N;
  if (implDestP.hasComments()) implDestP.comment("step");
  implDestP|step;
}
PUPable_def(SINGLE_ARG(Closure_Chr::run_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void finalsend(int num, int right);
 */

void CProxy_Chr::finalsend(int num, int right, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int right
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|right;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|right;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Chr::idx_finalsend_marshall3(),0);
}

// Entry point registration function

int CkIndex_Chr::reg_finalsend_marshall3() {
  int epidx = CkRegisterEp("finalsend(int num, int right)",
      _call_finalsend_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_finalsend_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_finalsend_marshall3);

  return epidx;
}


void CkIndex_Chr::_call_finalsend_marshall3(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  PUP::fromMem implP(impl_buf);
  Closure_Chr::finalsend_3_closure* genClosure = new Closure_Chr::finalsend_3_closure();
  implP|genClosure->num;
  implP|genClosure->right;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->finalsend(genClosure);
  genClosure->deref();
}

int CkIndex_Chr::_callmarshall_finalsend_marshall3(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  PUP::fromMem implP(impl_buf);
  Closure_Chr::finalsend_3_closure* genClosure = new Closure_Chr::finalsend_3_closure();
  implP|genClosure->num;
  implP|genClosure->right;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->finalsend(genClosure);
  genClosure->deref();
  return implP.size();
}

void CkIndex_Chr::_marshallmessagepup_finalsend_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int num, int right*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int right; implP|right;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("num");
  implDestP|num;
  if (implDestP.hasComments()) implDestP.comment("right");
  implDestP|right;
}
PUPable_def(SINGLE_ARG(Closure_Chr::finalsend_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvNumber(int step, int num);
 */

void CProxy_Chr::recvNumber(int step, int num, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int step, int num
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|step;
    implP|num;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|step;
    implP|num;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Chr::idx_recvNumber_marshall4(),0);
}

// Entry point registration function

int CkIndex_Chr::reg_recvNumber_marshall4() {
  int epidx = CkRegisterEp("recvNumber(int step, int num)",
      _call_recvNumber_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_recvNumber_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_recvNumber_marshall4);

  return epidx;
}


void CkIndex_Chr::_call_recvNumber_marshall4(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  PUP::fromMem implP(impl_buf);
  Closure_Chr::recvNumber_4_closure* genClosure = new Closure_Chr::recvNumber_4_closure();
  implP|genClosure->step;
  implP|genClosure->num;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->recvNumber(genClosure);
  genClosure->deref();
}

int CkIndex_Chr::_callmarshall_recvNumber_marshall4(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  PUP::fromMem implP(impl_buf);
  Closure_Chr::recvNumber_4_closure* genClosure = new Closure_Chr::recvNumber_4_closure();
  implP|genClosure->step;
  implP|genClosure->num;
  impl_buf+=CK_ALIGN(implP.size(),16);
  impl_obj->recvNumber(genClosure);
  genClosure->deref();
  return implP.size();
}

void CkIndex_Chr::_marshallmessagepup_recvNumber_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int step, int num*/
  PUP::fromMem implP(impl_buf);
  int step; implP|step;
  int num; implP|num;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("step");
  implDestP|step;
  if (implDestP.hasComments()) implDestP.comment("num");
  implDestP|num;
}
PUPable_def(SINGLE_ARG(Closure_Chr::recvNumber_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Chr::reg_Chr_CkMigrateMessage() {
  int epidx = CkRegisterEp("Chr(CkMigrateMessage* impl_msg)",
      _call_Chr_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Chr::_call_Chr_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Chr> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(const CProxy_Main &main, int N);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(int N, int step);
 */

void CProxySection_Chr::run(int N, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int N, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|N;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|N;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_run_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void finalsend(int num, int right);
 */

void CProxySection_Chr::finalsend(int num, int right, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int right
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|right;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|right;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_finalsend_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvNumber(int step, int num);
 */

void CProxySection_Chr::recvNumber(int step, int num, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int step, int num
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|step;
    implP|num;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|step;
    implP|num;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_recvNumber_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Chr(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Chr::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Chr(const CProxy_Main &main, int N);
  idx_Chr_marshall1();

  // REG: void run(int N, int step);
  idx_run_marshall2();

  // REG: void finalsend(int num, int right);
  idx_finalsend_marshall3();

  // REG: void recvNumber(int step, int num);
  idx_recvNumber_marshall4();

  // REG: Chr(CkMigrateMessage* impl_msg);
  idx_Chr_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Chr_CkMigrateMessage());

  Chr::__sdag_register(); // Potentially missing Chr_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Chr::run(int N, int step){
  Closure_Chr::run_2_closure* genClosure = new Closure_Chr::run_2_closure();
  genClosure->getP0() = N;
  genClosure->getP1() = step;
  run(genClosure);
  genClosure->deref();
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::run(Closure_Chr::run_2_closure* gen0) {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  _slist_0(gen0);
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::run_end(Closure_Chr::run_2_closure* gen0) {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_0(Closure_Chr::run_2_closure* gen0) {
  _for_0(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_0_end(Closure_Chr::run_2_closure* gen0) {
  run_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_for_0(Closure_Chr::run_2_closure* gen0) {
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    step=0;
    if (step<N) {
      _slist_1(gen0);
    } else {
      _serial_1(gen0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_for_0_end(Closure_Chr::run_2_closure* gen0) {
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    step++;
    if (step<N) {
      _slist_1(gen0);
    } else {
      _serial_1(gen0);
    }
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_1(Closure_Chr::run_2_closure* gen0) {
  _when_0(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_1_end(Closure_Chr::run_2_closure* gen0) {
  _for_0_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Chr::_when_0(Closure_Chr::run_2_closure* gen0) {
  CMK_REFNUM_TYPE refnum_0;
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    {
      refnum_0 = step;
    }
  }
  return _when_0(gen0, refnum_0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Chr::_when_0(Closure_Chr::run_2_closure* gen0, int refnum_0) {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(0, true, refnum_0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_0(gen0, static_cast<Closure_Chr::recvNumber_4_closure*>(buf0->cl));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(0);
    c->addClosure(gen0);
    c->entries.push_back(0);
    c->refnums.push_back(refnum_0);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_when_0_end(Closure_Chr::run_2_closure* gen0, Closure_Chr::recvNumber_4_closure* gen1) {
  _slist_1_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_serial_0(Closure_Chr::run_2_closure* gen0, Closure_Chr::recvNumber_4_closure* gen1) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Chr_serial_0()), CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    {
      int& istep = gen1->getP0();
      int& inum = gen1->getP1();
      { // begin serial block
#line 10 "oddeven.ci"

          if((step%2==0 && thisIndex%2==0) ||(step%2==1 && thisIndex%2==1)){
            num=inum<num?inum:num;
            if(thisIndex>0) {thisProxy[thisIndex-1].recvNumber(step+1,num);}
            else{thisProxy[thisIndex].recvNumber(step+1,num);}
          }
          else{
            num=inum>num?inum:num;
            if(thisIndex<N-1) {thisProxy[thisIndex+1].recvNumber(step+1,num);}
            else{thisProxy[thisIndex].recvNumber(step+1,num);}
          }
        
#line 1113 "oddeven.def.h"
      } // end serial block
    }
  }
  _TRACE_END_EXECUTE(); 
  _when_0_end(gen0, gen1);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_serial_1(Closure_Chr::run_2_closure* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Chr_serial_1()), CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    { // begin serial block
#line 23 "oddeven.ci"

        if(thisIndex>0)
          thisProxy[thisIndex-1].finalsend(num,1);
        if(thisIndex<N-1)
          thisProxy[thisIndex+1].finalsend(num,0);
      
#line 1137 "oddeven.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _forall_0(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_forall_0(Closure_Chr::run_2_closure* gen0) {
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
  int __first = (0), __last = (1), __stride = (1);
  if (__first > __last) {
    int __tmp=__first; __first=__last; __last=__tmp;
    __stride = -__stride;
  }
  SDAG::CCounter *_cf0 = new SDAG::CCounter(__first, __last, __stride);
  for(int step=__first;step<=__last;step+=__stride) {
    SDAG::ForallClosure* step_cl = new SDAG::ForallClosure(step);
    _slist_2(gen0, step_cl, _cf0);
  }
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_forall_0_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0) {
  _cf0->decrement(); /* DECREMENT 1 */ 
  step_cl->deref();
  if (_cf0->isDone()) {
    _cf0->deref();
    _slist_0_end(gen0);
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_2(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0) {
  _when_1(gen0, step_cl, _cf0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_slist_2_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0) {
  _forall_0_end(gen0, step_cl, _cf0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Chr::_when_1(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0) {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(1, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_2(gen0, step_cl, _cf0, static_cast<Closure_Chr::finalsend_3_closure*>(buf0->cl));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(1);
    c->addClosure(gen0);
    c->addClosure(step_cl);
    c->addClosure(_cf0);
    c->anyEntries.push_back(1);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_when_1_end(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0, Closure_Chr::finalsend_3_closure* gen3) {
  _slist_2_end(gen0, step_cl, _cf0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_serial_2(Closure_Chr::run_2_closure* gen0, SDAG::ForallClosure* step_cl, SDAG::CCounter* _cf0, Closure_Chr::finalsend_3_closure* gen3) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Chr_serial_2()), CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
  {
    int& N = gen0->getP0();
    int& step = gen0->getP1();
    {
      int& step = step_cl->getP0();
      {
        {
          int& inum = gen3->getP0();
          int& right = gen3->getP1();
          { // begin serial block
#line 30 "oddeven.ci"

          if((right && inum<num)||(!right && inum>num)){
            reduce(0);
          }
          else if(((thisIndex==N-1||thisIndex==0)&&step==0) || step==1){
            reduce(1);
          }
        
#line 1242 "oddeven.def.h"
          } // end serial block
        }
      }
    }
  }
  _TRACE_END_EXECUTE(); 
  _when_1_end(gen0, step_cl, _cf0, gen3);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::recvNumber(int istep, int inum){
  Closure_Chr::recvNumber_4_closure* genClosure = new Closure_Chr::recvNumber_4_closure();
  genClosure->getP0() = istep;
  genClosure->getP1() = inum;
  recvNumber(genClosure);
  genClosure->deref();
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::recvNumber(Closure_Chr::recvNumber_4_closure* genClosure){
  if (!__dep.get()) _sdag_init();
  if (!genClosure->hasRefnum) genClosure->setRefnum(genClosure->getP0());
  __dep->pushBuffer(0, genClosure);
  SDAG::Continuation* c = __dep->tryFindContinuation(0);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_0(
      static_cast<Closure_Chr::run_2_closure*>(c->closure[0]), 
      c->refnums[0]
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::finalsend(int inum, int right){
  Closure_Chr::finalsend_3_closure* genClosure = new Closure_Chr::finalsend_3_closure();
  genClosure->getP0() = inum;
  genClosure->getP1() = right;
  finalsend(genClosure);
  genClosure->deref();
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::finalsend(Closure_Chr::finalsend_3_closure* genClosure){
  if (!__dep.get()) _sdag_init();
  __dep->pushBuffer(1, genClosure);
  SDAG::Continuation* c = __dep->tryFindContinuation(1);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_1(
      static_cast<Closure_Chr::run_2_closure*>(c->closure[0]), 
      static_cast<SDAG::ForallClosure*>(c->closure[1]), 
      static_cast<SDAG::CCounter*>(c->closure[2])
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, ckGetArrayIndex().getProjectionID(), this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::_sdag_init() { // Potentially missing Chr_SDAG_CODE in your class definition?
  __dep.reset(new SDAG::Dependency(2,2));
  __dep->addDepends(0,0);
  __dep->addDepends(1,1);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::__sdag_init() { // Potentially missing Chr_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Chr::_sdag_pup(PUP::er &p) { // Potentially missing Chr_SDAG_CODE in your class definition?
#if CMK_USING_XLC
    bool hasSDAG = __dep.get();
    p|hasSDAG;
    if (p.isUnpacking() && hasSDAG) _sdag_init();
    if (hasSDAG) { __dep->pup(p); }
#else
    p|__dep;
#endif
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Chr::__sdag_register() { // Potentially missing Chr_SDAG_CODE in your class definition?
  (void)_sdag_idx_Chr_serial_0();
  (void)_sdag_idx_Chr_serial_1();
  (void)_sdag_idx_Chr_serial_2();
  PUPable_reg(SINGLE_ARG(Closure_Chr::run_2_closure));
  PUPable_reg(SINGLE_ARG(Closure_Chr::finalsend_3_closure));
  PUPable_reg(SINGLE_ARG(Closure_Chr::recvNumber_4_closure));
  PUPable_reg(SINGLE_ARG(Closure_Chr::run_2_closure));
  PUPable_reg(SINGLE_ARG(Closure_Chr::finalsend_3_closure));
  PUPable_reg(SINGLE_ARG(Closure_Chr::recvNumber_4_closure));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_idx_Chr_serial_0() { // Potentially missing Chr_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Chr_serial_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_reg_Chr_serial_0() { // Potentially missing Chr_SDAG_CODE in your class definition?
  return CkRegisterEp("Chr_serial_0", NULL, 0, CkIndex_Chr::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_idx_Chr_serial_1() { // Potentially missing Chr_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Chr_serial_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_reg_Chr_serial_1() { // Potentially missing Chr_SDAG_CODE in your class definition?
  return CkRegisterEp("Chr_serial_1", NULL, 0, CkIndex_Chr::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_idx_Chr_serial_2() { // Potentially missing Chr_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Chr_serial_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Chr::_sdag_reg_Chr_serial_2() { // Potentially missing Chr_SDAG_CODE in your class definition?
  return CkRegisterEp("Chr_serial_2", NULL, 0, CkIndex_Chr::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



#ifndef CK_TEMPLATES_ONLY
void _registeroddeven(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void checkSorted(int result);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Chr: ArrayElement{
Chr(const CProxy_Main &main, int N);
void run(int N, int step);
void finalsend(int num, int right);
void recvNumber(int step, int num);
Chr(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Chr::__register("Chr", sizeof(Chr));

}
extern "C" void CkRegisterMainModule(void) {
  _registeroddeven();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main >(dynamic_cast<Main* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Chr::virtual_pup(PUP::er &p) {
    recursive_pup<Chr >(dynamic_cast<Chr* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
