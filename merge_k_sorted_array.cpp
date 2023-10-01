//brute force time complexity is O(n*klog(n*k))

//optimized algorithm time complexity is O(n*klogk)


#include <bits/stdc++.h> 
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
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    //brute force approach 
    // vector<int> answer;
    // for(int i=0;i<k;i++){
    //     int s = kArrays[i].size();
    //     for(int j=0;j<s;j++){
    //         answer.push_back(kArrays[i][j]);
    //     }
    // }
    // sort(answer.begin(),answer.end());
    // return answer;


    //Optimized approach using heap

    //step1 make k size min heap and store first element of every array
    priority_queue<Node*,vector<Node*>,compare > pq;
    for(int i=0;i<k;i++){
        Node* temp = new Node(kArrays[i][0],i,0);
        pq.push(temp);
    }
    vector<int> answer;
    //step2 one by one delete and insert data in our min heap
    while(pq.size()>0){
        Node* top = pq.top();
        pq.pop();
        int row = top->row;
        int column = top->column;
        int data = top->data;
        answer.push_back(data);

        if(column+1 < kArrays[row].size()){
            Node* temp = new Node(kArrays[row][column+1],row,column+1);
            pq.push(temp);
        }
    }
    return answer;
}
