#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> lps;

void constructLPSTable(string p){
    int i =0,j=1;
    lps[0] = 0;
    while(j < lps.size()){
        if(p[j] == p[i]){
            lps[j] = i+1;
            j++;i++;
        }else{
            if(i == 0) {
                lps[j] = 0;j++;
            }else{
                i = lps[j-1];
            } 
        }
    }
}

int main(){
    string t,p;
    cin>>t>>p;
    return 0;
}