# TicTacToe en C

Este es un proyecto personal que implementa un sencillo juego de TicTacToe (tres en raya) en lenguaje C. Fue desarrollado para entornos Windows, aprovechando la funcionalidad de captura de teclas. Es un ejemplo básico de programación en C que combina lógica de juego y manipulación de entrada del usuario.

## Características

- Diseñado exclusivamente para **Windows**, debido a la dependencia de funciones específicas para la captura de teclas.
- Interfaz por consola simple y fácil de usar.
- **Controles**:
  - Usa las flechas direccionales para moverte entre las casillas.
  - Presiona **Enter** para seleccionar una casilla.
- **Modo de juego**: Una única partida entre dos jugadores locales (sin puntajes ni historial).

## Cómo jugar

1. Ejecuta el programa en un entorno Windows.
2. Usa las flechas direccionales para mover el cursor entre las casillas del tablero.
3. Presiona **Enter** para seleccionar una casilla.
4. El juego termina automáticamente cuando uno de los jugadores gana (completa una línea horizontal, vertical o diagonal) o si hay empate.

## Requisitos

- Sistema operativo: Windows.
- Compilador de C compatible (como GCC o MSVC).

## Instalación y ejecución en Windows

1. Clona este repositorio:
   ```bash
   git clone https://github.com/tuusuario/tictactoe-c.git
   ```
2. Compila el programa:
   ```bash
   gcc -o tictactoe main.c
   ```
3. Ejecuta el .exe:
   ```bash
   tictactoe.exe
   ```
    
