#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int>& arr,int x,int start,int end){
    if(start==end){
        if(arr[start]==x){
            return start;
        }
        else{
            return -1;
        }
    }
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        return Binary_Search(arr,x,start,mid-1);
    }
    else{
        return Binary_Search(arr,x,mid+1,end);
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    
    int answer = Binary_Search(arr,x,0,n-1);
    cout<<answer<<endl;
    return 0;
}
