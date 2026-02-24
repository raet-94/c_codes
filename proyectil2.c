#include <stdio.h>
#include <math.h>

int main()
{
    /* Variables del sistema */
    double x     = 0.0;
    double y     = 0.0;
    double t;            /* tiempo de vuelo */
    double h;            /* altura maxima */
    double h0    = 150.0; /* altura inicial */
    double theta = 45.0;
    double v0    = 50.0;
    double g     = 9.80665;
    double delta = 0.01;
    double Pi    = M_PI;

    FILE *f = fopen("coordproy2.dat", "w");
    if (!f) {
        printf("Error: No se pudo abrir coordproy2.dat\n");
        return 1;
    }

    /* Ecuaciones para tiro parabolico con altura inicial h0 */

    /* Bug original: v0*v0**sin(...) no es C valido -- corregido a v0*v0*sin(...) */
    t = (sqrt(v0 * v0 * sin(theta * (Pi / 180.0)) * sin(theta * (Pi / 180.0)) + 4.0 * g * h0)
         - v0 * sin(theta * (Pi / 180.0))) / g;

    h = h0 + (v0 * v0) * sin(theta * (Pi / 180.0)) * sin(theta * (Pi / 180.0)) / (2.0 * g);

    printf("El desplazamiento del proyectil, en x, y [metros]:\n");

    for (double i = 0.0; i <= t; i += delta) {
        x = v0 * cos(theta * Pi / 180.0) * i;
        y = -0.5 * g * (i * i) + v0 * sin(theta * Pi / 180.0) * i + h0;

        fprintf(f, "%.5lf %.5lf \n", x, y);
        printf("%.5lf %.5lf \n", x, y);
    }

    printf("Tiempo de vuelo [segundos]: %.5lf \n", t);
    printf("Altura maxima alcanzada [m]: %.5lf \n", h);

    fclose(f);
    return 0;
}
