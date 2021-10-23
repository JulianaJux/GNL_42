#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char  *argv[])
{
   int iFileDescriptor;
 
   /* A constante _POSIX_PATH_MAX] indica o tamanho (de caracteres incluindo diretórios e subdiretórios) que um arquivo pode possuir.
           Esta definido no arquivo limits.h */
   char sNome [_POSIX_PATH_MAX];
   ssize_t iQtdeLida;
   char aBuffer[100];
 
   printf ("Entre com o nome do arquivo : ");
   gets (sNome);
 
   iFileDescriptor = open (sNome, O_RDONLY);
   if (iFileDescriptor < 0)
   {
      perror (argv[0]);
      exit (errno);
   }
   printf ("Arquivo '%s' aberto\n", sNome);
 
   printf("\nTentando ler 10 bytes do arquivo indicado\n");
 
   /* deve-se passar sempre o endereço de memória da variável que vai receber os bytes lidos */
   iQtdeLida = read (iFileDescriptor, &aBuffer, 1);
 
   if (iQtdeLida < 0)
   {
      perror (argv[0]);
      exit (errno);
   }
 
   printf("\nForam lidos %zd bytes do arquivo '%s'\n", iQtdeLida, sNome);
   close (iFileDescriptor);
   return 0;
}