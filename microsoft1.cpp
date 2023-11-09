#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int Solve(vector<int> &arr,int n,int k){
    sort(arr.begin(),arr.end());
    
    
    int a = n/3;
    int left = a-1;
    int right = n-a;
    int left_count = 1;
    int right_count = 1;
    int left_index = left;
    int right_index = right;
    int left_value = arr[left];
    int right_value = arr[right];
    
    while(1){
        //check for left right_count
        while(left_index>0 && arr[left_index]==left_value)
            left_index--;
        
        //check for right count
        while(right_index>0 && arr[right_index]==right_value)
            right_index--;
            
        if(left-left_index < right-right_index){
            
        }
        else{
            
        }
        
    }
    
    
    return 0;
}

int main(){
    int n,k;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_bac(x);
    }
    cin>>k;
    
    int answer = Solve(arr,n,k);
    cout<<"Answer ->"<<answer<<"  ";
    return 0;
}
