

#ifndef LOADER_GETTABLE_H
#define LOADER_GETTABLE_H

#include "api/loadable/loader_respondable.h"
#include "utilities/connector.h"

namespace ARK
{
namespace API
{
namespace Loader
{
/*************************************************
*  PROTECTED: ARK::API::Loader::Gettable
**************************************************/
class Gettable
{
  protected:
/*************************************************
		* ARK::API::Loader::Gettable::status
		*   /api/loader/status
		**************************************************/
    ARK::API::Loader::Respondable::Status status(ARK::Utilities::Network::Connector& _netConnector);
    

/*************************************************
		* ARK::API::Loader::Gettable::sync
		*   /api/loader/status/sync
		**************************************************/
    ARK::API::Loader::Respondable::Sync sync(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
		* ARK::API::Loader::Gettable::autoconfigure
		*   /api/loader/autoconfigure
		**************************************************/
    ARK::Network autoconfigure(ARK::Utilities::Network::Connector& _netConnector);


/*  ==========================================================================  */
};
/*  =====================================  */
/*  ==========================================================================  */
};
};
};

#endif
