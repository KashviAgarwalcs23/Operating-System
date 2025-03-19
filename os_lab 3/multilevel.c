  #include <stdio.h>

int main() {

    int bt[20], wt[20], tat[20], ct[20], at[20], queue[20];
    int n;
    float wtavg = 0, tatavg = 0;
    int sys_bt[20], user_bt[20];
    int sys_count = 0, user_count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
      at[i] =0;
        printf("Enter Queue Number for Process %d: ", i + 1);
        scanf("%d", &queue[i]);

        if (queue[i] == 1) {
            sys_bt[sys_count++] = bt[i];
        } else if (queue[i] == 2) {
            user_bt[user_count++] = bt[i];
        }
    }

    int total_count = 0;
    int current_time = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {

                int temp_at = at[i], temp_bt = bt[i], temp_queue = queue[i];
                bt[i] = bt[j];
                queue[i] = queue[j];
                at[j] = temp_at;
                bt[j] = temp_bt;
                queue[j] = temp_queue;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        if (queue[i] == 1) {
            if (current_time < at[i]) {
                current_time = at[i];
            }

            wt[i] = current_time - at[i];
            tat[i] = wt[i] + bt[i];
            ct[i] = current_time + bt[i];
            current_time = ct[i];

            wtavg += wt[i];
            tatavg += tat[i];
            total_count++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (queue[i] == 2) {
            if (current_time < at[i]) {
                current_time = at[i];
            }

            wt[i] = current_time - at[i];
            tat[i] = wt[i] + bt[i];
            ct[i] = current_time + bt[i];
            current_time = ct[i];

            wtavg += wt[i];
            tatavg += tat[i];
            total_count++;
        }
    }

    printf("\nPROCESS\tBURST TIME\tQUEUE\t\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%s\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], (queue[i] == 1 ? "1" : "2"), ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
