#include <stdio.h>
#include <stdlib.h>
#define MAX 500000

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
int compar = 0; /* A counter for the number of comparison */
int main(){
   
    int *a,i,n;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    a = (int *) malloc (sizeof(int) * n);
    for(i=0;i<n;i++){
    a[i]=1+rand() % 1000; /*Random numbers from 1 to 1000 */
    }

    partition(a,0,n-1);

    printf("After merge sorting elements are:\n ");
    for(i=0;i<n;i++){
         printf("%d ",a[i]);
    }
    printf( "\n" );
    printf( "The number of comparisons is : %d\n",compar );
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
