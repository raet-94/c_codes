#include <math.h>
#include <stdio.h>

int main() {
  double x = 0.0;
  double y = 0.0;
  double t; /* tiempo de vuelo */
  double h; /* altura máxima */
  double theta = 0.0;
  double v0 = 0.0;
  double g = 9.80665;
  double delta = 0.01;

  /* Usamos M_PI de <math.h> en lugar de una constante manual */
  double Pi = M_PI;

  FILE *f = fopen("coordproy1.dat", "w");
  if (!f) {
    printf("Error: No se pudo abrir coordproy1.dat\n");
    return 1;
  }

  printf("Dame la velocidad inicial [m/s] del proyectil: \n");
  scanf("%lf", &v0);
  printf("\n");
  printf("Dame el ángulo inicial (grados): \n");
  scanf("%lf", &theta);

  /* Tiempo de vuelo y altura máxima */
  t = 2.0 * (v0 * sin(theta * (Pi / 180.0)) / g);
  h = (v0 * v0) * sin(theta * (Pi / 180.0)) * sin(theta * (Pi / 180.0)) /
      (2.0 * g);

  printf("El desplazamiento del proyectil, en x, y [metros]:\n");

  /* Iteramos con paso delta en el tiempo (usamos double para i) */
  for (double i = 0.0; i <= t; i += delta) {
    x = v0 * cos(theta * Pi / 180.0) * i;
    y = -0.5 * g * (i * i) + v0 * sin(theta * Pi / 180.0) * i;

    fprintf(f, "%.5lf %.5lf \n", x, y);
    printf("%.5lf %.5lf \n", x, y);
  }

  printf("El tiempo de vuelo [segundos]: %.5lf \n", t);
  printf("La altura máxima alcanzada [m]: %.5lf \n", h);

  fclose(f);
  return 0;
}
