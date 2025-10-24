TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM main
  VAR
    Inclinacion : BOOL := FALSE;
    LedVerde : BOOL := TRUE;
    LedRojo : BOOL := FALSE;
    Rele : BOOL := FALSE;
  END_VAR
  VAR
    PWM_CONTROLLER0 : PWM_CONTROLLER;
    ServoEneble : BOOL := FALSE;
    ServoChannel : SINT := 3;
    ServoFreq : REAL := 50.0;
    ServoDuty : REAL := 5.0;
    _TMP_NOT14_OUT : BOOL;
  END_VAR

  LedRojo := Inclinacion;
  _TMP_NOT14_OUT := NOT(Inclinacion);
  LedVerde := _TMP_NOT14_OUT;
  Rele := Inclinacion;
  PWM_CONTROLLER0(EN := Inclinacion, CHANNEL := ServoChannel, FREQ := ServoFreq, DUTY := ServoDuty);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
