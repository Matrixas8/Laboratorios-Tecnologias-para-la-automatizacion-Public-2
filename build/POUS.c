void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_LOCATED(INT,__IW1,data__->EJEX,retain)
  __INIT_LOCATED_VALUE(data__->EJEX,0)
  __INIT_LOCATED(INT,__QW0,data__->SALIDAPWM,retain)
  __INIT_LOCATED_VALUE(data__->SALIDAPWM,0)
  __INIT_LOCATED(INT,__QW1,data__->IN2,retain)
  __INIT_LOCATED_VALUE(data__->IN2,16)
  __INIT_VAR(data__->ESCALADO,0,retain)
  __INIT_VAR(data__->_TMP_MUL1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE5_OUT,0,retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_MUL1_OUT,,MUL__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_LOCATED(data__->IN2,)));
  __SET_VAR(data__->,ESCALADO,,__GET_VAR(data__->_TMP_MUL1_OUT,));
  __SET_VAR(data__->,_TMP_MOVE5_OUT,,MOVE__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->ESCALADO,)));
  __SET_LOCATED(data__->,SALIDAPWM,,__GET_VAR(data__->_TMP_MOVE5_OUT,));

  goto __end;

__end:
  return;
} // MAIN_body__() 





