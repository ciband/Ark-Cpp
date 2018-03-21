#include "utilities/json.h"

#include "ArduinoJson.h"

namespace ARK
{
namespace Utilities
{

namespace {

struct JSON : public JSONInterface
{

private:
	static const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;

	String jsonStr;

public:
	JSON(const String& _jsonStr) {
		this->jsonStr = _jsonStr;
	}

	/**************************************************
	* valueFor(key)
	*
	* { "key1": value1, "key2": value2 }
	**************************************************/
	String valueFor(const String& _key) override {
		DynamicJsonBuffer jsonBuffer(capacity);
		JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
		return root[_key];
	}

	/**************************************************
	* valueIn(key, subkey)
	**************************************************/
	String valueIn(const String& _key, const String& _subkey) override {
		DynamicJsonBuffer jsonBuffer(capacity);
		JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
		return root[_key][_subkey];
	}

	/**************************************************
	* subvalueFor(key, position)
	*
	* { "key": { subValue1, subvalue2 } }
	**************************************************/
	String subvalueFor(const String& _key, int _pos) override {
		DynamicJsonBuffer jsonBuffer(capacity);
		JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
		return root[_key][_pos];
	}

	/**************************************************
	* subvalueIn(key, subkey)
	**************************************************/
	String subvalueIn(const String& _key, const String& _subkey) override {
		DynamicJsonBuffer jsonBuffer(capacity);
		JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
		JsonObject &newRoot = root[_key];
		return newRoot[_subkey];
	}
	
	/**************************************************
	* subarrayValueIn(key, position, subkey)
	**************************************************/
	String subarrayValueIn(const String& _key, int _pos, const String& _subkey) override {
		DynamicJsonBuffer jsonBuffer(capacity);
		JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
		// JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
		return root[_key][_pos][_subkey];
	}
};

}

std::unique_ptr<JSONInterface> make_json_string(const String& json_str) {
	return std::unique_ptr<JSONInterface>(new JSON(json_str));
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

}
}
