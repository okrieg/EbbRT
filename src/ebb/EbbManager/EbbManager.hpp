#ifndef EBBRT_EBB_EBBMANAGER_EBBMANAGER_HPP
#define EBBRT_EBB_EBBMANAGER_EBBMANAGER_HPP

#include "ebb/ebb.hpp"
#include "lrt/trans_impl.hpp"

namespace ebbrt {
  class EbbManager : public EbbRep {
  public:
    virtual void CacheRep(EbbId id, EbbRep* rep) = 0;
    virtual EbbId AllocateId() = 0;
    virtual void Bind(EbbRoot* (*factory)(), EbbId id) = 0;
    virtual ~EbbManager() {}
  private:
    friend lrt::trans::InitRoot;
    virtual EbbRoot* FindRoot(EbbId id) = 0;
  };
  extern char ebb_manager_id_resv
  __attribute__ ((section ("static_ebb_ids")));
  extern "C" char static_ebb_ids_start[];
  const Ebb<EbbManager> ebb_manager =
    Ebb<EbbManager>(static_cast<EbbId>(&ebb_manager_id_resv -
                                         static_ebb_ids_start));
}

#endif
