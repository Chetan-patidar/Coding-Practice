/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
//univalue means root data and its child tree data value is same

pair<int,bool> Solve(BinaryTreeNode<int>* root,int previous){
    if(root->left==NULL && root->right==NULL)
        return {1,root->data==previous};
    pair<int,bool> left = {0,true};
    pair<int,bool> right = {0,true};
    if(root->left){
        left = Solve(root->left,root->data);
    }
    if(root->right){
        right = Solve(root->right,root->data);
    }
    int current = 0;
    if(left.second && right.second)
        current++;
    if(current==0){
        return {current+left.first+right.first,(root->data==previous&& left.second && right.second)};
    }
    return {current+left.first+right.first,(root->data==previous&& left.second && right.second)};
}


int countUnivalTrees(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
        return 0;
    pair<int,bool> answer = Solve(root,root->data);
    return answer.first;
}
