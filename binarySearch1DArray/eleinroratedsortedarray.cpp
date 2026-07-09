#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int target) {
        int low=0, high=a.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]==target) return mid;

            //the left side is sorted
            if(a[low]<=a[mid]) {
                //figure out if element lies on left half or not
                if(target>=a[low] && target<=a[mid]) {
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            //right side is sorted
            else{
                //figure out if element lies on right half or not
                if(target>=a[mid] && target<=a[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
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
    int res=search(arr, target);
    cout<<res;
    return 0;
}