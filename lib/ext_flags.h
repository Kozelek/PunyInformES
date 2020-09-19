! ext_flags.h, una extensión de librería para PunyInform de Fredrik Ramsberg, adaptada
! de flags.h de Adam Cadre.

! Este es un sistema sencillo para proporcionar banderas on/off que solo ocupen un bit de
! memoria; por tanto, no hay necesidad de malgastar memoria (y variables globales) declarando
! una variable como "banderahecho" o algo así, que necesita dieciséis bits para un valor que
! nunca será distinto de 0 o 1.

! Así es como debes usarla en tus programas. Tras incluir globals.h, pon el valor a FLAG_COUNT
! del número de banderas que necesitas, y luego incluye ext_flags.h.
!
! Cuando comiences a usar una nueva bandera, créate una constante con un nombre descriptivo.
! También puedes añadir un comentario, o tener una lista cerca con el significado de cada
! bandera.

! Constant F_LORO_ALIMENTADO 0; ! ¿Ha sido alimentado el loro?
! Constant F_BILLETE_OK 1;       ! ¿Ha reservado su billete de avión Hildegard con la tarjeta de crédito correcta?
! Constant F_GATO_SALVADO 2;    ! ¿Ha salvado el jugador al gato del árbol?

! Ya te haces una idea. Fíjate en que la primera bandera es la #0.

! Poner una bandera encendida o apagada se hace llamando a la rutina SetFlag(bandera#) o
! ClearFlag(bandera#), que encienden o apagan una bandera respectivamente. Para indicar que el
! jugador ha salvado al gato, haz "SetFlag(F_GATO_SALVADO);", y para apagar esa bandera, haz
! "ClearFlag(F_GATO_SALVADO);"  (Menos las comillas, claro.)

! Probar una bandera se logra llamando a FlagIsSet o FlagIsClear. Así que si tienes un código
! que solo debería ejecutarse si has alimentado al loro, deberías rodearlo de una instruccion
! "if (FlagIsSet(F_LORO_ALIMENTADO)) { ... }"
! Naturalmente, puedes probar si una bandera está apagada usando FlagIsClear.

System_file;

Array flag_powers static ->
	$$00000001
	$$00000010
	$$00000100
	$$00001000
	$$00010000
	$$00100000
	$$01000000
	$$10000000;

Array game_flags -> FLAG_COUNT / 8 + (FLAG_COUNT & 7 > 0);

[ SetFlag p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	game_flags -> _y = game_flags -> _y | flag_powers -> (p_x & 7);
];

[ ClearFlag p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	game_flags -> _y = game_flags -> _y & ~ flag_powers -> (p_x & 7);
];

[ FlagIsSet p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	return (game_flags -> _y & flag_powers -> (p_x & 7) > 0);
];

[ FlagIsClear p_x _y;
#IfV5;
	@log_shift p_x (-3) -> _y;
#IfNot;
	_y = p_x / 8;
#EndIf;
	return (game_flags -> _y & flag_powers -> (p_x & 7) == 0);
];
