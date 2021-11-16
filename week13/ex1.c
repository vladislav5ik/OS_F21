#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

int check_resources(int* A, int* P, int M){
    for(int j=0; j<M; j++){
        if(A[j] < P[j]){ //check if avaliable resouces for each resource class
            return FALSE;
        }
    }
    return TRUE;
}

int main(){
    //1. Collecing data

    int M, N; // 2D array size
    printf("Enter number of resource classes (M): ");
    scanf("%d", &M);
    printf("Enter number of processes (N): ");
    scanf("%d", &N);
    FILE* f = fopen("input.txt", "r");
    // Existing resource vector
    int* E = (int*) malloc(M * sizeof(int));
    for(int i=0; i<M; i++){
        fscanf(f, "%d", &E[i]);
    }

    // Avaliable resource vector
    int* A = (int*) malloc(M * sizeof(int));
    for(int i=0; i<M; i++){
        fscanf(f, "%d", &A[i]);
    }

    // Current allocation matrix (2D array)
    int** C = (int**) malloc(N * sizeof(int*));

    // Request matrix (2D array)
    int** R = (int**) malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++){
        C[i] = (int*)malloc(M * sizeof(int));
        C[i] = (int*)malloc(M * sizeof(int));
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            fscanf(f, "%d", &C[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            fscanf(f, "%d", &R[i][j]);
        }
    }

    // array showing if process done
    int* done = (int*) malloc(N * sizeof(int));
    for(int i=0; i<N; i++){
        done[i]=0;
    }


    //2. Algorithm
     while(TRUE){
        for(int i=0; i<N; i++){
            // check if we can execute process
            if((done[i] == 0) && (check_resources(A, R[i], M) == TRUE)){
                for(int k=0; k<M; k++){
                    A[k] += C[i][k];
                }
                done[i] = 1;
                break;
            }
        }
        for(int i=0; i<N; i++){
            // check if all processes done
            if(done[i]==0){
                printf("deadlock at %d\n", i);
                return 0;
            }
        }
        printf("No deadlock\n");
        return 0;
    }
}
