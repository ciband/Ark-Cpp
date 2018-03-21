#include "api/accountable/account_gettable.h"
#include "utilities/json.h"
#include "api/paths.h"
#include "utilities/connector.h"

/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Account::Gettable::balance  */
/*  /api/accounts/getBalance?address=arkAddress */
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balance(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO: check size
    strcpy(uri, ARK::API::Paths::Account::getBalance_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());
  
    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::balancefromJSON(callback);
};

/*
{ "success":true,
  "balance":  "Balance",
  "unconfirmedBalance": "Balance"
}
*/
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balancefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return ARK::API::Account::Respondable::Balances(Balance(jString->valueFor("balance").c_str()), Balance(jString->valueFor("unconfirmedBalance").c_str()));
};
/*  ==================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::publickey  */
/*  /api/accounts/getPublickey?address=arkAddress */
Publickey ARK::API::Account::Gettable::publickey(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);
    return ARK::API::Account::Gettable::publickeyfromJSON(callback);
};

/*
{ "success":true,
  "publicKey":  "Publickey"
}
*/
Publickey ARK::API::Account::Gettable::publickeyfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Publickey(jString->valueFor("publicKey").c_str());
};
/*  ====================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  =========================================  */
/*  ARK::API::Account::Gettable::delegatesFee  */
/*  /api/accounts/delegates/fee?address=arkAddress  */
Balance ARK::API::Account::Gettable::delegatesFee(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{

    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::delegatesFeefromJSON(callback);
};

/*
{ "success":true,
  "fee":2500000000
}
*/
Balance ARK::API::Account::Gettable::delegatesFeefromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

  return Balance(jString->valueFor("fee").c_str());
};
/*  =========================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ======================================  */
/*  ARK::API::Account::Gettable::delegates  */
/*  /api/accounts/delegates?address=arkAddress  */
ARK::Delegate ARK::API::Account::Gettable::delegates(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::delegates_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::delegatesfromJSON(callback);
};

/*
{ "success":true,
  "delegates":[{
    "username": "sleepdeficit",
    "address":  "Address",
    "publicKey":  "Publickey",
    "vote": "Balance",
    "producedblocks": String,
    "missedblocks": String,
    "rate": int,
    "approval": double,
    "productivity": double
  }]
}
*/
ARK::Delegate ARK::API::Account::Gettable::delegatesfromJSON(const char* const _jsonStr)
{
  auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return Delegate(
        jString->subarrayValueIn("delegates", 0, "username").c_str(),
        jString->subarrayValueIn("delegates", 0, "address").c_str(),
        jString->subarrayValueIn("delegates", 0, "publicKey").c_str(),
        jString->subarrayValueIn("delegates", 0, "vote").c_str(),
        convert_to_int(jString->subarrayValueIn("delegates", 0, "producedblocks")),
        convert_to_int(jString->subarrayValueIn("delegates", 0, "missedblocks")),
        convert_to_int(jString->subarrayValueIn("delegates", 0, "rate")),
        convert_to_float(jString->subarrayValueIn("delegates", 0, "approval")),
        convert_to_float(jString->subarrayValueIn("delegates", 0, "productivity"))
    );
};
/*  ======================================  */
/*  ==========================================================================  */




/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Account::Gettable::account  */
/*  /api/accounts?address=arkAddress  */
ARK::Account ARK::API::Account::Gettable::account(
    ARK::Utilities::Network::Connector& netManager,
    const Address& arkAddress)
{
    char uri[256] = { '\0' }; // TODO:  check size

    strcpy(uri, ARK::API::Paths::Account::accounts_s);
    strcat(uri, "?address=");
    strcat(uri, arkAddress.getValue());

    auto callback = netManager.cb(uri);

    return ARK::API::Account::Gettable::accountfromJSON(callback);
};

/*
{ "success":true,
  "account":{
    "address":  "Address",
    "unconfirmedBalance": "Balance",
    "balance":  "Balance",
    "publicKey":  "Publickey",
    "unconfirmedSignature": int,
    "secondSignature":  int,
    "secondPublicKey":  "Publickey",
    "multisignatures":[],
    "u_multisignatures":[]
  }
}
*/
ARK::Account ARK::API::Account::Gettable::accountfromJSON(const char* const _jsonStr)
{
    auto jString = ARK::Utilities::make_json_string(_jsonStr);

    return ARK::Account(
        jString->subvalueIn("account", "address").c_str(),
        jString->subvalueIn("account", "unconfirmedBalance").c_str(),
        jString->subvalueIn("account", "balance").c_str(),
        jString->subvalueIn("account", "publicKey").c_str(),
        convert_to_int(jString->subvalueIn("account", "unconfirmedSignature")),
        convert_to_int(jString->subvalueIn("account", "secondSignature")),
        jString->subvalueIn("account", "secondPublicKey").c_str(),
        jString->subvalueIn("account", "multisignatures").c_str(),
        jString->subvalueIn("account", "u_multisignatures").c_str()
    );
};
/*  ====================================  */
/*  ==========================================================================  */
