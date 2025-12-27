! Part of PunyInform: A small stdlib and parser for interactive fiction
! suitable for old-school computers such as the Commodore 64.
! Designed to be similar, but not identical, to the Inform 6 library.
!
System_file;

!
! Simple string messages
!

#IfDef MSG_OK;
Constant MSG_TAKE_DEFAULT MSG_OK;
Constant MSG_DROP_DROPPED MSG_OK;
Constant MSG_REMOVE_DEFAULT MSG_OK;
!Constant MSG_SAVE_DEFAULT MSG_OK;
#EndIf;

#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Ya te encuentras en tu posesión.";
#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Ya llevas demasiadas cosas encima.";
#EndIf;
#Ifndef MSG_DRINK_NOTHING_SUITABLE;
Constant MSG_DRINK_NOTHING_SUITABLE "Aquí no hay nada adecuado para beber.";
#EndIf;
#Ifndef MSG_THROW_ANIMATE;
Constant MSG_THROW_ANIMATE "Inútil.";
#Endif;
#Ifndef MSG_THROW_DEFAULT;
Constant MSG_THROW_DEFAULT "Te falta valor cuando llega el momento crucial.";
#Endif;
#Ifndef MSG_SMELL_DEFAULT;
Constant MSG_SMELL_DEFAULT "No hueles nada inesperado.";
#Endif;
#Ifndef MSG_LISTEN_DEFAULT;
Constant MSG_LISTEN_DEFAULT "No escuchas nada inesperado.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Hablas a solas un rato.";
#Endif;
#Ifndef MSG_TELL_DEFAULT;
Constant MSG_TELL_DEFAULT "Esto no provoca ninguna reacción.";
#Endif;
#Ifndef MSG_ENTER_ALREADY;
Constant MSG_ENTER_ALREADY "¡Pero si ya estás ahí!";
#Endif;
#Ifndef MSG_EXIT_ALREADY;
Constant MSG_EXIT_ALREADY "¡Pero si no estás dentro de nada ahora mismo!";
#Endif;
#Ifndef MSG_EXIT_NOT_ON;
Constant MSG_EXIT_NOT_ON "No estás sobre ello.";
#Endif;
#Ifndef MSG_EXIT_NOT_IN;
Constant MSG_EXIT_NOT_IN "No estás dentro de ello.";
#Endif;
#Ifndef MSG_INVENTORY_EMPTY;
Constant MSG_INVENTORY_EMPTY "Tienes las manos vacías.";
#Endif;
#Ifndef MSG_GO_CANT_GO;
Constant MSG_GO_CANT_GO "No puedes ir por ahí.";
#Endif;
#Ifndef MSG_SAVE_DEFAULT;
Constant MSG_SAVE_DEFAULT "Vale.";
#Endif;
#Ifndef MSG_INSERT_ITSELF;
Constant MSG_INSERT_ITSELF "No puedes meter algo dentro de sí mismo.";
#Endif;
#Ifndef MSG_PUTON_ITSELF;
Constant MSG_PUTON_ITSELF "No se puede poner algo sobre sí mismo.";
#Endif;
#Ifndef MSG_ATTACK_DEFAULT;
Constant MSG_ATTACK_DEFAULT "La violencia no es la respuesta.";
#Endif;
#Ifndef MSG_FILL_NO_WATER;
Constant MSG_FILL_NO_WATER "Pero aquí no hay agua que acarrear.";
#EndIf;
#Ifndef MSG_DIG_NO_USE;
Constant MSG_DIG_NO_USE "Cavar no serviría de nada.";
#EndIf;
#Ifndef MSG_WAIT_DEFAULT;
Constant MSG_WAIT_DEFAULT "No ocurre nada.";
#EndIf;
#Ifndef MSG_TOUCH_DEFAULT;
Constant MSG_TOUCH_DEFAULT "No sientes nada inesperado.";
#EndIf;
#Ifndef MSG_PUSHDIR_DEFAULT;
Constant MSG_PUSHDIR_DEFAULT "¿Es lo mejor que se te ocurre?";
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Saltas en el sitio, inútilmente.";
#EndIf;
#Ifndef MSG_REMOVE_DEFAULT;
Constant MSG_REMOVE_DEFAULT "Quitado.";
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "No encuentras nada especial.";
#EndIf;
#Ifndef MSG_OOPS_DEFAULT;
Constant MSG_OOPS_DEFAULT "No le des importancia.";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Sólo puedes hacer eso con algo animado.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "No puedes usar varios objetos con ese verbo.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_DIRS;
Constant MSG_PARSER_NOT_MULTIPLE_DIRS "No puedes usar varias direcciones.";
#EndIf;
#Ifndef MSG_PARSER_BAD_NUMBER;
Constant MSG_PARSER_BAD_NUMBER "No entendí ese número.";
#EndIf;
#Ifndef MSG_PARSER_NO_INPUT;
Constant MSG_PARSER_NO_INPUT "¿Perdón?";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_SENTENCE;
Constant MSG_PARSER_UNKNOWN_SENTENCE "No entiendo esa frase.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_VERB;
Constant MSG_PARSER_UNKNOWN_VERB "No es un verbo que reconozca.";
#EndIf;
#Ifndef MSG_PARSER_CANT_DISAMBIGUATE;
Constant MSG_PARSER_CANT_DISAMBIGUATE "Sigo sin entender a qué te refieres.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_PERSON;
Constant MSG_PARSER_UNKNOWN_PERSON "No veo a quién te refieres.";
#EndIf;
#Ifndef MSG_PARSER_NOSUCHTHING;
Constant MSG_PARSER_NOSUCHTHING "No puedes ver tal cosa.";
#EndIf;
#Ifndef MSG_PARSER_CANT_OOPS;
Constant MSG_PARSER_CANT_OOPS "Lo siento, eso no puede corregirse.";
#EndIf;
#Ifndef MSG_PARSER_COMPLEX_AGAIN;
Constant MSG_PARSER_COMPLEX_AGAIN "El comando 'repetir' debe estar en una nueva línea.^";
#EndIf;
#Ifndef MSG_PARSER_NOTHING_TO_AGAIN;
Constant MSG_PARSER_NOTHING_TO_AGAIN "Difícilmente puedes repetirlo.";
#EndIf;
#Ifndef MSG_PARSER_BE_MORE_SPECIFIC;
Constant MSG_PARSER_BE_MORE_SPECIFIC "Tienes que ser más específico.";
#EndIf;
#Ifndef MSG_PARSER_NO_MULTIPLES_FOR_NPC;
Constant MSG_PARSER_NO_MULTIPLES_FOR_NPC "Sólo puedes referirte a objetos individuales cuando hables con otras personas.";
#EndIf;
#IfnDef OPTIONAL_NO_DARKNESS;
#IfnDef MSG_NOW_DARK;
Constant MSG_NOW_DARK "^Ahora está muy oscuro aquí.";
#EndIf;
#EndIf;
#Ifndef MSG_SWITCH_ON_NOT_SWITCHABLE;
Constant MSG_SWITCH_ON_NOT_SWITCHABLE "No es algo que se pueda encender.";
#EndIf;
#Ifndef MSG_SWITCH_OFF_NOT_SWITCHABLE;
Constant MSG_SWITCH_OFF_NOT_SWITCHABLE "No es algo que se pueda apagar.";
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef OPTIONAL_SCORED;
#Ifndef MSG_FULLSCORE_OBJECTS;
Constant MSG_FULLSCORE_OBJECTS "encontrando artículos diversos";
#EndIf;
#Ifndef MSG_FULLSCORE_ROOMS;
Constant MSG_FULLSCORE_ROOMS "visitando diversos lugares";
#EndIf;
#EndIf;
#Ifndef MSG_FULLSCORE_ACTIONS;
Constant MSG_FULLSCORE_ACTIONS "realizando acciones destacables";
#EndIf;
#EndIf;

