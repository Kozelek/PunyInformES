! ######################### Grammar + Actions

! ---------------------
! Base verbs
! ---------------------

Verb 'responde' 'di' 'dile' 'decir'
    * 'a//' creature topic              		-> Answer reverse ! infsp fix , delete 'reverse'
    * topic 'a//' creature        				-> Answer ;

Verb 'pregunta' 'interroga' 'preguntar' 'interrogar'
    * creature 'sobre'/'por' topic      		-> Ask
    * 'a//' creature 'sobre'/'por' topic 		-> Ask
    * 'sobre'/'por' topic 'a//' creature 		-> Ask reverse
    * topic 'a//' creature        				-> Ask reverse
    * 'a//' creature 'acerca' 'de' topic 		-> Ask;
Verb 'pide' 'pidele' 'pedir'
    * 'a//' creature noun        				-> AskFor
    * noun 'a//' creature        				-> AskFor reverse;

Verb 'rompe' 'aplasta' 'golpea' 'romper' 'aplastar' 'golpear'
    'destruye' 'patea' 'pisotea' 'destruir' 'patear' 'pisotear'
	'ataca' 'mata' 'asesina' 'tortura' 'noquea'
	'atacar' 'matar' 'asesinar' 'torturar' 'noquear'
	* noun                                      -> Attack
    * 'a//' noun                    			-> Attack
	* noun 'con' held                          	-> Attack;

Verb 'escala' 'trepa' 'escalar' 'trepar'
    * 'a//' noun            					-> Climb
    * noun                                		-> Climb
    * 'por' noun                          		-> Climb;
Verb 'sube' 'subir' 'subete' 'subirse' 'subirte'
	*											-> GoUp
    * noun                              		-> Climb
    * 'a//' / 'en' / 'por'  noun        		-> Enter;

Verb 'cierra' 'cerrar' 'cubre' 'cubrir'
    * noun                               		-> Close
    * noun 'con' 'pestillo'        				-> Lock
    * noun 'con' held                    		-> Lock;

Verb 'corta' 'rasga' 'cortar' 'rasgar'
    * noun                               		-> Cut
    * noun 'con' held                    		-> Attack;

Verb 'cava' 'excava' 'cavar' 'excavar'
    * 'en' noun                					-> Dig
    * noun                              		-> Dig
    * noun 'con' held                   		-> Dig
    * 'en' noun 'con' held              		-> Dig;

Verb 'bebe' 'beber'
    * noun                               		-> Drink;

Verb 'deja' 'suelta' 'dejar' 'soltar'
    * multiheld                          		-> Drop
    * 'a//' noun            					-> Drop
    * multiexcept 'en' noun         			-> Insert
    * multiexcept 'dentro' 'de' noun     		-> Insert
    * multiexcept 'sobre' noun           		-> PutOn
    * multiexcept 'encima' 'de' noun     		-> PutOn;

Verb 'tira' 'tirar'
    * 'de' noun                          		-> Pull
    * multiheld                          		-> Drop
    * multiexcept 'en' container         		-> Insert
    * multiexcept 'en' noun         			-> PutOn
    * multiexcept 'dentro' 'de' noun     		-> Insert
    * multiexcept 'sobre' noun           		-> PutOn
    * multiexcept 'encima' 'de' noun     		-> PutOn
    * held 'a//' noun                      		-> ThrowAt
    * held 'por' noun                    		-> Insert
    * held 'contra' noun                 		-> ThrowAt;

Verb 'come' 'comete' 'comerse' 'comerte' 'comer'
    * held                -> Eat;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'entra' 'cruza' 'entrar' 'cruzar'
	*                                   -> GoIn
	* noun                              -> Enter;
#IfNot;
Verb 'entra' 'cruza' 'entrar' 'cruzar'
	* noun                              -> Enter;
#Endif;

Verb 'examina' 'examinar' 'x//'
	* noun -> Examine;

Verb 'sal' 'fuera' 'afuera' 'salte' 'bajate' 'levantate' 'bajarse'
    'levantarse' 'salirse' 'bajarte' 'levantarte' 'salirte' 'salir'
    *                                   -> Exit
    * 'de' noun                         -> GetOff
    * 'fuera'                           -> Exit
    * 'afuera'                          -> Exit;

Verb 'baja' 'bajar'
    *                                   -> GoDown
    * 'de' noun                         -> GetOff;

Verb 'llena' 'rellena' 'llenar' 'rellenar'
    * noun                           	-> Fill;

Verb 'coge' 'toma' 'recoge' 'coger' 'tomar' 'recoger'
  * multi                             	-> Take
  * 'a//' creature                    	-> Take
  * multiinside 'de' noun             	-> Remove;

Verb 'give' 'feed' 'offer' 'pay'
	* held 'to' creature                -> Give
	* creature held                     -> Give reverse
	* 'over' held 'to' creature         -> Give;
Verb 'da' 'dar' 'dale' 'ofrece' 'ofrecer'
    * held 'a//' creature        		-> Give
    * 'a//' creature held        		-> Give reverse
    * creature held            			-> Give reverse;

[ ADirection;
	if (noun == Directions) rtrue;
	rfalse;
];

Verb 'anda' 'camina' 'corre' 'ir' 've' 'vete' 'vuelve'
	'andar' 'caminar' 'correr'
    *                                   -> Go
    * noun=ADirection                   -> Go
    * 'a//' noun=ADirection           	-> Go
    * 'hacia' noun=ADirection           -> Go
    * noun                              -> Enter
    * 'a//' noun                        -> Enter
    * 'hacia' noun                      -> Enter
    * 'por' noun                        -> Enter;
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'pon' 'mete' 'echa' 'inserta' 'coloca' 'poner' 'meter' 'echar' 'insertar' 'colocar'
  * multiexcept 'en' container                              	-> Insert
  * multiexcept 'en' noun                                    	-> PutOn
  * multiexcept 'dentro' 'de' noun                           	-> Insert
  * multiexcept 'sobre' noun                                 	-> PutOn
  * noun 'a//' topic                                         	-> SetTo
  * 'a//' creature 'en' container                           	-> Insert
  * 'a//' creature 'en' noun                                 	-> PutOn
  * 'a//' creature 'dentro' 'de' noun                        	-> Insert
  * 'a//' creature 'sobre' noun                              	-> PutOn
  * multiexcept 'encima' 'de' noun                           	-> PutOn
  * 'a//' creature 'encima' 'de' noun                        	-> PutOn
  * 'cerrojo'/'pestillo'/'cierre' 'a//' noun                 	-> Lock
  * 'el' 'cerrojo'/'pestillo'/'cierre' 'a//' noun            	-> Lock
  * 'cerrojo'/'pestillo'/'cierre' 'a//' noun 'con' held      	-> Lock
  * 'el' 'cerrojo'/'pestillo'/'cierre' 'a//' noun 'con' held 	-> Lock;
#Ifnot;
Verb 'pon' 'mete' 'echa' 'inserta' 'coloca' 'poner' 'meter' 'echar' 'insertar' 'colocar'
  * multiexcept 'en' container                              	-> Insert
  * multiexcept 'en' noun                                    	-> PutOn
  * multiexcept 'dentro' 'de' noun                           	-> Insert
  * multiexcept 'sobre' noun                					-> PutOn
  * 'a//' creature 'en' container                           	-> Insert
  * 'a//' creature 'en' noun                                 	-> PutOn
  * 'a//' creature 'dentro' 'de' noun                        	-> Insert
  * 'a//' creature 'sobre' noun                              	-> PutOn
  * multiexcept 'encima' 'de' noun                           	-> PutOn
  * 'a//' creature 'encima' 'de' noun                        	-> PutOn
  * 'cerrojo'/'pestillo'/'cierre' 'a//' noun                 	-> Lock
  * 'el' 'cerrojo'/'pestillo'/'cierre' 'a//' noun            	-> Lock
  * 'cerrojo'/'pestillo'/'cierre' 'a//' noun 'con' held      	-> Lock
  * 'el' 'cerrojo'/'pestillo'/'cierre' 'a//' noun 'con' held 	-> Lock;
#EndIf;

#Ifdef OPTIONAL_FLEXIBLE_INVENTORY;
Verb 'inventario' 'i//' 
    *                                     		-> Inv
    * 'largo'/'ancho'                     		-> Inv;
#Ifnot;
Verb 'inventario' 'i//' 
	* 											-> Inv;
#Endif;

Verb 'salta' 'saltar'
    *                                    		-> Jump
    * noun                               		-> JumpOver
    * 'a//' noun                          		-> Enter
    * 'sobre' noun                       		-> JumpOver
    * 'por' 'encima' 'de' noun        			-> JumpOver;

Verb 'escucha' 'oye' 'escuchar' 'oir'
    *                                    		-> Listen
    * 'a//' noun            					-> Listen
    * noun                               		-> Listen;

