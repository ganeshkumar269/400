//https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

//Given  an equation ax+by=g where a,b,g are known and gcd(a,b) = g
// To find x and y values. , the algorithm find the gcd along a 'single' pair of values (x,y);
/*
    1. let a=g,b=0 (x,y) = (1,0) , |||ly (x,y) = (0,1)
    2. similar to Euclean theorem b*x1 + (a mod b)*y1 = g
    3. let a mod b = a - floor(a/b)*b
        -> b*x1 + a*y1 - floor(a/b)*b*y1 = g
        ->a*y1 + b*(x1-floor(a/b)*y1) = g 
        => x = y1 ; y = (x1 - floor(a/b)*y1)
    i.e following the recursive pattern of the euclidean theorem we get all the values of (x,y)
*/
#include <iostream>
#include <cmath>
using namespace std;

int extendedEuclideanAlgorithm(int a,int b,int& x,int& y){
    if(b == 0){
        x = 1;
        y=0;
        return a;
    } 
    int x1 = 0,y1=0;
    int d = extendedEuclideanAlgorithm(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*floor(a/b);
    return d;
}


int main(){
    int t1=0,t2=0,a=10,b=4;
    int g = extendedEuclideanAlgorithm(a,b,t1,t2);
    cout << "a:" << a << "*"<< "x:" << t1 << " + " << "b:" << b << "*"<< "y:" << t2 << " = " <<"gcd:" << g << endl;
}

