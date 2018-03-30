#include "utilities/platform.h"

#ifndef USE_IOT

#include "utilities/json.h"

#include "Poco/JSON/Array.h"
#include "Poco/JSON/Parser.h"

//#include "nlohmann/json.hpp"
//using json = nlohmann::json;

#include <string>

namespace ARK {
namespace Utilities {

namespace Internal {

class JSON : public JSONInterface<JSON>
{

private:
	//json _json;
	Poco::Dynamic::Var _json;

public:
	//JSON(const std::string& jsonStr) : _json(json::parse(jsonStr)) {
	JSON(const std::string& jsonStr) : _json(parse_json(jsonStr)) {
	}

	/**************************************************
	* valueFor(key)
	*
	* { "key1": value1, "key2": value2 }
	**************************************************/
	//String valueFor(const String& key) override {
	//	return get_value(_json[key]);
	//}

	template <typename T>
	T get_value(const std::string& key) {
		auto ptr = _json.extract<Poco::JSON::Object::Ptr>();
		return ptr->getValue<T>(key);
	}

	/**************************************************
	* valueIn(key, subkey)
	**************************************************/
	//String valueIn(const String& key, const String& subkey) override {
	//	return get_value(_json[key][subkey]);
	//}

	template <typename T>
	T get_sub_value(const std::string& key, const std::string& sub_key) {
		auto ptr = _json.extract<Poco::JSON::Object::Ptr>();
		ptr = ptr->getObject(key);
		return ptr->getValue<T>(sub_key);
	}

	class JSONArrayIterator {
	private:
		Poco::Dynamic::Array::const_iterator _impl;

	public:
		JSONArrayIterator(Poco::Dynamic::Array::const_iterator it) : _impl(std::move(it)) { }

		template <typename T>
		T get_value(const std::string& key) {
			return _impl->getAt(key).convert<T>();
		}
	};

	class JSONArray {
	public:
		typedef JSONArrayIterator const_iterator;

	private:
		Poco::SharedPtr<Poco::JSON::Array> _impl;

	public:
		JSONArray(Poco::SharedPtr<Poco::JSON::Array> p) : _impl(std::move(p)) { }

		const_iterator begin() const { return const_iterator(_impl->begin()); }
		const_iterator end() const { return const_iterator(_impl->end()); }
	};

	JSONArray get_array(const std::string& key) {
		auto ptr = _json.extract<Poco::JSON::Object::Ptr>();
		return JSONArray(ptr->getArray(key));
	}

	/**************************************************
	* subvalueFor(key, position)
	*
	* { "key": { subValue1, subvalue2 } }
	**************************************************/
	//String subvalueFor(const String& key, int pos) override {
	//	return get_value(_json[key][pos]);
	//}

	/*template <typename T>
	T get_sub_value(const std::string& key, size_t sub_index) {
		auto ptr = _json.extract<Poco::JSON::Object::Ptr>();
		ptr = ptr->getObject(key);
		return ptr->
	}*/

	/**************************************************
	* subvalueIn(key, subkey)
	**************************************************/
	//String subvalueIn(const String& key, const String& subkey) override {
	//	const json new_root(_json[key]);
	//	return get_value(new_root[subkey]);
	//}
	
	/**************************************************
	* subarrayValueIn(key, position, subkey)
	**************************************************/
	//String subarrayValueIn(const String& key, int pos, const String& subkey) override {
	//	return get_value(_json[key][pos][subkey]);
	//}

private:
	/*std::string get_value(const json& j) const {
		if (j.is_string()) {
			return j.get<std::string>();
		}
		std::ostringstream ss;
		ss << j;
		return ss.str();
	}*/

	static Poco::Dynamic::Var parse_json(const std::string& json_str) {
		Poco::JSON::Parser parser;
		return parser.parse(json_str);
	}
};

}

std::unique_ptr<JSONInterface<Internal::JSON>> make_json_string(const String& json_str) {
	return std::unique_ptr<JSONInterface<Internal::JSON>>(new Internal::JSON(json_str));
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
