

#ifndef CURRENCIES_H
#define CURRENCIES_H

namespace ARK
{
namespace Constants
{
namespace Currencies
{

  namespace Crypto
  {
    const ARK::Model::Currency ARK = { "ARK", "Ark", "Ѧ" };
    const ARK::Model::Currency BTC = { "BTC", "Bitcoin", "฿" };
  };

  namespace Fiat
  {
    const ARK::Model::Currency USD = { "USD", "United States Dollar", "$" };
    const ARK::Model::Currency EUR  ={ "EUR", "Euro", "€" };
    const ARK::Model::Currency GBT = { "GBP", "British Pound", "£" };
  };

};
};
};

#endif
