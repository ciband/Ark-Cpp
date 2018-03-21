# Ark Models


## account.h
`ARK::Model::Account`
```arduino
struct Account {
  public:
    Address address;
    Balance unconfirmedBalance;
    Balance balance;
    Publickey publicKey;
    int unconfirmedSignature;
    int secondSignature;
    Publickey secondPublicKey;
    Signature multisignatures;
    Signature u_multisignatures;
};
```


## block.h
`ARK::Model::Block`
```arduino
struct Block {
  public:
    char id[MAX_UINT128_CHARS];
    int version;
    char timestamp[MAX_UINT128_CHARS];
    char height[64];
    char previousBlock[MAX_UINT128_CHARS];
    char numberOfTransactions[64];
    Balance totalAmount;
    Balance totalFee;
    Balance reward;
    char payloadLength[64];
    Hash payloadHash;
    Publickey generatorPublicKey;
    Address generatorId;
    Signature blockSignature;
    char confirmations[64];
    Balance totalForged;
};
```


## currencies.h
`ARK::Model::Currency`
```arduino
struct Currency {
  public:
    char ticker[5];
    char name[20];
    char symbol[4];
};
```
`ARK::Model::Currencies::Cryptocurrencies`
```arduino
  Currency ARK { "ARK", "Ark", "Ѧ" };
  Currency BTC { "BTC", "Bitcoin", "฿" };
```
`ARK::Model::Currencies::Fiat`
```arduino
  Currency USD { "USD", "United States Dollar", "$" };
  Currency EUR { "EUR", "Euro", "€" };
  Currency GBT { "GBP", "British Pound", "£" };
```


## delegate.h
`ARK::Model::Delegate`
```arduino
struct Delegate {
  public:
		char username[20];
		Address address;
		Publickey publicKey;
		Balance vote;
		int producedblocks;
		int missedblocks;
		int rate;
		double approval;
		double productivity;
};
```


## network.h	
`ARK::Model::Network`
```arduino
struct Network {
  public:
    char nethash[64];
    char token[5];
    char symbol[2];
    char explorer[40];
    int version;
};
```


## peer.h
`ARK::Model::Peer`
```arduino
struct Peer {
  public:
    char ip[40];
    int port;
    char version[32];
    int errors;
    char os[32];
    char height[32];
    char status[32];
    int delay;
};
```


## transaction.h	
`ARK::Model::Transaction`
```arduino
struct asset_t {};
struct Transaction {
  public:
    Hash id;
    char blockid[32];
    char height[32];
    int type;
    char timestamp[32];
    Balance amount;
    Balance fee;
    char vendorField[64];
    Address senderId;
    Address recipientId;
    Publickey senderPublicKey;
    Signature signature;
    char confirmations[64];
};
```


## transport.h
`ARK::Model::Transport`
```arduino
struct TransportPeerHeader {
  public:
    char id[32];
    char height[32];
    int version;
    Balance totalAmount;
    Balance totalFee;
    Balance reward;
    Hash payloadHash;
    int payloadLength;
    char timestamp[32];
    int numberOfTransactions;
    char previousBlock[32];
    Publickey generatorPublicKey;
    Signature blockSignature;
}; 
```


## voter.h
`ARK::Model::Voter`
```arduino
struct Voter {
  public:
    char username[20];
    Address address;
    Publickey publicKey;
    Balance balance;
};
```
