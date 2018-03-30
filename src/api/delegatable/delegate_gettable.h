

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
    ARK::API::Delegate::Respondable::Search search(
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
     std::unique_ptr<ARK::Delegate[]> delegates(ARK::Utilities::Network::Connector _netConnector);
	 
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
/*  =====================================  */
/*  ==========================================================================  */

};
};
};

/**************************************************************************************************/
/*************************************************/
/*************************************************
* 	BROKEN: fix for large callbacks
*		Delegates callback is ~13,564 bytes
**************************************************/
/*************************************************
* ARK::API::Delegate::Gettable::delegates
*   /api/delegates
**************************************************/
// const char* ARK::API::Delegate::Gettable::delegates(ARK::Utilities::Network::Connector netConnector) {
//   String uri = ARK::API::Paths::Delegate::delegates_s;
//   String callback = _netConnector.cb(uri);

	// char uri[512] = { '\0' }; //TODO: review sizes
    // strcpy(uri, ARK::API::Paths::Delegate::delegates_s);
		  // auto callback = netConnector.cb(uri);

//   return ARK::API::Delegate::Gettable::delegatesfromJSON(callback);
// };
/*************************************************
*
*
*	{
*		"success":true,
*		"delegates":
*		[
*			{
*				"username":"d_chris",
*				"address":"DQUjMT6fhJWbwhaYL5pPdX9v5qPiRcAzRb",
*				"publicKey":"02bcfa0951a92e7876db1fb71996a853b57f996972ed059a950d910f7d541706c9",
*				"vote":"11511729062473143",
*				"producedblocks":38129,
*				"missedblocks":11252,
*				"rate":1,
*				"approval":88.81,
*				"productivity":77.21
*			},
*			...
*			{
*				"username":"phildark",
*				"address":"D6mtwEK2cyT2BRaUZtmgaWYg3XTpEML8s8",
*				"publicKey":"03f734e0baae2207eb1a225cf435e75c79b935a806c79edf5733e402cad8852dd8",
*				"vote":"2431020000000",
*				"producedblocks":7157,
*				"missedblocks":4685,
*				"rate":51,"approval":0.02,
*				"productivity":60.44
*			}
*		],
*		"totalCount":166
*	}
*
**************************************************/
// String ARK::API::Delegate::Gettable::delegatesfromJSON(String _jsonStr) {
//   Serial.println("========== delegatesfromJSON ==========");
//   // Serial.println("_jsonStr");
//   // Serial.println(_jsonStr);
//   // Serial.println();
//   ARK::Utilities::JSONString jString(_jsonStr);
//   int top51Count = 51;
//   // ARK::Delegate delegate[5];
//   ARK::DelegatesResponse delegatesResponse(5);
//   for (int i = 0; i < 5; i++) {
//     ARK::Delegate delegate = {
//       jString.subarrayValueIn("delegates", i, "username"),
//       jString.subarrayValueIn("delegates", i, "address"),
//       jString.subarrayValueIn("delegates", i, "publicKey"),
//       jString.subarrayValueIn("delegates", i, "vote"),
//       jString.subarrayValueIn("delegates", i, "producedblocks").toInt(),
//       jString.subarrayValueIn("delegates", i, "missedblocks").toInt(),
//       jString.subarrayValueIn("delegates", i, "rate").toInt(),
//       jString.subarrayValueIn("delegates", i, "approval").toFloat(),
//       jString.subarrayValueIn("delegates", i, "productivity").toFloat()
//     };
//     delegatesResponse.list[i] = delegate;
//   };
//   String resp;
//   for ( int i = 0; i < 5; i++ ) {
//     resp += "delegate ";  resp += i + 1;	resp += ":\n	";
//       resp += delegatesResponse.list[i].description();
//   };
//   resp += "totalCount:\n";
//     resp += jString.valueFor("totalCount");
//   return resp;
// };
/*************************************************/
/*************************************************/
/**************************************************************************************************/

#endif
