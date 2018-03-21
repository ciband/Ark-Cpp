

#ifndef MULTISIGNATURABLE_H
#define MULTISIGNATURABLE_H

#include "api/multisignaturable/multisignature_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::MultiSignaturable
*   	public MultiSignature::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Multisignature Loader Model
* 
**************************************************/
class MultiSignaturable :
    public MultiSignature::Gettable,
    virtual ARK::Utilities::Network::Connectable
{
  public:
		/*************************************************
		*		/api/multisignatures/pending?publicKey=
		*
		*		@uri:	/api/multisignatures/pending?publicKey=
		*		@returnType:	const char*
		*
		*   @method:	multisignaturesPending(const Publickey& publicKey)
		*		@parameters:
		*			const Publickey& publicKey
		*
		*   @outs:	ARK::API::MultiSignature::Gettable::pending(this->netConnector, _publicKey)
		*
		*   @description:
		*			Gets Pending Multisignatures of
		*			Account by Publickey from a Node via API.
		* 
		**************************************************/
    String multisignaturesPending(const Publickey& publicKey)
    {
      return ARK::API::MultiSignature::Gettable::pending(this->netConnector, publicKey);
    };
    /*************************************************/

/**************************************************************************************************/

    /*************************************************/
    /*************************************************/
    // /*  Only on Mainnet?  */
    //     /*  /api/multisignatures/accounts?publicKey=  */
    //     String multisignaturesAccounts(String _publicKey)
    //     { return ARK::API::MultiSignature::Gettable::accounts(this->netConnector, _publicKey); };
    /*************************************************/
		/*************************************************/

};

// namespace multisignature_cb {
//   struct signResponse : virtual ARK::API::Helpers::Successable {};
//   struct addMultisignatureResponse : virtual ARK::API::Helpers::Successable {};
// };

};
};

#endif
