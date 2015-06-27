#include<iostream>
using namespace std;

void counting_sort(int *arr, int max, int size);

int main(){
    
    int arr[] = {5,4,4,3,4,2,1,6,1};
    int max = 7;
    int size = sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr, max, size);
	int i=0;
	for(i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
    return 0;
}



/**
Counting Sort - This technique is based on keys between a specific range. First we count the frequencies of distinct elements in the array and store them in an auxillary array by mapping its value as index of the auxillary array and then place each element in its proper order in the output array according to decreasing or increasing order of frequency.
 To use the counting sort we should know the maximum element which can be in the array and it should be small as we will use an auxiliary array if the max value is big more space will be wasted in the auxillary array.
 Let 'max' be the maximum value of an element in the given array
 So we create a auxiliary array of max+1 size and out array of the given array size
 
 Time Complexity: O(max+n) where max is the range of input element in arr and n is the number of elements in arr
 
 In Place: No because auxiliary space O(max+n)
 
 Stable: Yes the implementation below is stable it preserves original order of input set 
 
 counting sort is efficient if the range of input data is not significantly greater than number of objects to be sorted 
 
**/

void counting_sort(int arr[], int max, int size){
    
    
    int out[size];      // output array
    int aux[max+1];     // Auxiliary array

    int i=0;
    
    // initialize all elements in auxiliary array to zero
    
    for (i=0; i<max+1; i++) {
        aux[i] = 0;
    }
    
	// storing frequency of each element in arr by mapping its value as index in the auxiliary array
    for (i=0; i<size; i++) {
        aux[arr[i]]++;
    }
	
	// calculating how many elements are less than or equal to i in the array
	for (i=1; i<max+1; i++){
		aux[i] += aux[i-1];
	}
	
	// placing each element in the arr to its correct position in sorted order in the out array we start from back because it preserves the relative order of similar keys in the sorted array and makes sorting stable 
	// if we perform this for loop from 0 to end of array the resulting sorting will not be stable 
	for(i=size-1; i>=0; i--){
		out[aux[arr[i]]-1] = arr[i];
		aux[arr[i]]--;
	}
	
	// copying out to original arr
	
	for(i=0; i<size; i++ ){
		arr[i] = out[i];
	}
}