//https://cp-algorithms.com/algebra/linear-diophantine-equation.html
/*
    Given an equation ax + by = c where a,b,c are known values find all the possible values of (x,y)
    Equation can be modified to a*(x*g/c) + b*(y*g/c) = g -> ax1 + by1 = g
    Using Extended Euclidean Theorem we find x1,y1;
        x = x1*c/g , y = y1*c/g
    Property to note
        a*(x + k*b/g) + b*(y - k*a/g) = c
        for different values of k we get diffent set of x,y i.e there are infinitley different values 

*/

#include <iostream>
using namespace std;
int main(){
    
}