#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

int main (int argc, char* argv[])
{
  int buf_size = 50, offset = 0;
  int counter;
  int fd1;
  char* buffer;
  ssize_t bytes_read;
  /* Sciezki dostepu i nazwy plikow */
  char const *path1;
  /* Atrybuty dostepu do pliku. */
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

  if (argc < 2)
    {
      printf("Podaj nazwe pliku jako argument wywolania.\n");
      printf("Przyklad wywolania:\n\t./program plik1\n");
      return EXIT_FAILURE;
    }

  path1 = argv[1];
  buffer = (char*)malloc(50 * sizeof(char));

  /* Otworz plik 1 */
  printf("Otwieram plik o nazwie: %s\n", path1);
  fd1 = open (path1, O_RDONLY, mode);
  if (fd1 < 0)
    {
      printf("Nie moge otworzyc pliku.\n");
      return EXIT_FAILURE;
    }
  printf("Czytam dane z pliku %s\n", path1);
  do
    {
      bytes_read = read(fd1, buffer, buf_size);
      offset = offset + bytes_read;
    }
  while (bytes_read == buf_size);

  counter = offset/sizeof(char);

  printf("%d %d %d\n", offset, sizeof(char), counter);

  printf("Zapisano %d bajtow\n", offset);
  printf("Zapisano %d znakow\n", counter);
  printf("Zamkniecie pliku.\n");
  /* Zamknij plik. */
  close(fd1);
  /* Zwolnij pamiec bufora */
  free(buffer);
  return EXIT_SUCCESS;
}