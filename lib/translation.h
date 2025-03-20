! ==============================================================================
! Pablo Martínez 2025
! Version 0.1
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

[ Translation w x length prefix;
	for (w=parse->1:w>=1:w--) {
		length = parse->(4*w);
		if (parse-->(w*2-1) == 0 && length >= 3) {
			x = parse->(4*w + 1) + length - 1; 
			if (buffer->x == 's' && length >= 4 && (buffer->(x-1) == 'o' || buffer->(x-1) == 'e' || buffer->(x-1) == 'a') && buffer->(x-2) == 'l') { ! prefijos -las -los -les
				prefix = 2;
				LTI_Insert(x-prefix, '-');
				LTI_Insert(x-prefix, ' ');
			} else if ((buffer->x == 'a' || buffer->x == 'o' || buffer->x == 'e') && buffer->(x-1) == 'l') { ! prefijos -la -lo -le
				prefix = 1;
				LTI_Insert(x-prefix, '-');
				LTI_Insert(x-prefix, ' ');
			} else if (buffer->x == 'e' && buffer->(x-1) == 't') { ! prefijo -te
				prefix = 1;
				LTI_Insert(x-prefix, '-');
				LTI_Insert(x-prefix, ' ');
			}
		}
	}
	if (prefix > 0) {
		Tokenise__(buffer, parse);
	}
	rtrue;
];