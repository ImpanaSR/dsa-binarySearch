#include<bits/stdc++.h>
using namespace std;

pair<int,int> floorAndCeil(vector<int> &arr, int target){

    sort(arr.begin(), arr.end());

    int floor = -1;
    int ceil = -1;

    int left = 0;
    int right = arr.size() - 1;

    // Find Floor
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] <= target){
            floor = arr[mid];
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    left = 0;
    right = arr.size() - 1;

    // Find Ceil
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] >= target){
            ceil = arr[mid];
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return {floor, ceil};
}

int main(){

    int n, target;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    pair<int,int> ans = floorAndCeil(arr, target);

    cout << "Floor = " << ans.first << endl;
    cout << "Ceil = " << ans.second;
}