#ifndef ACCOUNT_GETTABLE_H
#define ACCOUNT_GETTABLE_H

#include "api/accountable/account_respondable.h"
#include "models/account.h"
#include "utilities/connector.h"
#include "types/address.h"
#include "types/balance.h"
#include "types/publickey.h"
#include "models/delegate.h"

namespace ARK
{
namespace API
{
namespace Account
{
/*************************************************
*  PROTECTED: ARK::API::Account::Gettable
**************************************************/
class Gettable
{
  protected:
/*************************************************
		*	ARK::API::Account::Gettable::balance
		*		/api/accounts/getBalance?address=arkAddress
		**************************************************/
    ARK::API::Account::Respondable::Balances balance(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);


/*************************************************/

/*************************************************
		*	ARK::API::Account::Gettable::publickey
		*		/api/accounts/getPublickey?address=arkAddress
		**************************************************/
    Publickey publickey(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);




/*************************************************
		*	ARK::API::Account::Gettable::delegatesFee
		*		/api/accounts/delegates/fee?address=arkAddress
		**************************************************/
    Balance delegatesFee(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);




/*************************************************
		*	ARK::API::Account::Gettable::delegates
		*		/api/accounts/delegates?address=arkAddress
		**************************************************/
	std::unique_ptr<ARK::Delegate[]> delegates(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);




/*************************************************
		*	ARK::API::Account::Gettable::account
		*		/api/accounts?address=arkAddress 
		**************************************************/
	std::unique_ptr<ARK::Account[]> account(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);


/*  ==========================================================================  */
};
/*  ======================================  */
/*  ==========================================================================  */
};
};
};

#endif
