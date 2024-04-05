#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t empty_cond;
    pthread_cond_t full_cond;
    int buffer[SIZE];
    int count;
    int in;
    int out;
} my_buffer;

void my_buffer_init(my_buffer *buffer) {
    pthread_mutex_init(&buffer->mutex, NULL);
    pthread_cond_init(&buffer->empty_cond, NULL);
    pthread_cond_init(&buffer->full_cond, NULL);
    buffer->count = 0;
    buffer->in = 0;
    buffer->out = 0;
}

void my_buffer_produce(my_buffer *buffer, int item) {
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->count == SIZE) {
        pthread_cond_wait(&buffer->empty_cond, &buffer->mutex);
    }
    buffer->buffer[buffer->in] = item;
    buffer->in = (buffer->in + 1) % SIZE;
    buffer->count++;
    pthread_cond_signal(&buffer->full_cond);
    pthread_mutex_unlock(&buffer->mutex);
}

void *producer(void *arg) {
    my_buffer *buffer = (my_buffer *)arg;
    int item = 1; // Start with the first odd number
    while (1) {
        my_buffer_produce(buffer, item);
        printf("Produced odd: %d\n", item);
        item += 2; // Increment to next odd number
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    my_buffer buffer;
    my_buffer_init(&buffer);

    pthread_t producer_thread;
    if (pthread_create(&producer_thread, NULL, producer, (void *)&buffer) != 0) {
        fprintf(stderr, "Error creating producer thread\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the producer thread to finish (which it won't)
    pthread_join(producer_thread, NULL);

    pthread_mutex_destroy(&buffer.mutex);
    pthread_cond_destroy(&buffer.empty_cond);
    pthread_cond_destroy(&buffer.full_cond);

    return 0;
}
