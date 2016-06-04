#include <stdio.h>
#include <stdlib.h>


void quicksort( int a[], int l, int r);
int partition( int a[], int l, int r);

//void quicksort(int arr[], int firstIndex, int lastIndex);
int compar = 0;
int main(){

    int *arr,ii,n;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    arr = (int *) malloc (sizeof(int) * n);
    
    for(ii=0;ii<n;ii++){
    arr[ii]=1+rand() % 1000; /*Random numbers from 1 to 1000 */
    }
    printf("Elements to be sorted are:\n ");
    for(ii=0; ii<n; ii++){
         printf("%d ",arr[ii]);
    }
    printf( "\n" );

    quicksort(arr,0,n-1);

    printf("After sorting elements are:\n ");
    for(ii=0;ii<n;ii++){
         printf("%d ",arr[ii]);
    }
    printf( "\n" );
    printf( "The number of comparisions is :%d \n ",compar);
    return 0;
}
void quicksort( int a[], int l, int r)
{
   int j;
   if( l < r ) 
   {
    // divide and conquer
       j = partition( a, l, r);
       quicksort( a, l, j-1);
       quicksort( a, j+1, r);
   }
}

int partition( int a[], int l, int r) {
   int pivot, i, j, temp;
   pivot = a[l];
   i = l; j = r+1;
        
   while( 1)
   {
    do {
       ++i; 
       ++compar; 
   }
    while( a[i] <= pivot && i <= r );
    --compar;
    do {
       --j; 
       ++compar; 
   }
    while( a[j] > pivot );
    --compar;
    if( i >= j ) break;
    temp = a[i]; a[i] = a[j]; a[j] = temp;
   }
   temp = a[l]; a[l] = a[j]; a[j] = temp;
   return j;
}
