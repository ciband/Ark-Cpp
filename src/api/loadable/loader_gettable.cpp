#include "api/loadable/loader_gettable.h"
#include "api/paths.h"
#include "utilities/json.h"

/*  ==========================================================================  */
/*  ================================  */
/*  ARK::API::Loader::Gettable::status  */
/*  /api/loader/status  */
ARK::API::Loader::Respondable::Status ARK::API::Loader::Gettable::status(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::status_s);

  return ARK::Utilities::get_json_interface().loader_status_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  ==============================  */
/*  ARK::API::Loader::Gettable::sync  */
/*  /api/loader/status/sync  */
ARK::API::Loader::Respondable::Sync ARK::API::Loader::Gettable::sync(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::sync_s);

  return ARK::Utilities::get_json_interface().loader_status_sync_fromJSON(callback.c_str());
}

/*  ==========================================================================  */
/*  =======================================  */
/*  ARK::API::Loader::Gettable::autoconfigure  */
/*  /api/loader/autoconfigure  */
ARK::Network ARK::API::Loader::Gettable::autoconfigure(ARK::Utilities::Network::Connector& _netConnector)
{
  auto callback = _netConnector.cb(ARK::API::Paths::Loader::autoconfigure_s);

  return ARK::Utilities::get_json_interface().loader_autoconfigure_fromJSON(callback.c_str());
}

