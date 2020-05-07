#include <iostream>
#include <vector>
using namespace std;

#define Any_of ano
#define All_of alo
#define All_of_Any_of aloano

template <typename T>
bool Any_of(T f,vector<T> s){
    for(T i : s)
        if(i == f) return true;
    return false;
}
template <typename T>
bool Any_of(vector<T> f,vector<T> s){
    for(T i : f)
        if(Any_of(i,s)) return true; 
    return false;
}
template <typename T>
bool All_of(vector<T> f,T s){
    for(T i : f)
        if(i != s) return false;
    return true;
}
template <typename T>
bool All_of_Any_of(vector<T> f, vector<T> s){
    for(T i : f)
        if(!Any_of<T>(i,s)) return false;
    return true;
}