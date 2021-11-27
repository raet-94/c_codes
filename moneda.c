#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int n;
  int mon=0;
  int ag=0;
  int sel=0;
  int con1=0;
  int con2=0;
  int ev;

  srand(time(NULL));

  FILE * f1 = fopen("aguilas.dat","w");
  FILE * f2 = fopen("sellos.dat","w");

  printf(" Cuantas veces quieres lanzar? \n");
  scanf("%d",&n);
  printf("Cuantas veces se repetira ? \n");
  scanf("%d",&ev);
  
for (con2=0; con2< ev; con2++)
  
    {
      for (con1=0; con1<n; con1 ++)
        {
	  mon=rand()%2;
	  if (mon==0)
	    {
	      ag++;
	    }
	  else
	    {
	      sel++;
	    }
	}
      printf("%d %d %d\n", ag, sel, con2+1);
      fprintf(f1, "%d\n",ag);
      fprintf(f2, "%d\n",sel);

      ag=0;
      sel=0;
        
      }
  
fclose(f1);
fclose(f2);

return 0;
}
