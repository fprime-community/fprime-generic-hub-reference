// ======================================================================
// \title  ComponentB.hpp
// \author shahab
// \brief  hpp file for ComponentB component implementation class
// ======================================================================

#ifndef FprimeGenericHubReference_ComponentB_HPP
#define FprimeGenericHubReference_ComponentB_HPP

#include "FprimeGenericHubReference/Components/ComponentB/ComponentBComponentAc.hpp"

namespace FprimeGenericHubReference {

class ComponentB final : public ComponentBComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ComponentB object
    ComponentB(const char* const compName  //!< The component name
    );

    //! Destroy ComponentB object
    ~ComponentB();

  private:
  
    void bufRet_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) override;

    void send_serialData(U32 count);

    void bufIn_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) override;

    void serIn_handler(
          FwIndexType portNum, //!< The port number
          Fw::LinearBufferBase& serBuffer
    ) override; 

    //! Handler for input port eventIn
    void eventIn_handler(
          FwIndexType portNum, //!< The port number
          FwEventIdType id, //!< Log ID
          Fw::Time& timeTag, //!< Time Tag
          const Fw::LogSeverity& severity, //!< The severity argument
          Fw::LogBuffer& args //!< Buffer containing serialized log entry
    ) override;

    //! Handler for input port telemIn
    void telemIn_handler(
          FwIndexType portNum, //!< The port number
          FwChanIdType id, //!< Telemetry Channel ID
          Fw::Time& timeTag, //!< Time Tag
          Fw::TlmBuffer& tlmBuf //!< Buffer containing serialized telemetry value
    ) override;

  };

}  // namespace FprimeGenericHubReference

#endif
