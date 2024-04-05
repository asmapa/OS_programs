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

void my_buffer_consume(my_buffer *buffer, int *item) {
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->count == 0) {
        pthread_cond_wait(&buffer->full_cond, &buffer->mutex);
    }
    *item = buffer->buffer[buffer->out];
    buffer->out = (buffer->out + 1) % SIZE;
    buffer->count--;
    pthread_cond_signal(&buffer->empty_cond);
    pthread_mutex_unlock(&buffer->mutex);
}

void *consumer(void *arg) {
    my_buffer *buffer = (my_buffer *)arg;
    int item;
    while (1) {
        my_buffer_consume(buffer, &item);
        printf("Consumed even: %d\n", item);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    my_buffer buffer;
    my_buffer_init(&buffer);

    pthread_t consumer_thread;
    if (pthread_create(&consumer_thread, NULL, consumer, (void *)&buffer) != 0) {
        fprintf(stderr, "Error creating consumer thread\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the consumer thread to finish (which it won't)
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&buffer.mutex);
    pthread_cond_destroy(&buffer.empty_cond);
    pthread_cond_destroy(&buffer.full_cond);

    return 0;
}