!
! complex messages (enumerated)
!

! Note, we can only use id 2-999
Default MSG_CLOSE_YOU_CANT = 2;
Default MSG_ENTER_YOU_CANT = 3;
Default MSG_EXAMINE_NOTHING_SPECIAL = 4;
Default MSG_TAKE_ANIMATE = 5;
Default MSG_TAKE_PLAYER_PARENT = 6;
Default MSG_EAT_ANIMATE = 7;
Default MSG_DROP_NOT_HOLDING = 8;
Default MSG_OPEN_DEFAULT = 9;
Default MSG_CLOSE_DEFAULT = 10;
Default MSG_LOOK_BEFORE_ROOMNAME  = 11;
Default MSG_SHOW_NOT_HOLDING = 12;
Default MSG_SHOW_DEFAULT = 13;
Default MSG_GIVE_NOT_HOLDING = 14;
Default MSG_GIVE_DEFAULT = 15;
Default MSG_ASKFOR_DEFAULT = 16;
Default MSG_ASKTO_DEFAULT = 17;
Default MSG_ENTER_DEFAULT = 18;
Default MSG_EXIT_FIRST_LEAVE = 19;
Default MSG_ENTER_NOT_OPEN = 20;
Default MSG_EXIT_NOT_OPEN = 21;
Default MSG_EXIT_DEFAULT = 22;
Default MSG_INVENTORY_DEFAULT = 23;
Default MSG_GO_FIRST_LEAVE = 24;
Default MSG_GIVE_PLAYER 25;
Default MSG_SAVE_FAILED 26;
Default MSG_RESTORE_FAILED 27;
Default MSG_RESTART_FAILED 28;
Default MSG_INSERT_DEFAULT 29;
Default MSG_INSERT_NOT_OPEN 30;
Default MSG_ASK_DEFAULT 31;
Default MSG_ANSWER_DEFAULT 32;
Default MSG_RESTART_RESTORE_OR_QUIT 33;
Default MSG_AREYOUSUREQUIT 34;
Default MSG_WEAR_ALREADY_WORN 35;
Default MSG_WEAR_NOT_CLOTHING 36;
Default MSG_WEAR_NOT_HOLDING 37;
Default MSG_WEAR_DEFAULT 38;
Default MSG_INSERT_ALREADY 39;
Default MSG_INSERT_NO_ROOM 40;
Default MSG_PUTON_ALREADY 41;
Default MSG_PUTON_NO_ROOM 42;
Default MSG_PUTON_DEFAULT 43;
Default MSG_GO_DOOR_CLOSED 44;
Default MSG_SWITCH_ON_ON 47;
Default MSG_SWITCH_OFF_NOT_ON 48;
Default MSG_SWITCH_ON_DEFAULT 49;
Default MSG_SWITCH_OFF_DEFAULT 50;
Default MSG_PUSH_STATIC 51;
Default MSG_PULL_STATIC 52;
Default MSG_TURN_STATIC 53;
Default MSG_PUSH_SCENERY 54;
Default MSG_PULL_SCENERY 55;
Default MSG_TURN_SCENERY 56;
Default MSG_PUSH_ANIMATE 57;
Default MSG_PULL_ANIMATE 58;
Default MSG_TURN_ANIMATE 59;
Default MSG_TURN_DEFAULT 60;
Default MSG_PUSH_DEFAULT 61;
Default MSG_PULL_DEFAULT 62;
Default MSG_YOU_HAVE_WON 63;
Default MSG_YOU_HAVE_DIED 64;
Default MSG_OPEN_YOU_CANT = 65;
Default MSG_PARSER_NOTHING_TO_VERB 66;
Default MSG_TOUCHABLE_FOUND_CLOSED 67;
Default MSG_CONSULT_NOTHING_INTERESTING 68;
Default MSG_CUT_NO_USE 69;
Default MSG_SACK_PUTTING 70;
Default MSG_LOCK_NOT_A_LOCK 71;
Default MSG_LOCK_ALREADY_LOCKED 72;
Default MSG_LOCK_CLOSE_FIRST 73;
Default MSG_LOCK_KEY_DOESNT_FIT 74;
Default MSG_LOCK_DEFAULT 75;
Default MSG_DISROBE_NOT_WEARING 76;
Default MSG_DISROBE_DEFAULT 77;
Default MSG_REMOVE_NOT_HERE 79;
Default MSG_SEARCH_IN_IT_ISARE 80;
Default MSG_SEARCH_ON_IT_ISARE 81;
Default MSG_SEARCH_EMPTY 82;
Default MSG_SEARCH_NOTHING_ON 83;
Default MSG_SEARCH_CANT_SEE_CLOSED 84;
Default MSG_EAT_DEFAULT = 85;
#Ifdef OPTIONAL_FULL_SCORE;
Default MSG_FULLSCORE_START 86;
Default MSG_FULLSCORE_END 87;
#Endif;
Default MSG_SCORE_DEFAULT 88;
Default MSG_UNLOCK_NOT_A_LOCK 89;
Default MSG_UNLOCK_ALREADY_UNLOCKED 90;
Default MSG_UNLOCK_KEY_DOESNT_FIT 91;
Default MSG_UNLOCK_DEFAULT 92;
Default MSG_ENTER_BAD_LOCATION 93;
Default MSG_PROMPT 94;
#Ifndef OPTIONAL_NO_DARKNESS;
Default MSG_EXAMINE_DARK 95;
Default MSG_SEARCH_DARK 96;
#Endif;
Default MSG_EXAMINE_ONOFF 97;
Default MSG_ORDERS_WONT 98;
Default MSG_AUTO_TAKE 99;
Default MSG_AUTO_DISROBE = 100;
Default MSG_PARSER_PARTIAL_MATCH = 101;
Default MSG_TAKE_BELONGS 102;
Default MSG_TAKE_PART_OF 103;
Default MSG_TAKE_NOT_AVAILABLE 104;
Default MSG_PARSER_CONTAINER_ISNT_OPEN 105;
Default MSG_PARSER_NOT_HOLDING 106;
Default MSG_PARSER_CANT_TALK 107;
Default MSG_WAVE_NOTHOLDING 108;
Default MSG_JUMP_OVER 109;
Default MSG_TIE_DEFAULT 110;
Default MSG_CLOSE_NOT_OPEN 111;
Default MSG_RUB_DEFAULT 112;
Default MSG_SQUEEZE_DEFAULT 113;
Default MSG_EXAMINE_CLOSED 114;
Default MSG_EMPTY_IS_CLOSED 115; ! Only used from extended verbset, but same message also used in basic set.
Default MSG_PARSER_NO_NEED_REFER_TO 116;
Default MSG_PARSER_DONT_UNDERSTAND_WORD 117;
Default MSG_INSERT_NOT_CONTAINER 118;
Default MSG_TRANSFER_ALREADY 119;
Default MSG_YES_OR_NO 120;
Default MSG_RESTART_CONFIRM 121;
#Ifndef NO_SCORE;
Default MSG_PARSER_NEW_SCORE 122;
#Endif;
Default MSG_CLIMB_ANIMATE 123;
Default MSG_CLIMB_DEFAULT 124;
Default MSG_PARSER_BAD_PATTERN_PREFIX 125;
Default MSG_PARSER_BAD_PATTERN_SUFFIX 126;
Default MSG_TAKE_ALREADY_HAVE 127;
Default MSG_SHOUT_DEFAULT 128;
Default MSG_SHOUTAT_DEFAULT 129;
Default MSG_INSERT_ANIMATE 130;
Default MSG_PUTON_ANIMATE 131;
Default MSG_LOOKMODE_NORMAL 132;
Default MSG_LOOKMODE_LONG 133;
Default MSG_LOOKMODE_SHORT 134;
Default MSG_AUTO_TAKE_NOT_HELD = 135;
Default MSG_AUTO_DISROBE_WORN = 136;
Default MSG_TAKE_SCENERY = 137;
Default MSG_TAKE_STATIC = 138;
Default MSG_EAT_INEDIBLE = 139;
Default MSG_OPEN_ALREADY = 140;
Default MSG_OPEN_LOCKED = 141;
Default MSG_PUTON_NOT_SUPPORTER = 142;
Default MSG_PARSER_NO_IT = 143;
Default MSG_PARSER_CANT_SEE_IT = 144;
Default MSG_NOTIFY_ON = 145;
Default MSG_NOTIFY_OFF = 146;
Default MSG_ENTER_HELD 147;
Default MSG_TAKE_DEFAULT 148;
Default MSG_DROP_DROPPED 149;

