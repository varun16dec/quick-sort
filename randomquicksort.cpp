#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
    int random=l+rand()%r;      //generating random no

    while(random>r)
        random=l+random%r;      //random > r then make random into the range of l and r



/**
*       if the first element is not pivot element then
*       we have to do some preprocessing
*       we will swap the first element with pivot element
*       so the first become the pivot and we apply our algorithm
*/

    if(random!=l)           //if random index is not equal to first index then swap the values
    {
        int t=arr[random];
        arr[random]=arr[l];
        arr[l]=t;
    }

    int p=arr[l];           //make first element pivot element
    int i=l+1;
    for(int j=i;j<=r;j++)   //loop through l+1 to rth element
    {
        if(arr[j]<p)        //if jth element is <p then swap arr[i] and arr[j] element
        {
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
            i++;
        }
    }

    int t=arr[i-1];         //on loop completion we have to swap arr[i-1] and arr[l]
    arr[i-1]=arr[l];        //so that pivot element reaches its rightfull place`
    arr[l]=t;

    return i-1;             //return the pivot index
}
void randomquicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p=partition(arr,l,r);
        randomquicksort(arr,l,p-1);
        randomquicksort(arr,p+1,r);
    }
}
int main()
{
 int arr[]={3,8,2,5,1,4,7,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    srand(time(NULL));          //using time as seed for rand() else rand() won't proudce varied nos
    randomquicksort(arr,0,n-1); //quicksort function 0 is for first index and n-1 is the last index in array;

    printf("\nSorted Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

