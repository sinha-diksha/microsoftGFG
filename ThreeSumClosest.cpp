/*Three Sum Closest
EasyAccuracy: 17.65%Submissions: 36K+Points: 2
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array, Arr of N numbers, and another number target, find three integers in the array such that the sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, print the maximum one.

Example 1:

Input:
N = 6, target = 2
A[] = {-7,9,8,3,1,1}
Output: 2
Explanation: There is one triplet with sum
2 in the array. Triplet elements are -7,8,
1 whose sum is 2.
Example 2:

Input:
N = 4, target = 13
A[] = {5,2,7,5}
Output: 14
Explanation: There is one triplet with sum
12 and other with sum 14 in the array.
Triplet elements are 5, 2, 5 and 2, 7, 5
respectively. Since abs(13-12) ==
abs(13-14) maximum triplet sum will be
preferred i.e 14.
Your Task:
Complete threeSumClosest() function and return the expected answer.

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(1).

Constraints:
3 ≤ N ≤ 103
-105 ≤ A[i] ≤ 105
1 ≤ target ≤ 105*/

#include <bits/stdc++.h>
using namespace std;


int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
    sort(arr.begin(),arr.end());
    int closestSum=INT_MAX;
    int x,y,z;
    for(int i=0; i<arr.size()-2; i++){
        
        int p1=i+1;
        int p2=arr.size()-1;
    
        while(p1<p2){
            int sum=arr[i]+arr[p1]+arr[p2];
            if(abs(sum-target)<abs(closestSum-target)){
                x=i;
                y=p1;
                z=p2;
                closestSum=sum;
            }
            if(abs(sum-target)==abs(closestSum-target)){
                if(sum>closestSum){
                    x=i;
                    y=p1;
                    z=p2;
                    closestSum=sum;
                }
            }
            if(sum<target){
                p1++;
            }
            else if(sum>target){
                p2--;
            }
            else{
                return sum;
            }
        }
            

    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    return closestSum;
        
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<threeSumClosest(arr,target)<<endl;
}