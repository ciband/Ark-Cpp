

#ifndef LOADABLE_H
#define LOADABLE_H

#include "api/loadable/loader_respondable.h"
#include "api/loadable/loader_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Loadable
*   	public Loader::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Network Loader Model
* 
**************************************************/
class Loadable :
		public Loader::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*		/api/loader/status
		*
		*		@uri:	/api/loader/status
		*		@returnType:	ARK::API::Loader::Respondable::Status
		*
		*   @method:	loaderStatus()
		*
		*   @outs:	ARK::API::Loader::Gettable::status(this->netConnector)
		*
		*   @description:
		*			Gets Ark Network Status from a Node via API.
		* 
		**************************************************/
		ARK::API::Loader::Respondable::Status loaderStatus()
		{
			return ARK::API::Loader::Gettable::status(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/loader/status/sync
		*
		*		@uri:	/api/loader/status/sync
		*		@returnType:	ARK::API::Loader::Respondable::Sync
		*
		*   @method:	loaderSync()
		*
		*   @outs:	ARK::API::Loader::Gettable::sync(this->netConnector)
		*
		*   @description:
		*			Gets Ark Network Sync Status from a Node via API. 
		* 
		**************************************************/
		ARK::API::Loader::Respondable::Sync loaderSync()
		{
			return ARK::API::Loader::Gettable::sync(this->netConnector);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/loader/autoconfigure 
		*
		*		@uri:	/api/loader/autoconfigure 
		*		@returnType:	ARK::Network
		*
		*   @method:	loaderAutoconfigure()
		*
		*   @outs:	ARK::API::Loader::Gettable::autoconfigure(this->netConnector)
		*
		*   @description:
		*			Returns an auto-configured network
		*			from a Networks NetHash from a Node via API. 
		* 
		**************************************************/
		ARK::Network loaderAutoconfigure()
		{
			return ARK::API::Loader::Gettable::autoconfigure(this->netConnector);
		};
    /*************************************************/
};
/*************************************************/

};
};

#endif
