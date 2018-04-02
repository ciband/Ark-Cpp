

#ifndef TRANSACTION_GETTABLE_H
#define TRANSACTION_GETTABLE_H

#include "models/transaction.h"
#include "api/transactionable/transaction_respondable.h"
#include "utilities/connector.h"
#include "types/hash.h"

namespace ARK
{
namespace API
{
namespace Transaction
{
/*************************************************
*  PROTECTED: ARK::API::Transaction::Gettable
**************************************************/
class Gettable
{
  protected:
	/*************************************************
		* ARK::API::Transaction::Gettable::transaction
		*   /api/transactions/get?id=
		**************************************************/
    ARK::Transaction transaction(ARK::Utilities::Network::Connector& netConnector, const Hash& id);

	
/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,000 bytes  */
    /*  /api/transactions  */
	std::unique_ptr<ARK::Transaction[]> transactions(ARK::Utilities::Network::Connector& netConnector);


/*************************************************
		* ARK::API::Transaction::Gettable::transactionUnconfirmed
		*   /api/transactions/unconfirmed/get?id=
		**************************************************/
    ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(
        ARK::Utilities::Network::Connector& netConnector,
        const Hash& id);
        

	

/*************************************************
		* ARK::API::Transaction::Gettable::transactionsUnconfirmed
		*   /api/transactions/unconfirmed
		**************************************************/
    std::unique_ptr<ARK::API::Transaction::Respondable::Unconfirmed[]> transactionsUnconfirmed(ARK::Utilities::Network::Connector& netConnector);

	
/*  ==========================================================================  */

};

}
}
}

#endif
