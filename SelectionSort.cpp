

#include <iostream>
using namespace std;

void selection_sort(int *arr,int length);



int main(){
    int arr[] = {3,5,9,7,4,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    selection_sort(arr,length);
    
    int i=0;
    for (i=0; i<length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
 Selection sort maintains two subarrays of given array
 
 -> subarray that is sorted
 -> remaining subarray that is unsorted
 
 In every iteration minimum element from the unsorted subarray is selected and
 moved to sorted subaray.
 
    Time Complexity: O(n*n)
 
    Best Case Complexity: O(n*n)
 
    In Place Algorithm: Yes O(1) Auxiliary
 
    Stable: No as we swap the elements without taking care of their index.
 */


void selection_sort(int *arr,int length){
    int i,j,min,temp;
    for (i=0; i<length-1; i++) {
        min = i;
        for (j=i+1; j<length; j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}