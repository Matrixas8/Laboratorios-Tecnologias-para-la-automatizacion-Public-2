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
  __INIT_LOCATED(BOOL,__QX0_0,data__->LEDV,retain)
  __INIT_LOCATED_VALUE(data__->LEDV,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->LEDR,retain)
  __INIT_LOCATED_VALUE(data__->LEDR,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->RELE,retain)
  __INIT_LOCATED_VALUE(data__->RELE,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_0,data__->INCLINACION,retain)
  __INIT_LOCATED_VALUE(data__->INCLINACION,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->V1,306,retain)
  __INIT_VAR(data__->V2,512,retain)
  __INIT_VAR(data__->V3,716,retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMER,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->_TMP_AND23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT11_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE8_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT3_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND6_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE18_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR28_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT38_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND34_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT41_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_AND23_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->E2,),
    (BOOL)__GET_LOCATED(data__->INCLINACION,)));
  __SET_LOCATED(data__->,LEDV,,__GET_VAR(data__->_TMP_AND23_OUT,));
  __SET_VAR(data__->,_TMP_LT11_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V1,)));
  __SET_VAR(data__->,E1,,__GET_VAR(data__->_TMP_LT11_OUT,));
  __SET_VAR(data__->,_TMP_GE8_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V1,)));
  __SET_VAR(data__->,_TMP_LT1_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V2,)));
  __SET_VAR(data__->,_TMP_AND17_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_GE8_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LT1_OUT,)));
  __SET_VAR(data__->,E2,,__GET_VAR(data__->_TMP_AND17_OUT,));
  __SET_VAR(data__->,_TMP_GE2_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V2,)));
  __SET_VAR(data__->,_TMP_LT3_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V3,)));
  __SET_VAR(data__->,_TMP_AND6_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_GE2_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LT3_OUT,)));
  __SET_VAR(data__->,E3,,__GET_VAR(data__->_TMP_AND6_OUT,));
  __SET_VAR(data__->,_TMP_GE18_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_LOCATED(data__->EJEX,),
    (INT)__GET_VAR(data__->V3,)));
  __SET_VAR(data__->,E4,,__GET_VAR(data__->_TMP_GE18_OUT,));
  __SET_VAR(data__->,_TMP_NOT40_OUT,,!(__GET_LOCATED(data__->INCLINACION,)));
  __SET_VAR(data__->,_TMP_OR28_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (BOOL)__GET_VAR(data__->E3,),
    (BOOL)__GET_VAR(data__->E4,),
    (BOOL)__GET_VAR(data__->_TMP_NOT40_OUT,)));
  __SET_LOCATED(data__->,LEDR,,__GET_VAR(data__->_TMP_OR28_OUT,));
  __SET_VAR(data__->,_TMP_AND39_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->E4,),
    (BOOL)__GET_VAR(data__->_TMP_NOT38_OUT,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_AND39_OUT,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TIMER,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,_TMP_NOT38_OUT,,!(__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->,_TMP_AND34_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT38_OUT,),
    (BOOL)__GET_LOCATED(data__->LEDR,)));
  __SET_LOCATED(data__->,LEDR,,__GET_VAR(data__->_TMP_AND34_OUT,));
  __SET_VAR(data__->,_TMP_NOT37_OUT,,!(__GET_VAR(data__->E4,)));
  __SET_LOCATED(data__->,RELE,,__GET_VAR(data__->_TMP_NOT37_OUT,));
  __SET_VAR(data__->,_TMP_NOT41_OUT,,!(__GET_LOCATED(data__->INCLINACION,)));
  __SET_LOCATED(data__->,RELE,,__GET_VAR(data__->_TMP_NOT41_OUT,));

  goto __end;

__end:
  return;
} // MAIN_body__() 





