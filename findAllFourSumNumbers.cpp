
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
    sort(arr.begin(),arr.end());
    vector<vector<int> > final;
    for(int i=0; i<arr.size()-3; i++){
        for(int j=i+1; j<arr.size()-2; j++){
            int p1=j+1;
            int p2=arr.size()-1;
            while(p1<p2){
                int s=arr[i]+arr[j]+arr[p1]+arr[p2];
                if(s==k){
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(arr[p1]);
                    v.push_back(arr[p2]);
                    final.push_back(v);
                    p1++;
                    p2--;
                }
                else if(s<k){
                    p1++;
                }
                else{
                    p2--;
                }
            }
        }
    }
    return final;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int k; cin>>k;
        vector<vector<int> > v1=fourSum(v,k);
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<4; j++){
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}