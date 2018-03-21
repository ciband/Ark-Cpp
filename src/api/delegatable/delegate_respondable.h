

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

#include "types/address.h"
#include "types/publickey.h"
#include "types/balance.h"
#include "models/voter.h"
#include "utilities/platform.h"

#include <array>
#include <memory>

namespace ARK {
namespace API {
namespace Delegate {
namespace Respondable {


/*************************************************
*		ARK::API::Delegate::Respondable::Search
*
*		inherits:
*			const char* username;
*			Address address;
*			Publickey publicKey;
*			const Balance vote;
*			int producedblocks;
*			int missedblocks;
*
*   printTo(HardwareSerial &serial)
*
*   @brief:	Model for Delegate Search API Response
**************************************************/
class Search : public Printable {
private:
	char username_[64]; //TODO review sizes
	Address address_;
	Publickey publicKey_;
	Balance vote_;
	int producedblocks_;
	int missedblocks_;

public:
	Search(
		const char* const u, 
		const char* const a, 
		const char* const pk, 
		const char* const v, 
		int pb, 
		int mb
	) : username_(), address_(a), publicKey_(pk), vote_(v), producedblocks_(pb), missedblocks_(mb) {
		strncpy(username_, u, sizeof(username_) / sizeof(username_[0]));
	}

	const char* username() const noexcept { return username_; }
	const Address& address() const noexcept { return address_; }
	const Publickey& public_key() const noexcept { return publicKey_; }
	const Balance& vote() const noexcept { return vote_; }
	int produced_blocks() const noexcept { return producedblocks_; }
	int missed_blocks() const noexcept { return missedblocks_; }

	size_t printTo(Print& p) const override;
};
/*  =======================================  */
/*  ==========================================================================  */


/*************************************************
*		ARK::API::Delegate::Respondable::Voters
*
*		@param:	size_t, ARK::Voter* const
*
*   printTo(HardwareSerial &serial)
*		deconstuctor:	~Voters() { delete [] _voters; };
*		operators: 
*			Voter& operator[](size_t index)
*			Voter& operator[](size_t index)
*
*   @brief:	Model for Delegate Voters API Response
*
**************************************************/
class Voters : public Printable{
private:
    size_t count_;
    std::unique_ptr<ARK::Voter[]> voters_;

public:
    Voters(size_t c) : count_(c), voters_(new ARK::Voter[c]) { }

    const Voter& operator[](size_t index) const { return voters_.get()[index]; }
    Voter& operator[](size_t index) { return voters_.get()[index]; }

    size_t printTo(Print& p) const override;
};
/*  =========================================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==================================================  */
  /*  ARK::API::Delegate::Respondable::ForgedByAccount  */
class ForgedByAccount : public Printable {
private:
	Balance fees_;
	Balance rewards_;
	Balance forged_;

public:
	ForgedByAccount(
		const char* const f, 
		const char* const r, 
		const char* const fg
	) : fees_(f), rewards_(r), forged_(fg) { }

	const Balance& fees() const noexcept { return fees_; }
	const Balance& rewards() const noexcept { return rewards_; }
	const Balance& forged() const noexcept { return forged_; }

	size_t printTo(Print& p) const override;
};
/*  ==================================================  */
/*  ==========================================================================  */


/*************************************************
*		ARK::API::Delegate::Respondable::NextForgers
*
*		inherits: char[64], char[64], Publickey* const
*
*   printTo(HardwareSerial &serial)
*
*   @brief:	Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
class NextForgers : public Printable {
private:
	char currentBlock_[64];
	char currentSlot_[64];
	std::array<Publickey, 10> delegate_keys_;

public:
	NextForgers(const char* const _currentBlock, const char* const _currentSlot, const Publickey* const _delegates);

	const char* current_block() const noexcept { return currentBlock_; }
	const char* current_slot() const noexcept { return currentSlot_; }
	const std::array<Publickey, 10>& delegate_keys() const noexcept { return delegate_keys_; }

	size_t printTo(Print& p) const override;
};
/*  ==============================================  */
/*  ==========================================================================  */

}
}
}
}

#endif
