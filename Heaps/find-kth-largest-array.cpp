#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void MaxHeapify(int *arr, int i, int n)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i + 2;
	if(l<n && arr[i] < arr[l])
		largest = l;
	if(r<n && arr[largest] < arr[r])
		largest = r;
	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		MaxHeapify(arr, largest, n);
	}
}

int extractMax(int *arr, int &n)
{
	int root = arr[0];
	arr[0] = arr[n-1];
	MaxHeapify(arr, 0, n);
	return root;
}
	 
void kth(int *arr, int n, int k)
{
	for(int i = n/2;i>=0;i--)
	{
		MaxHeapify(arr, i, n);
	}
	int ans = 0;
	for(int i=0;i<k;i++)
	{
		ans = extractMax(arr, n);
	}
	cout<<ans<<endl;
}



int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	kth(a, n, k);
	return 0;
	}

		