#IfDef OPTIONAL_PROVIDE_UNDO_FINAL;
#Ifndef MSG_UNDO_NOTHING_DONE;
Constant MSG_UNDO_NOTHING_DONE "[¡No se puede ~deshacer~ lo que no se ha hecho!]";
#EndIf;
#Ifndef MSG_UNDO_NOT_PROVIDED;
Constant MSG_UNDO_NOT_PROVIDED "[Tu intérprete no proporciona ~undo~.]";
#EndIf;
#Ifndef MSG_UNDO_FAILED;
Constant MSG_UNDO_FAILED "~Undo~ ha fallado.";
#EndIf;
#Ifndef MSG_UNDO_DONE;
Constant MSG_UNDO_DONE "Turno previo deshecho.";
#EndIf;
#EndIf;

#Ifndef MSG_COMMENT_TRANSCRIPT;
Constant MSG_COMMENT_TRANSCRIPT "[Comentario grabado]^";
#EndIf;
#Ifndef MSG_COMMENT_NO_TRANSCRIPT;
#ifdef OPTIONAL_EXTENDED_METAVERBS;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Comentario no grabado. Para guardar un comentario, comienza una transcripción.]^";
#IfNot;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Comentario no grabado. Este juego no soporta transcripciones.]^";
#EndIf;
#EndIf;


#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifndef MSG_BURN_DEFAULT;
Constant MSG_BURN_DEFAULT "Con este peligroso acto no conseguirás nada.";
#EndIf;
#Ifndef MSG_BUY_DEFAULT;
Constant MSG_BUY_DEFAULT "Nada está en venta.";
#EndIf;
#Ifndef MSG_EMPTY_WOULDNT_ACHIEVE;
Constant MSG_EMPTY_WOULDNT_ACHIEVE "Eso difícilmente vaciará nada.";
#EndIf;
#Ifndef MSG_RHETORICAL_QUESTION;
Constant MSG_RHETORICAL_QUESTION "Era una pregunta retórica.";
#EndIf;
#Ifndef MSG_PRAY_DEFAULT;
Constant MSG_PRAY_DEFAULT "Nada práctico resulta de tu oración.";
#EndIf;
#Ifndef MSG_SING_DEFAULT;
Constant MSG_SING_DEFAULT "Tu canto es abominable.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "No te sientes especialmente somnoliento.";
#EndIf;
#Ifndef MSG_SORRY_DEFAULT;
Constant MSG_SORRY_DEFAULT "Bah, no te disculpes.";
#EndIf;
#Ifndef MSG_SQUEEZE_YOURSELF;
Constant MSG_SQUEEZE_YOURSELF "Mantén las manos quietas.";
#EndIf;

#Ifndef MSG_SWIM_DEFAULT;
Constant MSG_SWIM_DEFAULT "No hay suficiente agua para nadar.";
#EndIf;
#Ifndef MSG_SWING_DEFAULT;
Constant MSG_SWING_DEFAULT "No hay nada razonable para balancearse aquí.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "No pruebas nada inesperado.";
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Qué buena idea.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Saludas con la mano, sintiéndote idiota.";
#EndIf;
#Ifndef MSG_WAKE_DEFAULT;
Constant MSG_WAKE_DEFAULT "La terrible verdad es que esto no es un sueño.";
#Endif;
#Ifndef MSG_WAKEOTHER_DEFAULT;
Constant MSG_WAKEOTHER_DEFAULT "Eso parece innecesario.";
#Endif;
#Ifndef MSG_KISS_PLAYER;
Constant MSG_KISS_PLAYER "Si crees que eso te va a ayudar...";
#Endif;
#Ifndef MSG_KISS_DEFAULT;
Constant MSG_KISS_DEFAULT "Concéntrate en el juego.";
#Endif;
#Ifndef MSG_MILD_DEFAULT;
Constant MSG_MILD_DEFAULT "Bastante.";
#EndIf;
#Ifndef MSG_STRONG_DEFAULT;
Constant MSG_STRONG_DEFAULT "La gente aventurera de verdad, no emplea ese lenguaje.";
#EndIf;

Default MSG_BLOW_DEFAULT 200;
Default MSG_WAVE_DEFAULT 201;
Default MSG_EMPTY_ALREADY_EMPTY 202;
Default MSG_SET_DEFAULT 203;
Default MSG_SET_TO_DEFAULT 204;
Default MSG_EMPTY_NOT_CONTAINER 205;
#EndIf;


