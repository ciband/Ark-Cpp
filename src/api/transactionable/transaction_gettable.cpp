#include "api/transactionable/transaction_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "types/hash.h"
#include "utilities/connector.h"
#include "helpers/subcount.h"

#include <cstring>
#include <memory>

/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Transaction::Gettable::transaction  */
/*  /api/transactions/get?id=  */
ARK::Transaction ARK::API::Transaction::Gettable::transaction(
    ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[512] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
    strcat(uri, "?id=");
    strcat(uri, id.getValue());

    auto callback = netConnector.cb(uri);
    return ARK::API::Transaction::Gettable::transactionfromJSON(callback);
}

/*
{ "success":true,
  "transaction":{
    "id":"_txID",
    "blockid":"_blockID",
    "height":_height,
    "type":_type,
    "timestamp":_timestamp,
    "amount":_amount,
    "fee":_fee,
    "vendorField":"_vendorField",
    "senderId":"_senderID",
    "recipientId":"_recipientID",
    "senderPublicKey":"_senderPubkey",
    "signature":"_txSig",
    "confirmations":_confirmations
  }
}
*/
ARK::Transaction ARK::API::Transaction::Gettable::transactionfromJSON(const char* const jsonStr) {
    auto jString = ARK::Utilities::make_json_string(jsonStr); 

    /*char temp[34];
    jString->valueIn("transaction", "senderId").toCharArray(temp, 34);

    char temp2[34];
    jString->valueIn("transaction", "recipientId").toCharArray(temp, 34);*/

    return ARK::Transaction(
        jString->valueIn("transaction", "id").c_str(),
        jString->valueIn("transaction", "blockid").c_str(),
        jString->valueIn("transaction", "height").c_str(),
        convert_to_int(jString->valueIn("transaction", "type")),
        jString->valueIn("transaction", "timestamp").c_str(),
        jString->valueIn("transaction", "amount").c_str(),
        jString->valueIn("transaction", "fee").c_str(),
        jString->valueIn("transaction", "vendorField").c_str(),
        jString->valueIn("transaction", "senderId").c_str(),
       // temp,
        jString->valueIn("transaction", "recipientId").c_str(),
        //temp2,
        jString->valueIn("transaction", "senderPublicKey").c_str(),
        jString->valueIn("transaction", "signature").c_str(),
        jString->valueIn("transaction", "confirmations").c_str()
    );
}
/*  ============================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ==========================================================================  */
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
//   auto jString = ARK::Utilities::make_json_string(jsonStr); 
//   // ARK::Transaction transactions[50];
//   String resp;
//   for (int i = 0; i < 50; i++) {
//     String transactionSubstring = jString->subvalueFor("transactions", i);
//     ARK::Utilities::JSONInterface transactionJString(transactionSubstring); 
//     ARK::Transaction transaction = {
//       transactionjString->valueFor("id"),
//       transactionjString->valueFor("blockid"),
//       transactionjString->valueFor("height"),
//       transactionjString->valueFor("type").toInt(),
//       transactionjString->valueFor("timestamp"),
//       transactionjString->valueFor("amount"),
//       transactionjString->valueFor("fee"),
//       transactionjString->valueFor("vendorField"),
//       transactionjString->valueFor("senderId"),
//       transactionjString->valueFor("recipientId"),
//       transactionjString->valueFor("senderPublicKey"),
//       transactionjString->valueFor("signature"),
//       transactionjString->valueFor("confirmations")
//     };
//     // String transactionSubstring = jString->subvalueFor(transaction, i);
//     // ARK::Utilities::JSONInterface transactionJString(transactionSubstring); 
//     // ARK::Transaction transaction = {
//     //   jString->subarrayValueIn("transactions", i, "id"),
//     //   jString->subarrayValueIn("transactions", i, "blockid"),
//     //   jString->subarrayValueIn("transactions", i, "height"),
//     //   jString->subarrayValueIn("transactions", i, "type").toInt(),
//     //   jString->subarrayValueIn("transactions", i, "timestamp"),
//     //   jString->subarrayValueIn("transactions", i, "amount"),
//     //   jString->subarrayValueIn("transactions", i, "fee"),
//     //   jString->subarrayValueIn("transactions", i, "vendorField"),
//     //   jString->subarrayValueIn("transactions", i, "senderId"),
//     //   jString->subarrayValueIn("transactions", i, "recipientId"),
//     //   jString->subarrayValueIn("transactions", i, "senderPublicKey"),
//     //   jString->subarrayValueIn("transactions", i, "signature"),
//     //   jString->subarrayValueIn("transactions", i, "confirmations")
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
/*  ===========================================  */
/*  ==========================================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =====================================================  */
/*  ARK::API::Transaction::Gettable::transactionUnconfirmed  */
/*  /api/transactions/unconfirmed/get?id=  */
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionUnconfirmed(
    ARK::Utilities::Network::Connector& netConnector, 
    const Hash& id
) {
    char uri[1024] = { '\0' }; //TODO review sizes

    strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
    strcat(uri, "?id=");
    strcat(uri, id.getValue());

    auto callback = netConnector.cb(uri);
    return ARK::API::Transaction::Gettable::transactionUnconfirmedfromJSON(callback);
}

