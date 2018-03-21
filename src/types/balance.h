

#ifndef BALANCE_H
#define BALANCE_H

#include <cstring>
#include <cctype>

/********************************************************************************
*
* Currently very verbose, needs bigint implementation using pow(10,8)
*
* Balance: 
*   arktoshi : "100000000"
*   ark : "1.00000000"
*   
*   Big Integer/Floating Point | 8-decimal places/pow(10,8)
*   
*   Currenty Block Supply total ~ 1.3e16 (12984403000000000:arktoshi)/(129844030.00000000:ark)
*
********************************************************************************/

/*************************************************
*   Balance
**************************************************/
class Balance {
private:
    static const auto ARKTOSHI_SIZE = 17 * sizeof(int);
    static const auto ARK_SIZE = ((18 * sizeof(char)) + sizeof(int));
    static const auto DECIMAL_PLACES = 8u;

    char arktoshi_[ARKTOSHI_SIZE];
    char ark_[ARK_SIZE];

public:
	Balance() : arktoshi_(), ark_()
	{
		this->setBalance("0");
	};

	explicit Balance(const char* const balanceStr) : arktoshi_(), ark_()
	{
		bool isNumeric = true;

		for (auto i = 0u; i < strlen(balanceStr); ++i) {
			if (!isdigit(balanceStr[i])) {
				isNumeric = false;
				break;
			}
		}
		if (isNumeric) {
			this->setBalance(balanceStr);
		}
	}

	Balance(const Balance& other) : arktoshi_(), ark_() {
		strcpy(arktoshi_, other.arktoshi_);
		strcpy(ark_, other.ark_);
	}
	Balance& operator=(const Balance& other) {
		if (this != &other) {
			strcpy(arktoshi_, other.arktoshi_);
			strcpy(ark_, other.ark_);
		}
		return *this;
	}

	Balance(Balance&& other) : arktoshi_(), ark_() {
		strcpy(arktoshi_, other.arktoshi_);
		strcpy(ark_, other.ark_);
		other.arktoshi_[0] = '\0';
		other.ark_[0] = '\0';
	}
	Balance& operator=(Balance&& other) {
		if (this != &other) {
			strcpy(arktoshi_, other.arktoshi_);
			strcpy(ark_, other.ark_);
			other.arktoshi_[0] = '\0';
			other.ark_[0] = '\0';
		}
		return *this;
	}


    const char* ark() const { return ark_; }
    const char* arktoshi() const { return arktoshi_; }

    void setArktoshi(const char* const balanceStr) {
        strncpy(arktoshi_, balanceStr, ARKTOSHI_SIZE);
    }

  void setArk(const char* const balanceStr)
  {
    const auto length = strlen(balanceStr);
    if (length < DECIMAL_PLACES) {
        ark_[0] = '.';
        const auto num_zero_pad = DECIMAL_PLACES - length;
        for (auto i = 1u; i <= num_zero_pad; ++i)
        {
            ark_[i] = '0';
        }
        for (auto i = 0u; i <= num_zero_pad + 1; ++i) 
        {
            ark_[i + num_zero_pad + 1] = balanceStr[i];
        }
    }
    else
    {
		// TODO: making i unsigned causes problems.  Potential array out of bounds but no investigation has been done.
        for (int i = static_cast<int>(length); i >= 0; --i)
        {
            if (i < static_cast<int>(length - DECIMAL_PLACES)) { this->ark_[i] = balanceStr[i]; }
            if (i == static_cast<int>(length - DECIMAL_PLACES)) { this->ark_[i] = '.'; }
            if (i > static_cast<int>(length - DECIMAL_PLACES) && i <= static_cast<int>(length)) { this->ark_[i] = balanceStr[i - 1]; }
        }
    }
  }

  void setBalance(const char* const _balanceStr)
  {
    if (strcmp(_balanceStr, "0") == 0)
    {
      this->arktoshi_[0] = '0';
      this->ark_[0] = '0';
    }
    else
    {
      this->setArktoshi(_balanceStr);
      this->setArk(_balanceStr);
    }
  }
};

#endif