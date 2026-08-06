PROBLEMA E - PORTAFOLIO DE INVERSION EN ETFS

QUE PIDE EL PROBLEMA

Hay un capital exacto C y una lista de N ETFs, donde cada uno tiene un precio distinto. Se quiere saber de cuantas formas distintas se pueden escoger ETFs de esa lista para que la suma de sus precios sea exactamente igual a C. No se puede repetir un ETF ni comprar una parte de uno. Solo se puede escoger cada ETF una vez o no escogerlo.

Por ejemplo, si el capital es 100 y los precios son 20, 30, 40, 50 y 60, hay dos formas: 40 mas 60, o 20 mas 30 mas 50. La respuesta seria 2.

COMO SE RESOLVIO

Este es un problema de combinaciones. Para cada ETF hay dos opciones: tomarlo o no tomarlo. Con N ETFs hay 2 elevado a N formas de escoger, y se recorre cada una de esas formas usando un truco llamado mascaras de bits.

Una mascara es un numero que en su forma binaria dice que elementos se escogen. Si un bit vale 1, se toma ese ETF. Si vale 0, no se toma. Se prueban todas las mascaras desde 0 hasta 2 elevado a N menos 1, se suma el precio de los ETFs escogidos, y si la suma es igual a C, se cuenta.

Este metodo funciona porque N es a lo mucho 20, y 2 elevado a 20 es alrededor de un millon, que es un numero de operaciones que la computadora hace muy rapido.

EXPLICACION DEL CODIGO PASO A PASO

Lineas 4 y 5: se leen el capital C y la cantidad de ETFs N.
Lineas 6 y 7: se leen los precios de cada ETF.
Linea 8: variable que cuenta las combinaciones que suman C.
Linea 9: bucle que recorre todas las mascaras de bits, desde 0 hasta 2 elevado a N.
Linea 10: variable que guarda la suma de los precios de la mascara actual.
Lineas 11 a 13: se recorre cada ETF y si el bit de ese ETF esta encendido, se suma su precio.
Linea 14: si la suma es exactamente C, se suma uno al contador.
Linea 16: se imprime la cantidad de combinaciones.
