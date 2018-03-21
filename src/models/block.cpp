#include "models/block.h"

#include <cstring>
#include <cstdio>

size_t ARK::Block::printTo(Print& p) const
{
	size_t size = 0;

	size += p.print("id: ");
	size += p.print(this->id_);

	size += p.print("\nversion: ");
	size += p.print(this->version_);

	size += p.print("\ntimestamp: ");
	size += p.print(this->timestamp_);

	size += p.print("\nheight: ");
	size += p.print(this->height_);

	size += p.print("\npreviousBlock: ");
	size += p.print(this->previousBlock_);

	size += p.print("\nnumberOfTransactions: ");
	size += p.print(this->numberOfTransactions_);

	size += p.print("\ntotalAmount: ");
	size += p.print(this->totalAmount_.ark());

	size += p.print("\ntotalFee: ");
	size += p.print(this->totalFee_.ark());

	size += p.print("\nreward: ");
	size += p.print(this->reward_.ark());

	size += p.print("\npayloadLength: ");
	size += p.print(this->payloadLength_);

	size += p.print("\npayloadHash: ");
	size += p.print(this->payloadHash_.getValue());

	size += p.print("\ngeneratorPublicKey: ");
	size += p.print(this->generatorPublicKey_.getValue());

	size += p.print("\ngeneratorId: ");
	size += p.print(this->generatorId_.getValue());

	size += p.print("\nblockSignature: ");
	size += p.print(this->blockSignature_.getValue());

	size += p.print("\nconfirmations: ");
	size += p.print(this->confirmations_);

	size += p.print("\ntotalForged: ");
	size += p.print(this->totalForged_.ark());

	return size;
}

