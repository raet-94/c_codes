#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_lanzamientos;
  int num_repeticiones;
  int aguilas = 0;
  int sellos = 0;
  int resultado;

  srand(time(NULL));

  FILE *f_aguilas = fopen("aguilas.dat", "w");
  FILE *f_sellos = fopen("sellos.dat", "w");

  if (!f_aguilas || !f_sellos) {
    printf("Error: No se pudieron abrir los archivos de salida.\n");
    if (f_aguilas)
      fclose(f_aguilas);
    if (f_sellos)
      fclose(f_sellos);
    return 1;
  }

  printf("¿Cuántas veces quieres lanzar la moneda por intento? \n");
  scanf("%d", &num_lanzamientos);
  printf("¿Cuántas veces se repetirá el experimento? \n");
  scanf("%d", &num_repeticiones);

  for (int j = 0; j < num_repeticiones; j++) {
    for (int i = 0; i < num_lanzamientos; i++) {
      resultado = rand() % 2;
      if (resultado == 0) {
        aguilas++;
      } else {
        sellos++;
      }
    }
    printf("Intento %d: Aguilas = %d, Sellos = %d\n", j + 1, aguilas, sellos);
    fprintf(f_aguilas, "%d\n", aguilas);
    fprintf(f_sellos, "%d\n", sellos);

    aguilas = 0;
    sellos = 0;
  }

  fclose(f_aguilas);
  fclose(f_sellos);

  return 0;
}
