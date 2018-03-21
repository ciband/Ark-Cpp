#include "models/currency.h"

#include <cstring>

namespace ARK {
namespace Model {


Currency::Currency(const char* const t, const char* const n, const char* const s) : ticker_(), name_(), symbol_() {
	strncpy(ticker_, t, sizeof(ticker_) / sizeof(ticker_[0]));
	strncpy(name_, n, sizeof(name_) / sizeof(name_[0]));
	strncpy(symbol_, s, sizeof(symbol_) / sizeof(symbol_[0]));
}

size_t Currency::printTo(Print& p) const
{
	size_t size = 0;
      size += p.print("ticker: ");
      size += p.print(this->ticker_);

      size += p.print("\nname: ");
      size += p.print(this->name_);

      size += p.print("\nsymbol: ");
      size += p.print(this->symbol_);
	return size;
}

}
}