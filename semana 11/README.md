# Semana 11 - Sudoku con Backtracking

## Archivos

- **`sudoku.cpp`** - Solucion de sudoku con backtracking, version con comentarios.
- **`sudoku1.cpp`** - Solucion de sudoku con backtracking, version limpia y compacta.
- **`sudoku.exe`** / **`sudoku1.exe`** - Ejecutables compilados.

## Como ejecutar

1. Crear un archivo `in.txt` en la misma carpeta con el formato:
   ```
   fila columna valor
   ```
   Ejemplo:
   ```
   1 1 5
   1 2 3
   2 4 7
   ```

2. Compilar (si tienes MinGW):
   ```
   g++ sudoku.cpp -o sudoku.exe
   ```
   o
   ```
   g++ sudoku1.cpp -o sudoku1.exe
   ```

3. Ejecutar:
   ```
   sudoku.exe
   ```
   Lee automaticamente `in.txt` y muestra el tablero inicial y el resuelto.

## Que hace

Resuelve un sudoku 9x9 usando backtracking recursivo. Lee las pistas desde `in.txt` (fila, columna, valor), completa el tablero probando numeros del 1 al 9 y retrocede si una jugada no lleva a la solucion.
