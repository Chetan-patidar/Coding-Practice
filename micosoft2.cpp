#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(vector<pair<char,int>> &arr){
    int n = arr.size();
   // bool c = false;
    vector<int> visited(26,0);
    for(int i=0;i<n;i++){
        if(visited[arr[i].first-'a']==1)
            return false;
        visited[arr[i].first-'a']++;
        if(arr[i].second==1){
            for(int i=0;i<26;i++){
                visited[i]=0;
            }
        }
    }
    return true;
}
int Solve(string s,vector<int> &c,int k){
    
    int n = s.length();
    vector<pair<char,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({s[i],0});
    }
    int answer = 0;
    int start = 0;
    while(start<k){
        if(check(arr))
            return answer;
        int position = c[start++];
        answer++;
        arr[position-1].second = 1;
    }
    
    if(check(arr))
        return answer;
    
    
    return -1;
}

int main()
{
    
    string s;
    vector<int> c;
    int k;
    cin>>s;
    cin>>k;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        c.push_back(x);
    }
    
    int answer = Solve(s,c,k);
    cout<<"Answer -> "<<answer<<"  Program Finish";

    return 0;
}
