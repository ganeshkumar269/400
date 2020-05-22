#include <iostream>
#include <vector>
using namespace std;
/*
    https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
    Used to Find a cycle in a graph
    Draw back of Union FInd 1 is find_parent may take O(n) in worst case
    In this method 2 optimisations are be used
    Each node is associate diwht a parent and a rank value
    1. struct subset = {parent , rank} 
    2. create a subset array of size n, no. of veritces
    3.initialise subset[i].parent = i .rank = 0;
    4. for every edge e:
        p1 = find_parent(e.src)
        p2 = find_parent(e.dest)
        if(p1 == p2) cycle was found
        else Union(p1,p2)
    
    find_parent(x):
        if(subset[x].parent == -1) return x
        return subset[subset[x].parent]

    Union(x,y):
        x,y = find_parent(x),find_parent(y)
        if(subset[x].rank < subset[y].rank)
            subset[x].parent = y
        else if(subset[x].rank > subset[y].rank)
            subset[y].parent = x
        else 
            subset[y].parent = x
            subset[x].rank ++
*/

int main(){
    return 0;
}