#include<bits/stdc++.h>
using namespace std;

//TC-->O(n)
vector<int> firstandlastoccurence(vector<int> arr, int target){
    int first=-1, last=-1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==target){
            if(first==-1) first=i;
            last=i;
        }
    }
    return {first, last};
}

//TC-->O(2longn)

int lowerbound(vector<int> arr, int x){
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int ans=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }else{
            low=mid+1;
            }
        }
        return ans;
    }

    int upperbound(vector<int> arr, int n, int x){
        sort(arr.begin(), arr.end());
        int ans=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>x){
                ans=mid;
                high=mid-1;
            }else{
            low=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerbound(nums, target);
        if(lb==n || nums[lb]!=target) return {-1, -1};
        return {lb, upperbound(nums, n, target)-1};
    }

int main(){
    int n, target;
     cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    vector<int> res=firstandlastoccurence(arr, target);
    for(int x: res){
        cout<<x<<" ";
    }
    return 0;
}