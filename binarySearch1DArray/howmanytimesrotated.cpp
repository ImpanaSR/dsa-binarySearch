#include<bits/stdc++.h>
using namespace std;

    int findMin(vector<int>& nums) {
        int index=-1;
        int ans=INT_MAX;
        int low=0, high=nums.size()-1;
        while(low<=high){

            if(nums[low]<=nums[high]){
                if(ans<nums[low]){
                    index=low;
                    ans=nums[low];
                }
                break;
            }

            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                if(nums[low]<ans){
                    index=low;
                    ans=nums[low];
                }
                low=mid+1;
            }else{
                if(nums[mid]<ans){
                    index=mid;
                    ans=nums[mid];
                }
                high=mid-1;
            }
        }
        return ans;
    }

int main(){
    int n;
     cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int res=findMin(arr);
    cout<<res;
    return 0;
}