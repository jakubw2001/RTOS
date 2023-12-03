#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <unistd.h>

int main() 
{
    int forkR0_pid, forkR1_pid, forkR2_pid, forkR3_pid, forkR4_pid; //PID procesów R1, R2, R3, R4
    int statusR0, statusR1, statusR2, statusR3, statusR4;
    forkR0_pid = fork();    //rozwidlenie procesu P do R0
    int t[] = {20, 5, 3, 8, 9}; //tablica cykli dla procesów
    if(forkR0_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR0_pid == 0)    //jeśli git -> proces potomny R0 wystawia wartość 0 - w tym else if jest obsługa procesu R0
    {
        for(int i = 1; i <= t[0]; i++)
        {
            printf("PID R0 = %d Kolejny numer procesu: 1 Numer cyklu: %d\n", getpid(), i);  //wyświetl PID R0
            sleep(1);
        }
        exit(0);
        return 0;   //zakończ proces R0
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        forkR0_pid = wait(&statusR0);
        printf("Proces potomny %d zakończony; wartość exit: %d\n", forkR0_pid, WEXITSTATUS(statusR0));
        //__________________________________________________________________________________________________________________
        forkR1_pid = fork();    //rozwidlenie procesu P do R1
    }
    if(forkR1_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR1_pid == 0)    //jeśli git -> proces potomny R1 wystawia wartość 0 - w tym else if jest obsługa procesu R1
    {
        for(int i = 1; i <= t[1]; i++)
        {
            printf("PID R1 = %d Kolejny numer procesu: 2 Numer cyklu: %d\n", getpid(), i);  //wyświetl PID R1
            sleep(1);
        }
        exit(1);
        return 0;   //zakończ proces R1
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        forkR1_pid = wait(&statusR1);
        printf("Proces potomny %d zakończony; wartość exit: %d\n", forkR1_pid, WEXITSTATUS(statusR1));
        //__________________________________________________________________________________________________________________
        forkR2_pid = fork();    //rozwidlenie procesu P do R2
    }
    if(forkR2_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR2_pid == 0)    //jeśli git -> proces potomny R2 wystawia wartość 0 - w tym else if jest obsługa procesu R2
    {
        for(int i = 1; i <= t[2]; i++)
        {
            printf("PID R2 = %d Kolejny numer procesu: 3 Numer cyklu: %d\n", getpid(), i);  //wyświetl PID R2
            sleep(1);
        }
        exit(2);
        return 0;   //zakończ proces R2
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        forkR2_pid = wait(&statusR2);
        printf("Proces potomny %d zakończony; wartość exit: %d\n", forkR2_pid, WEXITSTATUS(statusR2));
        //__________________________________________________________________________________________________________________
        forkR3_pid = fork();    //rozwidlenie procesu P do R3
    }
    if(forkR3_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR3_pid == 0)    //jeśli git -> proces potomny R3 wystawia wartość 0 - w tym else if jest obsługa procesu R3
    {
        for(int i = 1; i <= t[3]; i++)
        {
            printf("PID R3 = %d Kolejny numer procesu: 4 Numer cyklu: %d\n", getpid(), i);  //wyświetl PID R3
            sleep(1);
        }
        exit(3);
        return 0;   //zakończ proces R3
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        forkR3_pid = wait(&statusR3);
        printf("Proces potomny %d zakończony; wartość exit: %d\n", forkR3_pid, WEXITSTATUS(statusR3));
        //__________________________________________________________________________________________________________________
        forkR4_pid = fork();    //rozwidlenie procesu P do R4
    }
    if(forkR4_pid == -1)    //jeśli wystąpił błąd
    {
        perror("Nie udalo sie utworzyc procesu potomnego...\n");
    }
    else if(forkR4_pid == 0)    //jeśli git -> proces potomny R4 wystawia wartość 0 - w tym else if jest obsługa procesu R4
    {
        for(int i = 1; i <= t[4]; i++)
        {
            printf("PID R4 = %d Kolejny numer procesu: brak Numer cyklu: %d\n", getpid(), i);  //wyświetl PID R4
            sleep(1);
        }
        exit(4);
        return 0;   //zakończ proces R4
    }
    else    //dla wartości >0 -> obsługa procesu P
    {
        forkR4_pid = wait(&statusR4);
        printf("Proces potomny %d zakończony; wartość exit: %d\n", forkR4_pid, WEXITSTATUS(statusR4));
    }
    return 0;   //zakończ proces P
}