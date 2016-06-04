#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quicksort( int a[], int l, int r);
int partition( int a[], int l, int r);

//void quicksort(int arr[], int firstIndex, int lastIndex);
int compar = 0;
int main(){

    int *arr,ii,n,p;
    int ave_compar = 0;
    clock_t tstart, tend;
    double time_spent;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    arr = (int *) malloc (sizeof(int) * n);
    tstart = clock();

    for(p=0;p<10000;p++){    
       srand(time(NULL));

       for(ii=0;ii<n;ii++){
       arr[ii]=1+rand() % 1000; /*Random numbers from 1 to 100 */
       }

    quicksort(arr,0,n-1);
    ave_compar=ave_compar+compar;
       compar = 0;
    }
    ave_compar=ave_compar/10000;
    tend = clock() ;
    time_spent = (double)(tend - tstart) / CLOCKS_PER_SEC;
    printf( "time  spent is = %.5f\n", time_spent ) ;
    
    printf( "The number of comparisions is :%d \n ",ave_compar);
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
