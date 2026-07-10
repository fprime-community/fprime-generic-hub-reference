// ======================================================================
// \title  ComponentB.cpp
// \author shahab
// \brief  cpp file for ComponentB component implementation class
// ======================================================================

#include "FprimeGenericHubReference/Components/ComponentB/ComponentB.hpp"
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Logger/Logger.hpp>

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

        Fw::Logger::log("Component B received buffer of size %u on bufIn\n",
                        static_cast<U32>(fwBuffer.getSize()));
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

        Fw::Logger::log("Component B received %u on serIn\n", val);
        
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

        Fw::Logger::log("Component B received event of size %u on eventIn\n",
                        static_cast<U32>(args.getSize()));

        this->eventOut_out(0, id, timeTag, severity, args);
  }

  //! Handler for input port telemIn
  void ComponentB ::telemIn_handler(
        FwIndexType portNum, //!< The port number
        FwChanIdType id, //!< Telemetry Channel ID
        Fw::Time& timeTag, //!< Time Tag
        Fw::TlmBuffer& tlmBuf //!< Buffer containing serialized telemetry value
      ) {

        Fw::Logger::log("Component B received telemetry of size %u on telemIn\n",
                        static_cast<U32>(tlmBuf.getSize()));
        this->telemOut_out(0, id, timeTag, tlmBuf);

  }

  void ComponentB ::bufRet_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) {}



}  // namespace FprimeGenericHubReference
