#include <stdio.h>
int main ()
{
  //definimos las variables pero no fijamos n    
  int n;
  double sum;
  int i;
//generamos el archivo de datos
  FILE *f=fopen("harm.dat","w");
//pedimos el valor de n
  printf("Cuantos terminos de la serie armonica quieres calcular? \n" );
  scanf("%i", &n);
  //Hacemos la serie atraves de un for
  for (i=1; i<=n; i++)
      {
     // al no poder simplemente la division ponemos (float)
      sum= sum + 1/(float)i ;
      printf("%i %f \n",i,sum);
      }
     //imprimimos los resultados para verficar
      fprintf(f,"%i %0.0Lf\n", i,sum);
      printf("%f %0.0Lf\n", i, sum);
    
  
return 0;
}