#include<bits/stdc++.h>

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
class dt{
    public:
    Node* ptr;
    int row;
    dt(Node* ptr,int row){
        this->ptr = ptr;
        this->row = row;
    }
};
class compare{
    public:
    bool operator()(dt* a,dt* b){
        return a->ptr->data > b->ptr->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    //brute force approach using extra space
    // int n = listArray.size();
    // vector<int> arr;
    // for(int i=0;i<n;i++){
    //     Node* temp = listArray[i];
    //     while(temp!=NULL){
    //         arr.push_back(temp->data);
    //         temp = temp->next;
    //     }
    // }
    // sort(arr.begin(),arr.end());
    // Node* head = new Node();
    // Node* temp = head;
    // n = arr.size();
    // for(int i=0;i<n;i++){
    //     Node* tmp = new Node();
    //     tmp->data = arr[i];
    //     temp->next = tmp;
    //     temp = temp->next;
    // }
    // return head->next;
    priority_queue<dt*,vector<dt*>,compare> pq;
    int n = listArray.size();
    for(int i=0;i<n;i++){
        dt* temp = new dt(listArray[i],i);
        pq.push(temp);
    }

    Node* head = new Node();
    Node* temp = head;
    while(pq.size()>0){
        dt* top = pq.top();
        pq.pop();
        Node* ptr = top->ptr;
        int row = top->row;
        temp->next = ptr;
        temp = ptr;
        if(ptr->next!=NULL){
            dt* tmp = new dt(ptr->next,row);
            pq.push(tmp);
        }
    }
    return head->next;

}