Verb 'look' 'mira' 'm//' 'ver' 'l//' 'mirar'
    *                                    		-> Look
    * 'a//' creature                    		-> Examine
    * noun                               		-> Examine
    * 'a//'/'hacia' noun        				-> Examine
    * 'en' noun                          		-> Search
    * 'dentro' 'de' noun                 		-> Search
    * 'sobre' noun                       		-> Search
    * 'a//' 'traves' 'de' noun        			-> Search
    * 'por' noun                         		-> Search;

Verb 'abre' 'abrir'
    * noun                               		-> Open
    * noun 'con' held                    		-> Unlock;

Verb 'arrastra' 'arrastrar'
	* noun                                      -> Pull;

Verb 'empuja' 'mueve' 'empujar' 'mover' 'pulsa' 'pulsar'
    * noun                               		-> Push
    * noun 'a//' noun                			-> Transfer
    * noun 'hacia' noun=ADirection              -> PushDir
    * noun noun=ADirection                      -> PushDir;

Verb 'ponte' 'ponerse' 'ponerte' 'ponerme'
	* held                              		-> Wear;

Verb 'lee' 'leer'
    * noun                               		-> Examine
    * 'sobre' topic 'en' noun        			-> Consult reverse
    * topic 'en' noun                			-> Consult reverse;

Verb 'saca' 'sacar'
	* multiinside 'de' noun             		-> Remove
	* 'a//' creature 'de' noun          		-> Remove;
Verb 'sacate' 'quitate' 'sacarse' 'quitarse' 'quitarte' 'sacarte' 'sacarme' 'quitarme' 'quitar'
	* noun                              		-> Disrobe;

Verb 'lava' 'limpia' 'pule' 'abrillanta' 'friega' 'frota'
	'lavar' 'limpiar' 'pulir' 'abrillantar' 'fregar' 'frotar'
    * noun                               		-> Rub
    * 'a//' creature                    		-> Rub;

Verb 'busca' 'buscar'
    * 'en' noun                          		-> Search
    * topic 'en' noun                 			-> Consult reverse
    * 'en' noun 'sobre' topic        			-> Consult
    * 'en' noun topic            				-> Consult
    * 'en' noun 'acerca' 'de' topic    			-> Consult;

Verb 'registra' 'registrar'
	* noun                         		        -> Search;

Verb 'grita' 'gritar'
	* topic 'a//' creature                  	-> Answer
	* 'a//' noun                            	-> ShoutAt
	* topic                                     -> Shout
	*                                           -> Shout;

Verb 'muestra' 'ensena' 'mostrar' 'ensenar'
    * creature held                     		-> Show reverse
    * 'a//' creature held        				-> Show reverse
    * held 'a//' creature        				-> Show;

Verb 'echate' 'sientate' 'echarse' 'sentarse' 'echarte' 'sentarte'
    * 'en' noun                          		-> Enter;

Verb 'huele' 'oler'
    *                                    		-> Smell
    * 'a//' noun            					-> Smell
    * noun                               		-> Smell;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'enciende' 'prende' 'encender' 'prender'
    * switchable            					-> SwitchOn
    * noun                						-> Burn;
#Ifnot;
Verb 'enciende' 'prende' 'encender' 'prender'
    * noun            							-> SwitchOn;
#EndIf;
Verb 'desconecta' 'apaga' 'desconectar' 'apagar'
    * noun                               		-> SwitchOff
    * 'a//' creature                    		-> SwitchOff;

Verb 'cuenta' 'narra' 'explica' 'habla' 'contar' 'narrar' 'explicar' 'hablar'
    * creature 'de' topic        				-> Tell
    * creature 'sobre' topic        			-> Tell
    * creature topic                       		-> Tell
    * 'a//' creature 'de'/'sobre' topic 		-> Tell
    * 'a//' creature  topic        				-> Tell
    * 'con' creature 'sobre' topic    			-> Tell
    * 'con' creature 'de' topic        			-> Tell
    * 'con' creature 'acerca' 'de' topic 		-> Tell
    * 'sobre' topic 'con' creature    			-> Tell reverse
    * 'acerca' 'de' topic 'con' creature 		-> Tell reverse
    * 'de' topic 'con'/'a//' creature    		-> Tell reverse
    * topic 'a//' creature        				-> Tell reverse;

Verb 'ata' 'enchufa' 'une' 'atar' 'enchufar' 'unir'
    * noun                               		-> Tie
    * 'a//' creature                    		-> Tie
    * 'a//' creature 'a//' noun         		-> Tie
    * noun 'a//' noun                      		-> Tie;

Verb 'toca' 'tocar'
    * noun                               		-> Touch
    * 'a//' creature                    		-> Touch;

Verb 'gira' 'atornilla' 'desatornilla' 'girar' 'atornillar' 'desatornillar'
    * noun                               -> Turn;

Verb 'espera' 'esperar' 'z//'
    *                                    -> Wait;

