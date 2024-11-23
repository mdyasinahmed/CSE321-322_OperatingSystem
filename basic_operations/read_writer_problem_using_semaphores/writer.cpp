it(&rw_mutex);   // Lock resource for writing

// Modify the resource

sem_post(&rw_mutex);   // Unlock resource for writing

