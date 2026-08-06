PROBLEMA H - ISLAS EN EL MAPA

QUE PIDE EL PROBLEMA

Se tiene un mapa formado por filas y columnas. Cada celda del mapa tiene un 1 o un 0. El 1 significa tierra y el 0 significa agua. Una isla es un grupo de unos que estan pegados entre si, ya sea hacia arriba, hacia abajo, a la izquierda o a la derecha. Dos unos que solo se tocan por una esquina no forman parte de la misma isla. Se debe contar cuantas islas hay.

COMO SE RESOLVIO

Se recorre todo el mapa celda por celda. Cada vez que se encuentra un 1 que no fue visitado, se encontro una isla nueva, entonces se suma uno al contador y se recorren todos los unos que estan pegados a el para marcarlos como visitados.

Para recorrer la isla se usa un metodo llamado busqueda en anchura, que funciona con una cola. La cola guarda las posiciones que faltan revisar. Se empieza con la posicion de la isla y mientras la cola no este vacia, se saca una posicion y se miran sus cuatro vecinos. Si un vecino es 1 y no fue visitado, se marca como visitado y se mete a la cola. Asi se recorre toda la isla completa.

Esta implementacion de la cola se hace con arreglos y dos variables, una para agregar y otra para sacar. No se usa una cola de la libreria para que sea mas rapida con mapas grandes.

EXPLICACION DEL CODIGO PASO A PASO

Lineas 3 a 6: variables globales para las filas, las columnas, el mapa, los visitados y la cola.
Lineas 8 y 9: se leen las filas y columnas.
Lineas 10 y 11: se lee el mapa entero.
Linea 12: contador de islas.
Linea 13: direcciones de los cuatro vecinos: arriba, abajo, izquierda y derecha.
Linea 14: bucle que recorre todas las filas.
Linea 15: bucle que recorre todas las columnas.
Linea 16: si hay un 1 que no fue visitado, se encontro una isla.
Linea 17: se suma uno al contador de islas.
Lineas 18 a 20: se mete la posicion inicial en la cola y se marca como visitada.
Linea 21: bucle que corre mientras la cola tenga posiciones.
Linea 22: se saca una posicion de la cola.
Lineas 23 y 24: se revisan los cuatro vecinos.
Linea 25: si el vecino esta dentro del mapa, es 1 y no fue visitado, se toma.
Linea 26: se marca como visitado.
Lineas 27 y 28: se mete el vecino a la cola.
Linea 34: se imprime la cantidad total de islas.
