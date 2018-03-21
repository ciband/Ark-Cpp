

#ifndef voter_h
#define voter_h

#include "types/address.h"
#include "types/balance.h"
#include "types/publickey.h"
#include "utilities/platform.h"

#include <cstring>

namespace ARK {
    
/*  ================================================  */
  /*  ==========  */
  /*  ARK::Voter  */
class Voter : public Printable {
private:
    char username_[64];
    Address address_;
    Publickey publicKey_;
    Balance balance_;

public:
    Voter() : username_() { }

    Voter(
        const char* const u, 
        const char* const a, 
        const char* const pk,
        const char* const b
    ) : username_(), address_(a), publicKey_(pk), balance_(b) {
        strncpy(username_, u, sizeof(username_) / sizeof(username_[0]));
    }

	const char* username() const noexcept { return username_; }
	const Address& address() const noexcept { return address_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	const Balance& balance() const noexcept { return balance_; }

	size_t printTo(Print& p) const override;
};
/*  ==========  */
/*  ================================================  */

};


#endif
