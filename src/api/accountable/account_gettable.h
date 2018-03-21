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

/*************************************************
		*
		*	{
		*		"success":true,
		*		"balance":  "Balance",
		*		"unconfirmedBalance": "Balance"
		*	}
		*
		**************************************************/
    ARK::API::Account::Respondable::Balances balancefromJSON(const char* const _jsonStr);
    ARK::API::Account::Respondable::Balances balancefromJSON(const String& _jsonStr) {
        return balancefromJSON(_jsonStr.c_str());
    }
/*************************************************/

/*************************************************
		*	ARK::API::Account::Gettable::publickey
		*		/api/accounts/getPublickey?address=arkAddress
		**************************************************/
    Publickey publickey(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

/*************************************************
		*
		*	{
		*		"success":true,
		*		"publicKey":  "Publickey"
		*	}
		*
		**************************************************/
    Publickey publickeyfromJSON(const char* const _jsonStr);
    Publickey publickeyfromJSON(const String& _jsonStr) {
        return publickeyfromJSON(_jsonStr.c_str());
    }


/*************************************************
		*	ARK::API::Account::Gettable::delegatesFee
		*		/api/accounts/delegates/fee?address=arkAddress
		**************************************************/
    Balance delegatesFee(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

/*************************************************
		*
		*	{
		*		"success":true,
		*		"fee":2500000000
		*	}
		*
		**************************************************/
    Balance delegatesFeefromJSON(const char* const _jsonStr);
    Balance delegatesFeefromJSON(const String& _jsonStr) {
        return delegatesFeefromJSON(_jsonStr.c_str());
    }


/*************************************************
		*	ARK::API::Account::Gettable::delegates
		*		/api/accounts/delegates?address=arkAddress
		**************************************************/
    ARK::Delegate delegates(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

/*************************************************
		*
		*	{
		*		"success":true,
		*		"delegates":
		*		[
		*			{
		*				"username": "sleepdeficit",
		*				"address":  "Address",
		*				"publicKey":  "Publickey",
		*				"vote": "Balance",
		*				"producedblocks": const char*,
		*				"missedblocks": String,
		*				"rate": int,
		*				"approval": double,
		*				"productivity": double
		*			}
		*		]
		*	}
		*
		**************************************************/
    ARK::Delegate delegatesfromJSON(const char* const _jsonStr);
    ARK::Delegate delegatesfromJSON(const String& _jsonStr) {
        return delegatesfromJSON(_jsonStr.c_str());
    }


/*************************************************
		*	ARK::API::Account::Gettable::account
		*		/api/accounts?address=arkAddress 
		**************************************************/
    ARK::Account account(
        ARK::Utilities::Network::Connector& netManager,
        const Address& arkAddress);

/*************************************************
		*
		*	{
		*		"success":true,
		*		"account":
		*		{
		*			"address":  "Address",
		*			"unconfirmedBalance": "Balance",
		*			"balance":  "Balance",
		*			"publicKey":  "Publickey",
		*			"unconfirmedSignature": int,
		*			"secondSignature":  int,
		*			"secondPublicKey":  "Publickey",
		*			"multisignatures":[],
		*			"u_multisignatures":[]
		*		}
		*	}
		*
		**************************************************/
    ARK::Account accountfromJSON(const char* const _jsonStr);
    ARK::Account accountfromJSON(const String& _jsonStr) {
        return accountfromJSON(_jsonStr.c_str());
    }
/*  ==========================================================================  */
};
/*  ======================================  */
/*  ==========================================================================  */
};
};
};

#endif
