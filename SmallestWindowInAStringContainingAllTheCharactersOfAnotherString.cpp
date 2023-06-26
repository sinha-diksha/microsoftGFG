/*
76. Minimum Window Substring
Hard
15.2K
639
Companies
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.*/

// Leetcode+gfg+microsoft

#include <bits/stdc++.h>
using namespace std;


string smallestWindow (string s, string p)
    {
        // Your code here
         int res=INT_MAX;
        unordered_map<char,int> mp;
        int count=0;
        for(int i=0; i<p.size(); i++){
            if(mp.count(p[i])>0){
                mp[p[i]]++;
                continue;
            }
            mp[p[i]]=1;
            count++;
        }
        int start=0;
        int i=0; int j=0;
        while(j<s.size()){
            if(mp.count(s[j])>0){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            //cout<<"D"<<endl;
            if(count==0){
                while(count==0){
                    if(j-i+1<res){
                        res=j-i+1;
                        // cout<<i<<" "<<j<<endl;
                        // cout<<res<<endl;
                        start=i;
                    }
                    if(mp.count(s[i])>0){
                        mp[s[i]]++;
                        if(mp[s[i]]>0){
                            count++;
                        }
                    }
                    i++;
                        
                }
            }
            j++;
        }
        if(res!=INT_MAX){
             return s.substr(start,res);
        }
        else{
            return "" ;       }
    }
   

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        cout<<smallestWindow(s,p)<<endl;
    }
}