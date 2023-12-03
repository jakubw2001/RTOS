#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <unistd.h>

int main() 
{
    int forkR1_pid, forkR2_pid, forkS1_pid, forkS2_pid; //PID procesów R1, R2, S1, S2
    forkR1_pid = fork();    //rozwidlenie procesu P do R1
    //printf("%d\n", forkR1_pid);
    if(forkR1_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR1_pid == 0)    //jeśli git -> proces potomny R1 wystawia wartość 0 - w tym else if jest obsługa procesu R1
    {
        printf("PID R1 = %d\n", getpid());  //wyświetl PID R1
        forkS1_pid = fork();    //rozwidlenie procesu R1 do S1

        if(forkS1_pid == -1)    //jeśli wystąpił błąd
        {
            perror("Nie udalo sie utworzyc procesu potomnego...\n");
        }
        else if(forkS1_pid == 0)    //jeśli git -> proces potomny S1 wystawia wartość 0 - w tym else if jest obsługa procesu S1
        {
            printf("PID S1 = %d\n", getpid());  //wyświetl PID S1
            return 0;   //zakończ proces S1
        }
        else    //dla wartości >0 -> obsługa procesu R1
        {
            printf("PPID S1 = %d\n", getpid()); //wyświetl PID R1 = PPID S1
        }
        return 0;   //zakończ proces R1
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        printf("PPID R1 = %d\n", getpid()); //wyświetl PID P = PPID R1
        forkR2_pid = fork();    //rozwidlenie procesu P do R2
    }
    if(forkR2_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR2_pid == 0)    //jeśli git -> proces potomny R2 wystawia wartość 0 - w tym else if jest obsługa procesu R2
    {
        printf("PID R2 = %d\n", getpid());  //wyświetl PID R2
        forkS2_pid = fork();    //rozwidlenie procesu R2 do S2
        if(forkS2_pid == -1)    //jeśli wystąpił błąd
        {
            perror("Nie udalo sie utworzyc procesu potomnego...\n");
        }
        else if(forkS2_pid == 0)    //jeśli git -> proces potomny S2 wystawia wartość 0 - w tym else if jest obsługa procesu S2
        {
            printf("PID S2 = %d\n", getpid());  //wyświetl PID S2
            return 0;   //zakończ proces S2
        }
        else    //dla wartości >0 -> obsługa procesu R2
        {
            printf("PPID S2 = %d\n", getpid());  //wyświetl PPID S2 = PID R2
        }
        return 0;   //zakończ proces R2
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        printf("PPID R2 = %d\n", getpid());  //wyświetl PPID R2 = PID P
    }
    return 0;   //zakończ proces P
}