#Iffalse MSG_PUSH_DEFAULT < 1000;
#Iffalse MSG_PULL_DEFAULT < 1000;
#Iffalse MSG_TURN_DEFAULT < 1000;
Constant SKIP_MSG_PUSH_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_STATIC < 1000;
#Iffalse MSG_PULL_STATIC < 1000;
#Iffalse MSG_TURN_STATIC < 1000;
#Iffalse MSG_TAKE_STATIC < 1000;
Constant SKIP_MSG_PUSH_STATIC;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_SCENERY < 1000;
#Iffalse MSG_PULL_SCENERY < 1000;
#Iffalse MSG_TURN_SCENERY < 1000;
Constant SKIP_MSG_PUSH_SCENERY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_ANIMATE < 1000;
#Iffalse MSG_PULL_ANIMATE < 1000;
#Iffalse MSG_TURN_ANIMATE < 1000;
#Iffalse MSG_CLIMB_ANIMATE < 1000;
Constant SKIP_MSG_PUSH_ANIMATE;
#Endif;
#Endif;
#Endif;
#Endif;


#Iffalse MSG_DROP_NOT_HOLDING < 1000;
#Iffalse MSG_SHOW_NOT_HOLDING < 1000;
#Iffalse MSG_GIVE_NOT_HOLDING < 1000;
#Iffalse MSG_WEAR_NOT_HOLDING < 1000;
Constant SKIP_MSG_DROP_NOT_HOLDING;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_OPEN_YOU_CANT < 1000;
#Iffalse MSG_CLOSE_YOU_CANT < 1000;
#Iffalse MSG_ENTER_YOU_CANT < 1000;
#Iffalse MSG_LOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_UNLOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_WEAR_NOT_CLOTHING < 1000;
Constant SKIP_MSG_OPEN_YOU_CANT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_TAKE_ANIMATE < 1000;
#Iffalse MSG_EAT_ANIMATE < 1000;
Constant SKIP_MSG_TAKE_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_TAKE_PLAYER_PARENT < 1000;
#Iffalse MSG_GO_FIRST_LEAVE < 1000;
#Iffalse MSG_EXIT_FIRST_LEAVE < 1000;
Constant SKIP_MSG_TAKE_PLAYER_PARENT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_DEFAULT < 1000;
#Iffalse MSG_ENTER_DEFAULT < 1000;
#Iffalse MSG_LOCK_DEFAULT < 1000;
#Iffalse MSG_UNLOCK_DEFAULT < 1000;
#Iffalse MSG_EXIT_DEFAULT < 1000;
Constant SKIP_MSG_CLOSE_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_DEFAULT < 1000;
#Iffalse MSG_SHOW_DEFAULT < 1000;
Constant SKIP_MSG_GIVE_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_ASKFOR_DEFAULT < 1000;
#Iffalse MSG_ASKTO_DEFAULT < 1000;
#Iffalse MSG_ORDERS_WONT < 1000;
Constant SKIP_MSG_ASKFOR_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_ENTER_NOT_OPEN < 1000;
#Iffalse MSG_EXIT_NOT_OPEN < 1000;
#Iffalse MSG_INSERT_NOT_OPEN < 1000;
#Iffalse MSG_GO_DOOR_CLOSED < 1000;
#Iffalse MSG_EMPTY_IS_CLOSED < 1000;
Constant SKIP_MSG_ENTER_NOT_OPEN;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_PLAYER < 1000;
#Iffalse MSG_TAKE_ALREADY_HAVE < 1000;
Constant SKIP_MSG_GIVE_PLAYER;
#Endif;
#Endif;

#Iffalse MSG_SAVE_FAILED < 1000;
#Iffalse MSG_RESTORE_FAILED < 1000;
#Iffalse MSG_RESTART_FAILED < 1000;
Constant SKIP_MSG_SAVE_FAILED;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ALREADY < 1000;
#Iffalse MSG_PUTON_ALREADY < 1000;
#Iffalse MSG_TRANSFER_ALREADY < 1000;
Constant SKIP_MSG_INSERT_ALREADY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ANIMATE < 1000;
#Iffalse MSG_PUTON_ANIMATE < 1000;
Constant SKIP_MSG_INSERT_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NO_ROOM < 1000;
#Iffalse MSG_PUTON_NO_ROOM < 1000;
Constant SKIP_MSG_INSERT_NO_ROOM;
#Endif;
#Endif;

#Iffalse MSG_ASK_DEFAULT < 1000;
#Iffalse MSG_ANSWER_DEFAULT < 1000;
#Iffalse MSG_SHOUT_DEFAULT < 1000;
#Iffalse MSG_SHOUTAT_DEFAULT < 1000;
Constant SKIP_MSG_ASK_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_ON < 1000;
#Iffalse MSG_SWITCH_OFF_NOT_ON < 1000;
Constant SKIP_MSG_SWITCH_ON_ON;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_DEFAULT < 1000;
#Iffalse MSG_SWITCH_OFF_DEFAULT < 1000;
Constant SKIP_MSG_SWITCH_ON_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_PARSER_NOT_HOLDING < 1000;
#Iffalse MSG_AUTO_TAKE_NOT_HELD < 1000;
#Iffalse MSG_WAVE_NOTHOLDING < 1000;
Constant SKIP_MSG_PARSER_NOT_HOLDING;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_NOT_OPEN < 1000;
#Iffalse MSG_TOUCHABLE_FOUND_CLOSED < 1000;
#Iffalse MSG_PARSER_CONTAINER_ISNT_OPEN < 1000;
Constant SKIP_MSG_CLOSE_NOT_OPEN;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CUT_NO_USE < 1000;
#Iffalse MSG_JUMP_OVER < 1000;
#Iffalse MSG_TIE_DEFAULT < 1000;
#Iffalse MSG_CLIMB_DEFAULT < 1000;
Constant SKIP_MSG_CUT_NO_USE;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_LOCK_ALREADY_LOCKED < 1000;
#Iffalse MSG_UNLOCK_ALREADY_UNLOCKED < 1000;
Constant SKIP_MSG_LOCK_ALREADY_LOCKED;
#Endif;
#Endif;

#Iffalse MSG_LOCK_KEY_DOESNT_FIT < 1000;
#Iffalse MSG_UNLOCK_KEY_DOESNT_FIT < 1000;
Constant SKIP_MSG_LOCK_KEY_DOESNT_FIT;
#Endif;
#Endif;

#Iffalse MSG_RUB_DEFAULT < 1000;
#Iffalse MSG_SQUEEZE_DEFAULT < 1000;
Constant SKIP_MSG_RUB_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_LOOKMODE_NORMAL < 1000;
#Iffalse MSG_LOOKMODE_LONG < 1000;
#Iffalse MSG_LOOKMODE_SHORT < 1000;
Constant SKIP_MSG_LOOKMODE;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NOT_CONTAINER < 1000;
#Ifndef MSG_EMPTY_NOT_CONTAINER;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Ifnot;
#Iffalse MSG_EMPTY_NOT_CONTAINER < 1000;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_SCORE;
#Iffalse MSG_NOTIFY_ON < 1000;
#Iffalse MSG_NOTIFY_OFF < 1000;
Constant SKIP_MSG_NOTIFY_ON;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_DARKNESS;
#Iffalse MSG_EXAMINE_DARK < 1000;
#Iffalse MSG_SEARCH_DARK < 1000;
Constant SKIP_MSG_EXAMINE_DARK;
#Endif;
#Endif;
#Endif;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(p_msg ofclass String)
		print_ret (string) p_msg;

