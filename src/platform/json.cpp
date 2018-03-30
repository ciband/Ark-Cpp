#include "utilities/platform.h"

#ifndef USE_IOT

#include "utilities/json.h"

#include "Poco/JSON/Array.h"
#include "Poco/JSON/Parser.h"

#include <string>

namespace ARK {
namespace Utilities {

namespace {

class JSON : public JSONInterface {

private:
	Poco::Dynamic::Var _json;

public:
	JSON(const std::string& jsonStr) : _json(parse_json(jsonStr)) {
	}

	ARK::API::Account::Respondable::Balances balancefromJSON(const char* const _jsonStr);
	Publickey publickeyfromJSON(const char* const _jsonStr);
	Balance delegatesFeefromJSON(const char* const _jsonStr);
	ARK::Account accountfromJSON(const char* const _jsonStr);
	ARK::Block blockfromJSON(const char* const jsonStr);
	std::unique_ptr<ARK::Block[]> blocksfromJSON(const char* const jsonStr);
	String epochfromJSON(const char* const _jsonStr);
	ARK::API::Block::Respondable::Height heightfromJSON(const char* const _jsonStr);
	Hash nethashfromJSON(const char* const _jsonStr);
	Balance feefromJSON(const char* const _jsonStr);
	ARK::Fees feesfromJSON(const char* const _jsonStr);
	String milestonefromJSON(const char* const _jsonStr);
	Balance rewardfromJSON(const char* const _jsonStr);
	Balance supplyfromJSON(const char* const _jsonStr);
	ARK::API::Block::Respondable::Status statusfromJSON(const char* const _jsonStr);
	int countfromJSON(const char* const _jsonStr);
	ARK::API::Delegate::Respondable::Search searchfromJSON(const char* const _jsonStr);
	ARK::API::Delegate::Respondable::Voters votersfromJSON(const char* const _jsonStr);
	ARK::Delegate delegatefromJSON(const char* const _jsonStr);
	std::unique_ptr<ARK::Delegate[]> delegatesfromJSON(const char* const _jsonStr);
	Balance feefromJSON(const char* const _jsonStr);
	ARK::API::Delegate::Respondable::ForgedByAccount forgedByAccountfromJSON(const char* const _jsonStr);
	ARK::API::Delegate::Respondable::NextForgers nextForgersfromJSON(const char* const _jsonStr);
	ARK::API::Loader::Respondable::Status loader_statusfromJSON(const char* const _jsonStr);
	ARK::API::Loader::Respondable::Sync syncfromJSON(const char* const _jsonStr);
	ARK::Network autoconfigurefromJSON(const char* const _jsonStr);
	String pendingfromJSON(const char* const _jsonStr);
	ARK::Peer peerfromJSON(const char* const _jsonStr);
	ARK::API::PeerGettablePeersResponse peersfromJSON(const char* const _jsonStr);
	ARK::API::Peer::Respondable::Version versionfromJSON(const char* const _jsonStr);
	Balance feefromJSON(const char* const _jsonStr);
	ARK::Transaction transactionfromJSON(const char* const jsonStr);
	ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmedfromJSON(const char* const jsonStr);
	ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmedfromJSON(const char* const jsonStr);
	std::unique_ptr<ARK::Transaction[]> ARK::API::Transaction::Gettable::transactionsfromJSON(const char* const jsonStr);

private:
	static Poco::Dynamic::Var parse_json(const std::string& json_str) {
		Poco::JSON::Parser parser;
		return parser.parse(json_str);
	}
};

}

std::unique_ptr<JSONInterface> make_json_string(const String& json_str) {
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
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
