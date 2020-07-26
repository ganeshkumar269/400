#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://www.youtube.com/watch?v=GTJr8OvyEVQ
vector<int> lps;

void constructLPSTable(string p){
    int i =1, j = 0;
    while(i < p.size()){
        if(p[i] == p[j]){
            lps[i] = j+1;i++;j++;
        }else{ // The Tricky Part
            if(j == 0) i++;
            else j = lps[j-1];
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    string t,p;
    cin>>t>>p;
    cout << t  <<" " << p<< endl;
    lps.resize(p.size());
    constructLPSTable(p);
    for(int i : lps)    cout << i << " ";
    
    for(int i =0,j=0 ; i < t.size();){
        if(t[i] == p[j]){
            i++;j++;
        }else{
            if(j == 0) i++;
            else j = lps[j-1];
        }
        cout << j << " ";
        if(j == p.size()){
            cout << "found at " << i - p.size() << endl; j = 0;
        }
    }


    return 0;
}