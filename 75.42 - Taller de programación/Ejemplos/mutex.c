//
//  mutex.c
//  Ejemplos
//
//  Created by Gastón Montes on 30/09/14.
//  Copyright (c) 2014 Gastón Montes. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
int thread_ids[3] = {0,1,2};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *inc_count(void*t)
{
    int j,i;
    double result=0.0; 
    long my_id = (long)t;
    for (i=0; i<TCOUNT; i++) { 
        pthread_mutex_lock(&count_mutex); count++;
        /*
         Verificar el valor de count y señalar al hilo que está en espera cuando el valor COUNT_LIMIT es alcanzado. Esto ocurre mientras el mutex está tomado.
         */
        if (count == COUNT_LIMIT) {
            pthread_cond_signal(&count_threshold_cv);
            printf("inc_count(): thread %ld, count = %d Threshold reached.n", my_id, count); 
        }
        printf("inc_count(): thread %ld, count = %d, unlocking mutexn", my_id, count);
        pthread_mutex_unlock(&count_mutex);
        /* Liberar adrede el procesador para darle tiempo a los otros hilos */ 
        sleep((unsigned int)1); // Alternativas pthread_yield(); o sleep(0);
    }
    return NULL; 
}

void *watch_count(void*t)
{
    long my_id - (long)t;
    printf("Starting watch_count(): thread %ldn", *my_id);
    /*
     Tomar el mutex y esperar la señal. Notar que la función pthread_cond_wait liberará el mutes en forma automática y
     atómica mientras espera. La verificación de que no se llegó
     a COUNT_LIMIT evita que este hilo se suspenda en forma indefiinda. */
    pthread_mutex_lock(&count_mutex);
    if (count<COUNT_LIMIT) {
        pthread_cond_wait(&count_threshold_cv, &count_mutex); printf("watch_count(): thread %ld Condition signal received.n", my_id); count += 125;
        printf("watch_count(): thread %ld count now = %d.n", my_id, count); }
    pthread_mutex_unlock(&count_mutex);
    return NULL; 
}

int main(int argc, char*argv[])
{
    int i, rc;
    long t1=1, t2=2, t3=3;
    pthread_t threads[3];
    pthread_attr_t attr;
    
    /* Se inicializan el mutex y la condition variable */ 
    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init (&count_threshold_cv, NULL); 
    /* Para mayor portabilidad, crear hilos de forma 79. que admintan join, explícitamente */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); 
    pthread_create(&threads[0], &attr, watch_count, (void *)t1);
    pthread_create(&threads[1], &attr, inc_count, (void *)t2);
    pthread_create(&threads[2], &attr, inc_count, (void *)t3);
    
    /* Esperar que todos lo hilos terminen */
    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf ("Main(): Waited on %d threads. Done.n", NUM_THREADS);
    /* Limpiar y salir */
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&count_threshold_cv);
    pthread_exit(NULL);
}
