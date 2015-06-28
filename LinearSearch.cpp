#include<iostream>
using namespace std;

bool linear_search_bool(int *arr, int length, int item);
int linear_search_pos(int *arr, int length, int item);
int recursive_linear_search(int *arr, int l, int r, int item);


int main(){
    int a[] = {1, 9, 2, 4, 6, 3, 7, 5, 8, 0};
    
    int length = sizeof(a)/sizeof(a[0]);
    
    //we need to search if 3 is present in array or not
    
    if(linear_search_bool(a, length, 3)){   // item present in the array
        
        cout << "Item is found" << endl;
        
    }else{  // item not present in the array
    
        cout << "Item is not found "<< endl;
        
    }
    
    int pos = linear_search_pos(a, length, 3);
    
    if (pos != -1) {
        cout << "Item found at position = " << pos << endl;
    }else{
        cout << "Item Not Found" << endl;
    }

    // recursive linear search
    
    pos = recursive_linear_search(a, 0, length-1, 7);
    
    if (pos != -1) {
        cout << "Item found at position = " << pos << endl;
    }else{
        cout << "Item Not Found" << endl;
    }
    
    return 0;
}

/**
 Linear Search - In Linear Search we start at the begining of the array and iterate through every element in the array if the item we need is found we return true and stop the iteration if the element is not present in the array we got to the end of array.
 
 Time Complexity: O(n)
 
 Minimum Time Best Case : O(1)
 
 
 **/

// recursive linear search

int recursive_linear_search(int *arr ,int l, int r, int item){
    if (l>r) {
        return -1;
    }
    if (arr[l] == item) {
        return l;
    }
    return recursive_linear_search(arr, l+1, r, item);
}



// linear search returning position where the item is found if not found returns -1

int linear_search_pos(int *arr, int length, int item){
    int i=0;
    for (i=0; i<length; i++) {
        if (arr[i] == item) {
            // item found
            return i;
        }
    }
    // item not found
    return -1;
}


// linear search returning boolean

bool linear_search_bool(int *arr, int length, int item){
    int i = 0;
    for (i=0; i<length; i++) {
        if (arr[i] == item) {
            //item found
            return true;
        }
    }
    //item not found
    return false;

}