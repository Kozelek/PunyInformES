# PunyInformES

PunyInformES es una librería escrita en Inform 6 que permite crear aventuras de texto (o ficción interactiva, o aventuras conversacionales) usando la máquina virtual Z de la antigua empresa ![Infocom](https://es.wikipedia.org/wiki/Infocom). La característica principal de esta librería es que está pensada para que funcione correctamente tanto en ordenadores de 8-bit como en plataformas modernas. Proporciona un parser, implementación de verbos comunes así como un entorno para la creación de aventuras de texto.

PunyInformES es la traducción al castellano de ![PunyInform](https://github.com/johanberntsson/PunyInform), la cual está basada en la librería Inform 6, desarrollada por Graham Nelson. Se ha hecho el intento de facilitar a los autores habituados a Inform 6 para que puedan comenzar usando PunyInformES. Hay un manual describiendo las diferencias.

Los juegos que usan PunyInformES pueden ser compilados a los formatos z3, z5 y z8. Comparado con la librería standard de Inform 6, esto supone que no ofrece soporte para Glulx pero incluye soporte para z3 (para el que la librería de Inform 6 carece).

Para compilar juegos que usen PunyInformES, recomendamos el compilador oficial de Inform 6 que mantiene David Kinder, en https://github.com/DavidKinder/Inform6 . Se pueden encontrar ejecutables en [if-archive](http://www.ifarchive.org/indexes/if-archiveXinfocomXcompilersXinform6Xexecutables.html) . PunyInform requiere Inform v6.34 o posterior.

![Un juego mínimo que utiliza PunyInformES](https://github.com/johanberntsson/PunyInform/blob/master/documentation/screenshots/simplegame.png?raw=true)

## Motivación

El objetivo principal de PunyInformES es permitir que los juegos sean más rápidos y tengan pocos requerimientos de memoria. Esto debería permitir que los juegos corran mejor en plataformas antiguas, como los ordenadores de 8-bit de los 80. Nuestro objetivo principal es hacerlo capaz de correr juegos en Commodore 64 usando [Ozmoo](https://github.com/johanberntsson/ozmoo/).

## Créditos

PunyInformES es la traducción de la librería PunyInform, concebida y diseñada por Johan Berntsson y Fredrik Ramsberg. El autor de la traducción es Pablo Martínez. Al igual que la librería original, incluye código de la librería standard de Inform 6, por Graham Nelson.
