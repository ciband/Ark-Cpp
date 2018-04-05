

#ifndef DELEGATE_GETTABLE_H
#define DELEGATE_GETTABLE_H

#include "utilities/connector.h"
#include "models/delegate.h"
#include "api/delegatable/delegate_respondable.h"

namespace ARK
{
namespace API
{
namespace Delegate
{
/*************************************************
*  PROTECTED: ARK::API::Delegate::Gettable 
**************************************************/
class Gettable
{
  protected:
/*************************************************
		* ARK::API::Delegate::Gettable::count
		*   /api/delegates/count
		**************************************************/
    int count(ARK::Utilities::Network::Connector& _netConnector);



/*************************************************
		* ARK::API::Delegate::Gettable::search
		*   /api/delegates/search?q=sleepdeficit
		**************************************************/
    std::unique_ptr<ARK::API::Delegate::Respondable::Search[]> search(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _username);



/*************************************************
		* ARK::API::Delegate::Gettable::voters
		*   /api/delegates/voters?publicKey=_pubKey
		**************************************************/
    ARK::API::Delegate::Respondable::Voters voters(
        ARK::Utilities::Network::Connector& _netConnector,
        const Publickey& _publicKey);



/*************************************************
	* ARK::API::Delegate::Gettable::delegate
	*   /api/delegates/get?username=sleepdeficit
	*		/api/delegates/get?publicKey=_pubKey
	**************************************************/
    ARK::Delegate delegate(
        ARK::Utilities::Network::Connector& _netConnector,
        const char* const _parameter);


/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks    */
    /*  Delegates callback is ~13,564 bytes  */
     std::unique_ptr<ARK::Delegate[]> delegates(ARK::Utilities::Network::Connector& _netConnector);
	 
/*  ==========================================================================  */

/*************************************************
		* ARK::API::Delegate::Gettable::fee
		*   /api/delegates/fee
		**************************************************/
    Balance fee(ARK::Utilities::Network::Connector& _netConnector);


  
  /*************************************************
		* ARK::API::Delegate::Gettable::forgedByAccount
		*   /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
		**************************************************/
    ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccount(
        ARK::Utilities::Network::Connector& _netConnector,
        const Publickey& _generatorPublicKey);



/*************************************************
		* ARK::API::Delegate::Gettable::nextForgers
		*   /api/delegates/getNextForgers
		**************************************************/
    ARK::API::Delegate::Respondable::NextForgers nextForgers(ARK::Utilities::Network::Connector& _netConnector);


/*  ==========================================================================  */
 };

}
}
}

#endif
