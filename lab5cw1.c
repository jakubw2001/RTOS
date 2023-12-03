#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 8
typedef struct
{
    int cnt;    //numer wątku
    int sum;    //suma kontrolna
    const char *msg;    //wiadomość
}thread_data;

/* Funkcja wykonywana przez watek */
void* start_routine (void* arg)
{ 
    thread_data *data = (thread_data*)arg;
    int id = data->cnt;
    printf("CNT: %d SUM: %d TEXT: %s\n", data->cnt, data->sum, data->msg);
    //usleep(5000); 
	pthread_exit((void*)id);
}

/* Program glowny */
int main ()
{

	int i, rc;
	pthread_t thread_id[NUM_THREADS];
    const char* messages[8];
    messages[0] = "English";
    messages[1] = "French";
    messages[2] = "Spanish";
    messages[3] = "Polish";
    messages[4] = "German";
    messages[5] = "Russian";
    messages[6] = "Japanese";
    messages[7] = "Latin";
    thread_data data;

	for(i = 0; i < NUM_THREADS; i++)
	{
		/* Utworz nowy watek, ktory bedzie wykonywal funkcje start_routine. */
		/* Przekaz argument i do watku */
		printf("Tworze watek nr: %d\n", i);
        data.cnt = i;
        data.sum = data.sum + i;
        data.msg = messages[i];
        //printf("%d  %d  %s\n", data.cnt, data.sum, data.msg);
		rc = pthread_create (&thread_id[i], NULL, &start_routine, (void*)&data);
		/* W przypadku, gdy nie uda sie utworzyc watku */
		if (rc)
		{
			printf("Blad. Kod powrotu z funkcji pthread_create(): %d\n", rc);
			exit(1);
		}
	}
	printf("Watek glowny zakonczony. Wyjscie\n");
	pthread_exit(NULL);
}
