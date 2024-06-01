#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void dibu_rect_sup(int ancho, int altura);
int x;
int y; 

/*************************************************************************/

int main()
{
  int ancho, altura;
  srand(time(NULL));

  const char *palabras[] = {"programación", "ahorcado", "computadora", "teclado", "desarrollo", "lenguaje",
                            "software", "ingeniería", "pantalla", "algoritmo", "compilador", "código", "base de datos",
                            "hardware", "redes", "ciberseguridad", "interfaz", "sistema operativo", "programador",
                            "virtualización"};

  const char *palabra_elegida = palabras[rand() % 21];
  dibu_rect_sup(ancho, altura);
  system("PAUSE");
  return 0;
}

/*************************************************************************/

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*************************************************************************/

void Color(int ClrT, int ClrF)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ClrT | ClrF);
}

/***********************RECTNAGULO DEL JUEGO***************************/

void dibu_rect_inf(int width, int height)
{
  char cornerTL = 201;   // Caracter para la esquina superior izquierda
  char cornerTR = 187;   // Caracter para la esquina superior derecha
  char cornerBL = 200;   // Caracter para la esquina inferior izquierda
  char cornerBR = 188;   // Caracter para la esquina inferior derecha
  char vertical = 186;   // Caracter para las paredes verticales
  char horizontal = 205; // Caracter para las paredes horizontales

  // Dibujar las esquinas superiores
  gotoxy(5, 4);
  printf("%c", cornerTL);

  gotoxy(width - 1, 4);
  printf("%c", cornerTR);

  // Dibujar las esquinas inferiores
  gotoxy(0, height - 1);
  printf("%c", cornerBL);

  gotoxy(width - 1, height - 1);
  printf("%c", cornerBR);

  // Dibujar las paredes
  for (int i = 1; i < width - 1; i++)
  {
    // Pared superior
    gotoxy(i, 0);
    printf("%c", horizontal);

    // Pared inferior
    gotoxy(i, height - 1);
    printf("%c", horizontal);
  }

  for (int i = 1; i < height - 1; i++)
  {
    // Pared izquierda
    gotoxy(0, i);
    printf("%c", vertical);

    // Pared derecha
    gotoxy(width - 1, i);
    printf("%c", vertical);
  }
  printf("\n");
  system("PAUSE");
}
