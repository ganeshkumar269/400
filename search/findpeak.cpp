#include <bits/stdc++.h>

using namespace std;

/*
    Find Peak: given array which increases initially and then decreases
                find the maximum value
    condition : 
        
        a[mid] > a[mid+1] r = mid - 1,store mid; else l = l + 1; 
*/  


int solve(vector<int>& arr){
    int l = 0, r = arr.size()-1;
    int ans = -1;
    while(l < r){
        int mid = l + (r-l)/2;
        if(mid == arr.size()-1) return mid;
        if(arr[mid] > arr[mid+1]){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,4,3,2,1,0};
    cout << solve(arr) << endl;
    return 0;
}
