(*[[
    UserText1= "mb_rtu_get_serial_mode",
    UserHelpURL= "ATCMfile:MODBUS_RTU_GET_SERIAL_MODE.HTML",
]]*)
FUNCTION MODBUS_RTU_GET_SERIAL_MODE : UINT
VAR_OUTPUT
    mode : UINT; (*[mode]*)
END_VAR
INLINE {STDLIB(MODBUS_RTU_GET_SERIAL_MODE)}
END_FUNCTION