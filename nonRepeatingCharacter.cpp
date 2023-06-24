/*
PROBLEM:
Non Repeating Character
EasyAccuracy: 40.43%Submissions: 138K+Points: 2
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 
Your Task:
You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= N <= 10^3


APPROACH:


*/

#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S)
{
       //Your code here
    unordered_map<char,int> mp;
    for(int i=0; i<S.length(); i++){
        if(mp.count(S[i])>0){
            mp[S[i]]++;
            continue;
        }
        mp[S[i]]=1;
    }

    for(int i=0; i<S.length(); i++){
        if(mp[S[i]]==1){
            return S[i];
        }
    }
    return '$';

       
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<nonrepeatingCharacter(s)<<endl;
    }
}