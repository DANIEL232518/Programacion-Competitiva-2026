PROBLEMA B - SIMON DICE

QUE PIDE EL PROBLEMA

Simon da instrucciones y algunas empiezan con la frase "Simon says ". Solo las que empiezan exactamente con esa frase se deben imprimir, pero imprimiendo solo la parte que viene despues de la frase. Las instrucciones que no empiezan con "Simon says " se ignoran por completo.

Por ejemplo, si la instruccion es "Simon says smile.", se imprime "smile.". Si la instruccion es "Smile.", no se imprime nada.

COMO SE RESOLVIO

Lo unico que hay que hacer es leer cada linea y revisar si empieza con los primeros 11 caracteres que forman la frase "Simon says ". Como la frase tiene exactamente 11 letras y espacios, podemos comparar la linea con esa frase.

Si la linea empieza con "Simon says ", entonces imprimimos la linea desde la posicion 11 en adelante, que es justamente la parte que viene despues de la frase. Como los arreglos de caracteres empiezan en la posicion 0, la posicion 11 es donde empieza el contenido que nos interesa.

COMO SE LEEN LAS LINEAS

Al principio leemos un numero n que dice cuantas instrucciones hay. Despues de leer ese numero, hay que quitar el salto de linea que queda en el teclado, porque si no, la primera lectura de linea saldria vacia. Para eso usamos la funcion ignore, que descarta los caracteres que sobran hasta encontrar un salto de linea.

Luego por cada instruccion usamos getline, que lee una linea completa incluyendo los espacios. Eso es importante porque las instrucciones tienen espacios dentro.

EXPLICACION DEL CODIGO PASO A PASO

Linea 4: se lee cuantas instrucciones hay.
Linea 5: se descarta el salto de linea que queda despues del numero.
Linea 6: se crea el arreglo para guardar cada linea, con espacio para 105 caracteres.
Lineas 8 a 13: se recorre cada instruccion.
Linea 9: se lee una linea completa con getline.
Linea 10: se compara la linea con la frase "Simon says " posicion por posicion.
Linea 11: si empieza con la frase, se imprime la linea desde la posicion 11 hasta el final.
