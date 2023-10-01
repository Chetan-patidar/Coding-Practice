/*
Given a Binary Search Tree. 
Convert a given BST into a Special Max Heap with 
the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
This condition is applied on all the nodes in the so converted Max Heap.
*/
        



void inorder(Node* root,vector<int> &arr){
        if(root==NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
        return;
    }
    void Solve(Node* root,int &index,vector<int>& arr){
        if(root==NULL)
            return;
        if(root->left){
            Solve(root->left,index,arr);
            index = index+1;
        }
        if(root->right){
            Solve(root->right,index,arr);
            index = index +1;
        }
        root->data = arr[index];
        return;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> arr;
        inorder(root,arr);
        int index = 0;
        Solve(root,index,arr);
        return;
    }    
