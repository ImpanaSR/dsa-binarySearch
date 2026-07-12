#include<bits/stdc++.h>
using namespace std;

//brute-force solution
int searchin2Dmatrix(vector<vector<int>> arr, int target){
    int n=arr.size();
    int m= arr[0].size();
    int i=0, j=m-1;
    while(i<n && j>=0){
        if(arr[i][j]==target){
            return 1;
        }else if(arr[i][j]>target){
            j--;
        }else{
        i++;
        }
    }
    return 0;
}

int Search2D(vector<vector<int>> arr, int target){
    int n=arr.size();
    int m=arr[0].size();
    int low=0, high=n*m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid/m][mid%m]==target){
            return true;
        }else if(arr[mid/m][mid%m]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    cout << searchin2Dmatrix(arr, 5);
    return 0;
}