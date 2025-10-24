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
  __INIT_VAR(data__->INCLINACION,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEDVERDE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LEDROJO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELE,__BOOL_LITERAL(FALSE),retain)
  PWM_CONTROLLER_init__(&data__->PWM_CONTROLLER0,retain);
  __INIT_VAR(data__->SERVOENEBLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SERVOCHANNEL,3,retain)
  __INIT_VAR(data__->SERVOFREQ,50.0,retain)
  __INIT_VAR(data__->SERVODUTY,5.0,retain)
  __INIT_VAR(data__->_TMP_NOT14_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,LEDROJO,,__GET_VAR(data__->INCLINACION,));
  __SET_VAR(data__->,_TMP_NOT14_OUT,,!(__GET_VAR(data__->INCLINACION,)));
  __SET_VAR(data__->,LEDVERDE,,__GET_VAR(data__->_TMP_NOT14_OUT,));
  __SET_VAR(data__->,RELE,,__GET_VAR(data__->INCLINACION,));
  __SET_VAR(data__->PWM_CONTROLLER0.,EN,,__GET_VAR(data__->INCLINACION,));
  __SET_VAR(data__->PWM_CONTROLLER0.,CHANNEL,,__GET_VAR(data__->SERVOCHANNEL,));
  __SET_VAR(data__->PWM_CONTROLLER0.,FREQ,,__GET_VAR(data__->SERVOFREQ,));
  __SET_VAR(data__->PWM_CONTROLLER0.,DUTY,,__GET_VAR(data__->SERVODUTY,));
  PWM_CONTROLLER_body__(&data__->PWM_CONTROLLER0);

  goto __end;

__end:
  return;
} // MAIN_body__() 





