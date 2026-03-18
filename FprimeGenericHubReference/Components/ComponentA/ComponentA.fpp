module FprimeGenericHubReference {
    @ Generic hub test component
    active component ComponentA {



        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @ TODO
        async command HubMessageTest(
                               msgNum: U32
                             ) 
            #opcode 0x5A00000

        #async command HUB_MESSAGE opcode 0x100000

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        #async command HUB_MESSAGE(param_name: U32)

        # @ Example telemetry counter
        telemetry GhCounter: U32

        telemetry verifyWord0: U32
        telemetry verifyWord1: U32

        # @ Example event
        event HubTest (count: U32) \
            severity activity low \
            id 1 \
            format "Command counter {} to test Generic Hub"

        event BufDataVerif ()  \
            severity activity low \
            id 2 \
            format "Depl-A to Depl-B round-trip buffer data; 2 words verified "

        event SerDataVerif ()  \
            severity activity low \
            id 3 \
            format "Depl-A to Depl-B round-trip serial data verified "

        event TlmDataVerif ()  \
            severity activity low \
            id 4 \
            format "Depl-A to Depl-B round-trip tlm data verified "

        event EvrDataVerif ()  \
            severity activity low \
            id 5 \
            format "Depl-A to Depl-B round-trip evr data verified "

        event SerDataVerifFail () \
            severity warning low \
            id 6 \
            format "Depl-A to Depl-B round-trip serial data verification FAILED "

        event EvrDataVerifFail () \
            severity warning low \
            id 7 \
            format "Depl-A to Depl-B round-trip evr data verification FAILED "

        event TlmDataVerifFail () \
            severity warning low \
            id 8 \
            format "Depl-A to Depl-B round-trip tlm data verification FAILED "

        event BufDataVerifFail () \
            severity warning low \
            id 9 \
            format "Depl-A to Depl-B round-trip buffer data verification FAILED "

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        output port opBuff: [2] Fw.BufferSend
        sync input port bufRet: [2] Fw.BufferSend

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        #@ Port for requesting the current time

        @ Enables command handling
        import Fw.Command

        @ Enables event handling
        import Fw.Event

        #@ Enables telemetry channels handling
        import Fw.Channel
        

        @ Time get port
        time get port timeCaller

        sync input port serIn: serial
        sync input port telemIn: Fw.Tlm
        sync input port eventIn: Fw.Log
        sync input port bufIn:   Fw.BufferSend
        output port bufInRet: Fw.BufferSend
        
        output port eventOut: Fw.Log
        output port telemOut: Fw.Tlm
        output port serOut: serial
    }
}


 