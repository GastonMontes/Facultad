
#ifndef Ejemplos_mutex_h
#define Ejemplos_mutex_h

#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
} mutex_t;

void mutex_create(mutex_t* self);
void mutex_destroy(mutex_t* self);
void mutex_lock(mutex_t* self);
void mutex_unlock(mutex_t* self);

#endif