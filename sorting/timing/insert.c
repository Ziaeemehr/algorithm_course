#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionsort(int arr[], int n);
int compar = 0;
int main(){

    int *a,ii,n,p;
    int ave_compar=0;
    clock_t tstart, tend;
    double time_spent;

    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    a = (int *) malloc (sizeof(int) * n);

    tstart = clock();

    for(p=0;p<1000;p++){    
       srand(time(NULL));

       for(ii=0;ii<n;ii++){
       a[ii]=1+rand() % 1000; /*Random numbers from 1 to 100 */
       }
    
       insertionsort(a,n);
       ave_compar=ave_compar+compar;
       compar = 0;

    }

    ave_compar=ave_compar/1000;

    tend = clock() ;
    time_spent = (double)(tend - tstart) / CLOCKS_PER_SEC;
    printf( "time  spent is = %.5f\n", time_spent ) ;
    
    printf( "The number of comparisions is :%d \n ",ave_compar);
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