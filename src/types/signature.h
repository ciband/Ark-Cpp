

#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <cstring>

/********************************************************************************
*
* signature: 
*   "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*   
*   142 Characters | ?-encoded
*
********************************************************************************/


class Signature {
private:
    static const auto SIGNATURE_SIZE = 143;
    char value_[SIGNATURE_SIZE];

public:
	Signature() = default;

	explicit Signature(const char* const _signatureString) : value_() {
      strncpy(value_, _signatureString, sizeof(value_) / sizeof(value_[0]));
    };

    const char* getValue() const noexcept { return value_; };      
};

#endif
