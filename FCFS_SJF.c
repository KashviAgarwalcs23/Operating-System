#include <stdio.h>
#include <stdlib.h>
int n, i, j, pos, temp, choice, BT[20], WT[20], TAT[20], process[20], total=0;
    float avg_TAT=0, avg_WT=0;
void FCFS() {
    WT[0] = 0;
    for (i = 0; i < n; i++) {
        WT[i] = 0;
        for (j = 0; j < i; j++) {
            WT[i] += BT[j];
        }
    }

    printf("\nProcess\t\tBurst_time\tWaiting_Time\tTurnAroundTime");
    for (i = 0; i < n; i++) {
        TAT[i] = BT[i] + WT[i];
        avg_WT += WT[i];
        avg_TAT += TAT[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, BT[i], WT[i], TAT[i]);
    }
    avg_WT = (float)(avg_WT) / (float)n;
    avg_TAT = (float)(avg_TAT) / (float)n;
    printf("\nAverage Waiting Time: %.2f", avg_WT);
    printf("\nAverage Turnaround Time: %.2f\n", avg_TAT);
}

void SJF() {
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (BT[j] < BT[pos]) {
                pos = j;
            }
        }
        temp = BT[i];
        BT[i] = BT[pos];
        BT[pos] = temp;
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    WT[0] = 0;
    for (i = 1; i < n; i++) {
        WT[i] = 0;
        for (j = 0; j < i; j++) {
            WT[i] += BT[j];
        }
        total += WT[i];
    }
    avg_WT = (float)total / n;
    total = 0;
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        TAT[i] = BT[i] + WT[i];
        total += TAT[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", process[i], BT[i], WT[i], TAT[i]);
    }
    avg_TAT = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_WT);
    printf("\nAverage Turnaround Time=%f\n", avg_TAT);
}

int main() {
 printf("Enter the total number of processes:");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]:", i + 1);
        scanf("%d", &BT[i]);
        process[i] = i + 1;
    }
    while (1) {
        printf("\n-----MAIN MENU-----\n");
        printf("1. FCFS Scheduling\n2. SJF Scheduling\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                FCFS(n, BT, process);
                break;
            case 2:
                SJF(n, BT, process);
                break;
            default:
                printf("Invalid Input!!!");
                exit(1);
        }
    }
    return 0;
}