#Ifdef LibraryMessages;
	if(p_msg > 999) {
		return LibraryMessages(p_msg, p_arg_1, p_arg_2);
	}
#Endif;

	! Not a string, there should be code for the message here
	switch(p_msg) {
#Iftrue MSG_TAKE_DEFAULT < 1000;
	MSG_TAKE_DEFAULT:
		"Tomad", (_o) noun, ".";
#EndIf;
#Iftrue MSG_DROP_DROPPED < 1000;
	MSG_DROP_DROPPED:
		"Dejad", (_o) noun, ".";
#EndIf;
#Iftrue MSG_TAKE_SCENERY < 1000;
	MSG_TAKE_SCENERY:
		print_ret (CTheyreorIts) noun, " difícilmente transportable", (_s) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_DEFAULT;
	MSG_PUSH_DEFAULT, MSG_PULL_DEFAULT, MSG_TURN_DEFAULT:
		"No ocurre nada evidente.";
#Endif;
#Ifndef SKIP_MSG_PUSH_STATIC;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC, MSG_TAKE_STATIC:
		print_ret (CTheyreorThats) noun, " fij", (_o) noun, " en el sitio.";
#Endif;
#Ifndef SKIP_MSG_PUSH_SCENERY;
	MSG_PUSH_SCENERY, MSG_PULL_SCENERY, MSG_TURN_SCENERY:
		"¡Menudo concepto!";
#Endif;
#IfDef SACK_OBJECT;
#IfTrue MSG_SACK_PUTTING < 1000;
	MSG_SACK_PUTTING:
	! p_arg_1 = the object being put into SACK_OBJECT.
		"(poniendo ", (the) p_arg_1, " dentro ", (de) SACK_OBJECT, " para hacer sitio)";
#EndIf;
#EndIf;
#IfTrue MSG_PROMPT < 1000;
	MSG_PROMPT:
		print "> ";
		rtrue;
#EndIf;
#IfTrue MSG_INVENTORY_DEFAULT < 1000;
	MSG_INVENTORY_DEFAULT:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		p_arg_1 = "Llevas ";
		if(inventory_style == 0) {
			p_arg_1 = "Llevas:";
			p_arg_2 = NEWLINE_BIT;
		}
		if(PrintContents(p_arg_1, player, p_arg_2)) {
			if(inventory_style) print ".^";
			rtrue;
		}
		rfalse;
#EndIf;
#IfTrue MSG_EXAMINE_NOTHING_SPECIAL < 1000;
	MSG_EXAMINE_NOTHING_SPECIAL:
		"No hay nada de especial en ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_ANIMATE;
	MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE, MSG_TURN_ANIMATE, MSG_CLIMB_ANIMATE:
		"Eso sería poco cortés.";
#Endif;
#Ifndef SKIP_MSG_DROP_NOT_HOLDING;
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
	MSG_WEAR_NOT_HOLDING:
		"No estás llevándo", (_lo) noun, ".";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_OPEN_YOU_CANT, MSG_CLOSE_YOU_CANT, MSG_ENTER_YOU_CANT,
	MSG_LOCK_NOT_A_LOCK, MSG_UNLOCK_NOT_A_LOCK, MSG_WEAR_NOT_CLOTHING:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"No puedes ", (verbname) p_arg_1, " ", (eso) noun, ".";
#Endif;
#IfTrue MSG_EAT_INEDIBLE < 1000;
	MSG_EAT_INEDIBLE:
		print_ret (CTheyreorIts) noun, " claramente incomible", (_s) noun, ".";
#EndIf;
#IfTrue MSG_OPEN_ALREADY < 1000;
	MSG_OPEN_ALREADY:
		print_ret (CTheyreorThats) noun, " ya abiert", (_o) noun, ".";
#EndIf;
#IfTrue MSG_OPEN_LOCKED < 1000;
	MSG_OPEN_LOCKED:
		print_ret (CTheyreorThats) noun, " cerrad", (_o) noun, ".";
#EndIf;
#IfTrue MSG_PUTON_NOT_SUPPORTER < 1000;
	MSG_PUTON_NOT_SUPPORTER:
		"No puedes poner cosas sobre ", (eso) second, ".";
#EndIf;
#Ifndef SKIP_MSG_TAKE_ANIMATE;
	MSG_TAKE_ANIMATE, MSG_EAT_ANIMATE:
		"No creo que ", (the) noun, " vea", (_n) noun, " bien eso.";
#Endif;
#Ifndef SKIP_MSG_TAKE_PLAYER_PARENT;
	MSG_TAKE_PLAYER_PARENT, MSG_GO_FIRST_LEAVE, MSG_EXIT_FIRST_LEAVE:
	! p_arg_1 = the object the player has to leave to perform the action.
		"Primero, deberías dejar ", (the) p_arg_1, ".";
#Endif;
#Iftrue MSG_OPEN_DEFAULT < 1000;
	MSG_OPEN_DEFAULT:
		print "Abres ", (the) noun;
		if(noun has container && noun hasnt transparent &&
				~~IndirectlyContains(noun, player)) {
			print ", revelando ";
			if(PrintContents(0, noun)==false) print "nada en especial";
		}
		".";
#Endif;
#Iftrue MSG_LOOK_BEFORE_ROOMNAME < 1000;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	!p_arg_1 = the base verb for this action ('open', 'close' etc).
    MSG_CLOSE_DEFAULT:
        "Cierras ", (the) noun, ".";
    MSG_LOCK_DEFAULT:
        "Echas el cerrojo en ", (the) noun, ".";
    MSG_UNLOCK_DEFAULT:
        "Quitas el cerrojo a ", (the) noun, ".";
    MSG_ENTER_DEFAULT:
        if (noun has container) print "Entras en";
        else print "Subes en";
        " ", (the) noun, ".";
    MSG_EXIT_DEFAULT:
        if (noun has container) print "Sales";
        else print "Bajas";
        " ", (de) noun, ".";
#Endif;
#Ifndef SKIP_MSG_GIVE_DEFAULT;
	MSG_GIVE_DEFAULT, MSG_SHOW_DEFAULT:
		print_ret (The) second, " no parece", (_n) noun, " interesad", (_o) noun, ".";
#Endif;
#Ifndef SKIP_MSG_ASKFOR_DEFAULT;
	MSG_ASKFOR_DEFAULT, MSG_ASKTO_DEFAULT, MSG_ORDERS_WONT:
	! p_arg_1 = the actor which the player has asked to do something.
		print_ret (The) p_arg_1, " tiene", (_n) noun, " cosas mejores que hacer.";
#Endif;
#Ifndef SKIP_MSG_ENTER_NOT_OPEN;
	MSG_ENTER_NOT_OPEN, MSG_EXIT_NOT_OPEN, MSG_INSERT_NOT_OPEN,
	MSG_GO_DOOR_CLOSED, MSG_EMPTY_IS_CLOSED:
	! p_arg_1 = the object which is closed, thus blocking the player's action.
		"No puedes, dado que ", (ObjIs) p_arg_1, " cerrad", (_o) p_arg_1, ".";
#Endif;
#Ifndef SKIP_MSG_GIVE_PLAYER;
	MSG_GIVE_PLAYER, MSG_TAKE_ALREADY_HAVE:
		"Ya ", (_lo) noun, " tienes.";
#Endif;
#Ifndef SKIP_MSG_SAVE_FAILED;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		"Falló ", (verbname) verb_word, ".";
#Endif;
#Ifndef SKIP_MSG_INSERT_ALREADY;
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY, MSG_TRANSFER_ALREADY:
		"Ya está allí.";
#Endif;
#Ifndef SKIP_MSG_INSERT_ANIMATE;
	MSG_INSERT_ANIMATE, MSG_PUTON_ANIMATE:
		"Intenta darle", (_s) second, " ",(the) noun," en vez de eso.";
#Endif;
#Ifndef SKIP_MSG_INSERT_NO_ROOM;
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"No hay más sitio.";
#Endif;
#IfTrue MSG_INSERT_DEFAULT < 1000;
	MSG_INSERT_DEFAULT:
		"Pones ", (the) noun, " dentro ", (de) second, ".";
#EndIf;
#IfTrue MSG_PUTON_DEFAULT < 1000;
	MSG_PUTON_DEFAULT:
		"Pones ", (the) noun, " sobre ", (the) second, ".";
#EndIf;
#Ifndef SKIP_MSG_ASK_DEFAULT;
	MSG_ASK_DEFAULT, MSG_ANSWER_DEFAULT, MSG_SHOUT_DEFAULT, MSG_SHOUTAT_DEFAULT:
		"No hay respuesta.";
#Endif;
#IfTrue MSG_WEAR_ALREADY_WORN < 1000;
	MSG_WEAR_ALREADY_WORN:
		"Ya llevas puest", (_o) noun, " ", (ItorThem) noun, ".";
#EndIf;
#IfTrue MSG_WEAR_DEFAULT < 1000;
	MSG_WEAR_DEFAULT:
		"Te pones ", (the) noun, ".";
#EndIf;
#IfTrue MSG_DISROBE_NOT_WEARING < 1000;
	MSG_DISROBE_NOT_WEARING:
		"No llevas puest", (_o) noun, " ", (the) noun, ".";
#EndIf;
#IfTrue MSG_DISROBE_DEFAULT < 1000;
	MSG_DISROBE_DEFAULT:
		"Te quitas ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_SWITCH_ON_ON;
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, " ya ", (OnOff) noun, ".";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_DEFAULT;
	MSG_SWITCH_ON_DEFAULT:
        "Enciendes ", (the) noun, ".";
        !activez éclairez/OK
    MSG_SWITCH_OFF_DEFAULT:
        "Apagas ", (the) noun, ".";
        !désactivez/OK
#Endif;
#Iftrue MSG_AUTO_TAKE < 1000;
	MSG_AUTO_TAKE:
	! p_arg_1 = the object the player automatically picks up
	"(tomando ", (the) p_arg_1, " primero)";
#Endif;
#Iftrue MSG_AUTO_DISROBE < 1000;
	MSG_AUTO_DISROBE:
	! p_arg_1 = the object the player automatically takes off.
		"(quitándote ", (the) p_arg_1, " primero)";
#Endif;
#Iftrue MSG_AUTO_DISROBE_WORN < 1000;
	MSG_AUTO_DISROBE_WORN:
	! p_arg_1 = the object the player would need to take off.
		"Pero necesitarías quitarte ", (the) p_arg_1, " primero.";
#Endif;
#IfTrue MSG_PARSER_NOTHING_TO_VERB < 1000;
	MSG_PARSER_NOTHING_TO_VERB:
	! p_arg_1 = the last word in player input + 1.
		if(action == ##Drop or ##Insert) {
			if((parse + 2 + (p_arg_1 - 2) *4) --> 0 == ALL_WORD)
				"No llevas nada.";
			if(TryNumber(verb_wordnum + 1) > 0) "No tienes nada.";
		}
		print "No hay cosas disponibles que coincidan con ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1 - 1);
		"~.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOT_HOLDING;
	MSG_PARSER_NOT_HOLDING, MSG_AUTO_TAKE_NOT_HELD, MSG_WAVE_NOTHOLDING:
	! p_arg_1 = the object which the player must be holding to perform the
	! action but isn't.
		"Pero si no estás sujetando ", (the) p_arg_1, ".";
#Endif;
#IfTrue MSG_PARSER_PARTIAL_MATCH < 1000;
	MSG_PARSER_PARTIAL_MATCH:
	! p_arg_1 = the word number of the last word understood + 1.
		print "Sólo te entendí hasta ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1);
		"~ pero luego me perdí.";
#EndIf;
#IfTrue MSG_PARSER_CANT_TALK < 1000;
	MSG_PARSER_CANT_TALK:
	! p_arg_1 = the object which can't be talked to.
		"No puedes hablar con ", (the) p_arg_1, ".";
#EndIf;
#IfTrue MSG_PARSER_NO_NEED_REFER_TO < 1000;
	MSG_PARSER_NO_NEED_REFER_TO:
		print "No necesitas referirte a ~";
		_PrintUnknownWord();
		"~ en este juego.";
#EndIf;
#IfTrue MSG_PARSER_DONT_UNDERSTAND_WORD < 1000;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
			print "Perdón, no entiendo ";
			if(oops_unfixed) {
				"tampoco esa otra palabra.";
			}
			print "lo que ~";
			_PrintUnknownWord();
			"~ significa.";
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_PREFIX < 1000;
	MSG_PARSER_BAD_PATTERN_PREFIX:
		print "Creo que quisiste decir ~";
		rtrue;
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_SUFFIX < 1000;
	MSG_PARSER_BAD_PATTERN_SUFFIX:
		"~. Por favor, inténtalo de nuevo.";
#EndIf;
#IfTrue MSG_PARSER_NO_IT < 1000;
	MSG_PARSER_NO_IT:
		"No se a qué se refiere ~",(address) p_arg_1, "~.";
#EndIf;
#IfTrue MSG_PARSER_CANT_SEE_IT < 1000;
	MSG_PARSER_CANT_SEE_IT:
		"No puedes ver ~",(address) p_arg_1, "~ (", (name) p_arg_2, ") por el momento.";
#EndIf;
#Ifndef SKIP_MSG_CLOSE_NOT_OPEN;
	MSG_CLOSE_NOT_OPEN, MSG_TOUCHABLE_FOUND_CLOSED,
	MSG_PARSER_CONTAINER_ISNT_OPEN:
	! p_arg_1 = the object which isn't open.
		print_ret (The) p_arg_1, " no está", (_n) p_arg_1, " abiert", (_o) p_arg_1, ".";
#Endif;
#IfTrue MSG_CONSULT_NOTHING_INTERESTING < 1000;
	MSG_CONSULT_NOTHING_INTERESTING:
		"No encuentras nada de interés en ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_CUT_NO_USE;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT, MSG_CLIMB_DEFAULT:
		"No conseguirás nada así.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED;
	MSG_LOCK_ALREADY_LOCKED:
		print_ret (The) noun, " ya está", (_n) noun, " con cerrojo.";
	MSG_UNLOCK_ALREADY_UNLOCKED:
		print_ret (The) noun, " ya está", (_n) noun, " sin cerrojo.";
#Endif;
#IfTrue MSG_LOCK_CLOSE_FIRST < 1000;
	MSG_LOCK_CLOSE_FIRST:
		"Primero deberías cerrar ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_LOCK_KEY_DOESNT_FIT;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		print_ret (The) second, " no parece", (_n) second, " servir para ese cerrojo.";
#Endif;
#IfTrue MSG_EXAMINE_CLOSED < 1000;
	MSG_EXAMINE_CLOSED:
	! p_arg_1 = the examines object (which is closed).
		print_ret (CObjIs) p_arg_1, " cerrad", (_o) p_arg_1, ".";
#Endif;
#IfTrue MSG_REMOVE_NOT_HERE < 1000;
	MSG_REMOVE_NOT_HERE:
		"Pero ", (the) noun, " no está", (_n) noun, " aquí ahora.";
#EndIf;
#IfTrue MSG_SEARCH_IN_IT_ISARE < 1000;
	MSG_SEARCH_IN_IT_ISARE:
		print (The) noun, " contiene", (_n) noun, " ";
		PrintContents(0, noun);
		".";
#EndIf;
#IfTrue MSG_SEARCH_ON_IT_ISARE < 1000;
	MSG_SEARCH_ON_IT_ISARE:
		print "En ", (the) noun;
		PrintContents(" ", noun, ISARE_BIT);
		".";
#EndIf;
#IfTrue MSG_SEARCH_EMPTY < 1000;
	MSG_SEARCH_EMPTY:
		print_ret (CObjIs) noun, " vací", (_o) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_NOTHING_ON < 1000;
	MSG_SEARCH_NOTHING_ON:
		"No hay nada en ", (the) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_CANT_SEE_CLOSED < 1000;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"No puedes ver el interior, puesto que ", (ObjIs) noun, " cerrad", (_o) noun, ".";
#EndIf;
#IfTrue MSG_EXAMINE_ONOFF < 1000;
	MSG_EXAMINE_ONOFF:
		print_ret (CObjIs) noun, " actualmente ", (onoff) noun, ".";
#EndIf;
#IfTrue MSG_EAT_DEFAULT < 1000;
	MSG_EAT_DEFAULT:
		"Te comes ", (the) noun, ". No está", (_n) noun, " mal.";
#EndIf;
#Ifndef SKIP_MSG_RUB_DEFAULT;
MSG_RUB_DEFAULT, MSG_SQUEEZE_DEFAULT:
	"No consigues nada así.";
#Endif;
#IfTrue MSG_TAKE_NOT_AVAILABLE < 1000;
	MSG_TAKE_NOT_AVAILABLE:
		print_ret (The) noun, " no está", (_n) noun, " disponible", (_s) noun, ".";
#EndIf;
#IfTrue MSG_TAKE_BELONGS < 1000;
	MSG_TAKE_BELONGS:
		! p_arg_1 = the object that is held by p_arg_2
		print_ret (The) p_arg_1, " parece", (_n) p_arg_1, " pertenecer a ", (the) p_arg_2, ".";
#EndIf;
#IfTrue MSG_TAKE_PART_OF < 1000;
	MSG_TAKE_PART_OF:
		! p_arg_1 = the object that is part of p_arg_2
		print_ret (The) p_arg_1, " parece", (_n) p_arg_1, " ser parte de ", (the) p_arg_2, ".";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef SKIP_MSG_EXAMINE_DARK;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Pero está oscuro.";
#Endif;
#Endif;
#Iftrue MSG_SCORE_DEFAULT < 1000;
	MSG_SCORE_DEFAULT:
#Ifdef NO_SCORE;
		"No hay puntuación en este juego.";
#Ifnot;
		if (deadflag) print "Durante el juego "; else print "Por ahora ";
		print "has obtenido ", score, " punto";
		if(score ~= 1) print "s";
		print " de un total de ", MAX_SCORE, ", en ", turns, " turno";
		if(turns ~= 1) print "s";
		rtrue;
#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
#IfTrue MSG_FULLSCORE_START < 1000;
	MSG_FULLSCORE_START:
		print "La puntuación se comp";
		if(deadflag) print "uso"; else print "one";
		" de la siguiente forma:";
#EndIf;
#IfTrue MSG_FULLSCORE_END < 1000;
	MSG_FULLSCORE_END:
		"en total (de ", MAX_SCORE, ")";
#EndIf;
#EndIf;
#Ifndef SKIP_MSG_LOOKMODE;
	MSG_LOOKMODE_NORMAL, MSG_LOOKMODE_LONG, MSG_LOOKMODE_SHORT:
		print "Este juego está ahora en modo ";
		if(lookmode==1) print "normal ~";
		if(lookmode==2) print "~largo";
		else {
			if(lookmode==3) print "~super";
			print "breve";
		}
		print "~, que ";
		if(lookmode ~= 1) print "siempre ";
		print "da descripciones ";
		if(lookmode == 3) print "cortas";
		else print "largas";
		print " de las localidades ";
		if(lookmode == 1)
			"nunca vistas y descripciones cortas en el resto de los casos.";
		print "(incluso si ";
		if(lookmode ~= 2) print "no ";
		"has estado en ellas antes).";
#Endif;
#IfTrue MSG_RESTART_RESTORE_OR_QUIT < 1000;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^¿Te gustaría REINICIAR, CARGAR";
#Ifdef OPTIONAL_PROVIDE_UNDO_FINAL;
	#Ifdef DEATH_MENTION_UNDO;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0)
				print ", deshacer el último movimiento (UNDO)";
	#Ifnot;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0 && deadflag ~= GS_WIN)
				print ", deshacer el último movimiento (UNDO)";
	#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
		print ", dar la puntuación TOTAL para el juego";
#EndIf;
		if(AMUSING_PROVIDED == 0 && deadflag == 2) print ", ver sugerencias de cosas INTERESANTES para hacer (AMUSING)";
		print " o ACABAR? ";
		rtrue;
#EndIf;
#IfTrue MSG_AREYOUSUREQUIT < 1000;
	MSG_AREYOUSUREQUIT: ! print and rtrue to avoid newline
		print "¿Estás seguro de querer salir del juego? ";
		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_WON < 1000;
	MSG_YOU_HAVE_WON: ! print and rtrue to avoid newline
 		print "Has ganado";
 		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_DIED < 1000;
	MSG_YOU_HAVE_DIED: ! print and rtrue to avoid newline
		print "Has muerto";
		rtrue;
#EndIf;
#IfTrue MSG_ENTER_BAD_LOCATION < 1000;
	MSG_ENTER_BAD_LOCATION:
		print "Tienes que ";
		if(player notin location && ~~IndirectlyContains(parent(player), noun))
			print "salir ", (de) parent(player);
		else
			print "entrar en ", (the) parent(noun);
		" primero.";
#EndIf;
#IfTrue MSG_ENTER_HELD < 1000;
	MSG_ENTER_HELD:
		"No puedes meterte en ", (the) noun, " mientras ", (_lo) noun, " llevas.";
#EndIf;
#Ifndef SKIP_MSG_INSERT_NOT_CONTAINER;
#ifdef MSG_EMPTY_NOT_CONTAINER;
	MSG_INSERT_NOT_CONTAINER, MSG_EMPTY_NOT_CONTAINER:
#Ifnot;
	MSG_INSERT_NOT_CONTAINER:
#Endif;
		! p_arg_1 = the object that can't contain things
		print_ret (The) p_arg_1, " no puede", (_n) p_arg_1, " contener cosas.";
#Endif;
#IfTrue MSG_YES_OR_NO < 1000;
	MSG_YES_OR_NO:
		print "Por favor, contesta sí o no: ";
		rtrue;
#EndIf;
#IfTrue MSG_RESTART_CONFIRM < 1000;
	MSG_RESTART_CONFIRM:
		print "¿Quieres reiniciar seguro? ";
		rtrue;
#Endif;

#Ifndef NO_SCORE;
#Ifndef SKIP_MSG_NOTIFY_ON;
	MSG_NOTIFY_ON, MSG_NOTIFY_OFF:
		print "Notificación de puntuación ";
		if(p_msg == MSG_NOTIFY_ON) "encencida.";
		"apagada.";
#Endif;
#Iftrue MSG_PARSER_NEW_SCORE < 1000;
	MSG_PARSER_NEW_SCORE:
		! p_arg_1 = the old score
		print "^[La puntuación ha ";
		if(p_arg_1 < score) {
			p_arg_2 = score - p_arg_1;
			print "creci";
		} else {
			p_arg_2 = p_arg_1 - score;
			print "mengua";
		}
		print "do ", p_arg_2, " punto";
		if(p_arg_2 > 1) print "s";
		".]";
#Endif;
#Endif;




#IfDef OPTIONAL_EXTENDED_VERBSET;
#IfTrue MSG_BLOW_DEFAULT < 1000;
	MSG_BLOW_DEFAULT:
		"No puedes soplar ", (the) noun, " con seguridad.";
#EndIf;
#IfTrue MSG_EMPTY_ALREADY_EMPTY < 1000;
	MSG_EMPTY_ALREADY_EMPTY:
		! p_arg_1 = the object that is already empty
		print_ret (CObjIs) p_arg_1, " ya vací", (_o) p_arg_1, ".";
#EndIf;
#IfTrue MSG_SET_DEFAULT < 1000;
	MSG_SET_DEFAULT:
		"No, no puedes ajustar ", (eso) noun, ".";
#EndIf;
#IfTrue MSG_SET_TO_DEFAULT < 1000;
	MSG_SET_TO_DEFAULT:
		"No, no puedes ajustar ", (eso) noun, " a nada.";
#EndIf;
#IfTrue MSG_WAVE_DEFAULT < 1000;
	MSG_WAVE_DEFAULT:
		"Sientes vergüenza al agitar ", (the) noun, ".";
#EndIf;
#EndIf;

default:
		! No code found. Print an error message.
		_RunTimeError(ERR_UNKNOWN_MSGNO);
	}
];

