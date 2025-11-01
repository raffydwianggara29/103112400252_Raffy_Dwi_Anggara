#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // jumlah philosopher

pthread_mutex_t chopstick[N];  // sumpit

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking\n", id);
        sleep(1); //s

        // ambil sumpit kiri dan kanan
        pthread_mutex_lock(&chopstick[id]);
        pthread_mutex_lock(&chopstick[(id + 1) % N]);

        printf("Philosopher %d is eating\n", id);
        sleep(1);

        // letakkan kembali sumpit
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % N]);

        printf("Philosopher %d finished eating\n", id);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t tid[N];
    int id[N];

    // inisialisasi mutex (sumpit)
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    // buat thread philosopher
    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &id[i]);
    }

    // tunggu (program berjalan terus)
    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}