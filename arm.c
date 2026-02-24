#include <stdio.h>

int main() {
  int n;
  double sum = 0.0; /* ← inicializar en 0 es indispensable */

  FILE *f = fopen("harm.dat", "w");
  if (!f) {
    printf("Error: No se pudo abrir harm.dat\n");
    return 1;
  }

  printf("¿Cuántos términos de la serie armónica quieres calcular? \n");
  scanf("%i", &n);

  /* Hacemos la serie y guardamos cada término */
  for (int i = 1; i <= n; i++) {
    sum = sum + 1.0 / (double)i;
    printf("%i %f \n", i, sum);
    fprintf(f, "%i %f\n", i, sum);
  }

  fclose(f);
  return 0;
}