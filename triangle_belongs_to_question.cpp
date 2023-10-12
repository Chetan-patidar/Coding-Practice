/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const float eps = 0.00001f;
struct point {
	int x, y;
};

float area(point a, point b, point c) {
	return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y))/2.0); 
}


bool isInside(point a, point b, point c, point p) {
	float a1 = area(a, b, p);
	float a2 = area(a, c, p);
	float a3 = area(b, c, p);
	float big = area(a, b, c);

	return (fabs(big - (a1 + a2 + a3)) < eps);
}


float distance(point a,point b){
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}



int main()
{
    //cout<<"Hello World";
    
    
    
    point a, b, c, p,q;
	cout << "Enter all the co-ordinates of triangle : ";
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> p.x >> p.y >> q.x >> q.y;
    
    
    
    
    // a.x = x1;
    // a.y = y1;
    
    // b.x = x2;
    // b.y = y2;
    
    // c.x = x3;
    // c.y = y3;
    
    // p.x = xp;
    // p.y = yp;
    
    
    // q.x = xq;
    // q.y = yq;
    
    bool first = true;
    if(distance(a,b) < distance(b,c)+distance(a,c) && distance(a,c) < distance(a,b)+distance(b,c) && distance(b,c) < distance(a,c)+distance(a,b) ){
        first = false;
    }
    cout<<first<<endl;
    if(first)
        return 0;
        
    
    bool check_p = isInside(a,b,c,p);
    bool check_q = isInside(a,b,c,q);
    cout<<endl<<check_p<<"   "<<check_q;  
    
    if(check_p==true && check_q==false)
        return 1;
        
    if(check_p==false && check_q==true)
        return 2;
        
    if(check_p==true && check_q==true)
        return 3;
    
    
    

    return 0;
}
