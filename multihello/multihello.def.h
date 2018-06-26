/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
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
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Origin::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Origin(CkArgMsg* impl_msg);
  idx_Origin_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Origin_CkArgMsg());

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: chare Interim: Chare{
Interim(int x);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Interim::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Interim(int x);
 */

CkChareID CProxy_Interim::ckNew(int x, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Interim::__idx, CkIndex_Interim::idx_Interim_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Interim::ckNew(int x, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkCreateChare(CkIndex_Interim::__idx, CkIndex_Interim::idx_Interim_marshall1(), impl_msg, pcid, impl_onPE);
}

  CProxy_Interim::CProxy_Interim(int x, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Interim::__idx, CkIndex_Interim::idx_Interim_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Interim::reg_Interim_marshall1() {
  int epidx = CkRegisterEp("Interim(int x)",
      _call_Interim_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Interim_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Interim_marshall1);

  return epidx;
}


void CkIndex_Interim::_call_Interim_marshall1(void* impl_msg, void* impl_obj_void)
{
  Interim* impl_obj = static_cast<Interim *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Interim(x);
}

int CkIndex_Interim::_callmarshall_Interim_marshall1(char* impl_buf, void* impl_obj_void) {
  Interim* impl_obj = static_cast< Interim *>(impl_obj_void);
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Interim(x);
  return implP.size();
}

void CkIndex_Interim::_marshallmessagepup_Interim_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("x");
  implDestP|x;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Interim::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Interim(int x);
  idx_Interim_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: chare Destination: Chare{
Destination(int x);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Destination::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Destination(int x);
 */

CkChareID CProxy_Destination::ckNew(int x, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Destination::__idx, CkIndex_Destination::idx_Destination_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Destination::ckNew(int x, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkCreateChare(CkIndex_Destination::__idx, CkIndex_Destination::idx_Destination_marshall1(), impl_msg, pcid, impl_onPE);
}

  CProxy_Destination::CProxy_Destination(int x, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int x
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|x;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|x;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Destination::__idx, CkIndex_Destination::idx_Destination_marshall1(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Destination::reg_Destination_marshall1() {
  int epidx = CkRegisterEp("Destination(int x)",
      _call_Destination_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Destination_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Destination_marshall1);

  return epidx;
}


void CkIndex_Destination::_call_Destination_marshall1(void* impl_msg, void* impl_obj_void)
{
  Destination* impl_obj = static_cast<Destination *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Destination(x);
}

int CkIndex_Destination::_callmarshall_Destination_marshall1(char* impl_buf, void* impl_obj_void) {
  Destination* impl_obj = static_cast< Destination *>(impl_obj_void);
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Destination(x);
  return implP.size();
}

void CkIndex_Destination::_marshallmessagepup_Destination_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int x*/
  PUP::fromMem implP(impl_buf);
  int x; implP|x;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("x");
  implDestP|x;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Destination::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Destination(int x);
  idx_Destination_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registermultihello(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Origin: Chare{
Origin(CkArgMsg* impl_msg);
};
*/
  CkIndex_Origin::__register("Origin", sizeof(Origin));

/* REG: chare Interim: Chare{
Interim(int x);
};
*/
  CkIndex_Interim::__register("Interim", sizeof(Interim));

/* REG: chare Destination: Chare{
Destination(int x);
};
*/
  CkIndex_Destination::__register("Destination", sizeof(Destination));

}
extern "C" void CkRegisterMainModule(void) {
  _registermultihello();
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
void CBase_Interim::virtual_pup(PUP::er &p) {
    recursive_pup<Interim >(dynamic_cast<Interim* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Destination::virtual_pup(PUP::er &p) {
    recursive_pup<Destination >(dynamic_cast<Destination* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
