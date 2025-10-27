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
    ejex AT %IW1 : INT;
    LedV AT %QX0.0 : BOOL;
    LedR AT %QX0.1 : BOOL;
    Rele AT %QX0.2 : BOOL := TRUE;
    Inclinacion AT %IX0.0 : BOOL;
  END_VAR
  VAR
    V1 : INT := 306;
    V2 : INT := 512;
    V3 : INT := 716;
    E1 : BOOL := FALSE;
    E2 : BOOL := FALSE;
    E3 : BOOL := FALSE;
    E4 : BOOL := FALSE;
    Timer : TIME := T#500ms;
    TON0 : TON;
    _TMP_AND23_OUT : BOOL;
    _TMP_LT11_OUT : BOOL;
    _TMP_GE8_OUT : BOOL;
    _TMP_LT1_OUT : BOOL;
    _TMP_AND17_OUT : BOOL;
    _TMP_GE2_OUT : BOOL;
    _TMP_LT3_OUT : BOOL;
    _TMP_AND6_OUT : BOOL;
    _TMP_GE18_OUT : BOOL;
    _TMP_NOT40_OUT : BOOL;
    _TMP_OR28_OUT : BOOL;
    _TMP_AND39_OUT : BOOL;
    _TMP_NOT38_OUT : BOOL;
    _TMP_AND34_OUT : BOOL;
  END_VAR

  _TMP_AND23_OUT := AND(E2, Inclinacion);
  LedV := _TMP_AND23_OUT;
  _TMP_LT11_OUT := LT(ejex, V1);
  E1 := _TMP_LT11_OUT;
  _TMP_GE8_OUT := GE(ejex, V1);
  _TMP_LT1_OUT := LT(ejex, V2);
  _TMP_AND17_OUT := AND(_TMP_GE8_OUT, _TMP_LT1_OUT);
  E2 := _TMP_AND17_OUT;
  _TMP_GE2_OUT := GE(ejex, V2);
  _TMP_LT3_OUT := LT(ejex, V3);
  _TMP_AND6_OUT := AND(_TMP_GE2_OUT, _TMP_LT3_OUT);
  E3 := _TMP_AND6_OUT;
  _TMP_GE18_OUT := GE(ejex, V3);
  E4 := _TMP_GE18_OUT;
  _TMP_NOT40_OUT := NOT(Inclinacion);
  _TMP_OR28_OUT := OR(E3, E4, _TMP_NOT40_OUT);
  LedR := _TMP_OR28_OUT;
  _TMP_AND39_OUT := AND(E4, _TMP_NOT38_OUT);
  TON0(IN := _TMP_AND39_OUT, PT := Timer);
  _TMP_NOT38_OUT := NOT(TON0.Q);
  _TMP_AND34_OUT := AND(_TMP_NOT38_OUT, LedR);
  LedR := _TMP_AND34_OUT;
  Rele := E4;
  Rele := Inclinacion;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
