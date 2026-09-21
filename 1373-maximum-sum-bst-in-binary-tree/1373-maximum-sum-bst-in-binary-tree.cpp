/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    int maxsum=0;
    vector<int> solve(TreeNode* root){
        if(!root){
            return {0,0,INT_MAX,INT_MIN};
        }

        vector<int>lt =solve(root->left);
        vector<int>rt =solve(root->right);
        if(lt[0]==-1 || rt[0]==-1){
            return {-1,0,0,0};
        }

        if(root->val<=lt[3] ){
            return {-1,0,0,0};
        }
        if(root->val>=rt[2]){
            return {-1,0,0,0};
        }
        int size =lt[0]+ rt[0]+ 1;
        sum= lt[1]+ rt[1]+ root->val;

        maxsum= max(sum,maxsum);

        int l =min(root->val,lt[2]);
        int r =max(root->val,rt[3]);

        return {size,sum,l,r};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};