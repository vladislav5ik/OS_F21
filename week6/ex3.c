#include <stdio.h>

void process(int n, int BT[], int AT[], int P[], int QT){
    int CT[n], WT[n], TAT[n], BT_temp[n], completed[n], tick[n];

    for(int i = 0; i < n; i++){
        BT_temp[i] = BT[i];
        completed[i] = 0;
        tick[i] = 0;
    }
    int time = 0;
    CT[0] = 0;
    int flag = 1;


    while(flag){
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (completed[i]) {
                continue;
            } else {
                tick[i]++;
                if (time < AT[i]){
                    time = AT[i];
                }
            }
            if (BT_temp[i] < QT){
                CT[i] = BT_temp[i] + time;
                WT[i] = CT[i] - AT[i] - BT_temp[i];
                BT_temp[i] = 0;
                completed[i] = 1;
            } else {
                CT[i] = QT + time;
                WT[i] = CT[i] - AT[i] - QT;
                BT_temp[i] -= QT;
            }
            TAT[i] = CT[i] - AT[i];
            if (tick[i] > 1) {
                WT[i] -= QT * (tick[i] - 1);
            }
            time = CT[i];
        }

        //searching for uncompleted items
        for(int i = 0; i < n; i++){
            if (completed[i] != 1) {
                flag = 1;
                break;
            }
        }
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
        printf("P%d       %d   %d   %d   %d    %d\n",
               P[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
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
    int n, QT;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter quantum: ");
    scanf("%d",&QT);
    printf("Enter Arrival time and Burst time for each process:\n");
    int AT[n], BT[n], P[n];
    for (int i = 0; i < n; i++){
        P[i] = i + 1;
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d",&AT[i]);
        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d",&BT[i]);
    }
    //sorting by Arrival Time
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (AT[j + 1] < AT[j]){
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&P[j], &P[j + 1]);
            }
        }
    }

    process(n,BT,AT,P, QT);
    return 0;
}

