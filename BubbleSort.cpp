/*
 This algorithm repeatedly compares adjacent elements and swaps them if they are in wrong order. The comparision is repeated until no swaps are needed which indicates that the list is sorted.
*/

#include <iostream>
using namespace std;

void bubble_sort(int *arr,int length);

int main(){
    
    int arr[] = {7,4,5,6,2,3};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    bubble_sort(arr,length);
    
    int i;
    
    for (i=0; i<length; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\n";

    return 0;
}

/* Here we sort the array in increasing order so when the first element is greater than the adjacent element we swap them
    After every iteration the largest element in the list will be placed to its position in the sorted order
 
 The below implementation is optimized implementation of bubble sort i.e the algorithm stops if the inner loop didn't cause any swap.
*/

void bubble_sort(int *arr, int length){
    int done,i,temp;
    do{
        done = 1;
        for (i=0; i<length-1; i++) {
            if (arr[i]>arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                done = 0;
            }
        }
    }while (done == 0);
}