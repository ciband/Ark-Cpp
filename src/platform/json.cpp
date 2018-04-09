#include "utilities/platform.h"

#ifndef USE_IOT

#include "api/accountable/account_respondable.h"
#include "types/balance.h"
#include "utilities/json.h"

#include "Poco/JSON/Array.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"

#include <string>

namespace ARK {
namespace Utilities {

namespace {

class JSON : public JSONInterface {
public:
	JSON() = default;

	// /api/accounts/getBalance
	ARK::API::Account::Respondable::Balances accounts_getBalance_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Account::Respondable::Balances(
			Balance(object->getValue<std::string>("balance").c_str()), 
			Balance(object->getValue<std::string>("unconfirmedBalance").c_str())
		);
	}

	// /api/accounts/getPublickey
	Publickey accounts_getPublickey_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Publickey(object->getValue<std::string>("publicKey").c_str());
	}

	// /api/accounts/delegates/fee
	Balance accounts_delegates_fee_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("fee").c_str());
	}

	// /api/accounts/delegates
	std::unique_ptr<ARK::Delegate[]> accounts_delegates_fromJSON(const char* const json_str) override {
		return parse_array<Delegate>(json_str, "delegates", [] (const Poco::JSON::Object::Ptr& delegate) {
			return ARK::Delegate(
				delegate->getValue<std::string>("username").c_str(),
				delegate->getValue<std::string>("address").c_str(),
				delegate->getValue<std::string>("publicKey").c_str(),
				delegate->getValue<std::string>("vote").c_str(),
				delegate->getValue<int>("producedblocks"),
				delegate->getValue<int>("missedblocks"),
				delegate->getValue<int>("rate"),
				delegate->getValue<float>("approval"),
				delegate->getValue<float>("productivity")
			);
		});
	}

	// /api/accounts
	ARK::Account accounts_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto block = object->get("account");
		object = block.extract<Poco::JSON::Object::Ptr>();
		return ARK::Account(
			object->getValue<std::string>("address").c_str(),
			object->getValue<std::string>("unconfirmedBalance").c_str(),
			object->getValue<std::string>("balance").c_str(),
			object->getValue<std::string>("publicKey").c_str(),
			object->getValue<int>("unconfirmedSignature"),
			object->getValue<int>("secondSignature"),
			object->getValue<std::string>("secondPublicKey").c_str(),
			object->getValue<std::string>("multisignatures").c_str(),
			object->getValue<std::string>("u_multisignatures").c_str()
		);
	}
	
	//TODO: /api/accounts/top 

	// /api/blocks/get
	ARK::Block blocks_get_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto block = object->get("block");
		object = block.extract<Poco::JSON::Object::Ptr>();
		return ARK::Block(
			object->getValue<std::string>("id").c_str(),
			object->getValue<int>("version"),
			object->getValue<std::string>("timestamp").c_str(),
			object->getValue<std::string>("height").c_str(),
			object->getValue<std::string>("previousBlock").c_str(),
			object->getValue<std::string>("numberOfTransactions").c_str(),
			object->getValue<std::string>("totalAmount").c_str(),
			object->getValue<std::string>("totalFee").c_str(),
			object->getValue<std::string>("reward").c_str(),
			object->getValue<std::string>("payloadLength").c_str(),
			object->getValue<std::string>("payloadHash").c_str(),
			object->getValue<std::string>("generatorPublicKey").c_str(),
			object->getValue<std::string>("generatorId").c_str(),
			object->getValue<std::string>("blockSignature").c_str(),
			object->getValue<std::string>("confirmations").c_str(),
			object->getValue<std::string>("totalForged").c_str()
		);
	}

	// /api/blocks
	std::unique_ptr<ARK::Block[]> blocks_fromJSON(const char* const json_str) override {
		return parse_array<Block>(json_str, "blocks", [](const Poco::JSON::Object::Ptr& block) {
			return ARK::Block(
				block->getValue<std::string>("id").c_str(),
				block->getValue<int>("version"),
				block->getValue<std::string>("timestamp").c_str(),
				block->getValue<std::string>("height").c_str(),
				block->getValue<std::string>("previousBlock").c_str(),
				block->getValue<std::string>("numberOfTransactions").c_str(),
				block->getValue<std::string>("totalAmount").c_str(),
				block->getValue<std::string>("totalFee").c_str(),
				block->getValue<std::string>("reward").c_str(),
				block->getValue<std::string>("payloadLength").c_str(),
				block->getValue<std::string>("payloadHash").c_str(),
				block->getValue<std::string>("generatorPublicKey").c_str(),
				block->getValue<std::string>("generatorId").c_str(),
				block->getValue<std::string>("blockSignature").c_str(),
				block->getValue<std::string>("confirmations").c_str(),
				block->getValue<std::string>("totalForged").c_str()
			);
		});
	}

	// /api/blocks/getEpoch
	std::string blocks_getEpoch_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return object->getValue<std::string>("epoch");
	}

	// /api/blocks/getHeight
	ARK::API::Block::Respondable::Height blocks_getHeight_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Block::Respondable::Height(
			object->getValue<std::string>("height").c_str(),
			object->getValue<std::string>("id").c_str()
		);
	}

	// /api/blocks/getNethash
	Hash blocks_getNethash_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Hash(object->getValue<std::string>("nethash").c_str());
	}

	// /api/blocks/getFee
	Balance blocks_getFee_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("fee").c_str());
	}

	// /api/blocks/getFees
	ARK::Fees blocks_getFees_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto fees = object->get("fees");
		object = fees.extract<Poco::JSON::Object::Ptr>();
		return ARK::Fees(
			object->getValue<std::string>("send").c_str(),
			object->getValue<std::string>("vote").c_str(),
			object->getValue<std::string>("delegate").c_str(),
			object->getValue<std::string>("secondsignature").c_str(),
			object->getValue<std::string>("multisignature").c_str()
		);
	}

	// /api/blocks/getMilestone
	std::string blocks_getMilestone_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return object->getValue<std::string>("milestone");
	}

	// /api/blocks/getReward
	Balance blocks_getReward_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("reward").c_str());
	}

	// /api/blocks/getSupply
	Balance blocks_getSupply_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("supply").c_str());
	}

	// /api/blocks/getStatus
	ARK::API::Block::Respondable::Status blocks_getStatus_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Block::Respondable::Status(
			object->getValue<std::string>("epoch").c_str(),
			object->getValue<std::string>("height").c_str(),
			object->getValue<std::string>("fee").c_str(),
			object->getValue<int>("milestone"),
			object->getValue<std::string>("nethash").c_str(),
			object->getValue<std::string>("reward").c_str(),
			object->getValue<std::string>("supply").c_str()
		);
	}

	// /api/delegates/count
	uint16_t delegates_count_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return object->getValue<uint16_t>("count");
	}

	// /api/delegates/search
	std::unique_ptr<ARK::API::Delegate::Respondable::Search[]> delegates_search_fromJSON(const char* const json_str) override {
		return parse_array<ARK::API::Delegate::Respondable::Search>(json_str, "delegates", [](const Poco::JSON::Object::Ptr& search) {
			return ARK::API::Delegate::Respondable::Search(
				search->getValue<std::string>("username").c_str(),
				search->getValue<std::string>("address").c_str(),
				search->getValue<std::string>("publicKey").c_str(),
				search->getValue<std::string>("vote").c_str(),
				search->getValue<int>("producedblocks"),
				search->getValue<int>("missedblocks")
			);
		});
	}

	// /api/delegates/voters
	ARK::API::Delegate::Respondable::Voters delegates_voters_fromJSON(const char* const json_str) override {
		return parse_array<ARK::Voter, ARK::API::Delegate::Respondable::Voters>(
			json_str, 
			"accounts", 
			[] (const Poco::JSON::Object::Ptr& voter) {
				return ARK::Voter(
					voter->getValue<std::string>("username").c_str(),
					voter->getValue<std::string>("address").c_str(),
					voter->getValue<std::string>("publicKey").c_str(),
					voter->getValue<std::string>("balance").c_str()
				);
			}, 
			[] (size_t count) {
				return ARK::API::Delegate::Respondable::Voters(count);
			}
		);
	}

	// /api/delegates/get
	ARK::Delegate delegates_get_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto delegate = object->get("delegate");
		object = delegate.extract<Poco::JSON::Object::Ptr>();
		return ARK::Delegate(
			object->getValue<std::string>("username").c_str(),
			object->getValue<std::string>("address").c_str(),
			object->getValue<std::string>("publicKey").c_str(),
			object->getValue<std::string>("vote").c_str(),
			object->getValue<int>("producedblocks"),
			object->getValue<int>("missedblocks"),
			object->getValue<int>("rate"),
			object->getValue<double>("approval"),
			object->getValue<double>("productivity")
		);
	}

	// /api/delegates
	std::unique_ptr<ARK::Delegate[]> delegates_fromJSON(const char* const json_str) override {
		return parse_array<ARK::Delegate>(json_str, "delegates", [] (const Poco::JSON::Object::Ptr& delegate) {
			return ARK::Delegate(
				delegate->getValue<std::string>("username").c_str(),
				delegate->getValue<std::string>("address").c_str(),
				delegate->getValue<std::string>("publicKey").c_str(),
				delegate->getValue<std::string>("vote").c_str(),
				delegate->getValue<int>("producedblocks"),
				delegate->getValue<int>("missedblocks"),
				delegate->getValue<int>("rate"),
				delegate->getValue<double>("approval"),
				delegate->getValue<double>("productivity")
			);
		});
	}

	// /api/delegates/fee
	Balance delegates_fee_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("fee").c_str());
	}

	// /api/delegates/forging/getForgedByAccount
	ARK::API::Delegate::Respondable::ForgedByAccount delegates_forging_getForgedByAccount_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Delegate::Respondable::ForgedByAccount(
			object->getValue<std::string>("fees").c_str(),
			object->getValue<std::string>("rewards").c_str(),
			object->getValue<std::string>("forged").c_str()
		);
	}

	// /api/delegates/getNextForgers
	ARK::API::Delegate::Respondable::NextForgers delegates_getNextForgers_fromJSON(const char* const json_str) {
		auto object = parse(json_str);
		auto delegates = parse_array<Publickey>(
			object, 
			"delegates",
			[] (const Poco::Dynamic::Var& node) {
				return Publickey(node.extract<std::string>().c_str());
			}
		);
		return ARK::API::Delegate::Respondable::NextForgers(
			object->getValue<std::string>("currentBlock").c_str(),
			object->getValue<std::string>("currentSlot").c_str(),
			delegates.get()
		);
	}

	// /api/loader/status
	ARK::API::Loader::Respondable::Status loader_status_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Loader::Respondable::Status(
			object->getValue<bool>("loaded"),
			object->getValue<int>("now"),
			object->getValue<std::string>("blocksCount").c_str()
		);
	}

	// /api/loader/status/sync
	ARK::API::Loader::Respondable::Sync loader_status_sync_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Loader::Respondable::Sync(
			object->getValue<bool>("syncing"),
			object->getValue<int>("blocks"),
			object->getValue<std::string>("height").c_str(),
			object->getValue<std::string>("id").c_str()
		);
	}

	// /api/loader/autoconfigure
	ARK::Network loader_autoconfigure_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto block = object->get("network");
		object = block.extract<Poco::JSON::Object::Ptr>();
		return ARK::Network(
			object->getValue<std::string>("nethash").c_str(),
			object->getValue<std::string>("token").c_str(),
			object->getValue<std::string>("symbol").c_str(),
			object->getValue<std::string>("explorer").c_str(),
			object->getValue<int>("version")
		);
	}

	// /api/multisignatures/pending
	String multisignatures_pending_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);
  
  return jString->valueFor("transactions");*/
		// TODO
		return "";
	}

	// TODO: /api/multisignatures/accounts

	// /api/peers/get
	ARK::Peer peers_get_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto block = object->get("peer");
		object = block.extract<Poco::JSON::Object::Ptr>();
		return ARK::Peer(
			object->getValue<std::string>("ip").c_str(),
			object->getValue<int>("port"),
			object->getValue<std::string>("version").c_str(),
			object->getValue<int>("errors"),
			object->getValue<std::string>("os").c_str(),
			object->getValue<std::string>("height").c_str(),
			object->getValue<std::string>("status").c_str(),
			object->getValue<int>("delay")
		);		
	}

	// /api/peers
	std::unique_ptr<ARK::Peer[]> peers_fromJSON(const char* const json_str) override {
		return parse_array<ARK::Peer>(json_str, "peers", [] (const Poco::JSON::Object::Ptr& peer) {
			return ARK::Peer(
				peer->getValue<std::string>("ip").c_str(),
				peer->getValue<int>("port"),
				peer->getValue<std::string>("version").c_str(),
				peer->getValue<int>("errors"),
				peer->getValue<std::string>("os").c_str(),
				peer->getValue<std::string>("height").c_str(),
				peer->getValue<std::string>("status").c_str(),
				peer->getValue<int>("delay")
			);
		});
	}

	// /api/peers/version
	ARK::API::Peer::Respondable::Version peers_version_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return ARK::API::Peer::Respondable::Version(
			object->getValue<std::string>("version").c_str(),
			object->getValue<std::string>("build").c_str()
		);
	}

	// /api/signatures_fee
	Balance signatures_Fee_fromJSON(const char* const json_str) override {
		const auto object = parse(json_str);
		return Balance(object->getValue<std::string>("fee").c_str());
	}

	// /api/transactions/get
	ARK::Transaction transactions_get_fromJSON(const char* const json_str) override {
		auto object = parse(json_str);
		const auto block = object->get("transaction");
		object = block.extract<Poco::JSON::Object::Ptr>();
		return ARK::Transaction(
			object->getValue<std::string>("id").c_str(),
			object->getValue<std::string>("blockid").c_str(),
			object->getValue<std::string>("height").c_str(),
			object->getValue<int>("type"),
			object->getValue<std::string>("timestamp").c_str(),
			object->getValue<std::string>("amount").c_str(),
			object->getValue<std::string>("fee").c_str(),
			object->getValue<std::string>("senderId").c_str(),
			object->getValue<std::string>("recipientId").c_str(),
			object->getValue<std::string>("senderPublicKey").c_str(),
			object->getValue<std::string>("signature").c_str(),
			object->getValue<std::string>("confirmations").c_str(),
			object->optValue<std::string>("vendorField", std::string()).c_str()
		);
	}

	// /api/transactions
	std::unique_ptr<ARK::Transaction[]> transactions_fromJSON(const char* const json_str) {
		return parse_array<ARK::Transaction>(json_str, "transactions", [](const Poco::JSON::Object::Ptr& transaction) {
			return ARK::Transaction(
				transaction->getValue<std::string>("id").c_str(),
				transaction->getValue<std::string>("blockid").c_str(),
				transaction->getValue<std::string>("height").c_str(),
				transaction->getValue<int>("type"),
				transaction->getValue<std::string>("timestamp").c_str(),
				transaction->getValue<std::string>("amount").c_str(),
				transaction->getValue<std::string>("fee").c_str(),
				transaction->getValue<std::string>("senderId").c_str(),
				transaction->getValue<std::string>("recipientId").c_str(),
				transaction->getValue<std::string>("senderPublicKey").c_str(),
				transaction->getValue<std::string>("signature").c_str(),
				transaction->getValue<std::string>("confirmations").c_str(),
				transaction->optValue<std::string>("vendorField", std::string()).c_str()
			);
		});
	}
	// api/transactions/unconfirmed/get
	ARK::API::Transaction::Respondable::Unconfirmed transactions_unconfirmed_get_fromJSON(const char* const json_str) override {
		/*auto parser = ARK::Utilities::makejson_string(json_str);
			
	int txCount = subCount(json_str, "id");

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
return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);*/
		return ARK::API::Transaction::Respondable::Unconfirmed();
	}
	// api/transactions/unconfirmed
	std::unique_ptr<ARK::API::Transaction::Respondable::Unconfirmed[]> transactions_unconfirmed_fromJSON(const char* const json_str) override {
		/*auto parser = ARK::Utilities::makejson_string(json_str);
			
			int txCount = subCount(json_str, "id");

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
			return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);*/
		return nullptr;
	}
	

	// TODO: /peer/list
	// TODO: /peer/blocks/common
	// TODO: /peer/block
	// TODO: /peer/blocks
	// TODO: /peer/transactions
	// TODO: POST ?? /peer/trasnactions
	// TODO: /peer/transactionsFromIds
	// TODO: /peer/height
	// TODO: /peer/status

