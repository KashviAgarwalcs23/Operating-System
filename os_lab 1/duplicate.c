//Write a program in C to count the total number of duplicate elements in an array.

#include<stdio.h>
#define SIZE 10

void duplicate(int array[],int ele){
int count =0;
for(int i =0; i<SIZE; i++){
if (array[i]==ele)
count++;
}
printf("%d is repeated %d times \n",ele,count);
}


void main(){
int array[SIZE],count;
printf("Enter the elements of the array");
for (int i =0; i<SIZE;i++){
scanf("%d",&array[i]);
}
for (int i =0; i<SIZE;i++){
duplicate(array,array[i]);
}
}
