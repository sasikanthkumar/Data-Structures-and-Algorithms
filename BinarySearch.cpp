#include<iostream>
using namespace std;

int recursive_binary_search(int *arr, int left, int right, int item);
int iterative_binary_search(int *arr, int length, int item);
int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int length = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Recursive binary search" << endl;
    
    int pos = recursive_binary_search(arr, 0, length-1, 5);
    
    
    if (pos != -1) {
        cout << "Item found in array in index = " << pos << endl;
    }else{
        cout << "Item not found in the array" << endl;
    }
    
    cout << "Iterative binary search" << endl;
    
    pos = iterative_binary_search(arr, length, 7);
    
    if (pos != -1) {
        cout << "Item found in array in index = " << pos << endl;
    }else{
        cout << "Item not found in the array" << endl;
    }
    return 0;
}


/**
 Binary Search - Divide and conquer Algorithm. 
    The array should be sorted 
    If the array is in ascending order
    
    First, comapre the item with middle element of the array if it matches return truee  or the index of element in the array
    If the item is less than the middle element we recurse on the sub array that is left to the middle element 
    If the item is larger than the middle element we recurse on the sub array that is right to the middle element 
    At each recursion size of array is reduced to half.
    At last step we will be left with one element in the array.
 
 
 Time complexity: O(Logn) n is the size of the array as for every iteration array size is reduced to half
 
 Best time: O(1) if our item is mid element in the array
 
 Auxiliary space: O(1) in iterative binary search
                O(Logn) in recursive binary search
 
 **/

// iterative binary search

int iterative_binary_search(int *arr, int length, int item){
    int left = 0;
    int right = length-1;
    while (left <= right) {
        
        int mid = left+(right-left)/2;
        
        if (arr[mid] == item) {
            return mid;
        }else if(item < arr[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return -1;
}



// recursive binary search

int recursive_binary_search(int *arr, int left, int right, int item){
    if (left <= right) {
        int mid = left + (right-left)/2;
        if (arr[mid] == item) {
            return mid;
        }else if(item<arr[mid]){
            return recursive_binary_search(arr, left, mid-1, item);
        }else{
            return recursive_binary_search(arr, mid+1, right, item);
        }
    }else{
        return -1;
    }
}