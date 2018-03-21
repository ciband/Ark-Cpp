#include "models/account.h"

size_t ARK::Account::printTo(Print& p) const
		{
			size_t size = 0;

			size += p.print("address: ");
			size += p.print(address_.getValue());

			size += p.print("\nunconfirmedBalance: ");
			size += p.print(this->unconfirmedBalance_.ark());

			size += p.print("\nbalance: ");
			size += p.print(this->balance_.ark());

			size += p.print("\npublicKey: ");
			size += p.print(this->publicKey_.getValue());

			size += p.print("\nunconfirmedSignature: ");
			size += p.print(this->unconfirmedSignature_);

			size += p.print("\nsecondSignature: ");
			size += p.print(this->secondSignature_);

			size += p.print("\nsecondPublicKey: ");
			size += p.print(this->secondPublicKey_.getValue());

			size += p.print("\nmultisignatures: ");
			size += p.print(this->multisignatures_.getValue());

			size += p.print("\nu_multisignatures: ");
			size += p.print(this->u_multisignatures_.getValue());

			return size;
		}