#include<bits/stdc++.h>

class Node{
    public:
    int data;
    int row;
    int column;
    Node(int data,int row,int column){
        this->data = data;
        this->row = row;
        this->column = column;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<Node*,vector<Node*>,compare> pq;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<k;i++){
        Node* temp = new Node(a[i][0],i,0);
        maxi = max(maxi,a[i][0]);
        pq.push(temp);
    }
    int answer = INT_MAX;

    while(!pq.empty()){
        Node* temp = pq.top();
        pq.pop();
        int data = temp->data;
        int row = temp->row;
        int column = temp->column;
        mini = data;
        if(maxi-mini < answer){
            answer = maxi-mini+1;
        }

        if(column+1>=n)
            return answer;
        if(column+1<n){
            Node* tmp = new Node(a[row][column+1],row,column+1);
            pq.push(tmp);
            maxi = max(a[row][column+1],maxi);
        }
    }
    return answer;
}
