/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* root, int k, vector<int>& ans){
        if(root==NULL){
            return ;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        find(root->left,k-1,ans);
        find(root->right,k-1,ans);
    }
    void solve(TreeNode* root, TreeNode* target, int k,vector<int>&ans, int &count, bool &flag){
        if(root==NULL){
            return;
        }
        if(root==target){
            flag=1;
            count=0;
           find(root,k,ans);
            return ;
        }
        solve(root->left,target,k,ans,count,flag);
        if(flag){
            count++;
            if(count==k){
                ans.push_back(root->val);
            }
            find(root->right,k-count-1,ans);
            return;
        }
        solve(root->right,target,k,ans,count,flag);
        if(flag){
            count++;
            if(count==k){
                ans.push_back(root->val);
            }
            find(root->left,k-count-1,ans);
            return;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        bool flag=0;
        int count=0;
        solve(root,target,k,ans,count,flag);
        return ans;
    }
};