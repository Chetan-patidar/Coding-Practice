class Solution {
  public:
    int countNode(Node* root){
        if(root==NULL)
            return 0;
            
        int left = countNode(root->left);
        int right = countNode(root->right);
        return left + right +1;
    }
    bool check_CBT(Node* root,int index ,int count){
        bool left = true;
        bool right = true;
        if(root->left==NULL && root->right){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left && root->right==NULL){
            if(2*index+1>=count)
                return false;
            left = check_CBT(root->left,2*index+1,count);
            return left;
        }
        else{
            if(2*index+1>=count || 2*index+2>=count)
                return false;
            left = check_CBT(root->left,2*index+1,count);
            right = check_CBT(root->right,2*index+2,count);
        }
        return left && right;
    }
    bool check_max(Node* root){
        if(root==NULL)
            return true;
        if(root->left && root->right==NULL){
            if(root->data < root->left->data)
                return false;
            return true;
        }
        else{
            if(root->data < root->left->data || root->data < root->right->data)
                return false;
        }
        return true;
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        //check two conditions 
        //first one is check CBT
        //second one check max properties follows or not
        int n = countNode(tree);
        bool cbt = check_CBT(tree,0,n);
        bool heap = check_max(tree);
        return cbt && heap;
        
    }
};
