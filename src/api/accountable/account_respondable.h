

#ifndef ACCOUNT_RESPONDABLE_H
#define ACCOUNT_RESPONDABLE_H

#include "types/balance.h"
#include "utilities/platform.h"

namespace ARK {
namespace API {
namespace Account {
namespace Respondable {

/*************************************************
*	  ARK::API::Account::Respondable::balances_t
*
*   @param: Balance confirmed, Balance confirmed
*
*   @brief: Model for Balances API Response
**************************************************/
struct balances_t
{
protected:
	Balance confirmed_;
	Balance unconfirmed_;

	balances_t(const Balance& c, const Balance& u) : confirmed_(c), unconfirmed_(u) { }
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*		ARK::API::Account::Respondable::Balances
*
*   @brief: Constructed API Balances Response Object
**************************************************/
class Balances : public Printable, virtual balances_t {

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
	Balances(const Balance& c, const Balance& u) : balances_t(c, u) { }
	
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