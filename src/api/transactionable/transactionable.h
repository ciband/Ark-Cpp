

#ifndef TRANSACTIONABLE_H
#define TRANSACTIONABLE_H

#include "api/transactionable/transaction_respondable.h"
#include "api/transactionable/transaction_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Transactionable
*   	public Transaction::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Peer Model
* 
**************************************************/
class Transactionable :
		public Transaction::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*		/api/transactions/get?id=
		*
		*		@return:	ARK::Transaction
		*
		*   @method:	transaction(Hash id)
    *   @param:	Hash id
		*
		*   calls:	eturn ARK::API::Transaction::Gettable::transaction(this->netConnector, id)
		*
		*   @brief:
		*			Gets Transaction by Hash ID from a Node via API.
		* 
		**************************************************/
		ARK::Transaction transaction(Hash id)
		{
			return ARK::API::Transaction::Gettable::transaction(this->netConnector, id);
		};
    /*************************************************/

/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
		/*    BROKEN: fix for large callbacks  */
		/*    Peers callback is ~28,908 bytes  */
		/*  /api/transactions  */
		// String transactions()
		// { return ARK::API::Transaction::Gettable::transactions(this->netConnector); };
    /*************************************************/
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/transactions/unconfirmed/get?id=
		*
		*		@return:	const char*
		*
		*   @method:	transactionUnconfirmed(Hash id)
    *   @param:	Hash id
		*
		*   calls:	ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id)
		*
		*   @brief:
		*			Gets Unconfirmed Transaction by Hash ID from a Node via API.
		* 
		**************************************************/
		ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(const Hash& id)
		{
			return ARK::API::Transaction::Gettable::transactionUnconfirmed(this->netConnector, id);
		};
    /*************************************************/

/**************************************************************************************************/

		/*************************************************
		*		/api/transactions/unconfirmed
		*
		*		@return:	const char*
		*
		*   @method:	transactionsUnconfirmed()
		*
		*   calls: ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector, id)
		*
		*   @brief:
		*			Gets Unconfirmed Transactions from a Node via API.
		* 
		**************************************************/
		ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed()
		{
			return ARK::API::Transaction::Gettable::transactionsUnconfirmed(this->netConnector);
		};
    /*************************************************/

};
/*************************************************/

// namespace transaction_cb {
//   struct addTransactionsResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};

#endif
