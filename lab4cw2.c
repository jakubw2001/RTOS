#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <unistd.h>

int main(int argc, char* argv[]) 
{
    int forkR_pid; //PID procesu R
    forkR_pid = fork();    //rozwidlenie procesu P do R
    char *const parmList[] = {"/home/Kuba/Lab4", NULL};
    if(forkR_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR_pid == 0)    //jeśli git -> proces potomny R wystawia wartość 0 - w tym else if jest obsługa procesu R
    {
        printf("PID R = %d\n", getpid());  //wyświetl PID R
        execv(argv[0], parmList);
        return 0;   //zakończ proces R
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        printf("PPID R = %d\n", getpid()); //wyświetl PID P = PPID R
    }
    return 0;   //zakończ proces P
}