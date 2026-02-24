#include <stdio.h>

#define N 3 /* Dimensión de los vectores */

int main() {
  int vector1[N];
  int vector2[N];
  int vector3[N];

  printf("Capture las coordenadas del vector 1 (3 enteros):\n");
  for (int i = 0; i < N; i++) {
    scanf("%d", &vector1[i]);
    printf("  vector1[%d] = %d\n", i + 1, vector1[i]);
  }

  printf("\nCapture las coordenadas del vector 2 (3 enteros):\n");
  for (int i = 0; i < N; i++) {
    scanf("%d", &vector2[i]);
    printf("  vector2[%d] = %d\n", i + 1, vector2[i]);
  }

  printf("\nResultado de la suma (vector3 = vector1 + vector2):\n");
  for (int i = 0; i < N; i++) {
    vector3[i] = vector1[i] + vector2[i];
    printf("  vector3[%d] = %d\n", i + 1, vector3[i]);
  }

  return 0;
}
