//upper bound -> smallest index such that arr[indx]>x
//ub=upper_bound(arr.begin(), arr.end(), n)-arr.begin();
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> arr, int n, int k){
    sort(arr.begin(), arr.end());
    int left=0;
    int right=n-1;
    int ans=n;

    while(left<=right){
        int mid=left+(right-left)/2;
        
        if(arr[mid]>k){
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
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
    int res=lowerbound(arr, n, target);
    cout<<res;
    return 0;
}