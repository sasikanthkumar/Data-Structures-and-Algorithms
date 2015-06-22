
#include<iostream>
using namespace std;

void merge_sort(int *arr, int left, int right);
void merge(int *arr, int start, int mid, int end);


int main(){
    int arr[] = {12,11,7,13,6,4,18,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    merge_sort(arr,0,size-1);
    
    int i=0;
    for (i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    return 0;
}

/**
MergeSort is a divide and conquer algorithm. It divides the given array repeatedly and sorts the two halves and merges them.It divides array until no further division is possible. So first we call the merge_sort method and it divides the array repetedly and we call the method merge to join two sorted arrays.
 
 TimeComplexity: Each merge sort calls two merge_sorts and one merge so the relation turns out to be T(n) = 2T(n/2)+O(n) which on solving gives us time complexity as 
 
    O(nLogn)
 
 MinimumTime: O(nLogn) as if the array is already sorted also it divides array until it is non divisible
 
 In Place: No as auxillary space is O(n)
 
 Stable: Yes the original order of the input set is preserved
 
 
 
**/

void merge_sort(int *arr, int left, int right){
    if (left < right) {
        
        int mid = left+(right-left)/2;
        
        // this mid is same as (left+right)/2 but this equation fails for larger values of left and right specifically when the sum of left and right exceeds maximum positive int value (2^31-1) so using the above equation solves the problem
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        
        // merge after dividing repeatedly
        merge(arr, left, mid, right);
    }
}

void merge(int *arr,int start, int mid, int end){
    
    // starting indexes of both arrays needed to merge
    int p = start;
    int q = mid+1;
    
    int temp[end-start+1];  // temporary array to store merged arrays
    
    int k = 0;
    
    while (p<=mid && q<=end) {
        if (arr[p] <= arr[q]) {
            temp[k] = arr[p];
            p++;
        }else{
            temp[k] = arr[q];
            q++;
        }
        k++;
    }
    
    // copying the remaining elements in the left array to temp
    while (p<=mid) {
        temp[k] = arr[p];
        p++;
        k++;
    }
    
    //copying the remaining elements in the right array to temp
    while (q<=end) {
        temp[k] = arr[q];
        q++;
        k++;
    }
    
    // copying sorted temp array to original array arr
    
    int i=0;
    k=0;
    for (i=start; i<=end; i++) {
        arr[i] = temp[k];
        k++;
    }
    
}