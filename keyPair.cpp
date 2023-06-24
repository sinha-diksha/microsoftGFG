/*Key Pair
EasyAccuracy: 30.61%Submissions: 185K+Points: 2
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

Example 1:

Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
Example 2:

Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and returns a boolean denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 105
*/

#include<bits/stdc++.h>
using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
   unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        if(mp.count(arr[i])>0){
            mp[arr[i]]++;
            continue;
        }
        mp[arr[i]]=1;
    }
    bool isFound=false;
    int i=0;
    while(i<n && isFound==false){
        int y=x-arr[i];
        if(mp.count(y)>0){
            if(y==arr[i]){
                if(mp[y]>1){
                    cout<<y<<" "<<arr[i]<<endl;
                    return true;
                }
            }else{
                cout<<y<<" "<<x<<endl;
                return true;
            }
        }
        i++;
    }
    return false;
	
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<hasArrayTwoCandidates(arr,n,x)<<endl;
    }
    

}