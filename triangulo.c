#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  double a, b, c;
  double p, A;

  /* Leemos los tres lados del triángulo */
  printf("Ingrese el lado a del triángulo: \n");
  scanf("%lf", &a); /* Bug original: usaba %d para double */
  printf("Ingrese el lado b del triángulo: \n");
  scanf("%lf", &b);
  printf("Ingrese el lado c del triángulo: \n");
  scanf("%lf", &c);

  /* Verificamos la desigualdad triangular:
     La suma de dos lados cualesquiera debe ser MAYOR al tercer lado */
  if (a + b > c && a + c > b && b + c > a) {
    p = (a + b + c) * 0.5;
    A = sqrt(p * (p - a) * (p - b) * (p - c)); /* Fórmula de Herón */
    printf("El área del triángulo es A = %.4f\n",
           A); /* Bug original: usaba %d para double */
  } else {
    printf("Estos lados no forman un triángulo válido.\n");
  }

  return 0;
}
