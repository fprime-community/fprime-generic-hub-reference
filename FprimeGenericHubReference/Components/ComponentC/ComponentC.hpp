// ======================================================================
// \title  ComponentC.hpp
// \author shahab
// \brief  hpp file for ComponentC component implementation class
// ======================================================================

#ifndef FprimeGenericHubReference_ComponentC_HPP
#define FprimeGenericHubReference_ComponentC_HPP

#include "FprimeGenericHubReference/Components/ComponentC/ComponentCComponentAc.hpp"

namespace FprimeGenericHubReference {

class ComponentC final : public ComponentCComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ComponentC object
    ComponentC(const char* const compName  //!< The component name
    );

    //! Destroy ComponentC object
    ~ComponentC();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command TODO
    //!
    //! TODO
    void HubCommandTest_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq            //!< The command sequence number
                         ) override;
};

}  // namespace FprimeGenericHubReference

#endif
