/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Origin::isPrime_2_closure : public SDAG::Closure {
            int n;
            int key;
            int *res;

      CkMarshallMsg* _impl_marshall;
      char* _impl_buf_in;
      int _impl_buf_size;

      isPrime_2_closure() {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
      isPrime_2_closure(CkMigrateMessage*) {
        init();
        _impl_marshall = 0;
        _impl_buf_in = 0;
        _impl_buf_size = 0;
      }
            int & getP0() { return n;}
            int & getP1() { return key;}
            int *& getP2() { return res;}
      void pup(PUP::er& __p) {
        __p | n;
        __p | key;
        packClosure(__p);
        __p | _impl_buf_size;
        bool hasMsg = (_impl_marshall != 0); __p | hasMsg;
        if (hasMsg) CkPupMessage(__p, (void**)&_impl_marshall);
        else PUParray(__p, _impl_buf_in, _impl_buf_size);
        if (__p.isUnpacking()) {
          char *impl_buf = _impl_marshall ? _impl_marshall->msgBuf : _impl_buf_in;
          PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_res, impl_cnt_res;
  implP|impl_off_res;
  implP|impl_cnt_res;
          impl_buf+=CK_ALIGN(implP.size(),16);
#if !CMK_ONESIDED_IMPL
#endif
          res = (int *)(impl_buf+impl_off_res);
        }
      }
      virtual ~isPrime_2_closure() {
        if (_impl_marshall) CmiFree(UsrToEnv(_impl_marshall));
      }
      PUPable_decl(SINGLE_ARG(isPrime_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
void isPrime(int n, int key, const int *res);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Origin::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Origin(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Origin::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Origin::__idx, CkIndex_Origin::idx_Origin_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Origin::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Origin::__idx, CkIndex_Origin::idx_Origin_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Origin::CProxy_Origin(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Origin::__idx, CkIndex_Origin::idx_Origin_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Origin::reg_Origin_CkArgMsg() {
  int epidx = CkRegisterEp("Origin(CkArgMsg* impl_msg)",
      _call_Origin_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}


void CkIndex_Origin::_call_Origin_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Origin* impl_obj = static_cast<Origin *>(impl_obj_void);
  new (impl_obj_void) Origin((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void isPrime(int n, int key, const int *res);
 */

void CProxy_Origin::isPrime(int n, int key, const int *res, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int n, int key, const int *res
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_res, impl_cnt_res;
  impl_off_res=impl_off=CK_ALIGN(impl_off,sizeof(int));
  impl_off+=(impl_cnt_res=sizeof(int)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|key;
    implP|impl_off_res;
    implP|impl_cnt_res;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|key;
    implP|impl_off_res;
    implP|impl_cnt_res;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_res,res,impl_cnt_res);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Origin::idx_isPrime_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Origin::idx_isPrime_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Origin::idx_isPrime_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function

int CkIndex_Origin::reg_isPrime_marshall2() {
  int epidx = CkRegisterEp("isPrime(int n, int key, const int *res)",
      _call_isPrime_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_isPrime_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_isPrime_marshall2);

  return epidx;
}


void CkIndex_Origin::_call_isPrime_marshall2(void* impl_msg, void* impl_obj_void)
{
  Origin* impl_obj = static_cast<Origin *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int key, const int *res*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_res, impl_cnt_res;
  implP|impl_off_res;
  implP|impl_cnt_res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *res=(int *)(impl_buf+impl_off_res);
  impl_obj->isPrime(n, key, res);
}

int CkIndex_Origin::_callmarshall_isPrime_marshall2(char* impl_buf, void* impl_obj_void) {
  Origin* impl_obj = static_cast< Origin *>(impl_obj_void);
  /*Unmarshall pup'd fields: int n, int key, const int *res*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_res, impl_cnt_res;
  implP|impl_off_res;
  implP|impl_cnt_res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *res=(int *)(impl_buf+impl_off_res);
  impl_obj->isPrime(n, key, res);
  return implP.size();
}

void CkIndex_Origin::_marshallmessagepup_isPrime_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int key, const int *res*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_res, impl_cnt_res;
  implP|impl_off_res;
  implP|impl_cnt_res;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *res=(int *)(impl_buf+impl_off_res);
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("key");
  implDestP|key;
  if (implDestP.hasComments()) implDestP.comment("res");
  implDestP.synchronize(PUP::sync_begin_array);
  for (int impl_i=0;impl_i*(sizeof(*res))<impl_cnt_res;impl_i++) {
    implDestP.synchronize(PUP::sync_item);
    implDestP|res[impl_i];
  }
  implDestP.synchronize(PUP::sync_end_array);
}
PUPable_def(SINGLE_ARG(Closure_Origin::isPrime_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Origin::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Origin(CkArgMsg* impl_msg);
  idx_Origin_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Origin_CkArgMsg());

  // REG: void isPrime(int n, int key, const int *res);
  idx_isPrime_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: chare checkPrime: Chare{
checkPrime(int n, int key, const int *val);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_checkPrime::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: checkPrime(int n, int key, const int *val);
 */

CkChareID CProxy_checkPrime::ckNew(int n, int key, const int *val, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int key, const int *val
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_val, impl_cnt_val;
  impl_off_val=impl_off=CK_ALIGN(impl_off,sizeof(int));
  impl_off+=(impl_cnt_val=sizeof(int)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_val,val,impl_cnt_val);
  CkChareID impl_ret;
  CkCreateChare(CkIndex_checkPrime::__idx, CkIndex_checkPrime::idx_checkPrime_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_checkPrime::ckNew(int n, int key, const int *val, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int key, const int *val
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_val, impl_cnt_val;
  impl_off_val=impl_off=CK_ALIGN(impl_off,sizeof(int));
  impl_off+=(impl_cnt_val=sizeof(int)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_val,val,impl_cnt_val);
  CkCreateChare(CkIndex_checkPrime::__idx, CkIndex_checkPrime::idx_checkPrime_marshall1(), impl_msg, pcid, impl_onPE);
}

  CProxy_checkPrime::CProxy_checkPrime(int n, int key, const int *val, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int key, const int *val
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_val, impl_cnt_val;
  impl_off_val=impl_off=CK_ALIGN(impl_off,sizeof(int));
  impl_off+=(impl_cnt_val=sizeof(int)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|key;
    implP|impl_off_val;
    implP|impl_cnt_val;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_val,val,impl_cnt_val);
  CkChareID impl_ret;
  CkCreateChare(CkIndex_checkPrime::__idx, CkIndex_checkPrime::idx_checkPrime_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_checkPrime::reg_checkPrime_marshall1() {
  int epidx = CkRegisterEp("checkPrime(int n, int key, const int *val)",
      _call_checkPrime_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_checkPrime_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_checkPrime_marshall1);

  return epidx;
}


void CkIndex_checkPrime::_call_checkPrime_marshall1(void* impl_msg, void* impl_obj_void)
{
  checkPrime* impl_obj = static_cast<checkPrime *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int key, const int *val*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_val, impl_cnt_val;
  implP|impl_off_val;
  implP|impl_cnt_val;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *val=(int *)(impl_buf+impl_off_val);
  new (impl_obj_void) checkPrime(n, key, val);
}

int CkIndex_checkPrime::_callmarshall_checkPrime_marshall1(char* impl_buf, void* impl_obj_void) {
  checkPrime* impl_obj = static_cast< checkPrime *>(impl_obj_void);
  /*Unmarshall pup'd fields: int n, int key, const int *val*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_val, impl_cnt_val;
  implP|impl_off_val;
  implP|impl_cnt_val;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *val=(int *)(impl_buf+impl_off_val);
  new (impl_obj_void) checkPrime(n, key, val);
  return implP.size();
}

void CkIndex_checkPrime::_marshallmessagepup_checkPrime_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int key, const int *val*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int key; implP|key;
  int impl_off_val, impl_cnt_val;
  implP|impl_off_val;
  implP|impl_cnt_val;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  int *val=(int *)(impl_buf+impl_off_val);
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("key");
  implDestP|key;
  if (implDestP.hasComments()) implDestP.comment("val");
  implDestP.synchronize(PUP::sync_begin_array);
  for (int impl_i=0;impl_i*(sizeof(*val))<impl_cnt_val;impl_i++) {
    implDestP.synchronize(PUP::sync_item);
    implDestP|val[impl_i];
  }
  implDestP.synchronize(PUP::sync_end_array);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_checkPrime::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: checkPrime(int n, int key, const int *val);
  idx_checkPrime_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registertestprime(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
void isPrime(int n, int key, const int *res);
};
*/
  CkIndex_Origin::__register("Origin", sizeof(Origin));

/* REG: chare checkPrime: Chare{
checkPrime(int n, int key, const int *val);
};
*/
  CkIndex_checkPrime::__register("checkPrime", sizeof(checkPrime));

}
extern "C" void CkRegisterMainModule(void) {
  _registertestprime();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Origin::virtual_pup(PUP::er &p) {
    recursive_pup<Origin >(dynamic_cast<Origin* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_checkPrime::virtual_pup(PUP::er &p) {
    recursive_pup<checkPrime >(dynamic_cast<checkPrime* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
