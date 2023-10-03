#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            arr[i][j] = temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<arr[i][j]<<"   ";
        }
       // cout<<endl;
    }
    
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            cout<<arr[i][j]<<"   ";
        }
        cout<<endl;
    }
}
