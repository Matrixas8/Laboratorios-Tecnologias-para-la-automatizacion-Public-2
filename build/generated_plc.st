PROGRAM main
  VAR
    ejex AT %IW1 : INT;
    SalidaPWM AT %QW0 : INT;
    IN2 AT %QW1 : INT := 16;
  END_VAR
  VAR
    Escalado : INT;
    _TMP_MUL1_OUT : INT;
    _TMP_MOVE5_OUT : INT;
  END_VAR

  _TMP_MUL1_OUT := MUL(ejex, IN2);
  Escalado := _TMP_MUL1_OUT;
  _TMP_MOVE5_OUT := MOVE(Escalado);
  SalidaPWM := _TMP_MOVE5_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
