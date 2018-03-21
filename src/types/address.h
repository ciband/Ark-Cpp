

#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring>

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/

#define ADDRESS_SIZE 35

class address_t {
private:
	static const auto ADDRESS_LENGTH = ADDRESS_SIZE / sizeof(char);
	char value_[ADDRESS_LENGTH];

public:
    address_t() : value_() { };

	address_t(const char* const addressString) : value_()
	{
        strncpy(value_, addressString, ADDRESS_LENGTH);
	}

	const char* getValue() const { return value_; }
};

/*************************************************
*   Address
**************************************************/
typedef address_t Address;

#endif