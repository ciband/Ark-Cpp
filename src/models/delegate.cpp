#include "models/delegate.h"

size_t ARK::Delegate::printTo(Print& p) const
{
	size_t size = 0;

	size += p.print("username: ");
	size += p.print(this->username_);

	size += p.print("\naddress: ");
	size += p.print(this->address_.getValue());

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey_.getValue());

	size += p.print("\nvote: ");
	size += p.print(this->vote_.ark());

	size += p.print("\nproducedblocks: ");
	size += p.print(this->producedblocks_);
	
	size += p.print("\nmissedblocks: ");
	size += p.print(this->missedblocks_);

	size += p.print("\nrate: ");
	size += p.print(this->rate_);

	size += p.print("\napproval: ");
	size += p.print(this->approval_);

	size += p.print("%\nproductivity: ");
	size += p.print(this->productivity_);
	size += p.print("%");

	return size;
}