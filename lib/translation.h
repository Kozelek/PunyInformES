! ==============================================================================
! Pablo Martínez 2025
! ==============================================================================
! Este fichero se encarga de modificar el comando del jugador para que algunos
! elementos del idioma sean entendidos por el analizador sintáctico.
! En este momento se limita a procesar los sufijos le,la,lo,les,las,los y te
! (como en "toma la caja y abrela") separándolos con un guión y un espacio
! (convierte "abrela" en "abre -la") para que sea una palabra distinta que el
! analizador pueda detectar.
! En este momento, solo puede funcionar para la versión V5 de la máquina Inform
! puesto que en V3 no puede analizar el comando del jugador una segunda vez
! después de leído. Eso significa que NO existen sufijos en V3.
! ==============================================================================
! Source encoding UTF-8 No Mark
System_file;

! From library 6.12
! To protect against a bug in early versions of the "Zip" interpreter:
[ Tokenise__ b p; b->(2 + b->1) = 0; @tokenise b p; ];

! From library 6.12
[ LTI_Insert i ch  b y;

    ! Protect us from strict mode, as this isn't an array in quite the
    ! sense it expects
    b = buffer;

    ! Insert character ch into buffer at point i.
    ! Being careful not to let the buffer possibly overflow:
    y = b->1;
    if (y > b->0) y = b->0;

    ! Move the subsequent text along one character:
    for (y=y+2 : y>i : y--) b->y = b->(y-1);
    b->i = ch;
    ! And the text is now one character longer:
    if (b->1 < b->0) (b->1)++;
];

[ Translation w x length change;
	for (w=parse->1:w>=1:w--) {
		length = parse->(4*w);
		if (parse-->(w*2-1) == 0 && length >= 3) {
			x = parse->(4*w + 1) + length - 1; 
			if (buffer->x == 's' && length >= 4 && (buffer->(x-1) == 'o' || buffer->(x-1) == 'e' || buffer->(x-1) == 'a') && buffer->(x-2) == 'l') { ! sufijos -las -los -les
				change = 1;
				Insert_Suffix(x, 2);
			} else if ((buffer->x == 'a' || buffer->x == 'o' || buffer->x == 'e') && buffer->(x-1) == 'l') { ! sufijos -la -lo -le
				change = 1;
				Insert_Suffix(x, 1);
			} else if (buffer->x == 'e' && buffer->(x-1) == 't') { ! sufijos -te
				change = 1;
				Insert_Suffix(x, 1);
			}
		}
	}
	if (change > 0) { ! ha habido un cambio
		Tokenise__(buffer, parse);
	}
	rtrue;
];

[ Insert_Suffix pos len;
	LTI_Insert(pos-len, '-');
	LTI_Insert(pos-len, ' ');
];