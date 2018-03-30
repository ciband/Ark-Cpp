

#ifndef JSON_H
#define JSON_H

#include "platform.h"

#include <memory>

namespace ARK {
namespace Utilities {

namespace Internal {

class JSON;

}

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONInterface 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
template <typename Derived>
class JSONInterface {
protected:
	JSONInterface() { }

public:
    virtual ~JSONInterface() { }

    //virtual String valueFor(const String& _key) = 0;
	template <typename T>
	T get_value(const String& key) {
		return static_cast<Derived*>(this)->get_value(key);
	}

	JSONArray get_array(const std::string& key) {
		return static_cast<Derived*>(this)->get_array(key);
	}

    //virtual String valueIn(const String& _key, const String& _subkey) = 0;
    //virtual String subvalueFor(const String& _key, int _pos) = 0;
    //virtual String subvalueIn(const String& _key, const String& _subkey) = 0;
    //virtual String subarrayValueIn(const String& _key, int _pos, const String& _subkey) = 0;
};
/*  ==========================================================================  */

// JSON object factory
std::unique_ptr<JSONInterface<Internal::JSON> > make_json_string(const String& str);

}
}

#endif
