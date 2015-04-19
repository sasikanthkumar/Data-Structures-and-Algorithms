/* Traverse through array bubble the largest value to the end using pairwise comparisions and swapping */
/* if we have N elements we write loop N-1 times so that all elements are sorted */

#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *,int );

int main(){
    
    int a[] = {7,4,5,6,2,3};
    int n= sizeof(a)/sizeof(int);

    bubble_sort(a,n);
    
    int i=0;
    for (i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}

void bubble_sort(int *a,int n){
    int done,i,temp;
    do{
        done = 1;
        for (i=0; i<n-1; i++) {
            if (a[i]>a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                done = 0;
            }
        }
    }while(done == 0);
}
