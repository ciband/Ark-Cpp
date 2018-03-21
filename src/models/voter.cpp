#include "models/voter.h"

size_t ARK::Voter::printTo(Print& p) const 
{
	size_t size = 0;

	size += p.print("\nusername: ");
	size += p.print(this->username_);

	size += p.print("\naddress: ");
	size += p.print(this->address_.getValue());

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey_.getValue());

	size += p.print("\nbalance.ark: ");
	size += p.print(this->balance_.ark());

	return size;
}