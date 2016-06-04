#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500000

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
int compar = 0; /* A counter for the number of comparison */
int main(){
   
    int *a,i,n,p;
    int ave_compar = 0;
    clock_t tstart, tend;
    double time_spent;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    a = (int *) malloc (sizeof(int) * n);
    tstart = clock();
    for(p=0;p<10000;p++){    
       srand(time(NULL));

       for(i=0;i<n;i++){
       a[i]=1+rand() % 1000; /*Random numbers from 1 to 100 */
       }

       partition(a,0,n-1);
       ave_compar=ave_compar+compar;
       compar = 0;
    }
    ave_compar=ave_compar/10000;
    tend = clock() ;
    time_spent = (double)(tend - tstart) / CLOCKS_PER_SEC;
    printf( "time  spent is = %.5f\n", time_spent ) ;
    
    printf( "The number of comparisons is : %d\n",ave_compar );
    return 0;
}
/********************************************************************/
void partition(int arr[],int low,int high){
    int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
/********************************************************************/
void mergeSort(int arr[],int low,int mid,int high){
    int i,m,k,l,temp[MAX];
    l = low;
    i = low;
    m = mid+1;
    while((l<=mid)&&(m<=high)){
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
             compar++;
         }
         else{
             temp[i]=arr[m];
             m++;
             compar++;
         }
         i++;
    }
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
/********************************************************************/
