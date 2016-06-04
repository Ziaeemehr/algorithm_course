#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[], int n);
int compar = 0;
int main(){

    int *a,ii,n;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    a = (int *) malloc (sizeof(int) * n);

    for(ii=0;ii<n;ii++){
    a[ii]=1+rand() % 10000; /*Random numbers from 1 to 10000 */
    }
    printf("Elements to be sorted are:\n ");
    for(ii=0; ii<n; ii++){
         printf("%d ",a[ii]);
    }
    printf( "\n" );

    insertionsort(a,n);

    printf("After sorting elements are:\n ");
    for(ii=0;ii<n;ii++){
         printf("%d ",a[ii]);
    }
    printf( "\n" );
    printf( "The number of comparisions is :%d \n ",compar);
    return 0;
}

void insertionsort(int arr[], int n) 
{
   int i, j, key,flag;
   for (j=1; j<n; j++)
   {
      key = arr[j];
      i= j-1;
      while ( i >= 0  )
      {
         if (arr[i] > key)
           flag = 1;
         else
           flag = 0;
         compar++;
         if (flag){
            arr[i+1] = arr[i];
            arr[i] = key;
            i--;
         }
         else
           break;      
      }      
  }
}