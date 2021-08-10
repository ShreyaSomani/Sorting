#include <iostream>
using namespace std;

int get_max(int a[],int n)
{
	int max=-1;
	for(int i=0;i<n;++i)
	if(max==-1 || a[i]>max)
	max=a[i];
	return max;
}

void count_sort(int a[],int n,int pos)
{
	int b[n];
	int count[10]={0};
	for(int i=0;i<n;++i)
	++count[(a[i]/pos)%10];
	
	for(int i=1;i<10;++i)
	count[i]=count[i]+count[i-1];
	
	for(int i=n-1;i>=0;--i)
	b[--count[(a[i]/pos)%10]]=a[i];
	
	for(int i=0;i<n;++i)
	a[i]=b[i];
}

void radix_sort(int a[],int n)
{
	int max=get_max(a,n);
	for(int pos=1;max/pos>0;pos=pos*10)
    count_sort(a,n,pos);
}

void print(int a[],int n)
{
	for(int i=n-1;i>=0;--i)//reverse print for descending order
	cout<<a[i]<<" ";
}

int main() 
{
  int n;
  cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) 
  cin >> a[i];
  radix_sort(a,n);
  print(a,n);
}