private:
	Poco::JSON::Object::Ptr parse(const char* const json_str) {
		Poco::JSON::Parser parser;
		const auto json = parser.parse(json_str);
		return json.extract<Poco::JSON::Object::Ptr>();
	}

	// helper functions to parse JSON array and create model data either in a dynamic array or in an array-like class
	// TODO:  could add concept-like or enable-if checking for template types to enforce interface
	template <typename T, typename CollectionType = std::unique_ptr<T[]>>
	CollectionType parse_array(
		const char* const json_str, 
		const char* const array_name, 
		T (*make_t)(const Poco::JSON::Object::Ptr& node),
		CollectionType (*make_collection)(size_t count) = [] (size_t count) { return std::unique_ptr<T[]>(new T[count]); }
	) {
		const auto object = parse(json_str);
		return parse_array(object, array_name, make_t, make_collection);
	}

	// used to return an array of objects
	template <typename T, typename CollectionType = std::unique_ptr<T[]>>
	CollectionType parse_array(
		Poco::SharedPtr<Poco::JSON::Object> object,
		const char* const array_name,
		T (*make_t)(const Poco::JSON::Object::Ptr& node),
		CollectionType(*make_collection)(size_t count) = [](size_t count) { return std::unique_ptr<T[]>(new T[count]); }
	) {
		const auto array = object->getArray(array_name);
		CollectionType data = make_collection(array->size());

		for (auto i = 0u; i < array->size(); ++i) {
			const auto& t = array->getObject(i);
			data[i] = make_t(t);
		}
		return data;
	}

	// used to return an array of simple data types
	template <typename T, typename CollectionType = std::unique_ptr<T[]>>
	CollectionType parse_array(
		Poco::SharedPtr<Poco::JSON::Object> object,
		const char* const array_name,
		T(*make_t)(const Poco::Dynamic::Var& node),
		CollectionType(*make_collection)(size_t count) = [](size_t count) { return std::unique_ptr<T[]>(new T[count]); }
	) {
		const auto array = object->getArray(array_name);
		CollectionType data = make_collection(array->size());

		for (auto i = 0u; i < array->size(); ++i) {
			const auto& t = array->get(0);
			data[i] = make_t(t);
		}
		return data;
	}
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
