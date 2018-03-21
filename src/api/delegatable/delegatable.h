

#ifndef DELEGATABLE_H
#define DELEGATABLE_H

#include "api/delegatable/delegate_respondable.h"
#include "api/delegatable/delegate_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Delegatable
*   	public API::Delegate::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Delegate Model
* 
**************************************************/
class Delegatable :
		public Delegate::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*		/api/delegates/count
		*
		*		@uri:	/api/delegates/count
		*		@returnType:	int
		*
		*   @method:	delegatesCount()
		*
		*   @outs:	ARK::API::Delegate::Gettable::count(this->netConnector)
		*
		*   @description:
		*			Gets current number of registered
		*			Delegates from a Node via API.
		* 
		**************************************************/
		int delegatesCount()
		{
			return ARK::API::Delegate::Gettable::count(this->netConnector);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/delegates/search?q=sleepdeficit 
		*
		*		@uri:	/api/delegates/search?q=sleepdeficit 
		*		@returnType:	ARK::API::Delegate::Respondable::Search
		*
		*   @method:	delegateSearch(const char* const username)
		*		@parameters:
		*			const char* const username
		*
		*   @outs:	ARK::API::Delegate::Gettable::search(this->netConnector, username)
		*
		*   @description:
		*			Searches for Delegate by username
		*			from a Node via API.
		* 
		**************************************************/
		ARK::API::Delegate::Respondable::Search delegateSearch(const char* const username)
		{
			return ARK::API::Delegate::Gettable::search(this->netConnector, username);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/delegates/voters?publicKey=_pubKey
		*
		*		@uri:	/api/delegates/voters?publicKey=_pubKey
		*		@returnType:	ARK::API::Delegate::Respondable::Voters
		*
		*   @method:	delegateVoters(const Publickey& publicKey)
		*		@parameters:
		*			const Publickey& publicKey
		*
		*   @outs:	ARK::API::Delegate::Gettable::voters(this->netConnector, publicKey)
		*
		*   @description:
		*			Returns Voters list for Delegate by Publickey
		*			from a Node via API.
		* 
		**************************************************/
		ARK::API::Delegate::Respondable::Voters delegateVoters(const Publickey& publicKey)
		{
			return ARK::API::Delegate::Gettable::voters(this->netConnector, publicKey);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/delegates/get?username=sleepdeficit
		*
		*		@uri:	/api/delegates/get?username=sleepdeficit
		*		@returnType:	ARK::API::Delegate::Respondable::Voters
		*
		*   @method:	delegate(const char* const parameter)
		*		@parameters:
		*			const char* const parameter
		*
		*   @outs:	ARK::API::Delegate::Gettable::delegate(this->netConnector, parameter)
		*
		*   @description:
		*			Returns Delegate by username
		*			from a Node via API.
		* 
		**************************************************/
		ARK::Delegate delegate(const char* const parameter)
		{
			return ARK::API::Delegate::Gettable::delegate(this->netConnector, parameter);
		};

		/*************************************************
		*		/api/delegates/get?publicKey=_pubKey
		*
		*		@uri:	/api/delegates/get?publicKey=_pubKey
		*		@returnType:	ARK::API::Delegate::Respondable::Voters
		*
		*   @method:	delegate(const Publickey& publicKey)
		*		@parameters:
		*			const Publickey& publicKey
		*
		*   @outs:	ARK::API::Delegate::Gettable::delegate(this->netConnector, publicKey.getValue())
		*
		*   @description:
		*			Returns Delegate by username
		*			from a Node via API.
		* 
		**************************************************/
		ARK::Delegate delegate(const Publickey& publicKey)
		{
			return ARK::API::Delegate::Gettable::delegate(this->netConnector, publicKey.getValue());
		};
    /*************************************************/


/**************************************************************************************************/


    /*************************************************/
    /*************************************************/
		/*    BROKEN: fix for large callbacks    */
		/*  Delegates callback is ~13,564 bytes  */
		/*  /api/delegates  */
		/*************************************************
    * /api/blocks/get?id=_blockID
    **************************************************/
		// String getDelegates()
		// { return ARK::API::DelegateGettable::delegates(this->netConnector); }; 
		// /*  =====================  */
		// /*  ARK::DelegateResponse  */
		// struct DelegatesResponse
		// {
		// public:
		// 	int count;
		// 	ARK::Delegate list[5]; // = {{}};
		// 	DelegatesResponse(int);
		// 	String description();
		// };
		// /*  =====================  */
		/*  =============  */
		/*  ARK::DelegatesResponse  */
		/*  Constructor  */
		// ARK::DelegatesResponse::DelegatesResponse(int _count)
		// {
		//         this->count = _count;
		// }
		/*  =====  */
		/*  Description  */
		// String ARK::DelegatesResponse::DelegatesResponse::description()
		// {
		//		String resp;
		//		if (this->count > 0)
		//		{
		//			for (int i = 0; i < this->count; i++)
		//			{
		//				resp += "\ndelegate ";
		//				resp += i + 1;
		//				resp += ":\n";
		//				resp += this->list[i].description();
		//				resp += "\n";
		//			};
		//		};
		//		return resp;
		// }
    /*************************************************/
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/delegates/fee
		*
		*		@uri:	/api/delegates/fee
		*		@returnType:	Balance
		*
		*   @method:	delegateFee()
		*
		*   @outs:	ARK::API::Delegate::Gettable::fee(this->netConnector)
		*
		*   @description:
		*			Returns Delegate Registration Fee
		*			from a Node via API.
		* 
		**************************************************/
		Balance delegateFee()
		{
			return ARK::API::Delegate::Gettable::fee(this->netConnector);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*		/api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
		*
		*		@uri:	/api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
		*		@returnType:	ARK::API::Delegate::Respondable::ForgedByAccount
		*
		*   @method:	delegateForgedByAccount(const Publickey& generatorPublicKey)
		*		@parameters:
		*			const Publickey& generatorPublicKey
		*
		*   @outs:	ARK::API::Delegate::Gettable::forgedByAccount(this->netConnector, generatorPublicKey)
		*
		*   @description:
		*			Returns Totals of Amounts Forged by Delegate by Publickey
		*			from a Node via API.
		* 
		**************************************************/
		ARK::API::Delegate::Respondable::ForgedByAccount delegateForgedByAccount(const Publickey& generatorPublicKey)
		{
			return ARK::API::Delegate::Gettable::forgedByAccount(this->netConnector, generatorPublicKey);
		};
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
    * /api/delegates/getNextForgers
    **************************************************/
		/*************************************************
		*		/api/delegates/getNextForgers
		*
		*		@uri:	/api/delegates/getNextForgers
		*		@returnType:	ARK::API::Delegate::Respondable::NextForgers
		*
		*   @method:	delegateNextForgers()
		*
		*   @outs:	ARK::API::Delegate::Gettable::nextForgers(this->netConnector)
		*
		*   @description:
		*			Returns next 10 Forging-Delegates
		*			from a Node via API.
		* 
		**************************************************/
		ARK::API::Delegate::Respondable::NextForgers delegateNextForgers()
		{
			return ARK::API::Delegate::Gettable::nextForgers(this->netConnector);
		};
    /*************************************************/

};
/*************************************************/

// namespace Delegate {
//   namespace delegates_cb {
//     struct addDelegateResponse : virtual ARK::API::Helpers::Successable {};
//     struct enableForgingResponse : virtual ARK::API::Helpers::Successable {};
//     struct disableForgingResponse : virtual ARK::API::Helpers::Successable {};
//   };
// };

};
};


#endif
