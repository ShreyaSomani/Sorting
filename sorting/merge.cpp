#include <iostream>
#include <stack>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void display(int A[],int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

 //iterative binary search
int binary_iterative(int a[],int key,int n)
{
    int beg=0;
    int end=n-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==key)
        return mid;

        else if(a[mid]<key)
        beg=mid+1;

        else
        end=mid-1;
    }
return -1;
}
//recursive binary search
int bin_recur(int a[], int beg,int end,int key)
{
    if(beg<=end)
    {
    int mid = (beg+end)/2;
    if(a[mid]==key)
    return mid;

    if(a[mid]<key)
    return (a,mid+1,end,key);

    return(a,beg,mid-1,key);
}
return -1;
}

//recursive merge sort
void mergesort(int a[],int left,int mid,int right)
{
int left_len = mid - left + 1;
int right_len = right - mid;

int l[left_len] , r[right_len];
int k=0;

for(int i=0;i<left_len;++i)
l[i]=a[k++];

for(int j=0;j<left_len;++j)
r[j]=a[k++];

int i=0,j=0,m=left;

while(i<left_len && j<right_len)
{
    if(l[i]<r[j])
    a[m++]=l[i++];

    else if(l[i]>r[j])
    a[m++]=r[j++];
}
    while(i<left_len)
    a[m++]=l[i++];

    while(j<right_len)
    a[m++]=r[j++];


}

void merge(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        merge(a,l,mid);
        merge(a,mid+1,r);
        mergesort(a,l,mid,r);
    }
}

//iterative merge sort
void merge_iterative(int a[],int n)
{
    int curr_size;
    int left_start;
    //bottom up approach
for(curr_size=1; curr_size<n; curr_size=2*curr_size) //size 1 to create sorted subarrays of size 2, then merge subarrays 
//of size 2 to create sorted subarrays of size 4, and so on.
{
    for(left_start=0; left_start<n-1; left_start+=2*curr_size)//starting point of left subarrays of current size
    {
        int mid = min(left_start+curr_size-1,n-1); //ending point of left subarray
        //mid+1 is starting point of right sub array
        int right_start = min(left_start+2*curr_size-1,n-1);//ending point of right subarray
        mergesort(a,left_start,mid,right_start);//merging subarrays
    }
}
}

//recursive quick sort
int partition(int a[],int start,int end)
{
int pivot=a[end];
int i=start-1;

for(int j=0;j<=end-1;++j)
{
    if(a[j]<=pivot)
    {
        ++i;
        swap(&a[i],&a[j]);
    }
}
swap(&a[i+1],&a[end]);
return (i+1);
}

void quick(int a[], int start,int end)
{
    if(start<end)
    {
        int pi=partition(a,start,end);
        quick(a,start,pi-1);
        quick(a,pi+1,end);
    }
    display(a,sizeof(a));
}

//iterative quick sort
void quick_recursive(int a[],int start,int end)
{
    int stack[end-start+1];
    int top=-1;
        stack[++top]=start;
        stack[++top]=end;
   
    while(top>=0)
    {
       end=stack[top--];
       start=stack[top--];
       int pi=partition(a,start,end);
       if(pi-1>start)
       {
       	stack[++top]=start;
       	stack[++top]=pi-1;
	   }
	   if(pi+1<end)
       {
       	stack[++top]=pi+1;
       	stack[++top]=end;
	   }
    }
}


 

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n";
    display(arr,arr_size);
    cout << "\nSorted array is \n";
    quick_recursive(arr, 0, arr_size - 1);
    display(arr,arr_size);
    return 0;
}
 
