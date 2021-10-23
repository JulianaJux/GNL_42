#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h" 
int main(int argc, char  *argv[])
{
   int iFileDescriptor;
   char *lido;
 
   /* A constante _POSIX_PATH_MAX] indica o tamanho (de caracteres incluindo diretórios e subdiretórios) que um arquivo pode possuir.
           Esta definido no arquivo limits.h */
   char sNome [_POSIX_PATH_MAX];
   printf ("Entre com o nome do arquivo : ");
   gets (sNome);
 
   iFileDescriptor = open (sNome, O_RDONLY);
   if (iFileDescriptor < 0)
   {
      perror (argv[0]);
      exit (errno);
   }
   printf ("Arquivo '%s' aberto\n", sNome);

   lido = get_next_line(iFileDescriptor);
   printf ("Arquivo '%s' lido\n", lido);
}
