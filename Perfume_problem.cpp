//for design a bottle of perfume, bottle will pass from 3 process p1,p2,p3 in sequentially and for every process there is some machine to do a work.
//for p1 we have p machines and for p2 we have q machine and similarly for p3 we have r machines and each will take time to complete process is t1,t2,t3.
//give that hmow much minimum time required to make a n bottles.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int p,q,r,t1,t2,t3;
    cin>>p>>q>>r>>t1>>t2>>t3;
    int arr[n] = {0};
    queue<int> q1;
    for(int i=0;i<p;i++){
        q1.push(0);
    }
    
    //process 1 for every bottle
    for(int i=0;i<n;i++){
        int ti = q1.front();
        q1.pop();
        arr[i] = arr[i] + ti + t1;
        q1.push(arr[i]);
    }
    
    //process 2 for every bottle
    queue<int> q2;
    for(int i=0;i<q;i++){
        q2.push(0);
    }
    
    for(int i=0;i<n;i++){
        int p1 = q2.front();
        q2.pop();
        arr[i] = max(arr[i],p1) + t2;
        q2.push(arr[i]);
    }
    
    //proces 3 for every bottle
    queue<int> q3;
    for(int i=0;i<r;i++){
        q3.push(0);
    }
    
    for(int i=0;i<n;i++){
        int p1 = q3.front();
        q3.pop();
        arr[i] = max(arr[i],p1) + t3;
        q3.push(arr[i]);
    }
    
    cout<<"Answer = "<<arr[n-1]<<endl;
    
    
}
