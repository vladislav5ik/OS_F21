#include <stdio.h>

void process(int n, int BT[], int AT[]){
    int ST[n], WT[n], TAT[n];

    ST[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        ST[i + 1] = ST[i] + BT[i];
    }

    WT[0] = 0;
    for (int i = 1; i < n; i++) {
        if (ST[i] - AT[i] >= 0) {
            WT[i] = ST[i] - AT[i];}
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
               i + 1, AT[i], BT[i], CT, TAT[i], WT[i]);
    }
    printf("Average Turnaround Time = %lf\n",TAT_avg);
    printf("Average Waiting Time = %lf\n",WT_avg);
}

int main(void) {
    printf("Enter number of processes: ");
    int n;
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time for each process:\n");
    int AT[100], BT[100];
    for (int i = 0; i < n; i++){
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d",&AT[i]);
        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d",&BT[i]);
    }
    process(n,BT,AT);
    return 0;
}
