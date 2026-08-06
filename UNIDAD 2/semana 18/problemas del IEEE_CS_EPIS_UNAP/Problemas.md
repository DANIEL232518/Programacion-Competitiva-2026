# Problemas - I Concurso de Programación Competitiva EPIS-UNAP-IEEE 2026

## Instrucciones generales

- 8 problemas: A a H, ordenados de menor a mayor dificultad.
- Lenguaje permitido: C++17.
- Entrada: estándar. Salida: estándar.
- Dificultad: sola (1 segundo), doble (2 segundos) o quíntuple (5 segundos).

---

## A - ABC

Se dan tres númerros enteros positivos. Al ordenarlos de menor a mayor corresponden a A, B y C. Luego se da una cadena con las letras A, B, C. Imprimir los valores en el orden que indica la cadena.

Entrada: tres enteros (<=100), luego una cadena de 3 letras A/B/C.
Salida: los tres enteros separados por espacio, en el orden de la cadena.

Ejemplo:
- Entrada: `1 5 3` y `ABC` -> Salida: `1 3 5`.
- Entrada: `6 4 2` y `CAB` -> Salida: `6 2 4`.

---

## B - Simon Dice

Procesar instrucciones. Si una instrucción comienza exactamente con "Simon says ", se imprime el resto. Las demás se ignoran.

Entrada: entero N (1..1000), luego N líneas de instrucciones (max 100 caracteres).
Salida: por cada instrucción válida, el resto después de "Simon says ".

Ejemplo:
- Entrada: `1` luego `Simon says smile.` -> Salida: `smile.`

---

## C - Puntuación del Concurso ACM

Se registran envíos: minuto, letra del problema, resultado (right/wrong). Se calcula: problemas resueltos y tiempo total (minuto de acierto + 20 minutos de penalización por cada wrong previo sobre ese problema). Problemas nunca resueltos no suman penalización. Envíos posteriores a un acierto se ignoran.

Entrada: líneas `minuto letra resultado`, termina con `-1`.
Salida: dos enteros: problemas resueltos y tiempo total.

Ejemplo:
- Entrada: `3 E right`, `10 A wrong`, `30 C wrong`, `50 B wrong`, `100 A wrong`, `200 A right`, `250 C wrong`, `300 D right`, `-1`.
- Salida: `3 543`.

---

## D - Baloncesto Uno contra Uno

Partido 1 contra 1. Cada canasta suma 1 o 2 puntos. Gana el primero que llega a 11, pero si va 10-10 se gana con diferencia de 2. El registro es una cadena de pares (letra + número): A/B son los jugadores, 1/2 los puntos.

Entrada: una línea con el registro (max 200 caracteres, sin espacios).
Salida: un carácter, 'A' o 'B', el ganador.

Ejemplo:
- Entrada: `A2B1A2B2A1A2A2A2` -> Salida: `A`.

---

## E - Portafolio de Inversión en ETFs

Invertir un capital exacto C usando una lista de N ETFs de precios enteros únicos. No se pueden repetir ni fraccionar. Contar cuántas combinaciones distintas suman exactamente C.

Entrada: C y N (1..10^4, 1..20), luego N precios (1..10^4).
Salida: número de combinaciones que suman C.

Ejemplo:
- Entrada: `100 5` luego `20 30 40 50 60` -> Salida: `2`.

---

## F - CD

Jack y Jill venden una copia de cada CD que ambos poseen. Cada lista está ordenada crecientemente y sin repes. Contar cuántos CDs tienen en común.

Entrada: varios casos. Cada caso inicia con N y M (1..10^6), luego N catálogos de Jack y M de Jill. Termina con `0 0`.
Salida: por caso, un entero con la cantidad de CDs comunes.

Ejemplo:
- Entrada: `3 3`, catálogos `1 2 3` y `1 2 4`, luego `1 2`, `10` y `5 6`, luego `0 0`.
- Salida: `2` y `0`.

---

## G - Inversiones en la Fila

Contar inversiones: pares (i, j) con i < j y a[i] > a[j]. Valores repetidos no cuentan.

Entrada: n (1..200000), luego n estaturas (1..10^9).
Salida: un entero de 64 bits con la cantidad de inversiones.

Ejemplo:
- Entrada: `6` luego `5 2 6 1 3 4` -> Salida: `8`.

Nota: con n hasta 200000 se recomienda O(n log n), pero la versión básica O(n^2) es correcta.

---

## H - Islas en el Mapa

Contar islas: grupos de celdas '1' conectadas horizontal o verticalmente (no por diagonales).

Entrada: R y C (1..1000), luego R líneas de C caracteres ('0' o '1', sin espacios).
Salida: un entero con la cantidad de islas.

Ejemplo:
- Entrada: `4 5` con la grilla:
  `11110`
  `11010`
  `11000`
  `01000`
  -> Salida: `1`.
- Entrada: `4 5` con:
  `11000`
  `11000`
  `00100`
  `00011`
  -> Salida: `3`.
