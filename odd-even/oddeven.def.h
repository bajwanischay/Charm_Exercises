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

    struct Closure_Chr::send_2_closure : public SDAG::Closure {
      

      send_2_closure() {
        init();
      }
      send_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~send_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(send_2_closure));
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

    struct Closure_Chr::sendNumber_4_closure : public SDAG::Closure {
            int num;
            int step;


      sendNumber_4_closure() {
        init();
      }
      sendNumber_4_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return num;}
            int & getP1() { return step;}
      void pup(PUP::er& __p) {
        __p | num;
        __p | step;
        packClosure(__p);
      }
      virtual ~sendNumber_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(sendNumber_4_closure));
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
void send();
void finalsend(int num, int right);
void sendNumber(int num, int step);
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
/* DEFS: void send();
 */

void CProxyElement_Chr::send(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_send_void(),0);
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
/* DEFS: void sendNumber(int num, int step);
 */

void CProxyElement_Chr::sendNumber(int num, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_sendNumber_marshall4(),0);
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
/* DEFS: void send();
 */

void CProxy_Chr::send(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Chr::idx_send_void(),0);
}

// Entry point registration function

int CkIndex_Chr::reg_send_void() {
  int epidx = CkRegisterEp("send()",
      _call_send_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Chr::_call_send_void(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->send();
}
PUPable_def(SINGLE_ARG(Closure_Chr::send_2_closure))
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
  /*Unmarshall pup'd fields: int num, int right*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int right; implP|right;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finalsend(num, right);
}

int CkIndex_Chr::_callmarshall_finalsend_marshall3(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  /*Unmarshall pup'd fields: int num, int right*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int right; implP|right;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->finalsend(num, right);
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
/* DEFS: void sendNumber(int num, int step);
 */

void CProxy_Chr::sendNumber(int num, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Chr::idx_sendNumber_marshall4(),0);
}

// Entry point registration function

int CkIndex_Chr::reg_sendNumber_marshall4() {
  int epidx = CkRegisterEp("sendNumber(int num, int step)",
      _call_sendNumber_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_sendNumber_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_sendNumber_marshall4);

  return epidx;
}


void CkIndex_Chr::_call_sendNumber_marshall4(void* impl_msg, void* impl_obj_void)
{
  Chr* impl_obj = static_cast<Chr *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int num, int step*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int step; implP|step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sendNumber(num, step);
}

int CkIndex_Chr::_callmarshall_sendNumber_marshall4(char* impl_buf, void* impl_obj_void) {
  Chr* impl_obj = static_cast< Chr *>(impl_obj_void);
  /*Unmarshall pup'd fields: int num, int step*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int step; implP|step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sendNumber(num, step);
  return implP.size();
}

void CkIndex_Chr::_marshallmessagepup_sendNumber_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int num, int step*/
  PUP::fromMem implP(impl_buf);
  int num; implP|num;
  int step; implP|step;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("num");
  implDestP|num;
  if (implDestP.hasComments()) implDestP.comment("step");
  implDestP|step;
}
PUPable_def(SINGLE_ARG(Closure_Chr::sendNumber_4_closure))
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
/* DEFS: void send();
 */

void CProxySection_Chr::send(const CkEntryOptions *impl_e_opts) 
{
  static_cast<void>(impl_e_opts);
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_send_void(),0);
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
/* DEFS: void sendNumber(int num, int step);
 */

void CProxySection_Chr::sendNumber(int num, int step, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int num, int step
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|num;
    implP|step;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|num;
    implP|step;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Chr::idx_sendNumber_marshall4(),0);
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

  // REG: void send();
  idx_send_void();

  // REG: void finalsend(int num, int right);
  idx_finalsend_marshall3();

  // REG: void sendNumber(int num, int step);
  idx_sendNumber_marshall4();

  // REG: Chr(CkMigrateMessage* impl_msg);
  idx_Chr_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Chr_CkMigrateMessage());

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
void send();
void finalsend(int num, int right);
void sendNumber(int num, int step);
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
