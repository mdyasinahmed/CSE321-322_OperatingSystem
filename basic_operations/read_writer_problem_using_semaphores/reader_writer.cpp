#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex, mutex;
int read_count = 0;
int data = 0;

void* reader(void* arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&rw_mutex); // First reader locks the resource
    sem_post(&mutex);

    printf("Reader %ld read data: %d\n", (long)arg, data);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&rw_mutex); // Last reader unlocks the resource
    sem_post(&mutex);
    return NULL;
}

void* writer(void* arg) {
    sem_wait(&rw_mutex);
    data += 10; // Modify shared data
    printf("Writer %ld wrote data: %d\n", (long)arg, data);
    sem_post(&rw_mutex);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, w2;
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_create(&r1, NULL, reader, (void*)1);
    pthread_create(&r2, NULL, reader, (void*)2);
    pthread_create(&w1, NULL, writer, (void*)1);
    pthread_create(&w2, NULL, writer, (void*)2);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    pthread_join(w2, NULL);

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
