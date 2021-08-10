#include <math.h> 
#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void ShellSort(int a[], int n) 
{ 

for(int gap=n/2;gap>=1;gap=gap/2)
{
	for(int j=gap;j<n;++j)
	{
		for(int i=j-gap;i>=0;i=i-gap)
		{
			if(a[i+gap]>a[i])
			break;
			else
			swap(&a[i+gap],&a[i]);
		}
	}
}
}


void printArray(int a[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int a[] = { 26, 12, 11, 13, 5, 6 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    ShellSort(a, n); 
    printArray(a, n); 
  
    return 0; 
} 
