#include <stdio.h>

int main() {
  int n;
  long double sum = 0.0; /* ← inicializar en 0 es indispensable */

  FILE *f = fopen("quad.dat", "w");
  if (!f) {
    printf("Error: No se pudo abrir quad.dat\n");
    return 1;
  }

  printf("¿Cuántos términos de la suma de cuadrados inversos quieres calcular? "
         "\n");
  scanf("%i", &n);

  /* Sumamos 1/i² para cada i y guardamos cada término */
  for (int i = 1; i <= n; i++) {
    sum = sum + 1.0L / ((long double)i * i);
    printf("%i %Lf \n", i, sum);
    fprintf(f, "%i %Lf\n", i, sum);
  }

  /* Nota: al converger, tiende a π²/6 ≈ 1.6449 */
  printf("Suma final: %Lf\n", sum);

  fclose(f);
  return 0;
}