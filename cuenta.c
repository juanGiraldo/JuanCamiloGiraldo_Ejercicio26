#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
     

     



#define BUFFER_SIZE 1000
/*declarar atributos*/
clock_t start, end;
double cpu_time_used;

/* declarar funciones */
int countOccurrences(FILE *fptr, char *word);

int main(int argc, char *argv[])
{
  start = clock();
  FILE * archivo;
  FILE * cuenta;
  FILE * tiempo;
  archivo=fopen(argv[1],"r");
  cuenta=fopen(argv[2],"w");
  tiempo=fopen(argv[3],"w");

  int cuenta1;
  int cuenta2;
  int cuenta3;
  int cuenta4;
  int cuenta5;
  if (argc!=4)
  {
    printf("faltan argumentos de entrada.\n");
    exit(EXIT_FAILURE);
  }
  
  cuenta1= countOccurrences(archivo, "1");
  fclose(archivo);
  archivo=fopen(argv[1],"r");
  cuenta2= countOccurrences(archivo, "12");
  fclose(archivo);
  archivo=fopen(argv[1],"r");
  cuenta3= countOccurrences(archivo, "123");
  fclose(archivo);
  archivo=fopen(argv[1],"r");
  cuenta4= countOccurrences(archivo, "1234");
  fclose(archivo);
  archivo=fopen(argv[1],"r");
  cuenta5= countOccurrences(archivo, "12345");
  fclose(archivo);
  fprintf(cuenta,"%d\n",cuenta1);
  fprintf(cuenta,"%d\n",cuenta2);
  fprintf(cuenta,"%d\n",cuenta3);
  fprintf(cuenta,"%d\n",cuenta4);
  fprintf(cuenta,"%d\n",cuenta5);
  fclose(cuenta);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(tiempo,"%lf\n",cpu_time_used);
  fclose(tiempo);
}

int countOccurrences(FILE *fptr, char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;
    
    count = 0;

    // lee linea a linea hasta el final del archivo
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // halla la siguiente ocurrencia
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}
