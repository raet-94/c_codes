#include <stdio.h>
int main ()
{
  int n;
  long double fn_1=0, fn_2=1;
  long double fn=0;
  int con;

  FILE *f=fopen("Fib.dat","w");

  printf("Cuantos terminos de Fibonacci quieres calcular? \n" );
  scanf("%i", &n);
  for (con=0; con <n; con++)
    {
      if (con <= 1)
	{
	  fn=0;
	}
      else
	{
      fn= fn_1 + fn_2 ;
      fn_1= fn_2;
      fn_2= fn;
          }

      fprintf(f,"%i %0.0Lf\n", con,fn);
      printf("%i %0.0Lf\n", con, fn);
    }
  
return 0;
}
