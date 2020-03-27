#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void * potok(void *arg) {
    int number = *((int*)arg);

    while (true) {
        cout << number << endl;
    }

    return (void*)0;
}

int main() {
    pthread_t *threads = new pthread_t[2];

    for (int i = 0 ; i < 2; i += 1) {
        int *number = new int(i);

        int errorCode = pthread_create(
                            &threads[i],
                            NULL,
                            potok,
                            (void*)number
                        );
        if (errorCode != 0) {
            cout << "Error: " << errorCode << endl;

            delete[] threads;

            return -1;
        }
    }

    cin.get();

    for (int i = 0; i < 2; i += 1) {
        if (pthread_cancel(threads[i]) != 0) {
            cout << "Error" << endl;

            delete[] threads;

            return -1;
        }
    }

    delete[] threads;

    return 0;
}
