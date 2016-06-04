#include<stdio.h>

using namespace std;

/**
    l=first index                                           r =last index
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    |_p_|_ _ _<p_ _ _|_ _ _ >p_ _ _|_ _ _unpartitioned_ _ _ |
     pivot           i             j
                (i is the      (j is the
                boundary b/w   boundary b/w
                elements       partitioned &
                <p & >p )     unpartitioned elements)


*/


int partition(int arr[],int l,int r)
{
    int p=arr[l];                   //pick first value as pivot
    int i=l+1;                      //set i to first index

    for(int j=i;j<=r;j++)           //loop j from first index to last index
    {
        if(arr[j]<p)                //if value at jth index is < p then swap the arr[i] and arr[j]
        {
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
            i++;
        }
    }
    int t=arr[l];                   //after loop pivot must be placed at its rightful index in array
    arr[l]=arr[i-1];
    arr[i-1]=t;

    return i-1;
}
void quicksort(int arr[],int l,int r) //l : first index for sub array , r: last index for subarray
{
    if(l<r){
    int p=partition(arr,l,r); //p is the index returned of pivot
    quicksort(arr,l,p-1);     // calling quicksort recursively for the left half of the array divided by pivot
    quicksort(arr,p+1,r);     // calling quicksort recursively for the right half of the array divided by pivot
    }
}
int main()
{
    int arr[]={3,8,2,5,1,4,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,n-1); //quicksort function 0 is for first index and n-1 is the last index in array;

    printf("\nSorted Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

}
