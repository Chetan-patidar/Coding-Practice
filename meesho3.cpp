// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int Solve(int vertices,vector<int> from,vector<int> to,vector<int> weight,int k){
    //Write your code here
    vector<pair<int,int>> adj[vertices+1];
    int edges = from.size();
    for(int i=0;i<edges;i++){
        int x = from[i];
        int y = to[i];
        int w = weight[i];
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    vector<int> distance(vertices+1,INT_MAX);
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    distance[1] = 0;
    
    while(!q.empty()){
        int level = q.front().second.second;
        int max_cost = q.front().second.first;
        int node = q.front().first;
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            int neighbour = adj[node][i].first;
            int w = adj[node][i].second;
            if(level+1<=k && distance[neighbour] > max(w,max_cost)){
                distance[neighbour] = max(w,max_cost);
                q.push({neighbour,{distance[neighbour],level+1}});
            }
        }
    }

    int answer = INT_MIN;
    for(int i=1;i<=vertices;i++){
        if(distance[i]==INT_MAX)
            return -1;
        answer = max(answer,distance[i]);
    }
    return answer;
    
}


int main() {
    // Write C++ code here
    int vertices;
    int edges;
    
    cin>>vertices;
    cin>>edges;
    vector<int> from(edges);
    vector<int> to(edges);
    vector<int> weight(edges);
    for(int i=0;i<edges;i++){
        int x,y,w;
        cin>>x>>y>>w;
        from[i] = x;
        to[i] = y;
        weight[i] = w;
    }
    int k;
    cin>>k;
    
    int answer = Solve(vertices,from,to,weight,k);
    cout<<"Answer ->"<<answer<<"Program finish"<<endl;
    return 0;
}
