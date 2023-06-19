/*Approach Explained

The code you provided is written in C++ and it solves a problem involving prefix sums and remainders.

Let's go through the code step by step:

The code includes the necessary libraries and defines a macro ll as long long to represent long integers.
The solve function takes three arguments: an integer n representing the size of the input array, 
a vector arr of long integers, and an integer k. This function calculates the maximum subarray length whose sum 
is divisible by k.
Inside the solve function, several variables are declared. sum is initialized to 0 to keep track of the prefix sum. 
ourMap is an unordered map that stores the remainder value and its index. mx is initialized to 0 and will hold the 
maximum subarray length.
A loop is used to iterate through each element of the input array. Inside the loop, the prefix sum sum is updated by 
adding the current element arr[i].
The remainder rem is calculated using the formula (sum%k+k)%k. This formula ensures that the remainder is always positive, 
even if sum is negative.
If the remainder rem is 0, it means that the current subarray starting from the beginning is divisible by k. In this case, 
the maximum length mx is updated to i+1 (i.e., the current index + 1).
If the remainder rem is not 0, the code checks if ourMap already contains the remainder. If it does not, the remainder and 
its index i are added to ourMap.
If the remainder rem is already present in ourMap, it means that there is a subarray between the indices ourMap[rem] and i 
whose sum is divisible by k. The maximum length mx is updated by taking the maximum of the current mx and i - ourMap[rem].
Finally, the maximum length mx is printed.
In the main function, the code reads the number of test cases t from the input.
A loop is used to iterate t times, and in each iteration, the code reads the size of the array n and the value of k. It 
then reads the elements of the array arr from the input.
The solve function is called with the input values n, arr, and k.
This code can be used to solve a problem where you need to find the maximum length of a subarray whose sum is divisible 
by k for multiple test cases.*/



#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll long long

void solve(int n, vector<ll> arr, int k){
    ll sum=0;
    unordered_map<int,int> ourMap; // store the value of remainder and it's index
    int mx=0;
    for(int i=0; i<n; i++){
        sum+=arr[i]; // calculate prefix sum and then it's index
        ll rem=(sum%k+k)%k; // if rem is negative, so it's better to use this formula to calculate the modulus value
        if(rem==0){
            mx=max(mx,i+1);
            continue;
        }
        if(ourMap.count(rem)==0){
            ourMap[rem]=i;
        }else{
            mx=max(mx,i-ourMap[rem]);
        }
    }
    cout<<mx<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        solve(n,arr,k);
    }
}