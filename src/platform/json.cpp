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
	std::unique_ptr<ARK::Account[]> accounts_fromJSON(const char* const json_str) override {
		return parse_array<Account>(json_str, "account", [] (const Poco::JSON::Object::Ptr& account) {
			return ARK::Account(
				account->getValue<std::string>("address").c_str(),
				account->getValue<std::string>("unconfirmedBalance").c_str(),
				account->getValue<std::string>("balance").c_str(),
				account->getValue<std::string>("publicKey").c_str(),
				account->getValue<int>("unconfirmedSignature"),
				account->getValue<int>("secondSignature"),
				account->getValue<std::string>("secondPublicKey").c_str(),
				account->getValue<std::string>("multisignatures").c_str(),
				account->getValue<std::string>("u_multisignatures").c_str()
			);
		});
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
		const auto object = parse(json_str);
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
		/*auto jString = ARK::Utilities::makejson_string(json_str);

		Publickey delegates[10];

		for (int i = 0; i < 10; i++)
		{
			delegates[i] = Publickey(jString->subvalueFor("delegates", i).c_str());
		};

		return ARK::API::Delegate::Respondable::NextForgers(
			jString->valueFor("currentBlock").c_str(),
			jString->valueFor("currentSlot").c_str(),
			delegates
		);*/
		return ARK::API::Delegate::Respondable::NextForgers();
	}
	// /api/loader/status
	ARK::API::Loader::Respondable::Status loader_status_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);

    return ARK::API::Loader::Respondable::Status(
        jString->valueFor("loaded").c_str(),
        convert_to_int(jString->valueFor("now")),
        jString->valueFor("blocksCount").c_str()
    );*/
		return ARK::API::Loader::Respondable::Status();
	}
	// /api/loader/status/sync
	ARK::API::Loader::Respondable::Sync loader_status_sync_fromJSON(const char* const json_str) override {
		/*
		auto jString = ARK::Utilities::makejson_string(json_str);

    return ARK::API::Loader::Respondable::Sync(
        jString->valueFor("syncing").c_str(),
        convert_to_int(jString->valueFor("blocks")),
        jString->valueFor("height").c_str(),
        jString->valueFor("id").c_str()
    );*/
		return ARK::API::Loader::Respondable::Sync();
	}
	// /api/loader/autoconfigure
	ARK::Network loader_autoconfigure_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);

    return ARK::Network(
        jString->valueIn("network", "nethash").c_str(),
        jString->valueIn("network", "token").c_str(),
        jString->valueIn("network", "symbol").c_str(),
        jString->valueIn("network", "explorer").c_str(),
        convert_to_int(jString->valueIn("network", "version"))
    );
*/
		return ARK::Network();
	}
	// /api/multisignatures/pending
	String multisignatures_pending_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);
  
  return jString->valueFor("transactions");*/
		return "";
	}

	// TODO: /api/multisignatures/accounts

	// /api/peers/get
	ARK::Peer peers_get_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);

    return ARK::Peer(
        jString->valueIn("peer", "ip").c_str(),
        convert_to_int(jString->valueIn("peer", "port")),
        jString->valueIn("peer", "version").c_str(),
        convert_to_int(jString->valueIn("peer", "errors")),
        jString->valueIn("peer", "os").c_str(),
        jString->valueIn("peer", "height").c_str(),
        jString->valueIn("peer", "status").c_str(),
        convert_to_int(jString->valueIn("peer", "delay"))
    );*/
		return ARK::Peer();
	}
	// /api/peers
	std::unique_ptr<ARK::Peer[]> peers_fromJSON(const char* const json_str) override {
		//   auto jString = ARK::Utilities::makejson_string(json_str);
		//   int peersCount = 10; // limited to 10
		//   ARK::Peer::PeersResponse peersResponse(peersCount);
		//   // for (int i = 0; i < peersCount; i++) {
		//   //   ARK::Peer peer = {
		//   //     jString->subarrayValueIn("peers", i, "ip"),
		//   //     jString->subarrayValueIn("peers", i, "port").toInt(),
		//   //     jString->subarrayValueIn("peers", i, "version"),
		//   //     jString->subarrayValueIn("peers", i, "errors").toInt(),
		//   //     jString->subarrayValueIn("peers", i, "os"),
		//   //     jString->subarrayValueIn("peers", i, "height"),
		//   //     jString->subarrayValueIn("peers", i, "status"),
		//   //     jString->subarrayValueIn("peers", i, "delay").toInt()
		//   //   };
		//   //   peersResponse.list[i] = peer;
		//   // };
		//   return peersResponse;
		return nullptr;
	}

	// /api/peers/version
	ARK::API::Peer::Respondable::Version peers_version_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);

    return ARK::API::Peer::Respondable::Version(
        jString->valueFor("version").c_str(),
        jString->valueFor("build").c_str()
    );*/
		return ARK::API::Peer::Respondable::Version();
	}

	// /api/signatures_fee
	Balance signatures_Fee_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str);

  return Balance(jString->valueFor("fee").c_str());*/
		return Balance();
	}
	// /api/transactions/get
	ARK::Transaction transactions_get_fromJSON(const char* const json_str) override {
		/*auto jString = ARK::Utilities::makejson_string(json_str); 

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
        jString->valueIn("transaction", "recipientId").c_str(),
        jString->valueIn("transaction", "senderPublicKey").c_str(),
        jString->valueIn("transaction", "signature").c_str(),
        jString->valueIn("transaction", "confirmations").c_str()
    );*/
		return ARK::Transaction();
	}
	// /api/transactions
	std::unique_ptr<ARK::Transaction[]> transactions_fromJSON(const char* const json_str) {
		/*//   auto jString = ARK::Utilities::makejson_string(json_str); 
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
//   return resp;*/
		return nullptr;
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

	/*template <typename T>
	std::unique_ptr<T[]> parse_array(
		const char* const json_str, 
		const char* const array_name, 
		T (*make_t)(const Poco::JSON::Object::Ptr& node)
	) {
		const auto object = parse(json_str);
		const auto array = object->getArray(array_name);
		std::unique_ptr<T[]> data(new T[array->size()]);

		for (auto i = 0u; i < array->size(); ++i) {
			const auto& t = array->getObject(i);
			data[i] = make_t(t);
		}
		return data;
	}*/

	// helper function parse JSON array and create model data either in a dynamic array or in an array-like class
	// TODO:  could add concept-like or enable-if checking for template types to enforce interface
	template <typename T, typename CollectionType = std::unique_ptr<T[]>>
	CollectionType parse_array(
		const char* const json_str, 
		const char* const array_name, 
		T (*make_t)(const Poco::JSON::Object::Ptr& node),
		CollectionType (*make_collection)(size_t count) = [] (size_t count) { return std::unique_ptr<T[]>(new T[count]); }
	) {
		const auto object = parse(json_str);
		const auto array = object->getArray(array_name);
		CollectionType data = make_collection(array->size());

		for (auto i = 0u; i < array->size(); ++i) {
			const auto& t = array->getObject(i);
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
