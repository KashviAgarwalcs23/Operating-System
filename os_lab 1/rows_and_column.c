// Write a program in C to find the sum of rows and columns of a matrix.

#include<stdio.h>
#define SIZE 3

void main(){
int array[SIZE][SIZE];
printf("Enter the elements of the array");
for (int i =0; i<SIZE;i++){
for (int j=0; j<SIZE; j++){
scanf("%d",&array[i][j]);
}
}

int sum_row1 =0, sum_row2 =0, sum_row3 =0, sum_column1 =0, sum_column2 =0, sum_column3 =0;
for (int i =0; i<SIZE;i++){
sum_row1 += array[0][i];
}
printf("the sum of row1 in the array is %d\n",sum_row1);
for (int i =0; i<SIZE;i++){
sum_row2 += array[1][i];
}
printf("the sum of row2 in the array is %d\n",sum_row2);
for (int i =0; i<SIZE;i++){
sum_row3 += array[2][0];
}
printf("the sum of row3 in the array is %d\n",sum_row3);
for (int i =0; i<SIZE;i++){
sum_column1 += array[i][0];
}
printf("the sum of column1 in the array is %d\n",sum_column1);
for (int i =0; i<SIZE;i++){
sum_column2 += array[i][1];
}
printf("the sum of column2 in the array is %d\n",sum_column2);
for (int i =0; i<SIZE;i++){
sum_column3 += array[i][2];
}
printf("the sum of column3 in the array is %d\n",sum_column3);
}
