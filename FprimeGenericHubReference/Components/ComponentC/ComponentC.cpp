// ======================================================================
// \title  ComponentC.cpp
// \author shahab
// \brief  cpp file for ComponentC component implementation class
// ======================================================================

#include "FprimeGenericHubReference/Components/ComponentC/ComponentC.hpp"

namespace FprimeGenericHubReference {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ComponentC ::ComponentC(const char* const compName) : ComponentCComponentBase(compName) {}

ComponentC ::~ComponentC() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void ComponentC ::HubCommandTest_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    this->log_ACTIVITY_LO_HubCommandTestEvr();
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace FprimeGenericHubReference
