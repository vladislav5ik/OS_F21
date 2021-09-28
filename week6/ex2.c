#include <stdio.h>

void process(int n, int BT[], int AT[], int P[]){
    int T[n], WT[n], TAT[n];

    T[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        T[i + 1] = T[i] + BT[i];
    }

    WT[0] = 0;
    for (int i = 1; i < n; i++) {
        if (T[i] - AT[i] >= 0) {
            WT[i] = T[i] - AT[i];}
        else {
            WT[i] = 0;
        }
    }

    for (int i = 0; i < n ; i++){
        TAT[i] = BT[i] + WT[i];
    }

    int WT_sum = 0, TAT_sum = 0;
    for (int i = 0 ; i < n ; i++){
        WT_sum += WT[i];
        TAT_sum += TAT[i];
    }
    float WT_avg = (float)WT_sum/(float)n;
    float TAT_avg =(float)TAT_sum/(float)n;

        printf("Process  AT  BT  CT  TAT  WT\n");
    for (int i = 0 ; i < n ; i++){
        int CT = TAT[i] + AT[i];
        printf("P%d       %d   %d   %d   %d    %d\n",
               P[i], AT[i], BT[i], CT, TAT[i], WT[i]);
    }
    printf("Average Turnaround Time = %lf\n",TAT_avg);
    printf("Average Waiting Time = %lf\n",WT_avg);
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {
    printf("Enter number of processes: ");
    int n;
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time for each process:\n");
    int AT[n], BT[n], P[n];
    for (int i = 0; i < n; i++){
        P[i] = i + 1;
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d",&AT[i]);
        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d",&BT[i]);
    }
    //sorting by Arrival and Burst Time
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (AT[j + 1] < AT[j]){
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&P[j], &P[j + 1]);
            } else {
                if ((AT[j] == BT[j + 1]) && (BT[j + 1] < BT[j])){
                    swap(&AT[j], &AT[j + 1]);
                    swap(&BT[j], &BT[j + 1]);
                    swap(&P[j], &P[j + 1]);
                }
            }
        }
    }

    process(n,BT,AT,P);
    return 0;
}
