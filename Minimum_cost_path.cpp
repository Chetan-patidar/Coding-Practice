#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int Solve(int arr[1000][1000],int n,int m){
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(m+1,{INT_MIN,INT_MAX}));
    for(int i=1;i<=n;i++){
        dp[i][m] = {arr[i][m],arr[i][m]};
    }
    
    for(int j=m-1;j>=1;j--){
        for(int i=1;i<=n;i++){
            pair<int,int> temp;
            int diff = INT_MAX;
            int p = arr[i][j];
            for(int k=1;k<=n;k++){
                int mini = dp[k][j+1].first;
                int maxi = dp[k][j+1].second;
                if(mini<=p && maxi>=p){
                    if(diff>(maxi-mini)){
                        temp.first = mini;
                        temp.second = maxi;
                        diff = maxi-mini;
                    }
                }
                else if(mini<p){
                    if(diff>(p-mini)){
                        temp.first = mini;
                        temp.second = p;
                        diff = p-mini;
                    }
                }
                else{
                    if(diff>(maxi-p)){
                        temp.first = p;
                        temp.second = maxi;
                        diff = maxi-p;
                    }
                }
            }
            dp[i][j] = temp;
        }
    }
    
    int diff = INT_MAX;
    pair<int,int> answer;
    for(int i=1;i<=n;i++){
        if(diff>(dp[i][1].second - dp[i][1].first)){
            diff = dp[i][1].second - dp[i][1].first;
            answer = dp[i][1];
        }
    }
    return answer.second - answer.first;
}


int main(){
    int n,m;
    int arr[1000][1000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    
    int answer = Solve(arr,n,m);
    cout<<answer<<endl;
    return 0;
}
