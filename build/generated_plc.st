PROGRAM main
  VAR
    Inclinacion AT %IX0.7 : BOOL := FALSE;
    LedVerde AT %QX0.6 : BOOL := TRUE;
    LedRojo AT %QX0.5 : BOOL := FALSE;
    Rele AT %QX0.4 : BOOL := FALSE;
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
