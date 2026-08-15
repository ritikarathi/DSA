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
    void bst(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        bst(root->left,arr);
        arr.push_back(root->val);
        bst(root->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>arr;
        bst(root,arr);
        vector<vector<int>>res;
        for(int i=0; i<queries.size();i++){
            int ceil;
            int floor;
            int x=queries[i];
            auto it =lower_bound(arr.begin(),arr.end(),x);
            if(it!=arr.end()){
                ceil=*it;
            }
            else{
                ceil=-1;
            }
            if(it!=arr.end() && *it==x){
                floor=x;
            }
            else if(it!=arr.begin()){
                it--;
                floor=*it;
            }
            else{
                floor=-1;
            }
            res.push_back({floor,ceil});
        }
        return res;
    }
};