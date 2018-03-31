

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

#include "types/balance.h"
#include "utilities/platform.h"

namespace ARK {
namespace API {
namespace Account {
namespace Respondable {

/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @brief: Constructed API Balances Response Object
**************************************************/
class Balances : public Printable {
private:
	Balance confirmed_;
	Balance unconfirmed_;

public:
/*************************************************
    *		ARK::API::Account::Respondable::Balances
    *
    *   @brief: Empty Initialization
    **************************************************/
	Balances() = default;

/*************************************************
    *		ARK::API::Account::Respondable::Balances(const Balance&, const Balance&)
    *
    *   @brief: Constructed API Balances Response Object
    **************************************************/
	Balances(const Balance& c, const Balance& u) : confirmed_(c), unconfirmed_(u) { }
	
	const Balance& confirmed() const noexcept { return confirmed_; }
	const Balance& unconfirmed() const noexcept { return unconfirmed_; }

	/*************************************************
    *   printTo(HardwareSerial &serial)
    *
    *   @brief: Prints balances_t items
    **************************************************/
    size_t printTo(Print& p) const override;
};
/*  ======================================  */
/*  ==========================================================================  */

}
}
}
}

#endif