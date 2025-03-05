// Write a program in C to find the second-smallest element in an array.

#include<stdio.h>
#define SIZE 10

void sort(int array[]){
for(int i =0; i<SIZE; i++){
for (int j =1; j<=SIZE; j++){
if (array[i]<=array[j]){
int temp = array[i];
array[i] = array[j];
array[j] = temp;
}
}
}
}

void main(){
int array[SIZE];
printf("Enter the elements of the array");
for (int i =0; i<SIZE;i++){
scanf("%d",&array[i]);
}
sort(array);
printf("the second smallest element in the array is %d",array[2]);
}
