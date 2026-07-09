// ======================================================================
// \title  ComponentB.cpp
// \author shahab
// \brief  cpp file for ComponentB component implementation class
// ======================================================================

#include "FprimeGenericHubReference/Components/ComponentB/ComponentB.hpp"
#include <Fw/Com/ComBuffer.hpp>

namespace FprimeGenericHubReference {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ComponentB ::ComponentB(const char* const compName) : ComponentBComponentBase(compName) {}

ComponentB ::~ComponentB() {}

  void ComponentB ::bufIn_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
      ) {

        this->log_ACTIVITY_LO_BufInReceived(static_cast<U32>(fwBuffer.getSize()));
        this->bufOut_out(0, fwBuffer);
      }

  void ComponentB ::send_serialData(U32 count) {
    Fw::ComBuffer serBuf;
    serBuf.resetSer();

    //Set serialization buffer for serOut
    serBuf.serializeFrom(count);
    this->serOut_out(0,serBuf);
  }


  void ComponentB ::serIn_handler(
          FwIndexType portNum, //!< The port number
          Fw::LinearBufferBase& serBuffer
      ) {
        
        U32 val; 

        serBuffer.deserializeTo(val);

        this->log_ACTIVITY_LO_SerInReceived(val);
        
        //Send data back to DeploymentA::ComponentA to verify
        this->send_serialData(val); 
  }

  //! Handler for input port eventIn
  void ComponentB ::eventIn_handler(
        FwIndexType portNum, //!< The port number
        FwEventIdType id, //!< Log ID
        Fw::Time& timeTag, //!< Time Tag
        const Fw::LogSeverity& severity, //!< The severity argument
        Fw::LogBuffer& args //!< Buffer containing serialized log entry
      ) {

        this->log_ACTIVITY_LO_EventInReceived(static_cast<U32>(args.getSize()));

        this->eventOut_out(0, id, timeTag, severity, args);
  }

  //! Handler for input port telemIn
  void ComponentB ::telemIn_handler(
        FwIndexType portNum, //!< The port number
        FwChanIdType id, //!< Telemetry Channel ID
        Fw::Time& timeTag, //!< Time Tag
        Fw::TlmBuffer& tlmBuf //!< Buffer containing serialized telemetry value
      ) {

        this->log_ACTIVITY_LO_TelemInReceived(static_cast<U32>(tlmBuf.getSize()));
        this->telemOut_out(0, id, timeTag, tlmBuf);

  }

  void ComponentB ::bufRet_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) {}



}  // namespace FprimeGenericHubReference
