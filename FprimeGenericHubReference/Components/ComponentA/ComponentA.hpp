// ======================================================================
// \title  ComponentA.hpp
// \author shahab
// \brief  hpp file for ComponentA component implementation class
// ======================================================================

#ifndef FprimeGenericHubReference_ComponentA_HPP
#define FprimeGenericHubReference_ComponentA_HPP

#include "FprimeGenericHubReference/Components/ComponentA/ComponentAComponentAc.hpp"

namespace FprimeGenericHubReference {

class ComponentA final : public ComponentAComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ComponentA object
    ComponentA(const char* const compName  //!< The component name
    );

    //! Destroy ComponentA object
    ~ComponentA();


  private: 
    void bufRet_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) override;
  
  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    void serIn_handler(
        FwIndexType portNum, //!< The port number
        Fw::LinearBufferBase& serBuffer
    ) override; 

    void telemIn_handler(
        FwIndexType portNum, //!< The port number
        FwChanIdType id, //!< Telemetry Channel ID
        Fw::Time& timeTag, //!< Time Tag
        Fw::TlmBuffer& tlmBuf //!< Buffer containing serialized telemetry value
    ) override; 

    void eventIn_handler(
          FwIndexType portNum, //!< The port number
          FwEventIdType id, //!< Log ID
          Fw::Time& timeTag, //!< Time Tag
          const Fw::LogSeverity& severity, //!< The severity argument
          Fw::LogBuffer& args //!< Buffer containing serialized log entry
    ) override;

    void bufIn_handler(
          FwIndexType portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
    ) override;

    //! Handler implementation for command TODO
    //!
    //! TODO
    void HubMessageTest_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq, U32 msgNum      //!< The command sequence number
    ) override;

                             //! Buffer for testing
    Fw::Buffer m_buffer;

    void send_serialData();
    void send_tlm(U32 count);
    void send_buffer();
    void send_event(U32 count);

    //! Storage for buffer data
    U8 m_data_store[5000];

    U32 m_ghCounter;
    Fw::Time tlmTime;
    Fw::Time evrTime;

    FwChanIdType tlmId;
    FwChanIdType evrId; 
};

}  // namespace FprimeGenericHubReference

#endif
