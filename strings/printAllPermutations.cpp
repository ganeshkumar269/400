#include<iostream>
#include <string>
using namespace std;
void printAllP(string& s,int l,string& temp){
    if(l == s.size())
        cout << temp << endl;
    else
        for(int i = l; i < s.size();i++){
            temp[l] = s[i];
            printAllP(s,l+1,temp);
            
        }

}
int main(){
    freopen("in.txt","r",stdin);
    string s,t;
    cin>>s;
    t.resize(s.size());
    printAllP(s,0,t);
}