

#ifndef JSON_H
#define JSON_H

#include "utilities/platform.h"

#include "api/accountable/accountable.h"
#include "api/blockable/blockable.h"
#include "api/delegatable/delegatable.h"
#include "api/loadable/loadable.h"
#include "api/peerable/peerable.h"
#include "api/transactionable/transactionable.h"
#include "models/block.h"
#include "models/fees.h"


#include <memory>

namespace ARK {
namespace Utilities {

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
class JSONInterface {
protected:
	JSONInterface() = default;

public:
    virtual ~JSONInterface() { }

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"balance":  "Balance",
	*		"unconfirmedBalance": "Balance"
	*	}
	*
	**************************************************/
	virtual ARK::API::Account::Respondable::Balances balancefromJSON(const char* const _jsonStr) = 0;
	ARK::API::Account::Respondable::Balances balancefromJSON(const String& _jsonStr) {
		return balancefromJSON(_jsonStr.c_str());
	}

	/*************************************************
		*
		* {
		*"success":true,
			*"publicKey" : "Publickey"
			*	}
	*
		**************************************************/
	virtual Publickey publickeyfromJSON(const char* const _jsonStr) = 0;
	Publickey publickeyfromJSON(const String& _jsonStr) {
		return publickeyfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"fee":2500000000
	*	}
	*
	**************************************************/
	virtual Balance delegatesFeefromJSON(const char* const _jsonStr) = 0;
	Balance delegatesFeefromJSON(const String& _jsonStr) {
		return delegatesFeefromJSON(_jsonStr.c_str());
	}

	/*
	{ "success":true,
	  "delegates":[{
		"username": "sleepdeficit",
		"address":  "Address",
		"publicKey":  "Publickey",
		"vote": "Balance",
		"producedblocks": String,
		"missedblocks": String,
		"rate": int,
		"approval": double,
		"productivity": double
	  }]
	}
	*/

	virtual ARK::Delegate ARK::API::Account::Gettable::delegatesfromJSON(const char* const _jsonStr) = 0;
	ARK::Delegate ARK::API::Account::Gettable::delegatesfromJSON(const String& _jsonStr) {
		return delegatesfromJSON(_jsonStr.c_str());
	}


	/*************************************************
	*
	*	{
	*		"success":true,
	*		"account":
	*		{
	*			"address":  "Address",
	*			"unconfirmedBalance": "Balance",
	*			"balance":  "Balance",
	*			"publicKey":  "Publickey",
	*			"unconfirmedSignature": int,
	*			"secondSignature":  int,
	*			"secondPublicKey":  "Publickey",
	*			"multisignatures":[],
	*			"u_multisignatures":[]
	*		}
	*	}
	*
	**************************************************/
	virtual ARK::Account accountfromJSON(const char* const _jsonStr) = 0;
	ARK::Account accountfromJSON(const String& _jsonStr) {
		return accountfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "block":
	*   {
	*     "id": "const char*",
	*     "version":  int,
	*     "timestamp":  const char*,
	*     "height": const char*,
	*     "previousBlock":  "const char*",
	*     "numberOfTransactions": const char*,
	*     "totalAmount":  Balance,
	*     "totalFee": Balance,
	*     "reward": Balance,
	*     "payloadLength":  const char*,
	*     "payloadHash":  "Hash",
	*     "generatorPublicKey": "Publickey",
	*     "generatorId":  "Address",
	*     "blockSignature": "Signature",
	*     "confirmations":  const char*,
	*     "totalForged":" Balance"
	*   }
	* }
	*
	**************************************************/
	virtual ARK::Block blockfromJSON(const char* const jsonStr) = 0;
	ARK::Block blockfromJSON(const String& jsonStr) {
		return blockfromJSON(jsonStr.c_str());
	}

