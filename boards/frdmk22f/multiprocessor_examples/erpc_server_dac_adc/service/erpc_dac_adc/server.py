#
# Generated by erpcgen 1.3.0 on Mon Sep  5 16:12:50 2016.
#
# AUTOGENERATED - DO NOT EDIT
#

import erpc
from . import common, interface

# Client for dac_adc
class dac_adcService(erpc.server.Service):
    def __init__(self, handler):
        super(dac_adcService, self).__init__(interface.Idac_adc.SERVICE_ID)
        self._handler = handler
        self._methods = {
                interface.Idac_adc.ADC_GET_CONFIG_ID : self._handle_adc_get_config,
                interface.Idac_adc.CONVERT_DAC_ADC_ID : self._handle_convert_dac_adc,
                interface.Idac_adc.SET_LED_ID : self._handle_set_led,
                interface.Idac_adc.INIT_MAG_ACCEL_ID : self._handle_init_mag_accel,
                interface.Idac_adc.READ_SENZOR_MAG_ACCEL_ID : self._handle_read_senzor_mag_accel,
                interface.Idac_adc.BOARD_GET_NAME_ID : self._handle_board_get_name,
            }

    def _handle_adc_get_config(self, sequence, inCodec, outCodec):
        # Create reference objects to pass into handler for out/inout parameters.
        config = erpc.Reference()

        # Read incoming parameters.
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.adc_get_config(config)

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.ADC_GET_CONFIG_ID,
            sequence=sequence))
        if config.value is None:
            raise ValueError("config is None")
        config.value._write(outCodec)
        outCodec.end_write_message()

    def _handle_convert_dac_adc(self, sequence, inCodec, outCodec):
        # Create reference objects to pass into handler for out/inout parameters.
        result = erpc.Reference()

        # Read incoming parameters.
        numberToConvert = inCodec.read_uint32()
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.convert_dac_adc(numberToConvert, result)

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.CONVERT_DAC_ADC_ID,
            sequence=sequence))
        if result.value is None:
            raise ValueError("result is None")
        outCodec.write_uint32(result.value)
        outCodec.end_write_message()

    def _handle_set_led(self, sequence, inCodec, outCodec):
        # Read incoming parameters.
        whichLed = inCodec.read_uint8()
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.set_led(whichLed)

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.SET_LED_ID,
            sequence=sequence))
        outCodec.end_write_message()

    def _handle_init_mag_accel(self, sequence, inCodec, outCodec):
        # Read incoming parameters.
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.init_mag_accel()

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.INIT_MAG_ACCEL_ID,
            sequence=sequence))
        outCodec.write_int32(_result)
        outCodec.end_write_message()

    def _handle_read_senzor_mag_accel(self, sequence, inCodec, outCodec):
        # Create reference objects to pass into handler for out/inout parameters.
        results = erpc.Reference()

        # Read incoming parameters.
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.read_senzor_mag_accel(results)

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.READ_SENZOR_MAG_ACCEL_ID,
            sequence=sequence))
        if results.value is None:
            raise ValueError("results is None")
        results.value._write(outCodec)
        outCodec.end_write_message()

    def _handle_board_get_name(self, sequence, inCodec, outCodec):
        # Create reference objects to pass into handler for out/inout parameters.
        name = erpc.Reference()

        # Read incoming parameters.
        inCodec.end_read_message()

        # Invoke user implementation of remote function.
        _result = self._handler.board_get_name(name)

        # Construct reply message.
        outCodec.start_write_message(erpc.codec.MessageInfo(
            type=erpc.codec.MessageType.kReplyMessage,
            service=interface.Idac_adc.SERVICE_ID,
            request=interface.Idac_adc.BOARD_GET_NAME_ID,
            sequence=sequence))
        if name.value is None:
            raise ValueError("name is None")
        outCodec.write_string(name.value)
        outCodec.end_write_message()


