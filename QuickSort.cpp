#include<iostream>
using namespace std;

void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

int main(){
    int arr[] = {10,7,16,5,1,9,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    quick_sort(arr,0,size-1);
    
    int i=0;
    for (i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/**
QuickSort - Quick sort is a divide and conquer algorithm compared to merge sort it reduces space complexity and removes use of auxillary array used in merge sort 
 It is based on the idea of choosing one element in the array as a pivot element and partitioning the array around it such that in the array left side of the pivot element contains all the elements less than pivot element and right side contains all elements greater than the pivot.
 There are many different versions of quicksort that picks pivot in different ways,
    1. First element as a pivot (Implemented here )
    2. Last element as a pivot
    3. Random element as a pivot
    4. Median as a pivot
 selecting a random pivot results into an improved time complexity in average cases
 
 Time Complexity: Time taken by quicksort in general can be written like this 
                    T(n) = T(k)+T(n-k-1)+O(n)
                T(k) and T(n-k-1) are for two recursive calls assuming that there are k elements less than the pivot element in that array
                Worst Case: In the worst case k will be equal to zero i.e pivot will be the largest or smallest element in the array time complexity becomes
                    T(n) = T(n-1)+O(n)
                    so in the worst case complexity is O(n^2)
                Best Case: In best case partition process always chooses the middle element as pivot so the time complexity equation becomes 
                    T(n) = 2T(n/2)+O(n)
                    and the time complexity becomes O(nLogn)
                Average Case: In the average case the time complexity equation becomes
                    T(n) = T(n/10)+T(9n/10)+O(n)
                    and the time complexity becomes O(nLogn)
 InPlace: Yes as auxillary space is O(1)
 Stable: No as it swaps two non-adjacent elements
**/

void quick_sort(int *arr,int start, int end){
    if (start < end) {
        int pivot_pos = partition(arr, start, end);
        quick_sort(arr, start, pivot_pos-1);
        quick_sort(arr, pivot_pos+1, end);
    }
}

int partition(int *arr, int start, int end){
    
    int i=start+1;
    int pivot = arr[start];   // choosing starting element as a pivot
    int j=0;
    int temp;
    for (j=start+1; j<=end; j++) {
        if (arr[j]<pivot) {
            
            // swapping i,j
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    // keeping the pivot element in its correct position
    temp = arr[i-1];
    arr[i-1] = arr[start];
    arr[start] = temp;
    
    return i-1;  // return position of pivot
}