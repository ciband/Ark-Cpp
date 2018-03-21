#include "api/transactionable/transaction_respondable.h"

namespace ARK {
namespace API {
namespace Transaction {
namespace Respondable  {

size_t Unconfirmed::printTo(Print& p) const {
    size_t size = 0;

    if (this->count_ == 0)
    {
        size += p.print("There are currently no Unconfirmed Transactions");
    }
    else
    {
        for (auto i = 0u; i < this->count_; ++i) {
			size += p.print("\ntransaction ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += this->transactions_[i].printTo(p);
        }
    };
    return size;
}

}
}
}
}

