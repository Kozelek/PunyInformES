# PunyInformES

PunyInformES es una biblioteca escrita en Inform 6 que permite a cualquier persona
crear aventuras de texto / ficción interactiva usando la máquina virtual Z-machine
para jugar en ordenadores de 8 bits y en plataformas más modernas. Proporciona un
analizador sintáctico, implementaciones de verbos comunes, así como un marco para
escribir aventuras de texto.

PunyInformES se basa en la biblioteca Inform 6, desarrollada por Graham Nelson.
Intentamos que sea fácil para los autores acostumbrados a escribir en Inform 6
empezar a usar PunyInform.

PunyInformES es la traducción de la librería PunyInform desarrollada por Johan
Berntsson y Fredrik Ramsberg. En general, para encontrar documentación sobre
PunyInformES, por el momento es imprescindible dirigirse al repositorio de
[PunyInform](https://github.com/johanberntsson/PunyInform).

Los juegos que utilizan PunyInform se pueden compilar en los formatos z3, z4, z5,
z6, z7 y z8. En comparación con la biblioteca de Inform 6, esto significa que no
tenemos compatibilidad con Glulx, pero sí tenemos compatibilidad con z3 y z4 (de las
que carece la biblioteca de Inform 6). También hay disponible una extensión que
ofrece compatibilidad básica con el modelo de pantalla z6 y con los gráficos.

## Comentarios relativos a la traducción de PunyInformES:

* PunyInform usa la Gramática Versión 3 que solo es soportada por versiones recientes
del compilador de Inform 6. PunyInform requiere al menos la versión 6.44 de Inform,
y recomendamos usar la última versión disponible.

* El parser intenta adivinar el infinitivo automáticamente solo en las versiones V5,
V6, V7 y V8. Para ello, elimina la última "r" de un verbo y comprueba si el imperativo
resultante existe en el vocabulario. Esto solo servirá con verbos regulares, como
"mira/mirar". En V3 o V4, sin embargo, será necesario definir el infinitivo en todo
caso. Si se desea tener un código que funcione tanto para V3 o V4 como para V5-V8 será
necesario escribir algo como esto:

```
#Iftrue #version_number < 5;
! V3 o V4
Verb 'mira' 'mirar'
    *                                    		-> Look;
#IfNot;
! V5, V6, V7 y V8
Verb 'mira'
    *                                    		-> Look;
#EndIf;
```

* Hay que recordar que esto solo vale para infinitivos regulares. En el caso de
"huele/oler" es necesario definir tanto el imperativo como el infinitivo. Asimismo,
hay que recordar que en V3 el máximo tamaño de cada palabra de vocabulario son 6
caracteres, y de V4 en adelante son 9. Si introducimos dos palabras que sean
equivalentes para el diccionario, el compilador dará error. Ejemplo:

```
Verb 'examina' 'examinar'
    *                                    		-> Examine;
! Esto dará error en V3, porque tanto "examina" como "examinar" coinciden en sus
! seis primeros caracteres.

Verb 'balancearte' 'balancearse'
    *                                    		-> Swing;
! Esto dará error tanto en V3 como en V4 o V5, porque sus 9 primeros caracteres
! coinciden en las dos palabras.
```

* Hay dos instancias en las cuales el parser para V5-V8 es ligeramente mejor que para V3
y V4 en español: En V5 puede comprender sufijos -lo, -le, -la,
-los, -les, -las, -te (como en "examina la caja y abrela" o en "examinate") pero no
es así en V3 o V4. Y en V3 o V4 hay caracteres que no es posible introducir en las órdenes
del jugador: á, é, í, ó, ú, ü, ñ, ç. Habrá que sustituirlos por los siguientes:
a, e, i, o, u, u, n, c. Ejemplo: "examina llave pequena, examina ciguena".

* El parser permite identificar objetos con artículos femeninos o masculinos, como
"el libro" o "la casa". Para ello hay que usar la propiedad "female" en el objeto.

* En la traducción de la extensión "ext_cheap_scenery.h" se ha incluído la
posibilidad de distinguir objetos masculinos o femeninos. En los comentarios de
esa librería opcional se explica cómo utilizar esa distinción.