/*
{ 
  "success":true,
  "transaction":{
    "id":"_txID",
    "blockid":"_blockID",
    "height":_height,
    "type":_type,
    "timestamp":_timestamp,
    "amount":_amount,
    "fee":_fee,
    "vendorField":_vendorField,
    "senderId":"_senderId",
    "recipientId":"_recipientId",
    "senderPublicKey":_senderPubkey,
    "signature":"_txSig",
    "confirmations":_confirmations
  }
}
||
{
  "success":false,
  "error":"Transaction not found"
}
*/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionUnconfirmedfromJSON(const char* const jsonStr) {
  /*auto jString = ARK::Utilities::make_json_string(jsonStr); 
  String resp;
  if (strstr(jsonStr, "Transaction not found") != nullptr) {
    resp += "There are currently No unconfirmed transactions by that transactionID";
  } else {
    ARK::Transaction transaction(
      jString->valueIn("transaction", "id").c_str(),
      jString->valueIn("transaction", "blockid").c_str(),
      jString->valueIn("transaction", "height").c_str(),
      convert_to_int(jString->valueIn("transaction", "type")),
      jString->valueIn("transaction", "timestamp").c_str(),
      jString->valueIn("transaction", "amount").c_str(),
      jString->valueIn("transaction", "fee").c_str(),
      jString->valueIn("transaction", "vendorField").c_str(),
      jString->valueIn("transaction", "senderId").c_str(),
      jString->valueIn("transaction", "recipientId").c_str(),
      jString->valueIn("transaction", "senderPublicKey").c_str(),
      jString->valueIn("transaction", "signature").c_str(),
      jString->valueIn("transaction", "confirmations").c_str()
    );
    char buf[128] = {};
    transaction.description(buf, sizeof(buf) / sizeof(buf[0]));
    resp += buf;
  }
  return resp;*/

	//ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr)); 
	auto parser = ARK::Utilities::make_json_string(jsonStr);
			
			int txCount = subCount(jsonStr, "id");

			std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);
			
			for (int i = 0; i < txCount; i++)
			{
				transactions[i] = ARK::Transaction(
					parser->valueIn("transaction", "id").c_str(),
					parser->valueIn("transaction", "blockid").c_str(),
					parser->valueIn("transaction", "height").c_str(),
					convert_to_int(parser->valueIn("transaction", "type")),
					parser->valueIn("transaction", "timestamp").c_str(),
					parser->valueIn("transaction", "amount").c_str(),
					parser->valueIn("transaction", "fee").c_str(),
					parser->valueIn("transaction", "vendorField").c_str(),
					parser->valueIn("transaction", "senderId").c_str(),
					parser->valueIn("transaction", "recipientId").c_str(),
					parser->valueIn("transaction", "senderPublicKey").c_str(),
					parser->valueIn("transaction", "signature").c_str(),
					parser->valueIn("transaction", "confirmations").c_str()
				);
			}
			return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);
}
/*  =====================================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================================  */
/*  ARK::API::Transaction::Gettable::transactionsUnconfirmed  */
/*  /api/transactions/unconfirmed  */
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionsUnconfirmed(
    ARK::Utilities::Network::Connector& netConnector
) {
    auto callback = netConnector.cb(ARK::API::Paths::Transaction::unconfirmed_s);

    return ARK::API::Transaction::Gettable::transactionsUnconfirmedfromJSON(callback);
}

/*
{
  "success":true,
  "transactions":[]
}
*/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transaction::Gettable::transactionsUnconfirmedfromJSON(const char* const jsonStr) {
  /*auto jString = ARK::Utilities::make_json_string(jsonStr); 

  int txCount = ARK::API::Helpers::substringCount(jsonStr, "id");

  String resp;
  if (txCount > 0) {

    for (int i = 0; i <= txCount; i++) {

      ARK::Transaction transaction(
        jString->subarrayValueIn("transaction", i, "id").c_str(),
        jString->subarrayValueIn("transaction", i,  "blockid").c_str(),
        jString->subarrayValueIn("transaction", i,  "height").c_str(),
        convert_to_int(jString->subarrayValueIn("transaction", i,  "type")),
        jString->subarrayValueIn("transaction", i,  "timestamp").c_str(),
        jString->subarrayValueIn("transaction", i,  "amount").c_str(),
        jString->subarrayValueIn("transaction", i,  "fee").c_str(),
        jString->subarrayValueIn("transaction", i,  "vendorField").c_str(),
        jString->subarrayValueIn("transaction", i,  "senderId").c_str(),
        jString->subarrayValueIn("transaction", i,  "recipientId").c_str(),
        jString->subarrayValueIn("transaction", i,  "senderPublicKey").c_str(),
        jString->subarrayValueIn("transaction", i,  "signature").c_str(),
        jString->subarrayValueIn("transaction", i,  "confirmations").c_str()
      );

      resp += "\ntransaction ";
      resp += i + 1;
      resp += ":\n";
      char buf[1024] = {};
      transaction.description(buf, sizeof(buf) / sizeof(buf[0]));
      resp += buf;
      resp += "\n";
    };

  } else {
    resp += "There are currently No Unconfirmed Transactions";
  };
  return resp;*/

	auto parser = ARK::Utilities::make_json_string(jsonStr);
			
			int txCount = subCount(jsonStr, "id");

			std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);
			
			for (int i = 0; i < txCount; ++i)
			{
				transactions[i] = ARK::Transaction(
					parser->valueIn("transaction", "id").c_str(),
					parser->valueIn("transaction", "blockid").c_str(),
					parser->valueIn("transaction", "height").c_str(),
					convert_to_int(parser->valueIn("transaction", "type")),
					parser->valueIn("transaction", "timestamp").c_str(),
					parser->valueIn("transaction", "amount").c_str(),
					parser->valueIn("transaction", "fee").c_str(),
					parser->valueIn("transaction", "vendorField").c_str(),
					parser->valueIn("transaction", "senderId").c_str(),
					parser->valueIn("transaction", "recipientId").c_str(),
					parser->valueIn("transaction", "senderPublicKey").c_str(),
					parser->valueIn("transaction", "signature").c_str(),
					parser->valueIn("transaction", "confirmations").c_str()
				);
			};
			return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);
}
/*  ======================================================  */
/*  ==========================================================================  */
