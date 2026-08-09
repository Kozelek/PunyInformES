! Librería para dar soporte a las ventanas, los colores, el cursor y los comandos del ratón de Z6
!
! Al final de este archivo hay un ejemplo que muestra la mayoría de los
! comandos en uso. Compílalo con:
! > inform -v6 --define Z6_TESTPROGRAM  ext_z6graphics.h
! y ejecuta el archivo resultante ext_z6graphics.z6 en sfrotz o un programa similar.

System_file;
#Iffalse (#version_number == 6);
error "ext_z6graphics solo se puede utilizar en modo -v6"
#Endif;

! En Z6, el modelo de pantalla funciona con unidades que no están especificadas
! en la especificación. Intérpretes como sfrotz utilizan la
! resolución de pantalla (640x400) como unidades, pero otros pueden hacerlo
! de forma diferente. Los juegos suelen funcionar con coordenadas de texto (filas y columnas),
! por lo que esta extensión define dos versiones de las funciones (_Units y _Chars)
! y proporciona estas funciones de conversión:

[ Z6RowToY p_row; return p_row * Z6FontHeight(); ];
[ Z6ColToX p_col; return p_col * Z6FontWidth(); ];
[ Z6YToRow p_y; return p_y / Z6FontHeight(); ];
[ Z6XToCol p_x; return p_x / Z6FontWidth(); ];

! ========================
!    Manejo de ventanas
! ========================
!
! propiedades de ventanas, ver z-spec 8.8.3.2
Constant Z6_WP_Y_COORD      =  0; ! _Units
Constant Z6_WP_X_COORD      =  1; ! _Units
Constant Z6_WP_Y_SIZE       =  2; ! _Units
Constant Z6_WP_X_SIZE       =  3; ! _Units
Constant Z6_WP_Y_CURSOR     =  4; ! _Units
Constant Z6_WP_X_CURSOR     =  5; ! _Units
Constant Z6_WP_LEFT_MARGIN  =  6; ! _Units
Constant Z6_WP_RIGHT_MARGIN =  7; ! _Units
Constant Z6_WP_NL_ROUTINE   =  8;
Constant Z6_WP_NL_COUNT     =  9;
Constant Z6_WP_TEXT_STYLE   = 10;
Constant Z6_WP_COLOUR       = 11;
Constant Z6_WP_FONT         = 12;
Constant Z6_WP_FONT_SIZE    = 13; ! _Units
Constant Z6_WP_ATTRIBUTES   = 14;
Constant Z6_WP_LINE_COUNT   = 15;
! banderas de estilo de ventana (see z-spec 8.8.3.1)
Constant Z6_WIN_WRAPPING    = 1;
Constant Z6_WIN_SCROLLING   = 2;
Constant Z6_WIN_TRANSCRIPT  = 4;
Constant Z6_WIN_BUFFERED    = 8;
! operaciones @window_stype
Constant Z6_WSTYLE_SET      = 0;
Constant Z6_WSTYLE_ON       = 1;
Constant Z6_WSTYLE_OFF      = 2;
Constant Z6_WSTYLE_TOGGLE   = 3;

Constant Z6_CURRENT_WINDOW = -3; ! valor mágico para ventana actual

[ Z6ShowWindow_Units p_window p_x p_y p_w p_h;
    @move_window p_window p_y p_x;
    @window_size p_window p_h p_w;
    @erase_window p_window;
    @set_window p_window;
];

[ Z6ShowWindow_Chars p_window p_start_x p_start_y p_width p_height;
    ! La posición es una celda de caracteres con base 1, y la unidad (1,1) es la superior izquierda.
    Z6ShowWindow_Units(p_window,
        Z6ColToX(p_start_x - 1) + 1, Z6RowToY(p_start_y - 1) + 1,
        Z6ColToX(p_width), Z6RowToY(p_height));
];

[ Z6HideWindow p_window;
    @erase_window p_window;
    @window_size p_window 0 0;
    @set_window 0;
];

