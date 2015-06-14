#include <iostream>
using namespace std;

void insertion_sort(int *arr, int length);

int main() {
    
    int arr[] = {3,7,9,5,2,4};
    
    int length = sizeof(arr)/sizeof(arr[0]);
    
    insertion_sort(arr,length);
    
    int i=0;
    
    for (i=0; i<length; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
    
    return 0;
}

/*
In Insertion sort first we select the element into temp Then in the while loop
 we check if the temp is less than the left adjacent element if temp is less we shift the left element to right side after ending while loop we insert temp into a position which is temp's position in the sorted list Like this in every iteration we shift the element to its correct position in the sorted list.
*/

void insertion_sort(int *arr,int length){
    int i,j,temp;
    
    for (i=0; i<length; i++) {
        temp = arr[i];
        j = i;
        
        // checking whether adjacent element in left side is less than or greater than the current element
        
        
        while (j>0 && temp<arr[j-1]) {
            
            // moving the element to forward position
            
            arr[j] = arr[j-1];
            j--;
        }
        
        // moving current element to its correct position in sorted list
        arr[j] = temp;
    }
}
