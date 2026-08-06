PROBLEMA C - PUNTUACION DEL CONCURSO ACM

QUE PIDE EL PROBLEMA

Se registran los envios de un concurso de programacion. Cada envio tiene tres datos: el minuto en que se hizo, la letra del problema, y el resultado que puede ser "right" o "wrong". Si el problema se resuelve, es decir, tiene un "right", el equipo gana puntos por ese problema. Si antes fallaron con "wrong", cada error suma 20 minutos de castigo.

Al final se imprimen dos numeros: cuantos problemas se resolvieron y el tiempo total. El tiempo total se calcula sumando el minuto del acierto mas 20 minutos por cada error anterior en ese mismo problema. Los errores de un problema que nunca se resolvio no cuentan. Los envios que llegan despues de haber resuelto el problema se ignoran.

COMO SE RESOLVIO

Se usan dos arreglos grandes. Uno cuenta cuantos errores tiene cada problema y el otro guarda si el problema ya fue resuelto. Como las letras de los problemas son caracteres, se pueden usar como posiciones del arreglo, porque cada letra tiene un numero de codigo.

Se leen envios uno por uno hasta encontrar el numero -1, que indica que no hay mas envios. Por cada envio se revisa si el problema ya fue resuelto. Si ya fue resuelto, se ignora ese envio. Si no, se revisa el resultado. Si es "right", se marca el problema como resuelto, se suma uno a los problemas resueltos, y se suma al tiempo el minuto mas los errores anteriores multiplicados por 20. Si es "wrong", solo se suma un error a ese problema.

EXPLICACION DEL CODIGO PASO A PASO

Linea 4: arreglo que cuenta los errores de cada problema.
Linea 5: arreglo que guarda si cada problema ya fue resuelto.
Linea 6: variables para contar problemas resueltos y sumar el tiempo total.
Linea 8: bucle que lee el minuto y termina cuando el minuto es -1.
Lineas 9 y 10: se leen la letra del problema y el resultado.
Linea 11: si el problema ya fue resuelto, se salta este envio.
Lineas 13 a 16: si el resultado es "right", se marca como resuelto y se suman los puntos.
Linea 16: se suma el minuto mas 20 por cada error anterior.
Linea 17 y 18: si el resultado es "wrong", se suma un error al problema.
Linea 21: se imprimen los problemas resueltos y el tiempo total.