[ Z6GetWindowProp p_win p_prop _value;
    @get_wind_prop p_win p_prop -> _value;
    return _value;
];

[ Z6SetWindowProp p_win p_prop p_value;
    @put_wind_prop p_win p_prop p_value;
];

[ Z6FormatWindow p_window p_flags p_operation;
    @window_style p_window p_flags p_operation;
];

[ Z6SetWindow p_window;
    @set_window p_window;
];

[ Z6EraseWindow p_window;
    @erase_window p_window;
];

! ========================
!      Manejo de color
! ========================

[ Z6SetColour p_foreground p_background p_window;
    @set_colour p_foreground p_background p_window;
];

! ========================
!      Manejo de ratón
! ========================
Array z6_current_mouse --> 4; ! updated by @read_mouse
! Códigos zscii del ratón (see z-spec 3.8.6)
Constant Z6_CLICK_MENU      = 252;
Constant Z6_CLICK_DOUBLE    = 253; 
Constant Z6_CLICK_SINGLE    = 254;

[ Z6MouseWindow p_window; ! -1 para toda la pantalla
    @mouse_window p_window;
];

[ Z6ReadMouse;
    @read_mouse z6_current_mouse;
];

[ Z6MouseRow_Units; 
    return z6_current_mouse --> 0;
];

[ Z6MouseCol_Units; 
    return z6_current_mouse --> 1;
];

[ Z6MouseRow_Chars; 
    return Z6YtoRow(Z6MouseRow_Units() -1) + 1;
];

[ Z6MouseCol_Chars; 
    return Z6XtoCol(Z6MouseCol_Units() -1) + 1;
];

! ========================
! Manejo de cursor de pantalla
! ========================
Array z6_current_cursor --> 2; ! actualizado por @get_cursor
[ Z6CursorRow_Units;
    @get_cursor z6_current_cursor;
    return z6_current_cursor-->0;
];

[ Z6CursorCol_Units;
    @get_cursor z6_current_cursor;
    return z6_current_cursor-->1;
];

[ Z6CursorRow_Chars;
    return Z6YToRow(Z6CursorRow_Units() - 1) + 1;
];

[ Z6CursorCol_Chars;
    return Z6XToCol(Z6CursorCol_Units() - 1) + 1;
];

[ Z6MoveCursor_Chars p_col p_row _x _y;
    _x = Z6ColToX(p_col - 1) + 1;
    _y = Z6RowToY(p_row - 1) + 1;
    @set_cursor _y _x;
];

! ========================
!     Manejo de fuente
! ========================

[ Z6FontHeight _h;
    _h = Z6GetWindowProp(Z6_CURRENT_WINDOW, Z6_WP_FONT_SIZE);
    _h = (_h & $ff00) / $100; ! la altura está en el byte alto
    if(_h < 1) _h = 1;
    return _h;
];

[ Z6FontWidth _w;
    _w = Z6GetWindowProp(Z6_CURRENT_WINDOW, Z6_WP_FONT_SIZE);
    _w = _w & $ff; ! el ancho es en el byte bajo
    if(_w < 1) _w = 1;
    return _w;
];

! ========================
!    Manejo de imágenes
! ========================

Array z6_picture_info --> 2; ! actualizado por @picture_data

[ Z6PictureExists p_picture;
    ! rtrue si existe, y actualiza z6_picture_info
    @picture_data p_picture z6_picture_info ?pictureExists;
    rfalse;
.pictureExists;
    rtrue;
];

[ Z6PictureHeight_Units p_picture;
    if(Z6PictureExists(p_picture)) return z6_picture_info-->0;
    rfalse;
];

[ Z6PictureWidth_Units p_picture;
    if(Z6PictureExists(p_picture)) return z6_picture_info-->1;
    rfalse;
];

