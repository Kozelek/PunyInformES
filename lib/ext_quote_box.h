! ext_quote_box.h, una extensión de la librería PunyInformES por Fredrik Ramsberg.
!
! Esta es una extensión que permite a los juegos mostrar una caja con una cita.
! Para los juegos de z5+, la extensión intentará centrar la cita en la pantalla,
! leyendo el ancho de pantalla proporcionado por el intérprete en la cabecera.
! Para z3, esta información no existe. En lugar de eso, lo hará de dos modos:
! 1: El programador del juego hace asumir a la extensión que la pantalla tiene un
!      cierto ancho y la extensión usa esta información para centrar la cita.
! 2: El programador del juego dice a la extensión que indente la caja de la cita
!      un número fijo de caracteres.

! Para usar (1), indica en la constante QUOTE_V3_SCREEN_WIDTH el ancho deseado,
! que debe ser > 6.

! Para usar (2), pon en la constante QUOTE_V3_SCREEN_WIDTH el número deseado de
! caracteres con los que indentar, que debe estar en el rango 0-6.

! Por defecto, el método (2) será usado, con 2 caracteres de indentación.

! Para mostrar la caja de cita, crea un array de palabras que guarde el número de
! líneas, el número de caracteres en la línea más larga y una cadena por línea, y
! llama a QuoteBox con el nombre del array como argumento.

! Array cita_1 static --> 5 32
! "Cuando muera, quiero irme en paz"
! "mientras duermo como mi abuelo."
! "No gritando de terror, como los"
! "pasajeros en un coche."
! "               -- Jack Handey";
!
! [CualquierRutina;
!   QuoteBox(cita_1);
! ];

System_file;

#IfnDef RUNTIME_ERRORS;
Constant RUNTIME_ERRORS = 2;
#EndIf;
#IfnDef RTE_MINIMUM;
Constant RTE_MINIMUM = 0;
Constant RTE_NORMAL = 1;
Constant RTE_VERBOSE = 2;
#EndIf;

Constant QUOTE_MAX_LENGTH = 80;

Default QUOTE_V3_SCREEN_WIDTH = 2;

#Iftrue	QUOTE_V3_SCREEN_WIDTH == 6;
Constant QUOTE_INDENT_STRING = "      ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 5;
Constant QUOTE_INDENT_STRING = "     ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 4;
Constant QUOTE_INDENT_STRING = "    ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 3;
Constant QUOTE_INDENT_STRING = "   ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 2;
Constant QUOTE_INDENT_STRING = "  ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 1;
Constant QUOTE_INDENT_STRING = " ";
#EndIf;
#Iftrue	QUOTE_V3_SCREEN_WIDTH == 0;
Constant QUOTE_INDENT_STRING = "";
#EndIf;

Array quote_buffer -> QUOTE_MAX_LENGTH + 3;

[ QuoteBox p_quote_data _quote_lines _quote_width _screen_width _i _j _k _last_index;
	_quote_lines = p_quote_data --> 0;
	_quote_width = p_quote_data --> 1;
#IfV5;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(_quote_width > QUOTE_MAX_LENGTH) {
		"ERROR: quote_box: ¡Intentó escribir una cita más ancha de ", QUOTE_MAX_LENGTH, " caracteres!^";
	}
#IfNot;
	if(_quote_width > QUOTE_MAX_LENGTH) {
		"ERROR: quote_box #1!^"; 
	}
#EndIf;
#EndIf;
	_screen_width = 0->$21;
	_i = _quote_lines + 4;
	@erase_window -2;
	@split_window _i;
	@set_window 1;
!	@erase_window 1;
#IfNot;
	_screen_width = QUOTE_V3_SCREEN_WIDTH;
#EndIf;
	@new_line;
	@new_line;
	_last_index = 2 + _quote_lines;
	for(_i = 1 : _i <= _last_index : _i++) {
#IfDef QUOTE_INDENT_STRING;
		print (string) QUOTE_INDENT_STRING;
#IfNot;
		for(_j = (_screen_width - _quote_width - 2) / 2 : _j > 0: _j--) @print_char ' ';
#EndIf;
		_k =  p_quote_data-->_i;
		if(_i == 1 or _last_index) {
			_k = "";
#IfV3;
			for(_j = -2 : _j < _quote_width: _j++) @print_char '-';
#EndIf;
		} else 
			_k =  p_quote_data-->_i;
#IfV5;
		style reverse;
#EndIf;
		@print_char ' ';
		print (string) _k;
#IfV5;
		@output_stream 3 quote_buffer;
		print (string) _k;
		@output_stream -3;
		for(_j = quote_buffer->1: _j < _quote_width + 1 : _j++) @print_char ' ';
		style roman;
#EndIf;
		@new_line;
	}
	
!	print (string) p_line_1;
!	@new_line;
#IfV5;
	@set_window 0;
!	print "[Pulsa una tecla para continuar]";
	@read_char _i;
!	@split_window 0;
	@erase_window -1;
#IfNot;
	@new_line;
!	print "[ENTER]";
	quote_buffer -> 0 = 0;
	read quote_buffer quote_buffer;
#EndIf;
!	" Ok.";
];

