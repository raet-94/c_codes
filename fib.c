#include <stdio.h>

int main() {
  int n;
  long double prev = 0.0; /* F(0) */
  long double curr = 1.0; /* F(1) */
  long double next;

  FILE *f = fopen("Fib.dat", "w");
  if (!f) {
    printf("Error: No se pudo abrir Fib.dat\n");
    return 1;
  }

  printf("¿Cuántos términos de Fibonacci quieres calcular? \n");
  scanf("%i", &n);

  /* Imprimir y guardar los primeros dos términos manualmente */
  if (n > 0) {
    printf("0 0\n");
    fprintf(f, "0 0\n");
  }
  if (n > 1) {
    printf("1 1\n");
    fprintf(f, "1 1\n");
  }

  /* Calcular el resto de la secuencia */
  for (int i = 2; i < n; i++) {
    next = prev + curr;
    prev = curr;
    curr = next;
    printf("%i %0.0Lf\n", i, curr);
    fprintf(f, "%i %0.0Lf\n", i, curr);
  }

  fclose(f);
  return 0;
}
