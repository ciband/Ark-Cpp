

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

	/*************************************************
		*
		*	{
		*		"success":true,
		*		"transaction":
		*		{
		*			"id":"_txID",
		*			"blockid":"_blockID",
		*			"height":_height,
		*			"type":_type,
		*			"timestamp":_timestamp,
		*			"amount":_amount,
		*			"fee":_fee,
		*			"vendorField":"_vendorField",
		*			"senderId":"_senderID",
		*			"recipientId":"_recipientID",
		*			"senderPublicKey":"_senderPubkey",
		*			"signature":"_txSig",
		*			"confirmations":_confirmations
		*		}
		*	}
		*
		**************************************************/
    ARK::Transaction transactionfromJSON(const char* const jsonStr);
    ARK::Transaction transactionfromJSON(const String& _jsonStr) {
        return transactionfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

/*  ==========================================================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,000 bytes  */
    /*  /api/transactions  */
    // String transactions(ARK::Utilities::Network::Connector netConnector);
    // String transactionsfromJSON(String jsonStr);


/*************************************************
		* ARK::API::Transaction::Gettable::transactionUnconfirmed
		*   /api/transactions/unconfirmed/get?id=
		**************************************************/
    ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(
        ARK::Utilities::Network::Connector& netConnector,
        const Hash& id);
        

	/*************************************************
		*
		*	{ 
		*		"success":true,
		*		"transaction":
		*		{
		*			"id":"_txID",
		*			"blockid":"_blockID",
		*			"height":_height,
		*			"type":_type,
		*			"timestamp":_timestamp,
		*			"amount":_amount,
		*			"fee":_fee,
		*			"vendorField":_vendorField,
		*			"senderId":"_senderId",
		*			"recipientId":"_recipientId",
		*			"senderPublicKey":_senderPubkey,
		*			"signature":"_txSig",
		*			"confirmations":_confirmations
		*		}
		*	}
		*		| or |
		*	{
		*		"success":false,
		*		"error":"Transaction not found"
		*	}
		*
		**************************************************/
    ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmedfromJSON(const char* const jsonStr);
    ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmedfromJSON(const String& _jsonStr) {
        return transactionUnconfirmedfromJSON(_jsonStr.c_str());
    }

/*************************************************
		* ARK::API::Transaction::Gettable::transactionsUnconfirmed
		*   /api/transactions/unconfirmed
		**************************************************/
    ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed(ARK::Utilities::Network::Connector& netConnector);

	/*************************************************
		*
		*	{
		*		"success":true,
		*		"transactions":[]
		*	}
		*
		**************************************************/
    ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmedfromJSON(const char* const jsonStr);
    ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmedfromJSON(const String& _jsonStr) {
        return transactionsUnconfirmedfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */

};
/*  ==========================================  */
/*  ==========================================================================  */

};
};
};

/**************************************************************************************************/
/*************************************************/
/*************************************************/
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
/*  ===========================================  */
/*  ARK::API::Transaction::Gettable::transactions  */
// /*  /api/transactions */
// String ARK::API::Transaction::Gettable::transactions(ARK::Utilities::Network::Connector netConnector) {
//   String uri = ARK::API::Paths::Transaction::transactions_s;
//   String callback = netConnector.cb(uri);
//   if (callback.indexOf("true") <= 0)
//     return callback;
//   return ARK::API::Transaction::Gettable::transactionsfromJSON(callback);
// }
// /*
// {
//   "success":true,
//   "transactions":[
//     {
//       "id":"_txID",
//       "blockid":"_blockID",
//       "type":_type,
//       "timestamp":_timestamp,
//       "amount":_amount,
//       "fee":_fee,
//       "vendorField":"_vendorField",
//       "senderId":"_senderID",
//       "recipientId":"_recipientID",
//       "senderPublicKey":"_senderPubkey",
//       "signature":"_txSig",
//       "confirmations":_confirmations
//     },
//     {
//       "id":"_txID",
//       "blockid":"_blockID",
//       "type":_type,
//       "timestamp":_timestamp,
//       "amount":_amount,
//       "fee":_fee,
//       "vendorField":"_vendorField",
//       "senderId":"_senderID",
//       "recipientId":"_recipientID",
//       "senderPublicKey":"_senderPubkey",
//       "signature":"_txSig",
//       "confirmations":_confirmations
//     }
//   ],
//   "count":"193015"
// }
// */
// String ARK::API::Transaction::Gettable::transactionsfromJSON(String jsonStr) {
//   ARK::Utilities::JSONString jString(jsonStr); 
//   // ARK::Transaction transactions[50];
//   String resp;
//   for (int i = 0; i < 50; i++) {
//     String transactionSubstring = jString.subvalueFor("transactions", i);
//     ARK::Utilities::JSONString transactionJString(transactionSubstring); 
//     ARK::Transaction transaction = {
//       transactionJString.valueFor("id"),
//       transactionJString.valueFor("blockid"),
//       transactionJString.valueFor("height"),
//       transactionJString.valueFor("type").toInt(),
//       transactionJString.valueFor("timestamp"),
//       transactionJString.valueFor("amount"),
//       transactionJString.valueFor("fee"),
//       transactionJString.valueFor("vendorField"),
//       transactionJString.valueFor("senderId"),
//       transactionJString.valueFor("recipientId"),
//       transactionJString.valueFor("senderPublicKey"),
//       transactionJString.valueFor("signature"),
//       transactionJString.valueFor("confirmations")
//     };
//     // String transactionSubstring = jString.subvalueFor(transaction, i);
//     // ARK::Utilities::JSONString transactionJString(transactionSubstring); 
//     // ARK::Transaction transaction = {
//     //   jString.subarrayValueIn("transactions", i, "id"),
//     //   jString.subarrayValueIn("transactions", i, "blockid"),
//     //   jString.subarrayValueIn("transactions", i, "height"),
//     //   jString.subarrayValueIn("transactions", i, "type").toInt(),
//     //   jString.subarrayValueIn("transactions", i, "timestamp"),
//     //   jString.subarrayValueIn("transactions", i, "amount"),
//     //   jString.subarrayValueIn("transactions", i, "fee"),
//     //   jString.subarrayValueIn("transactions", i, "vendorField"),
//     //   jString.subarrayValueIn("transactions", i, "senderId"),
//     //   jString.subarrayValueIn("transactions", i, "recipientId"),
//     //   jString.subarrayValueIn("transactions", i, "senderPublicKey"),
//     //   jString.subarrayValueIn("transactions", i, "signature"),
//     //   jString.subarrayValueIn("transactions", i, "confirmations")
//     // };
//     // transactions[i] = transaction;
//     resp += "transaction ";
//     resp += i + 1;
//     resp += ":\n";
//     resp += transaction.description();
//   };
//   // for (int i = 0; i < 50; i++) {
//   //   resp += "transaction ";
//   //   resp += i + 1;
//   //   resp += ":\n";
//   //   resp += transactions[i].description();
//   // };
//   resp += "\n";
//   return resp;
// }
/*************************************************/
/*************************************************/
/**************************************************************************************************/

#endif
