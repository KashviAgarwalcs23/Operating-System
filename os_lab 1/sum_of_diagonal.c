//Write a program in C to find the sum of the left diagonals of a matrix.


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

int sum =0;
for (int i =0; i<SIZE;i++){
sum += array[i][i];
}
printf("the sum of diagonal element in the array is %d",sum);
}