	virtual std::unique_ptr<ARK::Block[]> blocksfromJSON(const char* const jsonStr) = 0;
	std::unique_ptr<ARK::Block[]> blocksfromJSON(const String& jsonStr) {
		return blocksfromJSON(jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "epoch":  "String"
	* }
	**************************************************/
	virtual String epochfromJSON(const char* const _jsonStr) = 0;
	String epochfromJSON(const String& _jsonStr) {
		return epochfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "height": String,
	*   "id": "String"
	* }
	*
	**************************************************/
	virtual ARK::API::Block::Respondable::Height heightfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Block::Respondable::Height heightfromJSON(const String& _jsonStr) {
		return heightfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "nethash":  "Hash"
	* }
	*
	**************************************************/
	virtual Hash nethashfromJSON(const char* const _jsonStr) = 0;
	Hash nethashfromJSON(const String& _jsonStr) {
		return nethashfromJSON(_jsonStr.c_str());
	}

	virtual Balance blockFeefromJSON(const char* const _jsonStr) = 0;
	Balance blockFeefromJSON(const String& _jsonStr) {
		return blockFeefromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "fee":  Balance
	* }
	*
	**************************************************/
	virtual ARK::Fees feesfromJSON(const char* const _jsonStr) = 0;
	ARK::Fees feesfromJSON(const String& _jsonStr) {
		return feesfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "milestone": String
	* }
	*
	**************************************************/
	virtual String milestonefromJSON(const char* const _jsonStr) = 0;
	String milestonefromJSON(const String& _jsonStr) {
		return milestonefromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "reward": Balance
	* }
	*
	**************************************************/
	virtual Balance rewardfromJSON(const char* const _jsonStr) = 0;
	Balance rewardfromJSON(const String& _jsonStr) {
		return rewardfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "supply": Balance
	* }
	*
	**************************************************/
	virtual Balance supplyfromJSON(const char* const _jsonStr) = 0;
	Balance supplyfromJSON(const String& _jsonStr) {
		return supplyfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	* {
	*   "success":true,
	*   "epoch":  "String",
	*   "height": String,
	*   "fee":  Balance,
	*   "milestone":  String,
	*   "nethash":" Hash",
	*   "reward":_reward,
	*   "supply":_supply
	* }
	*
	**************************************************/
	virtual ARK::API::Block::Respondable::Status statusfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Block::Respondable::Status statusfromJSON(const String& _jsonStr) {
		return statusfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"count":166
	*	}
	*
	**************************************************/
	virtual int countfromJSON(const char* const _jsonStr) = 0;
	int countfromJSON(const String& _jsonStr) {
		return countfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"delegates":
	*		[
	*			{
	*				"username":"_username",
	*				"address":"_arkAddress",
	*				"publicKey":"_pubkey",
	*				"vote":"0000000000000",
	*				"producedblocks":0,
	*				"missedblocks":0
	*			}
	*		]
	*	}
	*
	**************************************************/
	virtual ARK::API::Delegate::Respondable::Search searchfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Delegate::Respondable::Search searchfromJSON(const String& _jsonStr) {
		return searchfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"accounts":
	*		[
	*			{
	*				"username": "const char*",
	*				"address":  "Balance",
	*				"publicKey":  "Publickey",
	*				"balance":  "Balance"
	*			},
	*			{
	*				"username": "const char*",
	*				"address":  "Address",
	*				"publicKey":  "Publickey",
	*				"balance":  "Balance"
	*			}
	*		]
	*	}
	*
	**************************************************/
	virtual ARK::API::Delegate::Respondable::Voters votersfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Delegate::Respondable::Voters votersfromJSON(const String& _jsonStr) {
		return votersfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"delegate":
	*		{
	*			"username": "sleepdeficit",
	*			"address":  "Address",
	*			"publicKey":  "Publickey",
	*			"vote": "Balance",
	*			"producedblocks": const char*,
	*			"missedblocks": const char*,
	*			"rate": int,
	*			"approval": double,
	*			"productivity": double
	*		}
	*	}
	*
	**************************************************/
	virtual ARK::Delegate delegatefromJSON(const char* const _jsonStr) = 0;
	ARK::Delegate delegatefromJSON(const String& _jsonStr) {
		return delegatefromJSON(_jsonStr.c_str());
	}

	virtual std::unique_ptr<ARK::Delegate[]> delegatesfromJSON(const char* const _jsonStr) = 0;
	std::unique_ptr<ARK::Delegate[]> delegatesfromJSON(const String& _jsonStr) {
		return delegatesfromJSON(_jsonStr);
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"fee":  Balance
	*	}
	*
	**************************************************/
	virtual Balance feefromJSON(const char* const _jsonStr) = 0;
	Balance feefromJSON(const String& _jsonStr) {
		return feefromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"fees": "Balance",
	*		"rewards":  "Balance",
	*		"forged": "Balance"
	*	}
	*
	**************************************************/
	virtual ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccountfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccountfromJSON(const String& _jsonStr) {
		return forgedByAccountfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"currentBlock":2307497,
	*		"currentSlot":3189409,
	*		"delegates":
	*		[
	*			"035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
	*			"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
	*			"028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
	*			"027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
	*			"02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
	*			"0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
	*			"02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
	*			"02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
	*			"022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
	*			"031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
	*		]
	*	}
	*
	**************************************************/
	virtual ARK::API::Delegate::Respondable::NextForgers nextForgersfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Delegate::Respondable::NextForgers nextForgersfromJSON(const String& _jsonStr) {
		return nextForgersfromJSON(_jsonStr.c_str());
	}

	virtual ARK::API::Loader::Respondable::Status loader_statusfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Loader::Respondable::Status loader_statusfromJSON(const String& _jsonStr) {
		return loader_statusfromJSON(_jsonStr.c_str());
	}

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
	virtual ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Loader::Respondable::Sync syncfromJSON(const String& _jsonStr) {
		return syncfromJSON(_jsonStr.c_str());
	}

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
	virtual ARK::Network autoconfigurefromJSON(const char* const _jsonStr) = 0;
	ARK::Network autoconfigurefromJSON(const String& _jsonStr) {
		return autoconfigurefromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"transactions":[]
	*	}
	*
	**************************************************/
	virtual String pendingfromJSON(const char* const _jsonStr) = 0;
	String pendingfromJSON(const String& _jsonStr) {
		return pendingfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"peer":
	*		{
	*			"ip": "String",
	*			"port": int,
	*			"version":  "String",
	*			"errors": int,
	*			"os": "String",
	*			"height": String,
	*			"status": "String",
	*			"delay":  int
	*		}
	*	}
	*
	**************************************************/
	virtual ARK::Peer peerfromJSON(const char* const _jsonStr) = 0;
	ARK::Peer peerfromJSON(const String& _jsonStr) {
		return peerfromJSON(_jsonStr.c_str());
	}

	virtual std::unique_ptr<ARK::Peer[]> peersfromJSON(const char* const _jsonStr) = 0;
	std::unique_ptr<ARK::Peer[]> peersfromJSON(const String& _jsonStr) {
		return peersfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"version":  "String",
	*		"build":  "String"
	*	}
	*
	**************************************************/
	virtual ARK::API::Peer::Respondable::Version versionfromJSON(const char* const _jsonStr) = 0;
	ARK::API::Peer::Respondable::Version versionfromJSON(const String& _jsonStr) {
		return versionfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"fee":  Balance
	*	}
	*
	**************************************************/
	virtual Balance signatureFeefromJSON(const char* const _jsonStr) = 0;
	Balance signatureFeefromJSON(const String& _jsonStr) {
		return signatureFeefromJSON(_jsonStr.c_str());
	}

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
	virtual ARK::Transaction transactionfromJSON(const char* const jsonStr) = 0;
	ARK::Transaction transactionfromJSON(const String& _jsonStr) {
		return transactionfromJSON(_jsonStr.c_str());
	}

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
	virtual ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmedfromJSON(const char* const jsonStr) = 0;
	ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmedfromJSON(const String& _jsonStr) {
		return transactionUnconfirmedfromJSON(_jsonStr.c_str());
	}

	/*************************************************
	*
	*	{
	*		"success":true,
	*		"transactions":[]
	*	}
	*
	**************************************************/
	virtual ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmedfromJSON(const char* const jsonStr) = 0;
	ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmedfromJSON(const String& _jsonStr) {
		return transactionsUnconfirmedfromJSON(_jsonStr.c_str());
	}

	virtual std::unique_ptr<ARK::Transaction[]> transactionsfromJSON(const char* const jsonStr) = 0;
	std::unique_ptr<ARK::Transaction[]> transactionsfromJSON(const String& jsonStr) {
		return transactionsfromJSON(jsonStr.c_str());
	}
};
/*  ==========================================================================  */

// JSON parser singleton
JSONInterface& get_json_interface();

}
}

#endif
