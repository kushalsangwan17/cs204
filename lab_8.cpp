#include<bits/stdc++.h>
using namespace std;


long double median(long double* a,long long int k);
long double radius(long double x,long double y);
long double* insertion_sort(long double* p,long long int k);
long long int ceil(long long int k);
long long int floor(long long int k);

int main()
{
	long long int num;
	cin>>num;
	while(num>0)
	{
		long long int k;
		cin>>k;
		long double a[k];
		for(int i=0;i<k;i++)
		{
			long double x;
			long double y;
			cin>>x;
			cin>>y;
			a[i]=radius(x,y);
		}

		

		long double* c=insertion_sort(a,k);
		
			cout<<c[ceil(k)-1]<<"\n"; 
		
		num--;
	}
}

long double radius(long double x,long double y)
{
	long double a=x*x;
	long double b=y*y;
	long double c=a+b;
	return pow(c,0.5);
}

long long int ceil(long long int k)
{
	if(k%2==0)
		return k/2;
	else
		return (k+1)/2;
}

long long int floor(long long int k)
{
	if(k%2==0)
		return k/2;
	else
		return (k-1)/2;
}


long double* insertion_sort(long double* a,long long int k)

{
	
	for(long long int i=1;i<k;i++)
	{	
		long long int j=i-1;
		long double key=a[i];
		while((a[j]>key)&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}

	return a;
}

long double median(long double* a,long long int k)
{
	
		long double* c=insertion_sort(a,k);
		return c[ceil(k)];
	

	
}