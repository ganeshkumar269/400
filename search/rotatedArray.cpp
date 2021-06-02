#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

/*
 https://youtu.be/GU7DpgHINWQ?t=1237
 Rotated Array:
    Given a sorted array but rotated in a random fashion, find the smallest element
    eg. 6789123 -> ans = 1
    (watch video for explanation)
    binary search but compare mid with last element
        
*/

int binary_search(int arr[10], int n){
    int l = 0, r = n-1;
    int ans = -1;
    while(l < r){
        int mid = l + (r-l)/2;
        if(arr[mid] <= arr[n-1]){
            ans = mid; 
            r = mid - 1;
        }
        else l = mid + 1; 
    }
    return ans;
}


int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,10);
    int t = dist(gen);
    cout << "T " << t << endl;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;
    for(int i = t; i < n; i++)
        swap(arr[i],arr[i-t]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';cout << endl;
    cout << "Ans: " << binary_search(arr,n) << endl;
    
    cout << t << endl;
}
