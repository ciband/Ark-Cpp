#include "utilities/platform.h"

#ifndef USE_IOT

#include "api/accountable/account_respondable.h"
#include "model/balance.h"
#include "utilities/json.h"

#include "Poco/JSON/Array.h"
#include "Poco/JSON/Parser.h"

#include <string>

namespace ARK {
namespace Utilities {

namespace {

class JSON : public JSONInterface {
private:
	Poco::JSON::Parser parser_;

public:
	JSON() = default;

	// /api/accounts/getBalance
	ARK::API::Account::Respondable::Balances accounts_getBalance_fromJSON(const char* const json_str) {
		auto json = parser.parse(json_str);
		auto object = json.extract<Object::Ptr>();
		return ARK::API::Account::Respondable::Balances(
			Balance(object->getValue<String>("balance").c_str()), 
			Balance(object->getValue<String>("unconfirmedBalance").c_str())
		);
	}

	// /api/accounts/getPublickey
	Publickey accounts_getPublickey_fromJSON(const char* const json_str) {
		auto json = parser.parse(json_str);
		auto object = json.extract<Object::Ptr>();
		return Publickey(object->getValue<String>("publicKey").c_str());
	}
	// /api/accounts/delegates/fee
	Balance accounts_delegates_feef_romJSON(const char* const json_str) {
		auto json = parser.parse(json_str);
		auto object = json.extract<Object::Ptr>();
		return Balance(object->getValue<String>("fee").c_str());
	}

	// /api/accounts/delegates
	std::unique_ptr<ARK::Delegate[]> accounts_delegates_fromJSON(const char* const json_str) {
		/*auto jString = ARK::Utilities::make_json_string(_jsonStr);
		for (auto delegate : jString->get_array("delegates")) {
			// return the first for now
			return Delegate(
				delegate->get_value<std::string>("username").c_str(),
				delegate->get_value<std::string>("address").c_str(),
				delegate->get_value<std::string>("publicKey").c_str(),
				delegate->get_value<std::string>("vote").c_str(),
				delegate->get_value<int>("producedblocks"),
				delegate->get_value<int>("missedblocks"),
				delegate->get_value<int>("rate"),
				delegate->get_value<float>("approval"),
				delegate->get_value<float>("productivity")
			);
		}*/
	}

	// /api/accounts
	std::unique_ptr<ARK::Account[]> accounts_fromJSON(const char* const _jsonStr);
	
	//TODO: /api/accounts/top 

	// /api/blocks/get
	ARK::Block blocks_get_fromJSON(const char* const jsonStr);
	// /api/blocks
	std::unique_ptr<ARK::Block[]> blocks_fromJSON(const char* const jsonStr);
	// /api/blocks/getEpoch
	String blocks_getEpoch_fromJSON(const char* const _jsonStr);
	// /api/blocks/getHeight
	ARK::API::Block::Respondable::Height blocks_getHeight_fromJSON(const char* const _jsonStr);
	// /api/blocks/getNethash
	Hash blocks_getNethash_fromJSON(const char* const _jsonStr);
	// /api/blocks/getFee
	Balance blocks_getFee_fromJSON(const char* const _jsonStr);
	// /api/blocks/getFees
	ARK::Fees blocks_getFees_fromJSON(const char* const _jsonStr);
	// /api/blocks/getMilestone
	String blocks_getMilestone_fromJSON(const char* const _jsonStr);
	// /api/blocks/getReward
	Balance blocks_getReward_fromJSON(const char* const _jsonStr);
	// /api/blocks/getSupply
	Balance blocks_getSupply_fromJSON(const char* const _jsonStr);
	// /api/blocks/getStatus
	ARK::API::Block::Respondable::Status blocks_getStatus_fromJSON(const char* const _jsonStr);
	// /api/delegates/count
	uint16_t delegates_count_fromJSON(const char* const _jsonStr);
	// /api/delegates/search
	ARK::API::Delegate::Respondable::Search delegates_search_fromJSON(const char* const _jsonStr);
	// /api/delegates/voters
	ARK::API::Delegate::Respondable::Voters delegates_voters_fromJSON(const char* const _jsonStr);
	// /api/delegates/get
	ARK::Delegate delegates_get_fromJSON(const char* const _jsonStr);
	// /api/delegates
	std::unique_ptr<ARK::Delegate[]> delegates_fromJSON(const char* const _jsonStr);
	// /api/delegates/fee
	Balance delegate_fee_fromJSON(const char* const _jsonStr);
	// /api/delegates/forging/getForgedByAccount
	ARK::API::Delegate::Respondable::ForgedByAccount delegates_forging_getForgedByAccount_fromJSON(const char* const _jsonStr);
	// /api/delegates/getNextForgers
	ARK::API::Delegate::Respondable::NextForgers delegates_getNextForgers_fromJSON(const char* const _jsonStr);
	// /api/loader/status
	ARK::API::Loader::Respondable::Status loader_status_fromJSON(const char* const _jsonStr);
	// /api/loader/status/sync
	ARK::API::Loader::Respondable::Sync loader_status_sync_fromJSON(const char* const _jsonStr);
	// /api/loader/autoconfigure
	ARK::Network loader_autoconfigure_fromJSON(const char* const _jsonStr);
	// /api/multisignatures/pending
	String multisignatures_pending_fromJSON(const char* const _jsonStr);

