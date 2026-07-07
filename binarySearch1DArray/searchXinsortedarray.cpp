#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    int left=0;
    int right=arr.size()-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target)
            return mid;
        else if(arr[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main(){
    int n, target;
     cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>target;
    int res=binarySearch(arr, target);
    cout<<res;
    return 0;
}