#include "api/accountable/account_respondable.h"

namespace ARK {
namespace API {
namespace Account {
namespace Respondable {

size_t Balances::printTo(Print& p) const
{
    size_t size = 0;
    size += p.print("\nconfirmed balance.ark: ");
    size += p.print(this->confirmed_.ark());
    size += p.print("\nconfirmed balance.arktoshi: ");
    size += p.print(this->confirmed_.arktoshi());
    size += p.print("\n\nunconfirmed balance.ark: ");
    size += p.print(this->unconfirmed_.ark());
    size += p.print("\nunconfirmed balance.arktoshi: ");
    size += p.print(this->unconfirmed_.arktoshi());
    return size;
}

}
}
}
}
