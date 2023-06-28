/*Sort array after converting elements to their squares
EasyAccuracy: 77.85%Submissions: 546+Points: 2
Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

Given an array A consisting of both positive and negative integers of size N which are sorted. Your task is to sort the square of the numbers of the array.

 

Example 1:

Input:
N = 6
A[] = {-6, -3, -1, 2, 4, 5}
Output: 1 4 9 16 25 36
Explanation: 
Square of the given array is -
[36, 9, 1, 4,16, 25]. When this array 
is sorted, it gives - [1, 4, 9, 16, 25, 36]
 

Example 2:

Input:
N = 5
A[]  = {-5, -4, -2, 0, 1}
Output: 0 1 4 16 25


Your Task:  
You don't need to read input or print anything. Your task is to complete the function sortSquares() which takes the array A[] and its size N as inputs and returns an array of size N.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 2 * 104
-104 <= Ai <= 104*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortSquares(int A[], int arr_size){
    vector<int> v(arr_size);
    for(int i=0; i<arr_size; i++){
        v[i]=(A[i]*A[i]);
    }
    sort(v.begin(),v.end());
    return v;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        vector<int> v=sortSquares(arr,n);
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}