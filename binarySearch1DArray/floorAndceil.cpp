//lower bound -> smallest index such that arr[indx]>=x
//lb=lower_bound(arr.begin(), arr.end(), n)-arr.begin();
#include<bits/stdc++.h>
using namespace std;

int floorandceil(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    int left=0;
    int right=n-1;
    int ans=-1;

    while(left<=right){
        int mid=left+(right-left)/2;
        
        if(arr[mid]<=mid){
            ans=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return ans;
}

int main(){
    int n, target;
     cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    int res=floorandceil(arr, n);
    cout<<res;
    return 0;
}