sem_wait(&mutex);      // Lock read_count
read_count++;          // Increment the number of readers
if (read_count == 1) {
    sem_wait(&rw_mutex);   // Lock resource for reading
}
sem_post(&mutex);      // Unlock read_count

// Read the resource

sem_wait(&mutex);      // Lock read_count
read_count--;          // Decrement the number of readers
if (read_count == 0) {
    sem_post(&rw_mutex);   // Unlock resource for writing
}
sem_post(&mutex);      // Unlock read_count

