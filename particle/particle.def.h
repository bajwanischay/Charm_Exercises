
/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::printMax_2_closure : public SDAG::Closure {
            int max;


      printMax_2_closure() {
        init();
      }
      printMax_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return max;}
      void pup(PUP::er& __p) {
        __p | max;
        packClosure(__p);
      }
      virtual ~printMax_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(printMax_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::printTotal_3_closure : public SDAG::Closure {
            int total;


      printTotal_3_closure() {
        init();
      }
      printTotal_3_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return total;}
      void pup(PUP::er& __p) {
        __p | total;
        packClosure(__p);
      }
      virtual ~printTotal_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(printTotal_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Grid::Move_2_closure : public SDAG::Closure {
            int iteration;


      Move_2_closure() {
        init();
      }
      Move_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return iteration;}
      void pup(PUP::er& __p) {
        __p | iteration;
        packClosure(__p);
      }
      virtual ~Move_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(Move_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Grid::Transfer_3_closure : public SDAG::Closure {
            std::vector<Particle > in;


      Transfer_3_closure() {
        init();
      }
      Transfer_3_closure(CkMigrateMessage*) {
        init();
      }
            std::vector<Particle > & getP0() { return in;}
      void pup(PUP::er& __p) {
        __p | in;
        packClosure(__p);
      }
      virtual ~Transfer_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(Transfer_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void printMax(int max);
void printTotal(int total);
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
/* DEFS: void printMax(int max);
 */

void CProxy_Main::printMax(int max, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|max;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_printMax_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_printMax_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_printMax_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_printMax_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int max*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printMax(max);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_printMax_marshall2() {
  int epidx = CkRegisterEp("printMax(int max)",
      _call_printMax_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_printMax_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_printMax_marshall2);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_printMax_marshall2() {
  return CkRegisterEp("redn_wrapper_printMax(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_printMax_marshall2, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_printMax_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int max*/
  PUP::fromMem implP(impl_buf);
  int max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printMax(max);
}

int CkIndex_Main::_callmarshall_printMax_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int max*/
  PUP::fromMem implP(impl_buf);
  int max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printMax(max);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_printMax_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int max*/
  PUP::fromMem implP(impl_buf);
  int max; implP|max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("max");
  implDestP|max;
}
PUPable_def(SINGLE_ARG(Closure_Main::printMax_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void printTotal(int total);
 */

void CProxy_Main::printTotal(int total, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int total
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|total;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|total;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_printTotal_marshall3(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_printTotal_marshall3(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_printTotal_marshall3(), impl_msg, &ckGetChareID(),0);
  }
}

void CkIndex_Main::_call_redn_wrapper_printTotal_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int total*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int total; implP|total;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printTotal(total);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_printTotal_marshall3() {
  int epidx = CkRegisterEp("printTotal(int total)",
      _call_printTotal_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_printTotal_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_printTotal_marshall3);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_printTotal_marshall3() {
  return CkRegisterEp("redn_wrapper_printTotal(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_printTotal_marshall3, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_printTotal_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int total*/
  PUP::fromMem implP(impl_buf);
  int total; implP|total;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printTotal(total);
}

int CkIndex_Main::_callmarshall_printTotal_marshall3(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int total*/
  PUP::fromMem implP(impl_buf);
  int total; implP|total;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->printTotal(total);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_printTotal_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int total*/
  PUP::fromMem implP(impl_buf);
  int total; implP|total;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("total");
  implDestP|total;
}
PUPable_def(SINGLE_ARG(Closure_Main::printTotal_3_closure))
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

  // REG: void printMax(int max);
  idx_printMax_marshall2();
  idx_redn_wrapper_printMax_marshall2();

  // REG: void printTotal(int total);
  idx_printTotal_marshall3();
  idx_redn_wrapper_printTotal_marshall3();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Grid: ArrayElement{
Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
void Move(int iteration);
void Transfer(const std::vector<Particle > &in);
Grid(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Grid::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Grid::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

void CProxySection_Grid::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
 */

void CProxyElement_Grid::insert(int n, int k, float dim, int maxiter, const CProxy_Main &main, int onPE, const CkEntryOptions *impl_e_opts)
{ 
   //Marshall: int n, int k, float dim, int maxiter, const CProxy_Main &main
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Grid::idx_Grid_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Move(int iteration);
 */

void CProxyElement_Grid::Move(int iteration, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iteration
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iteration;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iteration;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Grid::idx_Move_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Transfer(const std::vector<Particle > &in);
 */

void CProxyElement_Grid::Transfer(const std::vector<Particle > &in, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<Particle > &in
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Grid::idx_Transfer_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
 */

CkArrayID CProxy_Grid::ckNew(int n, int k, float dim, int maxiter, const CProxy_Main &main, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int k, float dim, int maxiter, const CProxy_Main &main
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Grid::idx_Grid_marshall1(), opts);
  return gId;
}

void CProxy_Grid::ckNew(int n, int k, float dim, int maxiter, const CProxy_Main &main, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int k, float dim, int maxiter, const CProxy_Main &main
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Grid::idx_Grid_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

CkArrayID CProxy_Grid::ckNew(int n, int k, float dim, int maxiter, const CProxy_Main &main, const int s1, const int s2, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int k, float dim, int maxiter, const CProxy_Main &main
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
  }
  CkArrayOptions opts(s1, s2);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Grid::idx_Grid_marshall1(), opts);
  return gId;
}

void CProxy_Grid::ckNew(int n, int k, float dim, int maxiter, const CProxy_Main &main, const int s1, const int s2, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, int k, float dim, int maxiter, const CProxy_Main &main
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    implP|k;
    implP|dim;
    implP|maxiter;
    //Have to cast away const-ness to get pup routine
    implP|(CProxy_Main &)main;
  }
  CkArrayOptions opts(s1, s2);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Grid::idx_Grid_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function

int CkIndex_Grid::reg_Grid_marshall1() {
  int epidx = CkRegisterEp("Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main)",
      _call_Grid_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Grid_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Grid_marshall1);

  return epidx;
}


void CkIndex_Grid::_call_Grid_marshall1(void* impl_msg, void* impl_obj_void)
{
  Grid* impl_obj = static_cast<Grid *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int k, float dim, int maxiter, const CProxy_Main &main*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int k; implP|k;
  float dim; implP|dim;
  int maxiter; implP|maxiter;
  CProxy_Main main; implP|main;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Grid(n, k, dim, maxiter, main);
}

int CkIndex_Grid::_callmarshall_Grid_marshall1(char* impl_buf, void* impl_obj_void) {
  Grid* impl_obj = static_cast< Grid *>(impl_obj_void);
  /*Unmarshall pup'd fields: int n, int k, float dim, int maxiter, const CProxy_Main &main*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int k; implP|k;
  float dim; implP|dim;
  int maxiter; implP|maxiter;
  CProxy_Main main; implP|main;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Grid(n, k, dim, maxiter, main);
  return implP.size();
}

void CkIndex_Grid::_marshallmessagepup_Grid_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int n, int k, float dim, int maxiter, const CProxy_Main &main*/
  PUP::fromMem implP(impl_buf);
  int n; implP|n;
  int k; implP|k;
  float dim; implP|dim;
  int maxiter; implP|maxiter;
  CProxy_Main main; implP|main;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("k");
  implDestP|k;
  if (implDestP.hasComments()) implDestP.comment("dim");
  implDestP|dim;
  if (implDestP.hasComments()) implDestP.comment("maxiter");
  implDestP|maxiter;
  if (implDestP.hasComments()) implDestP.comment("main");
  implDestP|main;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Move(int iteration);
 */

void CProxy_Grid::Move(int iteration, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iteration
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iteration;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iteration;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Grid::idx_Move_marshall2(),0);
}

// Entry point registration function

int CkIndex_Grid::reg_Move_marshall2() {
  int epidx = CkRegisterEp("Move(int iteration)",
      _call_Move_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Move_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Move_marshall2);

  return epidx;
}


void CkIndex_Grid::_call_Move_marshall2(void* impl_msg, void* impl_obj_void)
{
  Grid* impl_obj = static_cast<Grid *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iteration*/
  PUP::fromMem implP(impl_buf);
  int iteration; implP|iteration;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Move(iteration);
}

int CkIndex_Grid::_callmarshall_Move_marshall2(char* impl_buf, void* impl_obj_void) {
  Grid* impl_obj = static_cast< Grid *>(impl_obj_void);
  /*Unmarshall pup'd fields: int iteration*/
  PUP::fromMem implP(impl_buf);
  int iteration; implP|iteration;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Move(iteration);
  return implP.size();
}

void CkIndex_Grid::_marshallmessagepup_Move_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iteration*/
  PUP::fromMem implP(impl_buf);
  int iteration; implP|iteration;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("iteration");
  implDestP|iteration;
}
PUPable_def(SINGLE_ARG(Closure_Grid::Move_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Transfer(const std::vector<Particle > &in);
 */

void CProxy_Grid::Transfer(const std::vector<Particle > &in, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<Particle > &in
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Grid::idx_Transfer_marshall3(),0);
}

// Entry point registration function

int CkIndex_Grid::reg_Transfer_marshall3() {
  int epidx = CkRegisterEp("Transfer(const std::vector<Particle > &in)",
      _call_Transfer_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Transfer_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Transfer_marshall3);

  return epidx;
}


void CkIndex_Grid::_call_Transfer_marshall3(void* impl_msg, void* impl_obj_void)
{
  Grid* impl_obj = static_cast<Grid *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const std::vector<Particle > &in*/
  PUP::fromMem implP(impl_buf);
  std::vector<Particle > in; implP|in;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Transfer(in);
}

int CkIndex_Grid::_callmarshall_Transfer_marshall3(char* impl_buf, void* impl_obj_void) {
  Grid* impl_obj = static_cast< Grid *>(impl_obj_void);
  /*Unmarshall pup'd fields: const std::vector<Particle > &in*/
  PUP::fromMem implP(impl_buf);
  std::vector<Particle > in; implP|in;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->Transfer(in);
  return implP.size();
}

void CkIndex_Grid::_marshallmessagepup_Transfer_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const std::vector<Particle > &in*/
  PUP::fromMem implP(impl_buf);
  std::vector<Particle > in; implP|in;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("in");
  implDestP|in;
}
PUPable_def(SINGLE_ARG(Closure_Grid::Transfer_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Grid::reg_Grid_CkMigrateMessage() {
  int epidx = CkRegisterEp("Grid(CkMigrateMessage* impl_msg)",
      _call_Grid_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Grid::_call_Grid_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Grid> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Move(int iteration);
 */

void CProxySection_Grid::Move(int iteration, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iteration
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iteration;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iteration;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Grid::idx_Move_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void Transfer(const std::vector<Particle > &in);
 */

void CProxySection_Grid::Transfer(const std::vector<Particle > &in, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<Particle > &in
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(std::vector<Particle > &)in;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Grid::idx_Transfer_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Grid(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Grid::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
  idx_Grid_marshall1();

  // REG: void Move(int iteration);
  idx_Move_marshall2();

  // REG: void Transfer(const std::vector<Particle > &in);
  idx_Transfer_marshall3();

  // REG: Grid(CkMigrateMessage* impl_msg);
  idx_Grid_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Grid_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerparticle(void)
{
  static int _done = 0; if(_done) return; _done = 1;

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void printMax(int max);
void printTotal(int total);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Grid: ArrayElement{
Grid(int n, int k, float dim, int maxiter, const CProxy_Main &main);
void Move(int iteration);
void Transfer(const std::vector<Particle > &in);
Grid(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Grid::__register("Grid", sizeof(Grid));

}
extern "C" void CkRegisterMainModule(void) {
  _registerparticle();
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
void CBase_Grid::virtual_pup(PUP::er &p) {
    recursive_pup<Grid >(dynamic_cast<Grid* >(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
