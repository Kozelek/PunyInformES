! ext_cheap_scenery.h, una extensión de la librería PunyInformES, por Fredrik Ramsberg
!
! Esta extensión de la librería permite implementar objetos de escenario sencillos
! que solo pueden ser examinados, usando solo un único objeto para todo el juego.
! Esto permite reducir tanto el número de objetos como la memória dinámica.
!
! Para usarlo, incluye este fichero tras globals.h. Luego añade una propiedad
! cheap_scenery a la localidad donde quieras añadir los objetos de escenario 'baratos'.
! Puedes añadir hasta diez objetos de escenario baratos a una localidad de este modo.
! Para cada objeto de escenario especifica, en este orden, un adjetivo, un nombre y una
! cadena de texto (string) descriptiva o una rutina que la escriba. En lugar de un
! adjetivo, puedes darle un sinónimo al nombre. Si no se necesita adjetivo o sinónimo,
! usa el valor 1 en esa posición.
! 
! Nota: Si quieres usar esta extensión de librería en un juego de máquina Z versión 3,
! NO debes declarar cheap_scenery como una propiedad común, o solo podrá tener un objeto
! de escenario en lugar de diez.
!
! Si quieres usar la misma descripción para un objeto de escenario en varias localidades,
! declara una constante que tenga esa cadena de texto, y refiere la constante en cada
! localidad.
!
! Antes de incluir esta extensión, puedes definir también una cadena o rutina llamada
! SceneryReply. Si lo haces, se usará siempre que el jugador haga algo a un objeto de
! escenario en lugar de examinarlo. Si es una cadena, se muestra. Si es una rutina, se
! ejecuta. Si la rutina imprime algo, debe devolver verdadero (true), en caso contrario
! devolverá falso (false).
!
! Ejemplo de uso:

! [SceneryReply;
!   Push:
!     "¿Cómo pretendes hacer eso?";
!   default:
!     rfalse;
! ];
!
! Include "ext_cheap_scenery.h";
!
! Constant SCN_AGUA = "El agua es tan hermosa en esta época del año, tan clara y brillante.";
! [SCN_SOL;
!   deadflag = 1;
!   "Al mirar directamente al sol, sientes una quemazón en los ojos. Tras un rato, todo se
        oscurece. Sin poder ver, tienes pocas posibilidades de completar tu investigación.";
! ];
!
! Object RiverBank "Orilla del río"
!   with
!	 description "El río es bastante ancho por aquí. El sol refleja el agua azul, los
        pájaros vuelan en las alturas.",
!	 cheap_scenery
!      'azul' 'agua' SCN_AGUA
!      'pajaro' 'pajaros' "Parecen no tener ninguna preocupación."
!      1 'sun' SCN_SOL,
!   has light;


System_file;

#IfnDef RUNTIME_ERRORS;
Constant RUNTIME_ERRORS = 2;
#EndIf;
#IfnDef RTE_MINIMUM;
Constant RTE_MINIMUM = 0;
Constant RTE_NORMAL = 1;
Constant RTE_VERBOSE = 2;
#EndIf;

Object CheapScenery "objeto"
	with
		article "un",
		number 0,
		parse_name [ _w1 _w2 _i _sw1 _sw2 _len;
			_w1 = NextWordStopped();
			_w2 = NextWordStopped();
			_i = 0;
			_len = location.#cheap_scenery / 2;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
			if(_len % 3 > 0)
				"ERROR: ¡La propiedad cheap_scenery de la localidad actual tiene un # incorrecto de valores!^";
#IfNot;
			if(_len % 3 > 0)
				"ERROR: cheap_scenery #1!^";
#EndIf;
			while(_i < _len) {
				_sw1 = location.&cheap_scenery-->(_i+2);
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
				if(~~(_sw1 ofclass String or Routine))
					"ERROR: ¡Elemento ", _i+2, " en la propiedad cheap_scenery de la localidad actual no es un string o rutina!^",
						"Elemento: ", (name) _sw1, "^";
#IfNot;
				if(~~(_sw1 ofclass String or Routine))
					"ERROR: cheap_scenery #2!^";
#EndIf;

				_i = _i + 3;
			}
			_i = 0;
#endif;
			while(_i < _len) {
				_sw1 = location.&cheap_scenery-->_i;
				_sw2 = location.&cheap_scenery-->(_i+1);
				if(_w1 == _sw1 && _w2 == _sw2) {
					self.number = _i;
					return 2;
				}
				if(_w1 == _sw1 or _sw2) {
					self.number = _i;
					return 1;
				}
				_i = _i + 3;
			}
			! It would make sense to return 0 here, but property
			! routines return 0 by default anyway.
		],
		description [ _k;
			_k = location.&cheap_scenery-->(self.number + 2);
			if(_k ofclass Routine) {
				_k();
				rtrue;
			}
			print_ret (string) _k;
		],
		before [;
			Examine, Search:
				rfalse;
			default:
				#ifdef SceneryReply;
				if(SceneryReply ofclass string)
					print_ret (string) SceneryReply;
				if(SceneryReply())
					rtrue;
				#endif;
				"No necesitas fijarte en eso.";
		],
		found_in [;
			if(location provides cheap_scenery) rtrue;
		],
	has concealed scenery;

