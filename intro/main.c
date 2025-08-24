//
// Created by sathipa on 24/8/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void thread1_create(){

    pthread_t pthread1;

    static char *thread_input1 = "I am thread no 1";

    int rc = pthread_create(&pthread1,
                            NULL,
                            thread_fn_callback,
                            (void*) thread_input1
                            );

    if (rc != 0){
        printf("Error Occured, thread could not be created, "
               "errno = %d\n", rc);
        exit(0);
    }

}

int main(int argc, char **argv){

    thread1_create();
    printf("Main fun paused\n");
    pause();
    return 0;
}