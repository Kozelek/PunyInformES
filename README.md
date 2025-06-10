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

## Comentarios relativos a la traducción de PunyInformES:

* A diferencia de Inform 6 o InformATE, el parser no intenta adivinar el imperativo
automáticamente, ni existe una forma de definir imperativos irregulares. Esto es
así para mantener la mayor compatibilidad posible entre la versión V5 y V3 de la
Máquina Z. En la práctica, esto se traduce en la necesidad de introducir los
infinitivos como palabras adicionales en el vocabulario (es necesario especificar
tanto "lee" como "leer" si queremos que se puedan usar las dos formas verbales).

* Pese a lo anterior, hay dos instancias en las cuales el parser para V5 es ligera-
mente mejor que para V3 en español: En V5 puede comprender sufijos -lo, -le, -la,
-los, -les, -las, -te (como en "examina la caja y abrela" o en "examinate") pero no
es así en V3. Y en V3 hay caracteres que no es posible introducir en las órdenes
del jugador: á, é, í, ó, ú, ü, ñ, ç. Habrá que sustituirlos por los siguientes:
a, e, i, o, u, u, n, c. Ejemplo: "examina llave pequena, examina ciguena".

* El parser permite identificar objetos con artículos femeninos o masculinos, como
"el libro" o "la casa". Para ello hay que usar la propiedad "female" en el objeto.

* En la traducción de la extensión "ext_cheap_scenery.h" se ha incluído la
posibilidad de distinguir objetos masculinos o femeninos. En los comentarios de
esa librería opcional se explica cómo utilizar esa distinción.
