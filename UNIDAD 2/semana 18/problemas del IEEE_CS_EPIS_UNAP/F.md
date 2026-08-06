PROBLEMA F - CD

QUE PIDE EL PROBLEMA

Jack y Jill tienen colecciones de CDs. Ambos quieren vender una copia de cada CD que tienen en comun. Se debe contar cuantos CDs aparecen en las dos listas al mismo tiempo. Las dos listas estan ordenadas de menor a mayor y no tienen repetidos, lo cual hace el problema mas facil.

El programa recibe varios casos de prueba. Cada caso empieza con dos numeros N y M. N es la cantidad de CDs de Jack y M la cantidad de CDs de Jill. Luego vienen los N CDs de Jack y los M de Jill. Cuando se lee 0 y 0, no hay mas casos y se termina. Por cada caso se imprime la cantidad de CDs en comun.

COMO SE RESOLVIO

Como las dos listas estan ordenadas, se usa la tecnica de dos punteros. Se tiene una posicion i para la lista de Jack y una posicion j para la lista de Jill. Los dos empiezan en 0.

En cada paso se compara el CD de la posicion i con el de la posicion j. Si son iguales, es un CD en comun, se suma uno al contador y se avanza las dos posiciones. Si el CD de Jack es mas pequeno que el de Jill, significa que ese CD de Jack no esta en la lista de Jill, porque la lista de Jill es ordenada y solo tiene numeros mas grandes, entonces se avanza solo i. Si el CD de Jack es mas grande, se avanza solo j.

Esto se repite hasta que una de las dos listas se termina. Como las listas son ordenadas, no hace falta revisar mas alla de eso.

EXPLICACION DEL CODIGO PASO A PASO

Lineas 3 y 4: arreglos grandes para guardar los CDs de Jack y de Jill.
Linea 7: bucle que lee N y M, y termina cuando los dos son 0.
Linea 8: si N y M son 0, se sale del bucle.
Lineas 9 y 10: se leen los CDs de cada lista.
Linea 11: variables i y j para recorrer las listas, y la variable common que cuenta los CDs en comun.
Linea 12: bucle que corre mientras queden CDs en las dos listas.
Linea 13: si los dos CDs son iguales, se cuenta uno en comun.
Linea 14: si son iguales, se avanza en las dos listas.
Lineas 15 a 20: si no son iguales, se avanza solo en la lista que tiene el numero mas pequeno.
Linea 22: se imprime la cantidad de CDs en comun de este caso.
