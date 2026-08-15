/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int solve(Node* root, int x){
        if(root==NULL){
            return -1;
        }
        if(root->data==x){
            return root->data;
        }
        if(x>root->data){
            return solve(root->right,x);
        }
        int ans =solve(root->left,x);
        if(ans!=-1){
            return ans;
        }
        return root->data;
    }
    int findCeil(Node* root, int x) {
        // code here
        return solve(root,x);
    }
};
