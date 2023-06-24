/*Count distinct elements in every window
EasyAccuracy: 41.83%Submissions: 101K+Points: 2
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1
Your Task:
Your task is to complete the function countDistinct() which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= K <= N <= 105
1 <= A[i] <= 105 , for each valid i*/

#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct (int A[], int n, int k)
{
        //code here.
    unordered_map<int, int> mp;
    int i=0;
    for(; i<k; i++){
        if(mp.count(A[i])>0){
            mp[A[i]]++;
            continue;
        }
        mp[A[i]]=1;
    }
    vector<int> v;
    v.push_back(mp.size());
    for(; i<n; i++){
        if(mp.count(A[i])>0){
            mp[A[i]]++;
        }else{
            mp[A[i]]=1;
        }
        mp[A[i-k]]--;
        if(mp[A[i-k]]<1){
            mp.erase(A[i-k]);
        }
        v.push_back(mp.size());

    }
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int* arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        vector<int> output=countDistinct(arr,n,k);
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}