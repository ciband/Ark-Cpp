

#ifndef MANAGER_H
#define MANAGER_H

#include "accountable/accountable.h"
#include "blockable/blockable.h"
#include "delegatable/delegatable.h"
#include "loadable/loadable.h"
#include "multisignaturable/multisignaturable.h"
#include "peerable/peerable.h"
#include "signaturable/signaturable.h"
#include "transactionable/transactionable.h"
#include "utilities/connector.h"

namespace ARK
{
namespace API
{
/*************************************************
*  ARK::API::Manager
**************************************************/
class Manager :
    public ARK::API::Accountable,
    public ARK::API::Blockable,
    public Delegatable,
    public Loadable,
    public MultiSignaturable,
    public Peerable,
    public Signaturable,
    public Transactionable,
    virtual ARK::Utilities::Network::Connectable
{

  public:
 /*************************************************
    *  ARK::API::Manager
    **************************************************/
    Manager();

/*************************************************
    *  ARK::API::Manager
    **************************************************/
    explicit Manager(const ARK::Network& network);

  private:
/*************************************************
    *  ARK::API::Manager::connect
    **************************************************/
    void connect(const ARK::Network& network);

};
/*  =================  */
/*  ==========================================================================  */

};
};


#endif
