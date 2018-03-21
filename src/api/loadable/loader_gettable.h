

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
    ARK::API::Loader::Respondable::Status statusfromJSON(const char* const _jsonStr);
    ARK::API::Loader::Respondable::Status statusfromJSON(const String& _jsonStr) {
        return statusfromJSON(_jsonStr.c_str());
    }

/*************************************************
		* ARK::API::Loader::Gettable::sync
		*   /api/loader/status/sync
		**************************************************/
    ARK::API::Loader::Respondable::Sync sync(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
		*
		*	{ 
		*		"success":true,
		*		"syncing":  bool,
		*		"blocks": int,
		*		"height": const char*,
		*		"id": "const char*"
		*	}
		*
		**************************************************/
    ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const _jsonStr);
    ARK::API::Loader::Respondable::Sync syncfromJSON(const String& _jsonStr) {
        return syncfromJSON(_jsonStr.c_str());
    }

/*************************************************
		* ARK::API::Loader::Gettable::autoconfigure
		*   /api/loader/autoconfigure
		**************************************************/
    ARK::Network autoconfigure(ARK::Utilities::Network::Connector& _netConnector);

/*************************************************
		*
		*	{
		*		"success":true,
		*		"network":
		*		{
		*			"nethash":  "Hash",
		*			"token":  "const char*",
		*			"symbol": "const char*,
		*			"explorer": "const char*",
		*			"version":  int
		*		}
		*	}
		*
		**************************************************/
    ARK::Network autoconfigurefromJSON(const char* const _jsonStr);
    ARK::Network autoconfigurefromJSON(const String& _jsonStr) {
        return autoconfigurefromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  =====================================  */
/*  ==========================================================================  */
};
};
};

#endif
