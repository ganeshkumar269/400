#include <iostream>
#include <vector>
using namespace std;
/*
    https://www.geeksforgeeks.org/union-find/
    1.Create a parent array size = n , no.of vertices
    2.initialise parent[i] = i
    3.For every edge e:
        p1 = find_parent(e.src)   // find
        p2 = find_parent(e.dest)
        if(p1 == p2) cycle found
        else Union(e.src,e.dest) // union

    find_parent(x):
        if(parent[x] == -1) return x
        return find_parent(parent[x])
    Union(x,y):
        x,y = find_parent(x) , find_parent(y)
        if(x != y ) parent[x] = y
    Worst Case Scenario find_parent takes O(n) 
        eg. for find_parent(4) in 0 - 1 - 2 -3 -4
*/


int main(){
    
    return 0;
}