[ AnswerSub;
	if (second > 1 && RunLife(second,##Answer) ~= 0) rfalse;
	return MSG_ANSWER_DEFAULT;
];

[ AskSub;
	if (RunLife(noun,##Ask) ~= 0) rfalse;
	return MSG_ASK_DEFAULT;
];

[ AskToSub;
	PrintMsg(MSG_ASKTO_DEFAULT, noun);
];

[ AskForSub;
	if (noun == player) <<Inv>>;
	PrintMsg(MSG_ASKFOR_DEFAULT, noun);
];

[ AttackSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate && RunLife(noun, ##Attack) ~= 0) rfalse;
	return MSG_ATTACK_DEFAULT;
];

[ ClimbSub;
	if(noun has animate) return MSG_CLIMB_ANIMATE;
	return MSG_CLIMB_DEFAULT;
];

[ CloseSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_CLOSE_YOU_CANT, 'cerrar'); rtrue; }
	if(noun hasnt open) { PrintMsg(MSG_CLOSE_NOT_OPEN, noun); rtrue; }
	give noun ~open;
	scope_modified = true;
	run_after_routines_msg = MSG_CLOSE_DEFAULT;
	run_after_routines_arg_1 = 'cerrar';
];

[ ConsultSub;
	return MSG_CONSULT_NOTHING_INTERESTING;
];

[ CutSub;
	return MSG_CUT_NO_USE;
];

[ DigSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	return MSG_DIG_NO_USE;
];

[ DisrobeSub;
	if (noun notin player || noun hasnt worn) return MSG_DISROBE_NOT_WEARING;
	give noun ~worn;
	run_after_routines_msg = MSG_DISROBE_DEFAULT;
];

[ DrinkSub;
	return MSG_DRINK_NOTHING_SUITABLE;
];

[ DropSub;
	if(noun notin player) return MSG_DROP_NOT_HOLDING;
	if(ImplicitDisrobeIfWorn(noun)) rtrue;
	move noun to parent(player);
	give noun moved;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark)
		scope_modified = true;
#Endif;
	PrintMsg(MSG_DROP_DROPPED, noun); rtrue;
];

[ EatSub;
	if(noun has animate) return MSG_EAT_ANIMATE;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	if(noun hasnt edible) return MSG_EAT_INEDIBLE;
	remove noun;
	scope_modified = true;
	run_after_routines_msg = MSG_EAT_DEFAULT;
];

#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
[ _CheckDoorDirTo p_door;
#Ifdef OPTIONAL_SIMPLE_DOORS;
	if(p_door.&door_dir == 0 || (p_door.&door_to == 0 && (p_door.&found_in == 0 || p_door.#found_in ~= 4))) {
		_RunTimeError(ERR_OBJECT_HASNT_PROPERTY, p_door);
		rtrue;
	}
#Ifnot;
	if(p_door.&door_to == 0 || p_door.&door_dir == 0) {
		_RunTimeError(ERR_OBJECT_HASNT_PROPERTY, p_door);
		rtrue;
	}
#EndIf;
];
#EndIf;


[ DoorDir p_door _door_dir;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	_CheckDoorDirTo(p_door);
#EndIf;
#IfDef OPTIONAL_SIMPLE_DOORS;
	if(p_door.#door_dir > 2) {
		! This is a Simple Door, where door_dir is an array
		if(real_location == p_door.&found_in-->1)
			_door_dir = 1;
		return p_door.&door_dir-->_door_dir;
	} else {
#EndIf;
		! Normal Inform door
		_door_dir = p_door.door_dir;
		if(UnsignedCompare(_door_dir, top_object) > 0)
			return p_door.door_dir();
		return _door_dir;
#IfDef OPTIONAL_SIMPLE_DOORS;
	}
#EndIf;
];

[ EnterSub _door_dir;
	if(noun has door) {
		_door_dir = DoorDir(noun);
		! Convert to fake object
		_door_dir = DirPropToFakeObj(_door_dir);
		<<Go _door_dir>>;
	}
	if(noun hasnt enterable) { PrintMsg(MSG_ENTER_YOU_CANT, 'entrar'); rtrue; }
	if(player in noun) return MSG_ENTER_ALREADY;
	if(IndirectlyContains(player, noun)) return MSG_ENTER_HELD;
	if(noun has container && noun hasnt open) { PrintMsg(MSG_ENTER_NOT_OPEN, noun); rtrue; }
	if(parent(noun) ~= parent(player)) return MSG_ENTER_BAD_LOCATION;
	PlayerTo(noun, true);
	run_after_routines_msg = MSG_ENTER_DEFAULT;
	run_after_routines_arg_1 = 'entrar';
];

[ ExamineSub x;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) return MSG_EXAMINE_DARK;
#Endif;
	if (noun.description == 0) {
		if (noun has container) {
			if (noun has open or transparent) <<Search noun>>;
			else { PrintMsg(MSG_EXAMINE_CLOSED, noun); rtrue;	}
		}
		if (noun has switchable) return MSG_EXAMINE_ONOFF;
		return MSG_EXAMINE_NOTHING_SPECIAL;
	}
	x = PrintOrRun(noun, description);
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
	if (x == 0 && noun has switchable) return MSG_EXAMINE_ONOFF;
];

[ ExitSub _p;
	_p = parent(player);
	if(parent(_p) == 0) {
		! player not inside, standing in the room
		if(_p.out_to && noun == 0) <<Go FAKE_OUT_OBJ>>;
		return MSG_EXIT_ALREADY;
	}
	if(noun == 0) <<Exit _p>>;
	if(player notin noun) {
		if(IndirectlyContains(noun, player)) { PrintMsg(MSG_EXIT_FIRST_LEAVE, parent(player)); rtrue; }
		if(noun has supporter) return MSG_EXIT_NOT_ON;
		return MSG_EXIT_NOT_IN;
	}
	if(noun has container && noun hasnt open) { PrintMsg(MSG_EXIT_NOT_OPEN, noun); rtrue; }
	PlayerTo(parent(noun), true);
	run_after_routines_msg = MSG_EXIT_DEFAULT;
	run_after_routines_arg_1 = 'salir';
];

[ FillSub;
	return MSG_FILL_NO_WATER;
];

[ GetOffSub;
	if (parent(player) == noun) <<Exit noun>>;
	return MSG_EXIT_NOT_ON;
];

[ GiveSub;
	if(ObjectIsUntouchable(second)) return;
	if (noun notin player) return MSG_GIVE_NOT_HOLDING;
	if (second == player)  return MSG_GIVE_PLAYER;
	if (RunLife(second, ##Give) ~= 0) rfalse;
	return MSG_GIVE_DEFAULT;
];

[ GoSub _prop;
	! when called Directions have been set properly
	_prop = selected_direction;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(_prop == 0) { _RunTimeError(ERR_INVALID_DIR_PROP); rtrue; }
#EndIf;

	return GoDir(_prop);
];

! Generic routine to move object. Can be used for Insert, PutOn, Take, Drop, Transfer, Empty (and Enter/Exit?)
! p_messages:
! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
[ _MoveNounToSecond p_messages _msg _ancestor _action;
	if(ObjectIsUntouchable(second)) return;
	_ancestor = CommonAncestor(noun, second);

	_msg = p_messages-->0;
	if(_msg && parent(noun) == second) 
		return _msg;
	_msg = p_messages-->1;
	if(_msg && _ancestor == noun) 
		return _msg;
	_msg = p_messages-->2;
	if(_msg && second ~= _ancestor && second has container && second hasnt open) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->3;
	if(_msg && noun ~=player && second ~= Directions &&  ImplicitGrabIfNotHeld(noun)) rtrue;

	_msg = p_messages-->4;
	if(_msg && ImplicitDisrobeIfWorn(noun)) rtrue;

	! run before on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
	receive_action = action;
	_action = action; action = ##Receive;
	if(RunRoutines(second, before) ~= 0) { action = _action; rtrue; }
	action = _action;

	_msg = p_messages-->5;
	if(_msg && second has animate)
		return _msg;
	_msg = p_messages-->6;
	if(_msg && second hasnt container) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->7;
	if(_msg && second hasnt supporter) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->8;
	if(_msg && _AtFullCapacity(second))
		return _msg;

	move noun to second;

	! run after on object
	if(AfterRoutines()) rtrue;

	! run after on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").after()^";
#EndIf;
	_action = action; action = ##Receive;
	if(RunRoutines(second, after) ~= 0) { action = _action; rtrue; }
	action = _action;

	if (keep_silent) return;
	_msg = p_messages-->9;
	return _msg; ! Can be 0 or a message#
];


! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _InsertMessages -->
	MSG_INSERT_ALREADY
	MSG_INSERT_ITSELF
	MSG_INSERT_NOT_OPEN
	1
	1
	MSG_INSERT_ANIMATE
	MSG_INSERT_NOT_CONTAINER
	0
	MSG_INSERT_NO_ROOM
	MSG_INSERT_DEFAULT;

[ InsertSub;
	if(noun == player) <<Enter second>>;
	return _MoveNounToSecond(_InsertMessages);
];

#Ifdef OPTIONAL_FLEXIBLE_INVENTORY;
[ InvSub _mode;
	_mode = WordValue(num_words);
	if(_mode == 'columna') inventory_style = 0;
	if(_mode == 'linea') inventory_style = 1;
#Ifnot;
[ InvSub;
#Endif;
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
	if(PrintMsg(MSG_INVENTORY_DEFAULT) == false)
		return MSG_INVENTORY_EMPTY;
];

[ JumpSub;
	return MSG_JUMP;
];

[ JumpOverSub;
	return MSG_JUMP_OVER;
];

[ ListenSub;
	return MSG_LISTEN_DEFAULT;
];

[ LockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_LOCK_NOT_A_LOCK, 'echar el cerrojo'); rtrue; }
	if (noun has locked)  { PrintMsg(MSG_LOCK_ALREADY_LOCKED, 'echar el cerrojo'); rtrue; }
	if (noun has open) return MSG_LOCK_CLOSE_FIRST;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (RunRoutines(noun, with_key) ~= second) return MSG_LOCK_KEY_DOESNT_FIT;
	give noun locked;
	run_after_routines_msg = MSG_LOCK_DEFAULT;
	run_after_routines_arg_1 = 'echar el cerrojo';
];

[ LookSub _old_lookmode;
	_old_lookmode = lookmode;
	lookmode = 2; ! force long description
	Look();
	lookmode = _old_lookmode;
];

[ OpenSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_OPEN_YOU_CANT, 'abrir'); rtrue; }
	if(noun has locked) return MSG_OPEN_LOCKED;
	if(noun has open) return MSG_OPEN_ALREADY;
	give noun open;
	scope_modified = true;
	run_after_routines_msg = MSG_OPEN_DEFAULT;
];

[ PullSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_PULL_STATIC;
	if (noun has scenery)  return MSG_PULL_SCENERY;
	if (noun has animate)  return MSG_PULL_ANIMATE;
	return MSG_PULL_DEFAULT; !Nothing obvious happens
];

[ PushSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_PUSH_STATIC;
	if (noun has scenery)  return MSG_PUSH_SCENERY;
	if (noun has animate)  return MSG_PUSH_ANIMATE;
	return MSG_PUSH_DEFAULT;
];

[ PushDirSub;
	return MSG_PUSHDIR_DEFAULT;
];

! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _PutOnMessages -->
	MSG_PUTON_ALREADY
	MSG_PUTON_ITSELF
	0
	1
	1
	MSG_PUTON_ANIMATE
	0
	MSG_PUTON_NOT_SUPPORTER
	MSG_PUTON_NO_ROOM
	MSG_PUTON_DEFAULT;

[ PutOnSub;
	if(noun == player) <<Enter second>>;
	return _MoveNounToSecond(_PutOnMessages);
];

[ RemoveSub _i;
	_i = parent(noun);
	if (_i has container && _i hasnt open) { PrintMsg(MSG_REMOVE_CLOSED, _i); rtrue; }
	if (_i ~= second) return MSG_REMOVE_NOT_HERE;
	if(TryToTakeNoun() ~= false) rtrue;
	action = ##Remove; if (AfterRoutines()) rtrue;
	action = ##Take;
	run_after_routines_msg = MSG_REMOVE_DEFAULT;
];

[ RubSub;
	return MSG_RUB_DEFAULT;
];

[ SearchSub _i _plural;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) return MSG_SEARCH_DARK;
#Endif;
	if (ObjectIsUntouchable(noun)) return;
	_plural = PrintContents(1, noun);

	if(noun has supporter) {
		if(_plural == 0)
			return MSG_SEARCH_NOTHING_ON;
		else
			return MSG_SEARCH_ON_IT_ISARE;
	}
	if(noun hasnt container) return MSG_SEARCH_NOTHING_SPECIAL;
	if(noun hasnt transparent && noun hasnt open)
		return MSG_SEARCH_CANT_SEE_CLOSED;
	if(AfterRoutines()) rtrue;
	_i = MSG_SEARCH_EMPTY;
	if(_plural)
		_i = MSG_SEARCH_IN_IT_ISARE;
	return _i;
];

[ ShoutSub;
	return MSG_SHOUT_DEFAULT;
];

[ ShoutAtSub;
	return MSG_SHOUTAT_DEFAULT;
];

[ ShowSub;
	if (parent(noun) ~= player) return MSG_SHOW_NOT_HOLDING;
	if (second == player) <<Examine noun>>;
	if (RunLife(second, ##Show) ~= 0) rfalse;
	return MSG_SHOW_DEFAULT;
];

[ SmellSub;
	if(ObjectIsUntouchable(noun)) return;
	return MSG_SMELL_DEFAULT;
];

[ SwitchOffSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) return MSG_SWITCH_OFF_NOT_SWITCHABLE;
	if (noun hasnt on)         return MSG_SWITCH_OFF_NOT_ON;
	give noun ~on;
	run_after_routines_msg = MSG_SWITCH_OFF_DEFAULT;
];

[ SwitchOnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) return MSG_SWITCH_ON_NOT_SWITCHABLE;
	if (noun has on)           return MSG_SWITCH_ON_ON;
	give noun on;
	run_after_routines_msg = MSG_SWITCH_ON_DEFAULT;
];

[ TakeSub;
	if(TryToTakeNoun(true) ~= false) rtrue;
	PrintMsg(MSG_TAKE_DEFAULT); rtrue;
];

[ TieSub;
	return MSG_TIE_DEFAULT;
];

[ TellSub;
	if (noun == player) return MSG_TELL_PLAYER;
	if (RunLife(noun, ##Tell) ~= 0) rfalse;
	return MSG_TELL_DEFAULT;
];

[ ThrowAtSub;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	if(ObjectIsUntouchable(second)) return;
	if(ImplicitDisrobeIfWorn(noun)) rtrue;
	if(second > 1) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
		action = ##ThrownAt;
		if (RunRoutines(second, before) ~= 0) { action = ##ThrowAt; rtrue; }
		action = ##ThrowAt;
	}
	if(second hasnt animate) return MSG_THROW_ANIMATE;
	if(RunLife(second,##ThrowAt) ~= 0) rfalse;
	return MSG_THROW_DEFAULT;
];

[ TouchSub;
	if(ObjectIsUntouchable(noun)) return;
	return MSG_TOUCH_DEFAULT;
];

[ TransferSub _work_to_do;
	if(noun notin second) _work_to_do = true;
	if(second == player) { <Take noun>; run_after_routines_msg = _work_to_do; rtrue; }
	if(_work_to_do == false || (noun in parent(player) && second == Directions && selected_direction == d_to))
		return MSG_TRANSFER_ALREADY;
	if(noun notin player && TryToTakeNoun() == true) rtrue;
	if (second == Directions && selected_direction == d_to) {
		<Drop noun>;
		if(noun in location) run_after_routines_msg = 1;
	}
	else {
		if (second has supporter) 
			<PutOn noun second>;
		else 
			<Insert noun second>;
		if(noun in second)
			run_after_routines_msg = 1;
	}
];

[ TurnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_TURN_STATIC;
	if (noun has scenery)  return MSG_TURN_SCENERY;
	if (noun has animate)  return MSG_TURN_ANIMATE;
	return MSG_TURN_DEFAULT;
];

[ UnlockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_UNLOCK_NOT_A_LOCK, 'quitar el cerrojo'); rtrue; }
	if (noun hasnt locked)  { PrintMsg(MSG_UNLOCK_ALREADY_UNLOCKED, 'quitar el cerrojo'); rtrue; }
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (RunRoutines(noun, with_key) ~= second) return MSG_UNLOCK_KEY_DOESNT_FIT;
	give noun ~locked;
	run_after_routines_msg = MSG_UNLOCK_DEFAULT;
	run_after_routines_arg_1 = 'quitar el cerrojo';
];

[ WaitSub;
	if(AfterRoutines()) rtrue;
	return MSG_WAIT_DEFAULT;
];

[ WearSub;
	if (parent(noun) ~= player) return MSG_WEAR_NOT_HOLDING;
	if (noun has worn) return MSG_WEAR_ALREADY_WORN;
	if (noun hasnt clothing) { PrintMsg(MSG_WEAR_NOT_CLOTHING, 'ponerse'); rtrue; }
	give noun worn;
	run_after_routines_msg = MSG_WEAR_DEFAULT;
];

[ GoDownSub;
	! shortcut to <<Go down>>
	<Go FAKE_D_OBJ>;
];

[ GoUpSub;
	! shortcut to <<Go up>>
	<Go FAKE_U_OBJ>;
];


! ---------------------
! Extended verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_VERBSET;

Verb 'sopla' 'soplar'
    * noun                               		-> Blow;

Verb 'tonto' 'bobo' 'idiota'
    *                                    		-> Mild
    * topic                            			-> Mild;

Verb 'quema'
    * noun                               		-> Burn
    * 'a//' creature                    		-> Burn
    * 'a//' creature 'con' held         		-> Burn
    * noun 'con' held                    		-> Burn;

Verb 'compra' 'comprar'
    * noun                               		-> Buy;

Verb 'consulta'
    * creature 'sobre' topic            		-> Ask
    * 'a//' creature 'sobre' topic    			-> Ask
    * 'sobre' topic 'a//' creature    			-> Ask reverse
    * noun 'sobre' topic                		-> Consult
    * noun 'acerca' 'de' topic            		-> Consult
    * topic 'en' noun            				-> Consult reverse;

Verb 'vacia'
    * noun                               		-> Empty
    * noun 'dentro' 'de' noun            		-> EmptyT
    * noun 'en' noun                     		-> EmptyT
    * noun 'sobre' noun                  		-> EmptyT
    * noun 'encima' 'de' noun            		-> EmptyT;

Verb 'besa' 'abraza' 'besar' 'abrazar'
    * creature                           		-> Kiss
    * 'a//' creature                    		-> Kiss;

Verb 'no'
	*                                           -> No;

Verb 'reza' 'rezar'
    *                                    		-> Pray;

Verb 'ajusta' 'fija' 'ajustar' 'fijar'
    * noun                               		-> Set
    * noun 'en'/'a//' topic        				-> SetTo;

Verb 'mierda' 'jode' 'joder' 'puta' 'cono' 'cabron' 'puto'
    *                                   		-> Strong
    * topic                            			-> Strong;

Verb 'canta' 'cantar'
    *                    						-> Sing;

Verb 'duerme' 'dormir' 'descansa' 'descansar'
    *                    						-> Sleep;

Verb 'perdon' 'perdona' 'disculpa'
    *                                   		-> Sorry;

Verb 'retuerce' 'aprieta' 'estruja' 'tuerce' 'torcer' 'estrujar' 'apretar' 'retorcer'
    * noun                               		-> Squeeze
    * 'a//' creature                    		-> Squeeze;

Verb 'nada' 'nadar' 'bucea' 'bucear'
    *                                    		-> Swim;

Verb 'balanceate' 'columpiate' 'meneate' 'balancearse' 'columpiarse'
    'menearse' 'balancearte' 'columpiarte' 'menearte' 'balancear' 'columpiar'
    * 'en' noun                          		-> Swing;

Verb 'saborea' 'prueba' 'saborear' 'probar' 'lame' 'lamer'
    * noun                               		-> Taste
    * 'a//' noun            					-> Taste;

Verb 'piensa' 'pensar'
    *                                    		-> Think;

Verb 'transfiere' 'cambia' 'transferir' 'cambiar'
    * noun 'a//' noun                     -> Transfer;

Verb 'wake' 'awake' 'awaken'
	*                                           -> Wake
	* 'up'                                      -> Wake
	* creature                                  -> WakeOther
	* creature 'up'                             -> WakeOther
	* 'up' creature                             -> WakeOther;
Verb 'despierta' 'despertar' 
    *                                    		-> Wake
    * creature                           		-> WakeOther
    * 'a//' creature                    		-> WakeOther;
Verb 'despertarte'
    *                    						-> Wake;

Verb 'sacude' 'agita' 'sacudir' 'agitar'
    * creature                          		-> Attack
    * 'a//' creature                    		-> Attack
    * 'la' 'mano'                       		-> WaveHands
    * 'las' 'manos'                     		-> WaveHands
    * noun                               		-> Wave;
Verb 'saluda' 'saludar'
    * 'con' 'la' 'mano'            				-> WaveHands;

Verb 'si'
	*                                           -> Yes;

[ BlowSub;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	return MSG_BLOW_DEFAULT;
];

[ BurnSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	return MSG_BURN_DEFAULT;
];

[ BuySub;
	return MSG_BUY_DEFAULT;
];

[ EmptySub;
	<EmptyT noun FAKE_D_OBJ>;
];

[ EmptyTSub _i _recipient;
	if(noun == second) return MSG_EMPTY_WOULDNT_ACHIEVE;
	if(noun hasnt container) { PrintMsg(MSG_EMPTY_NOT_CONTAINER, noun); rtrue; }
	if(noun hasnt open) {
		PrintMsg(MSG_EMPTY_IS_CLOSED, noun);
		rtrue;
	}
	if(second == Directions && selected_direction ~= 0)
		_recipient = DirPropToFakeObj(selected_direction);
	else
		_recipient = second;
	_i = child(noun);
	if(_i == 0) { PrintMsg(MSG_EMPTY_ALREADY_EMPTY, noun); rtrue; }
	while(_i ~= 0) {
		if(keep_silent == 0) print (name) _i, ": ";
		<Transfer _i _recipient>;
		if(_i in noun || _i in player) rtrue;
		_i = child(noun);
	}
	run_after_routines_msg = 1;
];

[ GoInSub;
	! shortcut to <<Go in>>
	<Go FAKE_IN_OBJ>;
];

[ KissSub;
	if (ObjectIsUntouchable(noun)) return;
	if (RunLife(noun, ##Kiss) ~= 0) rfalse;
	if (noun == player) return MSG_KISS_PLAYER;
	return MSG_KISS_DEFAULT;
];

[ MildSub;
	return MSG_MILD_DEFAULT;
];

[ NoSub;
	return MSG_RHETORICAL_QUESTION;
];

[ PraySub;
	return MSG_PRAY_DEFAULT;
];

[ SetSub;
	return MSG_SET_DEFAULT;
];

[ SetToSub;
	return MSG_SET_TO_DEFAULT;
];

[ SingSub;
	return MSG_SING_DEFAULT;
];

[ SleepSub;
	return MSG_SLEEP_DEFAULT;
];

[ SorrySub;
	return MSG_SORRY_DEFAULT;
];

[ StrongSub;
	return MSG_STRONG_DEFAULT;
];

[ SqueezeSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate) return MSG_SQUEEZE_YOURSELF;
	return MSG_SQUEEZE_DEFAULT;
];

[ SwimSub;
	return MSG_SWIM_DEFAULT;
];

[ SwingSub;
	return MSG_SWING_DEFAULT;
];

[ TasteSub;
	if (ObjectIsUntouchable(noun)) return;
	return MSG_TASTE_DEFAULT;
];

[ ThinkSub;
	return MSG_THINK_DEFAULT;
];

[ WakeSub;
	return MSG_WAKE_DEFAULT;
];

[ WakeOtherSub;
	if (ObjectIsUntouchable(noun)) return;
	if (RunLife(noun, ##WakeOther) ~= 0) rfalse;
	return MSG_WAKEOTHER_DEFAULT;
];

[ WaveSub;
	if(parent(noun) ~= player) { PrintMsg(MSG_WAVE_NOTHOLDING, noun); rtrue; }
	return MSG_WAVE_DEFAULT;
];

[ WaveHandsSub;
	return MSG_WAVEHANDS_DEFAULT;
];

[ YesSub;
	return MSG_RHETORICAL_QUESTION;
];

#EndIf;

! ---------------------
! Base meta verbs
! ---------------------

Verb meta 'repite' 'repetir' 'g//'
	*                                           -> Again;

Verb meta 'breve' 'normal'
	*                                           -> LookModeNormal;

#Ifdef OPTIONAL_FULL_SCORE;
Verb meta 'total'
    *                                           -> FullScore;
Verb meta 'score'
    *                                           -> Score
    * 'total'                                   -> FullScore;
#Ifnot;
Verb meta 'score'
    *                                           -> Score;
#Endif;

#Ifndef NO_SCORE;
Verb meta 'notificacion'
	*                                           -> NotifyOn
	* 'on'/'activa'                             -> NotifyOn
	* 'off'/'inactiva'                          -> NotifyOff;
#Endif;

Verb meta 'oops' 'ups'
	*                                           -> Oops
	* special                                   -> OopsCorrection;

Verb meta 'restart' 'reiniciar'
	*                                           -> Restart;

Verb meta 'restore' 'cargar'
	*                                           -> Restore;

Verb meta 'save' 'salvar'
	*                                           -> Save;

Verb meta 'superbrief' 'short' 'corto'
	*                                           -> LookModeShort;

Verb meta 'verbose' 'long' 'largo'
	*                                           -> LookModeLong;

Verb meta 'version'
	*                                           -> Version;

Verb meta 'quit' 'q//' 'fin'
	*                                           -> Quit;

[ AgainSub;
	! nothing here - this is taken care of in the main game loop instead
];

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ FullScoreSub _i _score_sum _sc;
#IfNot;
[ FullScoreSub _i _score_sum;
#EndIf;
	new_line;
	PrintMsg(MSG_FULLSCORE_START);
#IfDef TASKS_PROVIDED;
	for(_i=0 : _i<NUMBER_TASKS : _i++)
		if (task_done->_i == 1) {
			_sc = task_scores->(_i);
			PANum(_sc);
			_score_sum = _score_sum + _sc;
#Ifdef PrintTaskName;
			PrintTaskName(_i);
#Endif;
		}
#IfNot;
	_i = 0; ! Avoid warning
#EndIf;
#IfDef OPTIONAL_SCORED;
	if(things_score ~= 0) {
		PANum(things_score);
		PrintMsg(MSG_FULLSCORE_OBJECTS);
	}
	if(places_score ~= 0) {
		PANum(places_score);
		PrintMsg(MSG_FULLSCORE_ROOMS);
	}
	_score_sum = score - _score_sum - things_score - places_score;
#IfNot;
	_score_sum = score - _score_sum;
#EndIf;
	if(_score_sum ~= 0) {
		PANum(_score_sum);
		PrintMsg(MSG_FULLSCORE_ACTIONS);
	}
	new_line;
	PANum(score);
	return MSG_FULLSCORE_END;
];
#EndIf;

[ LookModeNormalSub;
	lookmode=1;
	return MSG_LOOKMODE_NORMAL;
];

[ LookModeLongSub;
	lookmode=2;
	return MSG_LOOKMODE_LONG;
];

[ LookModeShortSub;
	lookmode=3;
	return MSG_LOOKMODE_SHORT;
];

#Ifndef NO_SCORE;
[ NotifyOnSub;
	notify_mode = 1;
	return MSG_NOTIFY_ON;
];

[ NotifyOffSub;
	notify_mode = 0;
	return MSG_NOTIFY_OFF;
];
#Endif;

[ OopsSub;
	return MSG_OOPS_DEFAULT;
];

[ OopsCorrectionSub;
	! nothing here - this is taken care of in the main game loop instead
];

[ QuitSub;
	PrintMsg(MSG_AREYOUSUREQUIT);
	if(YesOrNo()) {
		deadflag = GS_QUIT;
	}
];

[ RestartSub;
	PrintMsg(MSG_RESTART_CONFIRM);
	if(YesOrNo()) {
		@restart;
		return MSG_RESTART_FAILED;
	}
];

#IfV3;
[ RestoreSub;
	@restore ?_restore_was_successful; ! can't use @restore because of compiler test
	verb_word = 'cargar';
	return MSG_RESTORE_FAILED;
._restore_was_successful; ! This is never reached, since a successful restore continues after save opcode.
#IfNot;
[ RestoreSub _flag;
	@restore -> _flag;
	! must have failed here so no need to check the flag
	return MSG_RESTORE_FAILED;
#EndIf;
];

#IfV3;
[ SaveSub;
	@save ?_save_was_successful;
	return MSG_SAVE_FAILED;
._save_was_successful;
	return MSG_SAVE_DEFAULT;
#IfNot;
[ SaveSub _result;
	@save -> _result;
	if(_result == 0) return MSG_SAVE_FAILED;
	return MSG_SAVE_DEFAULT; ! _result = 1: save ok, 2: Restore ok
#EndIf;
];

#Ifdef NO_SCORE;
[ ScoreSub;
	return MSG_SCORE_DEFAULT;
];
#Ifnot;
[ ScoreSub;
	PrintMsg(MSG_SCORE_DEFAULT);
	PrintRank();
];
#Endif;

[ Banner _i;
	new_line;
#IfDef Story;
	#IfV5;
		style bold;
	#EndIf;
		print (string) Story;
	#IfV5;
		style roman;
	#EndIf;
	#IfDef Headline;
		print (string) Headline;
	#EndIf;
#EndIf;
	print "Versión ", (0-->1) & $03ff, " / No.Serie ";
	for (_i = 18:_i < 24: _i++) print (char) 0->_i;
	print " / Inform v";
	inversion;
	print " PunyInformES v", PUNYINFORM_MAJOR_VERSION, (char) '.', PUNYINFORM_MINOR_VERSION;
	if(PUNYINFORM_PATCH_VERSION)
		print ".", PUNYINFORM_PATCH_VERSION;
#Ifdef PUNYINFORM_VERSION_SUFFIX;
	print (string) PUNYINFORM_VERSION_SUFFIX;
#EndIf;
	_i = 0;
#IfDef STRICT_MODE;
	#IfV5;
	print " S";
	_i = 1;
	#EndIf;
#EndIf;
#IfDef DEBUG;
	if(_i == 0) print " ";
	print "D";
	_i = 1;
#EndIf;
#IfTrue RUNTIME_ERRORS > 0;
	if(_i == 0) print " ";
	print "R";
#EndIf;
	new_line;
];

[ VersionSub;
	Banner();
];

! ---------------------
! Extended meta verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_METAVERBS;
Global transcript_mode = false;        ! true when game scripting is on
Global xcommsdir = false;              ! true if command recording is on

Verb meta 'noscript' 'unscript'
	*                                           -> ScriptOff;

#Ifndef NO_PLACES;
Verb meta 'objects' 'objetos'
	*                                           -> Objects;
Verb meta 'places' 'lugares'
	*                                           -> Places;
#Endif; ! NO_PLACES

Verb meta 'recording' 'grabacion'
	*                                           -> CommandsOn
	* 'on'/'activa'/'activo'                    -> CommandsOn
	* 'off'/'inactiva'/'inactivo'               -> CommandsOff;

Verb meta 'replay' 'rejugar'
	*                                           -> CommandsRead;

Verb meta 'script' 'transcript'
	*                                           -> ScriptOn
	* 'on'/'activo'                             -> ScriptOn
	* 'off'/'inactivo'                          -> ScriptOff;

Verb meta 'verify' 'verificacion'
	*                                           -> Verify;

[ CommandsOnSub;
	@output_stream 4;
	xcommsdir = 1;
	"[Grabación activada.]";
];

[ CommandsOffSub;
	if (xcommsdir == 1) @output_stream -4;
	xcommsdir = 0;
	"[Grabación desactivada.]";
];

[ CommandsReadSub;
	@input_stream 1;
	xcommsdir = 2;
	"[Rejugando comandos.]";
];

#Ifndef NO_PLACES;
[ PlacesSub i j k;
	print "Has visitado: ";
	objectloop(i has visited) if(parent(i) == 0) j++;
	objectloop(i has visited) {
		if(parent(i) == 0) {
			print (name) i; k++;
			if (k == j) { print ".^"; return; }
			if (k == j-1) print " y ";
			else          print ", ";
		}
	}
];

[ ObjectsSub i j f;
	print "Objetos que has adquirido: ";
	objectloop (i has moved) {
		j = parent(i);
		if(j) {
			if(f == 0) new_line;
			f = 1;
			print "- ", (the) i, "   ";
			if (j == player) {
				if (i has worn) {
					print "(puesto)";
				} else {
					print "(en mano)";
				}
			} else if(j has animate) print "(dado)";
			else if(j has visited) print "(en ", (name) j, ")";
			else if(j has container) print "(dentro ", (the) j, ")";
			else if(j has supporter) print "(sobre ", (the) j, ")";
			else if(j has enterable) print "(en ", (the) j, ")";
			else print "(perdido)";
			new_line;
		}
	}
	if(f == 0) "nada.";
];
#Endif; ! NO_PLACES

[ ScriptOnSub;
	transcript_mode = ((HDR_GAMEFLAGS-->0) & 1);
	if (transcript_mode) "La transcripción ya está activada.";
	@output_stream 2;
	if (((HDR_GAMEFLAGS-->0) & 1) == 0) "Intento de transcribir fallido.";
	print "Comienzo de una transcripción de^";
	Banner();
	transcript_mode = true;
];

[ ScriptOffSub;
	transcript_mode = ((HDR_GAMEFLAGS-->0) & 1);
	if (transcript_mode == false) "La transcripción ya está inactiva.";
	print "^Fin de transcripción.^";
	@output_stream -2;
	if ((HDR_GAMEFLAGS-->0) & 1) "Intento de terminar transcripción fallido.";
	transcript_mode = false;
];

[ VerifySub;
	@verify ?_verify_was_maybe_ok;
	"El archivo del juego no se verificó como intacto, y puede estar corrupto.";
._verify_was_maybe_ok;
	"El archivo del juego se ha verificado como intacto.";
];


#EndIf;

! ---------------------
! Debug verbs
! ---------------------

#IfDef DEBUG;
Verb meta 'pronoun'
	*                                           -> Pronouns;
#IfV5;
Verb meta 'pronouns'
	*                                           -> Pronouns;
#EndIf;

Verb meta 'random'
	*                                           -> RandomSeed
	* special                                   -> RandomSeed
	* 'seed' number                             -> RandomSeed;

Verb meta 'scope'
	*                                           -> Scope
	* noun                                      -> Scope;

Verb meta 'purloin'
	* noun                                      -> Purloin;

Verb meta 'tree'
	*                                           -> Tree
	* number                                    -> Tree
	* noun                                      -> Tree;

Verb meta 'forest'
	*                                           -> Forest;

Verb meta 'rooms'
	*                                           -> Rooms;

Verb meta 'gonear'
	* noun                                      -> GoNear;

Verb meta 'goto'
	* topic                                     -> Goto;

Verb meta 'debug'
	*                                           -> Debug
	* 'reactive'                                -> Debug;

Verb meta 'routines' 'messages'
	*                                           -> RoutinesOn
	* 'on'                                      -> RoutinesOn
	* 'off'                                     -> RoutinesOff;

Verb meta 'actions'
	*                                           -> ActionsOn
	* 'on'                                      -> ActionsOn
	* 'off'                                     -> ActionsOff;

Verb meta 'timers' 'daemons'
	*                                           -> TimersOn
	* 'on'                                      -> TimersOn
	* 'off'                                     -> TimersOff;

Global scope_cnt;

[ GoNearSub _obj;
	_obj = noun;
	while(parent(_obj) ~= 0) _obj = parent(_obj);
	if(_obj == noun) print_ret (The) noun, " is not in anything!";
	PlayerTo(_obj);
];

#Ifndef GOTOSUB_BUFFER_SIZE;
Constant GOTOSUB_BUFFER_SIZE 80;
#Endif;

Array _GotoSubBuffer --> (1 + (GOTOSUB_BUFFER_SIZE + 1)/2); ! Add an extra word of constant has odd value


[ _RoomLike p_obj;
	! Return true if p_obj seems to be a room
	if(p_obj > Directions && p_obj <= top_object &&  parent(p_obj) == 0
			&& (~~(p_obj provides describe or life or found_in))
			&& (~~DebugParseNameObject(p_obj))) {
		if(p_obj has edible or talkable or supporter or container or transparent
				or concealed or proper or scenery or static or animate or clothing
				or pluralname or switchable or door or lockable)
			rfalse;
		rtrue;
	}
	rfalse;
];


[ GotoSub _obj _first _count _i _j _k _t _val_printed _val_input _match;
	if(consult_words == 1) {
		_obj = TryNumber(consult_from);
		if(_obj > 0) {
			if(_RoomLike(_obj))
				jump _gotoObj;
			jump _not_a_room;
		}
	}
	_t = _GotoSubBuffer + 2;
	_first = WordAddress(consult_from);
	_i = consult_from + consult_words - 1;
	_count = WordAddress(_i) + WordLength(_i) - _first;
	objectloop(_obj) {
		if(parent(_obj) == nothing) {
!			print _obj;
			@output_stream 3 _GotoSubBuffer;
			print (name) _obj;
			@output_stream -3;
			_k = _GotoSubBuffer-->0;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
			if(_k > GOTOSUB_BUFFER_SIZE) {
				_RunTimeError(ERR_BUFFER_OVERRUN, _obj);
				rtrue;
			}
#Endif;
			if(_k == _count) {
				_match = true;
				for(_i=_first, _j=0 : _j<_count : _i++, _j++) {
					_val_printed = _t->_j;
					_val_input = _i->0;
					if(_val_printed == _val_input) continue;
					if(_val_printed < 91 && _val_printed > 64 && _val_printed + 32 == _val_input) continue;
					_match = false;
					break;
				}
				if(_match) {
._gotoObj;
					PlayerTo(_obj);
					rtrue;
				}
			}
		}
	}
._not_a_room;
	"That doesn't seem to be a room.";
];

[ PronounsSub;
	print "el: ", (name) el_obj, "^la: ", (name) la_obj, "^los: ", (name) los_obj, "^las: ", (name) las_obj, "^";
!	, "^un: ", (name) un_obj, "^una: ", (name) una_obj, "^unos: ", (name) unos_obj, "^unas: ", (name) unas_obj, "^";
];

[ PurloinSub;
	if(noun == player) return MSG_TAKE_YOURSELF;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	move noun to player;
	scope_modified = true;
	"Purloined.";
];

[ RandomSeedSub _i;
	! sets the random seed, making randomness predictable
	! also a test of special and number, thus the fancy grammar
	!print special_word, " ", special_number," ",parsed_number,"^";
	if(special_word ~=0) "You can't send randomness to an object!";
	_i = parsed_number;
	if(_i == 0) _i = 100; ! either 'xxxx' (unknown special) or '0'
	random(-_i);
	"The random seed is set to ", _i, ".";
];

[ _ScopeSubHelper p_obj;
	print scope_cnt++,": ", (a) p_obj, " (", p_obj, ")";
	if(ObjectIsUntouchable(p_obj, true)) print " [untouchable]";
	new_line;
];

[ ScopeSub;
	scope_cnt = 1;
	LoopOverScope(_ScopeSubHelper, noun);
	if(scope_cnt < 2) "Nothing in scope.^";
];

[ _TreeSubHelper p_parent p_indent _x _i;
	objectloop(_x in p_parent) {
		for(_i = 0 : _i < p_indent : _i++) print "  ";
		print (a) _x, " (", _x, ")^";
		if(child(_x)) _TreeSubHelper(_x, p_indent + 1);
	}
];

Constant _REAL_LOCATION_TEXT " *** real_location ***";

[ TreeSub p_real_location _p;
	if(parsed_number > 0 && noun == parsed_number) {
		if(parsed_number < Directions || parsed_number > top_object)
			"That doesn't seem to be an object.";
	}

	if(noun==0) noun = real_location;
	if(noun in nothing)
		print (name) noun;
	else
		print (a) noun;
	print " (", noun, ")";
	_p = parent(noun);
	if(_p) {
		if(_p has supporter)
			print " on";
		else
			print " in";
		print " ~", (name) _p, "~ (", _p, ")";
	}
	if(noun == p_real_location) {
#IfV5;
		style bold;
#Endif;
		print (string) _REAL_LOCATION_TEXT;
#IfV5;
		style roman;
#Endif;
	}
	new_line;
	_TreeSubHelper(noun, 1);
];

[ ForestSub;
	for(noun=Directions : noun<= top_object: noun++)
		if(noun in nothing)
			TreeSub(real_location);
];

[ RoomsSub _obj;
	for(_obj=Directions + 1 : _obj<= top_object: _obj++)
		if(_RoomLike(_obj)) {
			print (name) _obj, " (", _obj, ")";
			if(_obj == real_location) {
#IfV5;
				style bold;
#Endif;
				print (string) _REAL_LOCATION_TEXT;
#IfV5;
				style roman;
#Endif;
			}
			new_line;
		}
];


#Ifdef OPTIONAL_MANUAL_REACTIVE;
[ MayBeRoutine p_obj p_prop _val;
	_val = p_obj.&p_prop;
	if(_val == 0) rfalse;
	_val = _val-->0;
	if(_val == 0 or NULL || metaclass(_val) == Routine) rtrue;
	rfalse;
];
#Endif;

[DebugSub _w _o;
	wn = num_words;
	_w = NextWord();
	switch(_w) {
		'reactive':
#Ifndef OPTIONAL_MANUAL_REACTIVE;
			_o = 1;
			"Define OPTIONAL_MANUAL_REACTIVE and recompile.";
#Ifnot;
			print "Probably give reactive to these objects (see notes about ~reactive~ in manual) :^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o hasnt reactive && (
						MayBeRoutine(_o, react_before) ||
						MayBeRoutine(_o, react_after) ||
						MayBeRoutine(_o, parse_name) ||
						_o.&add_to_scope ~= 0 ||
						_o.&each_turn ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o hasnt reactive && (
						MayBeRoutine(_o, react_before) ||
						MayBeRoutine(_o, react_after) ||
						_o.&add_to_scope ~= 0 ||
						_o.&each_turn ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
			print "^Remove reactive from these objects:^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o has reactive && (
						MayBeRoutine(_o, react_before) == false &&
						MayBeRoutine(_o, react_after) == false &&
						MayBeRoutine(_o, parse_name) == false &&
						_o.&add_to_scope == 0 &&
						_o.&each_turn == 0))
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o has reactive && (
						MayBeRoutine(_o, react_before) == false &&
						MayBeRoutine(_o, react_after) == false &&
						_o.&add_to_scope == 0 &&
						_o.&each_turn == 0))
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
#Endif;
		default:
			"Type one of the following:^
			DEBUG REACTIVE";
	}
];

[ RoutinesOnSub;  debug_flag = debug_flag | 1;  "[Message listing on.]"; ];

[ RoutinesOffSub; debug_flag = debug_flag & 14; "[Message listing off.]"; ];

[ ActionsOnSub;   debug_flag = debug_flag | 2;  "[Action listing on.]"; ];

[ ActionsOffSub;  debug_flag = debug_flag & 13; "[Action listing off.]"; ];

[ TimersOnSub;    debug_flag = debug_flag | 4;  "[Timers listing on.]"; ];

[ TimersOffSub;   debug_flag = debug_flag & 11; "[Timers listing off.]"; ];


#EndIf;

! ---------------------
! HELP ROUTINES
! ---------------------

[ _ListObjsMsg p_parent;
	p_parent = 0; ! Avoid warning
	print "^Puedes ver ";
	if(also_flag) print "también ";
];

[ _ListObjsInOnMsg p_parent;
	if(newline_flag)
		print "^";
	if(p_parent has supporter) print "Sobre "; else print "En ";
	print (the) p_parent, " puedes ver ";
	if(also_flag) print "también ";
];

[ Look _obj _top_ceil _ceil _describe_room
	_you_can_see_1 _you_can_see_2 _desc_prop _last_level _action;
	PrintMsg(MSG_LOOK_BEFORE_ROOMNAME);
	if((lookmode == 1 && location hasnt visited) || lookmode == 2) _describe_room = true;
#IfV5;
	style bold;
#EndIf;

	! Print the room name
#Ifdef OPTIONAL_NO_DARKNESS;
	_ceil = ScopeCeiling(player, _last_level);
#Ifnot;
	if(location == thedark)
		_ceil = location;
	else
		_ceil = ScopeCeiling(player, _last_level);
#Endif;

	_top_ceil = _ceil;

	if(_ceil == location) {
#IfDef OPTIONAL_SCORED;
		if(location has scored && location hasnt visited) {
			score = score + ROOM_SCORE;
#IfDef OPTIONAL_FULL_SCORE;
			places_score = places_score + ROOM_SCORE;
#EndIf;
		}
#EndIf;
		_PrintObjName(location);
	} else {
		print (The) _ceil;
	}
#IfV5;
	style roman;
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		new_line;
		PrintOrRun(location, description);
		jump _EndOfLookRoutine;
	}
#Endif;
	_obj = parent(player);
	while(_obj ~= _ceil or 0) {
		if(_obj has supporter)
			print " (sobre ";
		else
			print " (en ";
		print (the) _obj, ")";
		_obj = parent(_obj);
	}
	while(_ceil ~= player or 0) {
		if(_describe_room) {
			if(_ceil == location) {
				new_line;
				PrintOrRun(_ceil, description);
			} else if(_ceil.inside_description ~= 0 or NULL) {
				new_line;
				PrintOrRun(_ceil, inside_description);
			}
		} else if(_ceil == location)
			new_line;

		also_flag = false;
		! write intial and describe messages in a new paragraph
		objectloop(_obj in _ceil)
			if(_obj hasnt scenery or concealed && _obj ~= player) {
				give _obj workflag;
				if(_obj.&describe) {
					if(PrintOrRun(_obj, describe, 0)) {
						give _obj ~workflag;
						also_flag = true;
						continue;
					}
				}
				if(_obj has container or door) {
					if(_obj has open) {
						_desc_prop = when_open;
					} else {
						_desc_prop = when_closed;
					}
				} else if(_obj has switchable) {
					if(_obj has on) {
						_desc_prop = when_on;
					} else {
						_desc_prop = when_off;
					}
				} else {
					_desc_prop = initial;
				}
				if(_obj.&_desc_prop && (_obj hasnt moved || _desc_prop == when_off)) { ! Note: when_closed in an alias of when_off
					give _obj ~workflag;
					new_line;
					PrintOrRun(_obj, _desc_prop);
					also_flag = true;
				}
			}

		! write any remaining objects in a new paragraph
		if(parent(_ceil) == 0) {
			_you_can_see_1 = _ListObjsMsg;
		} else {
			_you_can_see_1 = _ListObjsInOnMsg;
		}
		_you_can_see_2 = ".^";
		newline_flag = true;
		if(PrintContents(_you_can_see_1, _ceil, true)) print (string) _you_can_see_2;


#IfDef OPTIONAL_PRINT_SCENERY_CONTENTS;
		newline_flag = true;
		objectloop(_obj in _ceil)
			if(_obj has scenery &&
					(_obj has supporter ||
						(_obj has container && _obj has transparent or open)) &&
						child(_obj) ~= 0 &&
						IndirectlyContains(_obj, player) == false) {
				if(PrintContents(_ListObjsInOnMsg, _obj)) {
					print (string) ". ";
					newline_flag = false;
				}
			}
		if(newline_flag == false)
			print "^";
#EndIf;

		! Descend one level
		_ceil = ScopeCeiling(player, _ceil);
	} ! while
._EndOfLookRoutine;
#Ifdef LookRoutine;
	! finally, call the optional library entry routine
	RunEntryPointRoutine(LookRoutine);
#Endif;
	_action = action; action = ##Look;
	AfterRoutines();
	action = _action;

	if(_top_ceil == location)
		give location visited;
];

#Ifndef NO_SCORE;
#Ifndef PrintRank;
[ PrintRank; "."; ];
#Endif;
#Endif;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ Achieved num;
	if (task_done->num == 0) {
		task_done->num = 1;
		score = score + task_scores->num;
	}
];
#EndIf;
[ PANum p_m _n;
	print "  ";
	_n = p_m;
	if(_n < 0)    _n = -10 * p_m;
	if(_n < 10)   print " ";
	if(_n < 100)  print " ";
	if(_n < 1000) print " ";
._Panuml;
	print p_m, " ";
];
#EndIf;

[ TryToTakeNoun p_suppress_before_after _i _k _r _ancestor _after_recipient;
	! Try to transfer the given item to the player. Return values:
	! 	0: Success, no message has been printed
	!   1: Failed, a message has been printed
	!   2: Success, a message has been printed

	_k = action;
	if(p_suppress_before_after == false) {
		action = ##Take;
		_r = BeforeRoutines();
		action = _k;
		if (_r) rtrue;
	}

	! People cannot ordinarily be taken.
	if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; };
#Ifdef DisallowTakeAnimate;
	if(noun has animate && DisallowTakeAnimate(noun)) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Ifnot;
	if(noun has animate) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Endif;
	_ancestor = CommonAncestor(player, noun);

	if (_ancestor == 0) {
		_i = _ObjectScopedBySomething(noun);
		if (_i) _ancestor = CommonAncestor(player, _i);
	}

	if(noun in player) { PrintMsg(MSG_TAKE_ALREADY_HAVE); rtrue; }
	if(ObjectIsUntouchable(noun, false, true)) rtrue;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	! The item is now known to be accessible.

	! Consult the immediate possessor of the item, if it's in a container
	! which the actor is not in.

	_i = parent(noun);
	if (_i && _i ~= _ancestor && (_i has container or supporter)) {
		_after_recipient = _i;
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _i, ").before()^";
#EndIf;
		action = ##LetGo;
		_r = RunRoutines(_i, before);
		action = _k;
		if (_r) rtrue;
	}
	

	if(noun has scenery) { PrintMsg(MSG_TAKE_SCENERY); rtrue; }
	if(noun has static) { PrintMsg(MSG_TAKE_STATIC); rtrue; }
	if(_AtFullCapacity(player)) { PrintMsg(MSG_TAKE_NO_CAPACITY); rtrue; }

	move noun to player;
	give noun ~concealed;
	update_moved = true;

	! Send "after" message to the object letting go of the item, if any.

	if (_after_recipient) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _after_recipient, ").after()^";
#EndIf;
		action = ##LetGo;
		_i = RunRoutines(_after_recipient, after);
		action = _k;
		if(_i) return 2;
	}

	if(p_suppress_before_after == false) {
		action = ##Take;
		_r = AfterRoutines();
		action = _k;
		if (_r) return 2;
	}

	rfalse;
];

[ DoorTo p_door _door_to;
	! Returns the location the door leads to (handling Simple Doors, as needed). 
	! Value true means the exit is blocked and a message has been printed
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	_CheckDoorDirTo(p_door);
#EndIf;
	_door_to = p_door.door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
	if(_door_to == 0) {
		! This is a Simple Door, where door_to has been left out
		if(real_location == p_door.&found_in-->0)
			_door_to = 1;
		return p_door.&found_in-->_door_to;
	} else {
#EndIf;
		! Normal Inform door
		if(UnsignedCompare(_door_to, top_object) > 0)
			return p_door.door_to();
		return _door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
	}
#EndIf;
];

[ GoDir p_property _new_location _old_location _vehicle _vehicle_mode _saved_location;
	if(parent(player) ~= real_location) {
		! special rule when in enterable (veichles)
		! before routine for the object is called with Go dir, and returns
		! 0   to disallow the movement, printing a refusal;
		! 1   to allow the movement, moving vehicle and player;
		! 2   to disallow but print and do nothing; or
		! 3   to allow but print and do nothing.
		_vehicle = parent(player);
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _vehicle, ").before()^";
#EndIf;
		_saved_location = location;
#Ifndef OPTIONAL_NO_DARKNESS;
		if(location == thedark) location = real_location;
#Endif;
		_vehicle_mode = RunRoutines(_vehicle, before);
		if(_vehicle_mode ~= 3) location = _saved_location;
		if(_vehicle_mode == 0) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
		if(_vehicle_mode == 2 or 3) rtrue;
	}
	!if(player notin location) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
	if(real_location provides p_property) {
		@get_prop real_location p_property -> _new_location; ! works in z3 and z5
	}
	if(_new_location ofclass String)
		print_ret (string) _new_location;
	if(UnsignedCompare(_new_location, top_object) > 0) {
		_new_location = real_location.p_property();
		if(_new_location == 1)
			rtrue;
	}

	! Check for a door
	if(_new_location ~= 0 && _new_location has door) {
		! The destination is in fact a door
		if(_new_location has concealed)
			_new_location = 0;
		else {
			if(_new_location hasnt open) { PrintMsg(MSG_GO_DOOR_CLOSED, _new_location); rtrue; }
			_new_location = DoorTo(_new_location);
			if(_new_location == 1)
				rtrue;
		}
	}

	! If _new_location is 0, we tell the player they can't go there and exit
	if(_new_location == 0) {
		if(real_location provides cant_go) {
#IfDef DEBUG;
#IfV3;
			if(debug_flag & 1) print "(", (name) real_location, ").cant_go()^";
#EndIf;
#EndIf;
			PrintOrRun(real_location, cant_go);
			rtrue;
		}
		return MSG_GO_CANT_GO;
	}

#IfDef DEBUG;
#IfV3;
	if(debug_flag & 1) print "(", (name) _new_location, ").before()^";
#EndIf;
#EndIf;
	action = ##Going;
	if(RunRoutines(_new_location, before)) { action = ##Go; rtrue; }
	action = ##Go;

	if(_vehicle_mode == 1) {
		move _vehicle to _new_location;
		_new_location = _vehicle;
	}

	_old_location = location;

	PlayerTo(_new_location, true);
	if(deadflag ~= GS_PLAYING) rtrue;

	action = ##Going;
	if(RunRoutines(_old_location, after)) { action = ##Go; rtrue; }
	action = ##Go;


	if(AfterRoutines()) rtrue;
	if(keep_silent) rtrue;
	Look();
];


[ VerbName p_v ;
#Ifdef PrintVerb;
	! first give entry routine a chance to override
	if(PrintVerb(p_v)) return;
#Endif;

#IfV3;
	switch(p_v) {
		'g//': print "repetir"; return;
		'i//', 'inv': print "inventario"; return;
		'l//': print "mirar"; return;
		'q//': print "fin"; return;
		'x//': print "examinar"; return;
		'z//': print "wait"; return;
	}

	print (address) p_v;

	! For words longer than 6 characters, print the extra characters
	switch(p_v) {
		'destroy', 'display': print (char) 'y'; return;
		'discard': print (char) 'd'; return;
		'disrobe', 'restore', 'torture', 'verbose': print (char) 'e'; return;
#Ifndef NO_PLACES;
		'objects': print (char) 's'; return;
#Endif;
		'present', 'restart': print (char) 't'; return;
		'superbrief': print "rief"; return;
		'swallow', 'unscrew': print (char) 'w'; return;
		'uncover': print (char) 'r'; return;
		'version': print (char) 'n'; return;
#IfDef OPTIONAL_EXTENDED_VERBSET;
		'consult': print (char) 't'; return;
		'embrace', 'squeeze': print (char) 'e'; return;
		'purchase': print "se"; return;
		'transfer': print "er"; return;
#EndIf;
#IfDef OPTIONAL_EXTENDED_METAVERBS;
		'noscript', 'unscript': print "pt"; return;
		'transcript': print "ript"; return;
#EndIf;
	}
#IfNot; ! This is z5+
	switch(p_v) {
		'superbrief': print "superbrief"; return;
		'g//': print "repetir"; return;
		'i//': print (address) 'inventario'; return;
		'l//': print "mirar"; return;
		'q//': print "fin"; return;
		'x//': print (address) 'examinar'; return;
		'z//': print "esperar"; return;
#IfDef OPTIONAL_EXTENDED_METAVERBS;
		'transcript': print "transcript"; return;
#EndIf;
	}
	print (address) p_v;
#EndIf;

];