	// TODO: /api/multisignatures/accounts

	// /api/peers/get
	ARK::Peer peers_get_fromJSON(const char* const _jsonStr);
	// /api/peers
	std::unique_ptr<ARK::Peer[]> peers_fromJSON(const char* const _jsonStr);
	// /api/peers/version
	ARK::API::Peer::Respondable::Version peers_version_fromJSON(const char* const _jsonStr);
	// /api/signatures_fee
	Balance signatures_Fee_fromJSON(const char* const _jsonStr);
	// /api/transactions/get
	ARK::Transaction transactions_get_fromJSON(const char* const jsonStr);
	// /api/transactions
	std::unique_ptr<ARK::Transaction[]> transactions_fromJSON(const char* const jsonStr);
	// api/transactions/unconfirmed/get
	ARK::API::Transaction::Respondable::Unconfirmed transactions_unconfirmed_get_fromJSON(const char* const jsonStr);
	// api/transactions/unconfirmed
	std::unique_ptr<ARK::API::Transaction::Respondable::Unconfirmed[]> transactions_unconfirmed_fromJSON(const char* const jsonStr);
	

	// TODO: /peer/list
	// TODO: /peer/blocks/common
	// TODO: /peer/block
	// TODO: /peer/blocks
	// TODO: /peer/transactions
	// TODO: POST ?? /peer/trasnactions
	// TODO: /peer/transactionsFromIds
	// TODO: /peer/height
	// TODO: /peer/status
};

}

JSONInterface& get_json_interface() {
	static JSON json;
	return json;
}

}
}
/*  ==========================================================================  */
/*  ==========================================================================  */
// /**************************************************
// * ARK::Utilities::JSONChar 
// *
// * The purpose of this class is to serve as an
// *   entry point for integrating and simplifying
// *   integration of a JSON library
// **************************************************/
// struct JSONChar
// {
//   private:
//     char *jsonChars;
//   public:
//     JSONChar(const char *_jsonChars);
//     const char *subvalueIn(const char *_key, const char *_subkey);
//     const char *subarrayValueIn(const char *_key, int _pos, const char *_subkey);
// };
// ARK::Utilities::JSONChar::JSONChar(const char *_jsonChars)
// {
//   strcpy(this->jsonChars, _jsonChars);
// };
// const char *ARK::Utilities::JSONChar::subvalueIn(const char *key, const char *subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   jsonBuffer.clear();
//   JsonObject &newRoot = root[key];
//   return newRoot[subkey];
// }
// const char *ARK::Utilities::JSONChar::subarrayValueIn(const char *_key, int _pos, const char *_subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   jsonBuffer.clear();
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   // JsonArray& root = jsonBuffer.parseArray(this->jsonChars);
//   return root[_key][_pos][_subkey];
// }
/*  ==========================================================================  */
/*  ==========================================================================  */

#endif