[ eso p_obj;
	print "es", (_o) p_obj;
	rtrue;
];

[ ItorThem p_obj;
	if (p_obj == player) { print " a tí mismo"; rtrue; }
	if (p_obj has animate) {
		if (p_obj has pluralname) { 
			if (p_obj has female) { print "a ellos"; rtrue; }
			if (p_obj hasnt female) { print "a ellas"; rtrue; }
		} else {
			if (p_obj has female) { print "a él"; rtrue; }
			if (p_obj hasnt female) { print "a ella"; rtrue; }
		}
	}
	print (eso) p_obj;
];

[ CObjIs p_obj;
	print (The) p_obj, " ", (isorare) p_obj;
];

[ ObjIs p_obj;
	print (the) p_obj, " ", (isorare) p_obj;
];

[ IsorAre p_obj;
	print "está", (_n) p_obj;
];

[ CTheyreorThats p_obj;
	if (p_obj == player)			 { print "Estás"; return; }
	if (p_obj has pluralname)		{ print "Están"; return; }
	print "Está";
];

[ CTheyreorIts p_obj;
	if (p_obj == player)			 { print "Eres"; return; }
	if (p_obj has pluralname)		{ print "Son"; return; }
	print "Es";
];

[OnOff p_obj;
	if(p_obj has on) print "encendid", (_o) p_obj;
	else print "apagad", (_o) p_obj;
	return;
];

