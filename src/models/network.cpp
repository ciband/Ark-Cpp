#include "models/network.h"

#include <cstdio>

size_t ARK::Network::printTo(Print& p) const
{
	size_t size = 0;
	
	size += p.print("\nnethash: ");
	size += p.print(this->nethash_);

	size += p.print("\ntoken: ");
	size += p.print(this->token_);

	size += p.print("\nsymbol: ");
	size += p.print(this->symbol_);

	size += p.print("\nexplorer: ");
	size += p.print(this->explorer_);

	size += p.print("\nversion: ");
	size += p.print(this->version_);

	return size;
}
/*  =====  */
/*  Operator  */
/*  ARK::Network == ARK::Network  */
bool ARK::Network::Network::operator==(const Network& rhs) const {
    return (strcmp(this->nethash_, rhs.nethash_) == 0
        && strcmp(this->token_, rhs.token_) == 0
        && strcmp(this->symbol_, rhs.symbol_) == 0
        && strcmp(this->explorer_, rhs.explorer_) == 0
        && this->version_ == rhs.version_);
};
/*  =====  */
/*  Operator  */
/*  ARK::Network != ARK::Network  */
bool ARK::Network::Network::operator!=(const Network& rhs) const { return !(*this == rhs); };
/*  ============  */
/*  ================================================  */

