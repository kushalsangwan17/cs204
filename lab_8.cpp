#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll kthSmallest(ll arr[], ll l, ll r, ll k) ;
ll partition(ll arr[], ll l, ll r, ll x) ;
ll findMedian(ll arr[], ll n) ;
void swap(ll *a, ll *b);

int main()
{
  ll t;
  cin>>t;
  for(ll i=0;i<t;++i)
  {
    ll k;
    cin>>k;
    ll arr[k];
    for(ll j=0;j<k;++j)
    {
      ll a,b;
      cin>>a>>b;
     ll dis = (a*a+b*b);
      arr[j]=dis;
    }
    ll ans =0;
    if(k%2==0)
   ans = kthSmallest(arr,0,k-1,k/2);
 else 
  ans = kthSmallest(arr,0,k-1,k/2+1);
    cout<<sqrt(ans)<<endl;
  }
}

ll findMedian(ll arr[], ll n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
void swap(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 
ll partition(ll arr[], ll l, ll r, ll x) 
{ 
    ll i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
ll kthSmallest(ll arr[], ll l, ll r, ll k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        ll n = r-l+1; // Number of elements in arr[l..r] 
        ll i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
        ll medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        ll pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return INT_MAX; 
} 
