module FprimeGenericHubReference {
    @ Generic Hub Test
    passive component ComponentB {

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

    
        sync input port eventIn: Fw.Log
        sync input port telemIn: Fw.Tlm
        sync input port serIn: serial
        sync input port bufIn: Fw.BufferSend

        event BufInReceived(bufferSize: U32) \
            severity activity low \
            id 1 \
            format "Received buffer of size {} on bufIn"

        event SerInReceived(value: U32) \
            severity activity low \
            id 2 \
            format "Received {} on serIn"

        event EventInReceived(eventSize: U32) \
            severity activity low \
            id 3 \
            format "Received event of size {} on eventIn"

        event TelemInReceived(tlmSize: U32) \
            severity activity low \
            id 4 \
            format "Received telemetry of size {} on telemIn"

        output port bufInRet: Fw.BufferSend

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Enables event handling
        import Fw.Event

        @ Enables telemetry channels handling
        import Fw.Channel

        output port eventOut: Fw.Log
        output port telemOut: Fw.Tlm
        output port serOut: serial
        output port bufOut:  Fw.BufferSend
        sync input port bufRet: Fw.BufferSend

    }
}