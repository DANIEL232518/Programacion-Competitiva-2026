PROBLEMA A - ABC

QUE PIDE EL PROBLEMA

Se te dan tres numeros enteros positivos. Cuando los ordenas de menor a mayor, el primero es A, el segundo es B y el tercero es C. Despues te dan una cadena de tres letras que pueden ser A, B o C en cualquier orden. Tienes que imprimir los tres numeros en el orden que dice la cadena.

Por ejemplo, si los numeros son 1, 5 y 3, ordenados quedan 1, 3 y 5. Entonces A vale 1, B vale 3 y C vale 5. Si la cadena dice ABC, imprimes 1 3 5. Si la cadena dice CAB, imprimes 5 1 3.

COMO SE RESOLVIO

Primero guardamos los tres numeros en un arreglo llamado n. Luego ordenamos ese arreglo de menor a mayor usando dos bucles que comparan cada numero con los que estan despues. Si un numero es mas grande que otro, los cambiamos de lugar usando una variable temporal llamada t. Esta forma de ordenar se llama burbuja, es simple y funciona bien porque solo hay tres numeros.

Despues leemos la cadena de letras y la guardamos en una variable llamada s. Recorremos la cadena letra por letra. Si la letra es A, imprimimos el numero que esta en la posicion 0 del arreglo, que es el mas pequeno. Si es B, imprimimos el de la posicion 1, que es el del medio. Si es C, imprimimos el de la posicion 2, que es el mas grande.

Entre numero y numero imprimimos un espacio para que la salida se vea bien. Al final de cada linea imprimimos un salto de linea.

EXPLICACION DEL CODIGO PASO A PASO

Linea 3: se crea un arreglo de tres posiciones para guardar los numeros.
Linea 5: se leen los tres numeros desde el teclado.
Lineas 6 a 12: se ordenan los tres numeros de menor a mayor con dos bucles anidados.
Linea 8: si el numero de la posicion i es mayor que el de la posicion j, se cambian.
Linea 13: se crea la variable para guardar la cadena de letras.
Linea 14: se lee la cadena.
Lineas 15 a 20: se recorre la cadena y se imprime el numero que corresponde a cada letra.
Linea 19: imprime un espacio entre numero y numero, menos al final.
Linea 21: imprime un salto de linea.