[ Z6PictureRows_Chars p_picture _h _unitheight _fontheight;
    _unitheight = Z6PictureHeight_Units(p_picture);
    if(_unitheight == 0) rfalse;
    _fontheight = Z6FontHeight();
    ! redondeamos hacia arriba para asegurarnos de que cubrimos toda la imagen
    _h = (_unitheight + _fontheight - 1) / _fontheight;
    if(_h < 1) _h = 1;
    return _h;
];

[ Z6PictureCols_Chars p_picture _w _unitwidth _fontwidth;
    _unitwidth = Z6PictureWidth_Units(p_picture);
    if(_unitwidth == 0) rfalse;
    _fontwidth = Z6FontWidth();
    ! redondeamos hacia arriba para asegurarnos de que cubrimos toda la imagen
    _w = (_unitwidth + _fontwidth - 1) / _fontwidth;
    if(_w < 1) _w = 1;
    return _w;
];

[ Z6DrawPictureHere p_picture _x _y;
    @get_cursor z6_current_cursor;
    _x = z6_current_cursor --> 1;
    _y = z6_current_cursor --> 0;
    @draw_picture p_picture _y _x;
];

! ========================
!      Programa de prueba
! ========================
#Ifdef Z6_TESTPROGRAM;

! normalmente definido en globals.h en vez de aquí
Constant CLR_DEFAULT = 1;
Constant CLR_BLACK = 2;
Constant CLR_RED = 3;
Constant CLR_YELLOW = 5;
Constant CLR_BLUE = 6;
Constant CLR_CYAN = 8;
Constant CLR_WHITE = 9;

[ Main _c;
    ! Ventana 0 es la pantalla completa (fondo)
    Z6SetColour(CLR_WHITE, CLR_BLUE, 0);
    Z6EraseWindow(0);
    Z6SetWindow(0);
    Z6MoveCursor_Chars(1, 1);
    print "ventana 0: blanco sobre azul";

    ! Ventana 1, mostrará el estado del ratón
    Z6FormatWindow(1, Z6_WIN_WRAPPING, Z6_WSTYLE_SET);
    Z6SetColour(CLR_BLACK, CLR_CYAN, 1);
    Z6ShowWindow_Chars(1, 3, 4, 30, 3);
    Z6MoveCursor_Chars(1, 1);
    print "ventana 1: negro sobre celeste";
    Z6MoveCursor_Chars(4, 3);
    print "ratón: -,-";

    ! Ventana 2, esperando el input
    Z6FormatWindow(2, Z6_WIN_WRAPPING + Z6_WIN_BUFFERED, Z6_WSTYLE_SET);
    Z6SetColour(CLR_YELLOW, CLR_RED, 2);
    Z6ShowWindow_Chars(2, 6, 9, 30, 4);
    Z6MoveCursor_Chars(1, 1);
    print "ventana 2:^amarillo sobre rojo^^haz click, o pulsa RETURN para salir^";

    ! bucle principal: esperar a que se produzcan eventos del ratón o del teclado
    Z6MouseWindow(-1); ! los clicks en cualquier lugar de la pantalla cuentan
    while(true) {
        @read_char 1 -> _c;
        if(_c == 13) break;
        if(_c == Z6_CLICK_SINGLE or Z6_CLICK_DOUBLE or Z6_CLICK_MENU) {
            ! Informa del clic en la segunda línea de la ventana 1 y, a continuación, vuelve a la ventana 2.
            Z6ReadMouse();
            Z6SetWindow(1);
            Z6MoveCursor_Chars(4, 3);
            @erase_line 1;
            print "ratón: ", Z6MouseRow_Chars(), ",", Z6MouseCol_Chars();
            Z6SetWindow(2);
        }
    }

    ! Al borrar una ventana queda un hueco, así que vuelve a colocar toda la pantalla en su sitio.
    Z6HideWindow(2);
    Z6HideWindow(1);
    Z6SetColour(CLR_DEFAULT, CLR_DEFAULT, 0);
    Z6EraseWindow(0);
    Z6SetWindow(0);
    Z6MoveCursor_Chars(1, 1);
    print "hecho.^";
];

#Endif;

