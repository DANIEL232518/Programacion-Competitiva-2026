PROBLEMA D - BALONCESTO UNO CONTRA UNO

QUE PIDE EL PROBLEMA

Hay un partido de baloncesto uno contra uno entre los jugadores A y B. Cada canasta vale 1 o 2 puntos. El registro del partido es una cadena de texto donde cada canasta esta formada por dos caracteres: la letra del jugador y el numero de puntos. Por ejemplo, "A2B1" significa que el jugador A anoto 2 puntos y luego el jugador B anoto 1 punto.

Gana el primero que llega a 11 puntos, pero si el marcador llega a estar 10 a 10, entonces se gana con diferencia de 2. Hay que imprimir la letra del ganador, que puede ser A o B.

COMO SE RESOLVIO

Se recorre la cadena de dos en dos caracteres. El primer caracter de cada par dice quien anoto y el segundo dice cuantos puntos. Para saber cuantos puntos son, se le resta el caracter '0', porque los numeros en texto tienen codigos distintos que los numeros normales. Por ejemplo, el caracter '2' tiene un codigo, y '0' tiene otro, y la resta da exactamente 2.

Con cada canasta se suma a la cuenta del jugador correspondiente. Despues de cada canasta se revisa si alguien gano. Un jugador gana si tiene 11 o mas puntos y ademas le saca 2 o mas de diferencia a su rival. Si eso pasa, se imprime la letra y termina el programa.

Si se acaba la cadena y nadie cumplio la condicion, se imprime el que tenga mas puntos.

EXPLICACION DEL CODIGO PASO A PASO

Linea 4: se crea el arreglo para guardar la cadena del registro.
Linea 5: se lee la cadena.
Lineas 6 y 7: variables para contar los puntos de A y de B.
Linea 8: posicion desde donde se empieza a recorrer la cadena.
Linea 9: bucle que recorre hasta el final de la cadena.
Linea 10: se toma la letra del jugador.
Linea 11: se toma el numero de puntos y se convierte restando el caracter '0'.
Lineas 12 a 14: se suma a la cuenta del jugador que anoto.
Linea 15: se avanza dos posiciones porque cada canasta ocupa dos caracteres.
Lineas 16 a 21: se revisa si alguien gano con 11 puntos o mas y 2 de diferencia.
Lineas 22 a 24: si la cadena termino, se imprime el que tenga mas puntos.
