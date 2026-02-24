#include <stdio.h>
#include <math.h>

/* Modelo de Lotka-Volterra (depredador-presa)
 * x = poblacion de presas (Hz)
 * y = poblacion de depredadores (P)
 * alpha, beta, gamma, delta = parametros del modelo
 */

/* Prototipos */
long double f1(long double x, long double y, long double alpha, long double beta);
long double f2(long double x, long double y, long double delta, long double gamma);
long double V(long double x, long double y, long double delta, long double gamma,
              long double alpha, long double beta);

int main()
{
    /* Parametros de integracion */
    int N = 10000;
    int M = 10;
    long double t0 = 0.0L;

    /* Condiciones iniciales */
    long double x0 = 0.9L;
    long double y0 = 1.8L;

    /* Constantes de Lotka-Volterra */
    long double alpha = 1.1L;
    long double beta  = 0.9L;
    long double gamma = 1.0L;
    long double delta = 2.0L;

    /* Magnitudes derivadas */
    long double w  = sqrtl(alpha * gamma);
    long double h  = 3.151592L / (long double)N;
    long double k1 = (delta / beta) * sqrtl(alpha / gamma);

    FILE *f = fopen("LV2.dat", "w");
    if (!f) {
        printf("Error: No se pudo abrir LV2.dat\n");
        return 1;
    }

    for (int j = 0; j < M; j++) {
        long double x = x0 + (long double)j;
        long double y = y0 + (long double)j;

        for (int i = 0; i < 4 * N; i++) {
            long double tn = t0 + (long double)i;
            long double x1 = x * cosl(w * (long double)i / h) + k1 * sinl(w * (long double)i / h);
            long double y1 = y * cosl(w * (long double)i / h) - (1.0L / k1) * sinl(w * (long double)i / h);
            long double v  = V(x1, y1, delta, gamma, alpha, beta);

            printf("t[%d]=%0.1Lf  H[%d]=%0.5Lf  P[%d]=%0.5Lf  V=%0.5Lf\n",
                   i, tn, i, x1, i, y1, v);
            fprintf(f, "%0.5Lf %0.5Lf %0.5Lf\n", x1, y1, v);
        }
    }

    fclose(f);
    return 0;
}

/* dH/dt = alpha*H - beta*H*P */
long double f1(long double x, long double y, long double alpha, long double beta)
{
    return (alpha * x - beta * x * y);
}

/* dP/dt = delta*H*P - gamma*P */
long double f2(long double x, long double y, long double delta, long double gamma)
{
    return (delta * x * y - gamma * y);
}

/* Integral de movimiento V(H,P) */
long double V(long double x, long double y, long double delta, long double gamma,
              long double alpha, long double beta)
{
    return (-delta * x + gamma * logl(x) - beta * y + alpha * logl(y));
}
