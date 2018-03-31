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

    return ARK::Utilities::get_json_interface().balancefromJSON(callback);
};

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
    return ARK::Utilities::get_json_interface().publickeyfromJSON(callback);
};



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

    return ARK::Utilities::get_json_interface().delegatesFeefromJSON(callback);
};





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

    return ARK::Utilities::get_json_interface().delegatesfromJSON(callback);
}


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

    return ARK::Utilities::get_json_interface().accountfromJSON(callback);
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
}
/*  ====================================  */
/*  ==========================================================================  */
