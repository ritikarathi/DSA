/* Tree Node Structure 
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int solve(Node *root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left= 1+solve(root->left,ans);
        int right=1+ solve(root->right,ans);
        
        int maxi =max(left,right);
        ans=max(maxi,ans);
        return maxi;
    }
    int maxDepth(Node *root) {
        // code here
        int ans=0;
        int maxi=0;
        solve(root,ans);
        return ans;
    }
};
