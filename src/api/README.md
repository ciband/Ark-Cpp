


## Whats Here

1) Modelable
> Primary Model for entering of API's syntax  

    ARK::API::Accountable  
    ARK::API::Blockable  
    ARK::API::Delegatable  
    ARK::API::Loadable  
    ARK::API::MultiSignaturable  
    ARK::API::Peerable  
    ARK::API::Signaturable  
    ARK::API::Transactionable  

2) Gettable
> These methods return API Respondables to their corresponding API Modelables  

    ARK::API::Account::Gettable  
    ARK::API::Block::Gettable  
    ARK::API::Delegate::Gettable  
    ARK::API::Loader::Gettable  
    ARK::API::MultiSignature::Gettable  
    ARK::API::Peer::Gettable  
    ARK::API::Signature::Gettable  
    ARK::API::Transaction::Gettable  

3) Respondable
> These are structs that model certain API Responses  

    ARK::API::Account::Respondable  
    ARK::API::Block::Respondable  
    ARK::API::Delegate::Respondable  
    ARK::API::Loader::Respondable  
    ARK::API::Peer::Respondable  


##

```
======================= Accounts ====================  


/api/accounts/getBalance?address=arkAddress
 ARK::API::Account::Respondable::Balances accountBalance(Address arkAddress)

/api/accounts/getPublickey?address=arkAddress
 Publickey accountPublickey(String arkAddress)

/api/accounts/delegates/fee?address=arkAddress
 Balance accountDelegatesFee(String arkAddress)

/api/accounts/delegates?address=arkAddress
 ARK::Delegate accountDelegates(String arkAddress)

/api/accounts?address=arkAddress
 ARK::Account account(String _arkAddress)

===================== /Accounts =====================
```


```
======================= Blocks ======================  

/api/blocks/get?id=_blockID  
 ARK::Block  block(String _blockId)  

/*  =================================================  */
// BROKEN: fix for large callbacks  
///api/blocks  
// String blocks()  
/*  =================================================  */

/api/blocks/getEpoch
 String blockEpoch()  

/api/blocks/getHeight
 ARK::API::Block::Respondable::Height blockHeight()  

/api/blocks/getNethash  
 Hash blockNethash()  

/api/blocks/getFee  
 Balance blockFee()  

/api/blocks/getFees  
 ARK::Fees blockFees()  

/api/blocks/getMilestone  
 String blockMilestone()

/api/blocks/getReward  
 Balance blockReward()  

/api/blocks/getSupply  
 Balance blockSupply()  

/api/blocks/getStatus  
 ARK::API::Block::Respondable::Status blockStatus()  

======================= /Blocks =====================  
```


```
====================== Delegates ====================  

/api/delegates/count  
 int delegatesCount()  

/api/delegates/search?q=sleepdeficit  
 ARK::API::Delegate::Respondable::Search delegateSearch(String username)  

/api/delegates/voters?publicKey=_pubKey  
 ARK::API::Delegate::Respondable::Voters delegateVoters(String publicKey)  

  
/api/delegates/get?username=sleepdeficit  
/api/delegates/get?publicKey=_pubKey  
 ARK::Delegate delegate(String parameter)  

/*  =================================================  */
// BROKEN: fix for large callbacks  
// Delegates callback is ~13,564 bytes  
//    /api/delegates  
//      String delegates()  
/*  =================================================  */

/api/delegates/fee  
 Balance delegateFee()  

/api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  
 ARK::API::Delegate::Respondable::ForgedByAccount delegateForgedByAccount(String generatorPublicKey)  

/api/delegates/getNextForgers  
 ARK::API::Delegate::Respondable::NextForgers delegateNextForgers()  

===================== /Delegates ====================  
```


```
====================== Loader =======================  

/api/loader/status  
 ARK::API::Loader::Respondable::Status loaderStatus()  

/api/loader/status/sync  
 ARK::API::Loader::Respondable::Sync loaderSync()  

/api/loader/autoconfigure  
 ARK::Network loaderAutoconfigure()  

======================= /Loader =====================  
```


```
================== MultiSignatures ==================  

/api/multisignatures/pending?publicKey=  
 String multisignaturesPending(String _publicKey)  

/*  =================================================  */
// Only on Mainnet?  
///api/multisignatures/accounts?publicKey=  
// String multisignaturesAccounts(String _publicKey)  
/*  =================================================  */


================== /MultiSignatures =================  
```

```
======================= Peer ========================  

/api/peers/get?ip=167.114.29.55&port=4002  
 ARK::Peer peer(String _ip, int _port)  

/*  =================================================  */
// BROKEN: fix for large callbacks  
// Peers callback is ~10,792 bytes  
//     /api/peers  
//      String peers()  
/*  =================================================  */

/api/peers/version  
 ARK::API::Peer::Respondable::Version peerVersion()  

======================= /Peer =======================  
```


```
==================== Signatures =====================  

/api/signatures/fee
 Balance signaturesFee()

=================== /Signatures =====================  
```


```
==================== Transaction ====================  

/api/transactions/get?id=  
 ARK::Transaction transaction(String _id)  

/*  =================================================  */
//  BROKEN: fix for large callbacks  
//  Peers callback is ~28,908 bytes  
//    /api/transactions  
//      String transactions()  
/*  =================================================  */

/api/transactions/unconfirmed/get?id=  
 String transactionUnconfirmed(String _id)  

/api/transactions/unconfirmed  
 String transactionsUnconfirmed()  
   
==================== /Transaction ===================  
```
