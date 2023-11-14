/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int scan(vector<int> arr,int n,int x){
    int answer = 1;
    int len = n;
    vector<int> visited(n,0);
    int count = 1;
    cout<<"test ";
    int index = 0;
    while(len!=1){
        if(visited[index]==0){
            if(count==x){
                visited[index] = 1;
                cout<<arr[index]<<"  ";
                count = 1;
                len--;
            }
            else{
                count++;
            }
            if(index+1==n)
                answer++;
            index = (index+1)%n;
        }
        else{
            if(index+1==n)
                answer++;
            count++;
            index = (index+1)%n;
            
        }
    }
    
    
    return answer;
}

int main()
{
    //cout<<"Hello World";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int answer = scan(arr,n,x);
    cout<<"Answer -> "<<answer<<endl;

    return 0;
}
