PROBLEMA G - INVERSIONES EN LA FILA

QUE PIDE EL PROBLEMA

Se tiene una fila de personas y cada una tiene una estatura. Se quiere contar cuantas inversiones hay. Una inversion es un par de posiciones i y j donde i esta antes que j en la fila, pero la persona en i es mas alta que la persona en j. Si dos personas miden igual, ese par no cuenta.

Por ejemplo, con las estaturas 5, 2, 6, 1, 3 y 4, la respuesta es 8. Se cuentan pares como el 5 con el 2, o el 5 con el 1, porque el 5 esta antes y es mas alto.

COMO SE RESOLVIO

La forma mas simple es comparar todas las parejas posibles. Con dos bucles, el primero toma cada posicion i y el segundo recorre todas las posiciones j que estan despues de i. Si la estatura en i es mayor que la de j, se suma uno al contador.

Esta forma se llama fuerza bruta porque revisa todo. El problema dice que con muchos datos se recomienda una solucion mas rapida, pero esta version simple es correcta y sirve para la cantidad de datos de la prueba.

La cantidad de inversiones puede ser un numero muy grande, por eso el contador es de tipo long long, que guarda numeros mas grandes que un entero normal.

EXPLICACION DEL CODIGO PASO A PASO

Linea 3: arreglo grande para guardar las estaturas.
Linea 5: se lee cuantas personas hay.
Lineas 6 y 7: se leen las estaturas de la fila.
Linea 8: contador de inversiones, con tipo long long porque el numero puede ser muy grande.
Linea 9: bucle que toma cada posicion i.
Linea 10: bucle que toma las posiciones j que estan despues de i.
Linea 11: si la estatura de i es mayor que la de j, hay una inversion.
Linea 12: se suma uno al contador.
Linea 14: se imprime la cantidad total de inversiones.
