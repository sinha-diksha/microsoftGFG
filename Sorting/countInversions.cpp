/*
here we use the idea of merge sort. Time complexity: O(nlogn)
while using brute force, we need to traverse the array teice inside the loop which will take O(n^2) time complexity, which is 
definitely not an efficient approach.

So when we use merge sort:
we divide the array llo two parts,
let's assume we have the answers for left and right parts, let's say the inversion count for left is left_inv and the inversion count
for right is right_inv, now what are the values that are left, the values left are those which we get when we merge the array.
Let n be the size of the left array and m be the size of the right array.
So now, you need to use two pollers i and j, as you use in merge sort,
let count=0;
if(arr1[i]<=arr2[j]){
    arr3[k]=arr1[i];
    i++;
    k++;
}else{
    arr3[k]=arr2[j];
    count+=(n-i);
    k++;
    j++;
}

This is the soul condition of our process. 
Let's write the code!!!!
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


long long merge(long long arr[], ll left, ll right){
    ll mid=(left+right)/2;
    ll n=(mid-left)+1;
    ll m=right-mid;
    ll* arr1=new ll[n];
    ll* arr2=new ll[m];
    ll l=0;
    for(ll i=left; i<mid+1; i++){
        arr1[l]=arr[i];
        l++;
    }
    l=0;
    for(ll j=mid+1; j<=right; j++){
        arr2[l]=arr[j];
        l++;
    }

    ll i=0; ll j=0;
    ll* arr3=new ll[n+m];
    ll k=0;
    ll count=0;
    while(i!=n && j!=m){
        if(arr1[i]<=arr2[j]){
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
            count+=(n-i);
            k++;
        }
    }
    while(i!=n){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j!=m){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    l=0;
    for(ll i=left; i<=right; i++){
        arr[i]=arr3[l];
        l++;
    }

    return count;
}

long long mergeSort(long long arr[], ll left, ll right){
    if(left>=right){
        return 0;
    }
    long long mid=(left+right)/2;
    long long leftInv=mergeSort(arr,left,mid);

    long long rightInv=mergeSort(arr,mid+1, right);

    long long final=merge(arr,left,right);

    return leftInv+rightInv+final;
}

long long inversionCount(long long arr[], long long N){
    return mergeSort(arr,0,N-1);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long * arr=new long long[n];
        for(ll i=0; i<n; i++){
            cin>>arr[i];
        } 
        cout<<inversionCount(arr,n);
    }
}