[_o p_obj;
	if (p_obj has female) print "a";
	else print "o";
	if (p_obj has pluralname) print "s";
	return;
];

[_s p_obj;
	if (p_obj has pluralname) print "s";
	return;
];

[_n p_obj;
	if (p_obj has pluralname) print "n";
	return;
];

[_lo p_obj;
	if (p_obj has female) print "la";
	if (p_obj hasnt female) print "lo";
	if (p_obj has pluralname) print "s";
	return;
];

[de p_obj;
	if (p_obj has female || p_obj has pluralname) print "de ", (the) p_obj;
	else print "del ", (object) p_obj;
];


!
! Error messages
!
Constant ERR_TOO_MANY_TIMERS_DAEMONS 1;
Constant ERR_OBJECT_HASNT_PROPERTY 2;
Constant ERR_SCOPE_FULL 3;
Constant ERR_UNKNOWN_MSGNO 4;
Constant ERR_INVALID_DIR_PROP 5;
Constant ERR_TOO_MANY_FLOATING 6;
Constant ERR_NOT_DIR_PROP 7;
Constant ERR_NOT_FAKE_OBJ 8;
Constant ERR_ILLEGAL_CHOOSEOBJNO 9;
Constant ERR_BUFFER_OVERRUN 10;

[_RunTimeError p_err p_obj _parent;
	print "^[PunyInform error: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
		print p_err;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		print " - ";
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Too many timers/daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Object lacks required property";
		ERR_SCOPE_FULL:
			print "Scope full";
		ERR_UNKNOWN_MSGNO:
			print "Unknown message#";
		ERR_INVALID_DIR_PROP:
			print "GoSub called with invalid direction property";
		ERR_TOO_MANY_FLOATING:
			print "Too many floating objects";
		ERR_NOT_DIR_PROP:
			print "DirPropToFakeObj called with non-dirprop";
		ERR_NOT_FAKE_OBJ:
			print "FakeObjToDirProp called with non-fakeobj";
		ERR_ILLEGAL_CHOOSEOBJNO:
			print "ChooseObjectsFinal_(Pick or Discard) called with nonexistent array index";
#Ifdef DEBUG;
		ERR_BUFFER_OVERRUN:
			print "Buffer overrun: Printing too many characters to a buffer";
#Endif;
		default:
			print "Unknown error";
		}
#EndIf;
	}
	print "]^";
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(p_obj ofclass object) {
		_parent = parent(p_obj);
		print "Offending object: ", (the) p_obj, " (", p_obj, ") in ", (name) _parent, " (", _parent, ")^";
	}
#Ifnot;
	_parent = p_obj; ! Avoid compiler warning
#EndIf;
	rtrue;
];
