#include "api/delegatable/delegate_respondable.h"
#include "utilities/json.h"

#include <cstring>
#include <cstdio>

namespace ARK {
namespace API {
namespace Delegate {
namespace Respondable {

size_t Search::printTo(Print& p) const
{
	size_t size = 0;
		size += p.print("\nusername: ");
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
	return size;
}


size_t Voters::printTo(Print& p) const
{
	size_t size = 0;

	if (this->count_ > 0)
	{
		size += p.print("\n\0");

		for (int i = 0; i < static_cast<int>(this->count_); i++)
		{
			size += p.print("\nvoter ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += voters_[i].printTo(p);
			size += p.print("\n");
		};
	};
	return size;
}

size_t ForgedByAccount::printTo(Print& p) const
{
	size_t size = 0;
	size += p.print("fees: ");
	size += p.print(this->fees_.ark());
	size += p.print("\nrewards: ");
	size += p.print(this->rewards_.ark());
	size += p.print("\nforged: ");
	size += p.print(this->forged_.ark());
	return size;
}



/*  ==========================================================================  */
/*  ============================================  */
/*  ARK::API::Delegate::Respondable::NextForgers  */
/*  Constructor  */
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
    const char* const currentBlock, const char* const currentSlot,
    const Publickey* const delegates) : currentBlock_(), currentSlot_()
{
    //TODO:  wish i had std::array for _delegates.  pointer decay sucks.
    strncpy(this->currentBlock_, currentBlock, sizeof(this->currentBlock_));
    strncpy(this->currentSlot_, currentSlot, sizeof(this->currentSlot_));
	for (auto i = 0u; i < delegate_keys_.size(); ++i)
	{
		this->delegate_keys_[i] = delegates[i];
	};
}
size_t NextForgers::printTo(Print& p) const
{
	size_t size = 0;
	size += p.print("currentBlock: ");
	size += p.print(this->currentBlock_);
	size += p.print("\ncurrentSlot: ");
	size += p.print(this->currentSlot_);

	for (int i = 0; i < 9; i++)
	{
		size += p.print("delegate ");
		size += p.print(i + 1);
		size += p.print(":\npublicKey: ");
		size += p.print(delegate_keys_[i].getValue());
	};
	return size;
}

}
}
}
}

