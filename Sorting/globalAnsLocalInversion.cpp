#include <bits/stdc++.h>
using namespace std;


    int merge(vector<int>& nums, int left, int right){
    int mid=(left+right)/2;
    vector<int> temp;
    int i=left,j=mid+1,k=left,inv=0;
           while(i<=mid&&j<=right)
           {
               if(nums[i]<=nums[j])
               {
                   temp.push_back(nums[i]);
                   i++;
                

               }
               else
               {
                   temp.push_back(nums[j]);
                 j++;
                   inv+=mid-i+1;
          }
           }
           while(i<=mid)
           temp.push_back(nums[i++]);
           while(j<=right)
           temp.push_back(nums[j++]);
           int l=0;
           for(i=left;i<=right;i++){
            nums[i]=temp[l];
            l++;
           }
           return inv;
}

int mergeSort(vector<int>& nums, int left, int right){
    if(left>=right){
        return 0;
    }
    int mid=(left+right)/2;
    int leftInv=mergeSort(nums,left,mid);

    int rightInv=mergeSort(nums,mid+1, right);

    int final=merge(nums,left,right);

    return leftInv+rightInv+final;
}


    int globalInversion(vector<int>& nums){
        return mergeSort(nums,0,nums.size()-1);
    }
    int localInversion(vector<int>& nums){
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        return count;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int lC=localInversion(nums);
        int gC=globalInversion(nums);
        cout<<lC<<" "<<gC<<endl;
        if(lC==gC){
            return true;
        }else{
            return false;
        }
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
        cout<<isIdealPermutation(v)<<endl;
    }
}