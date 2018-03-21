

#ifndef JSON_H
#define JSON_H

#include "platform.h"

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
	JSONInterface() { }

public:
    virtual String valueFor(const String& _key) = 0;
    virtual String valueIn(const String& _key, const String& _subkey) = 0;
    virtual String subvalueFor(const String& _key, int _pos) = 0;
    virtual String subvalueIn(const String& _key, const String& _subkey) = 0;
    virtual String subarrayValueIn(const String& _key, int _pos, const String& _subkey) = 0;
};
/*  ==========================================================================  */

// JSON object factory
std::unique_ptr<JSONInterface> make_json_string(const String& str);

}
}

#endif
