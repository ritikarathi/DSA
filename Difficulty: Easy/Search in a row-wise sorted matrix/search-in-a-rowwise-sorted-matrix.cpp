

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i=0; i<mat.size();i++){
            vector<int>ans=mat[i];
            int start=0,end=ans.size(),mid=0;
            while(start<=end){
                mid=start+(end-start)/2;
                if(ans[mid]==x){
                    return true;
                }
                else if(ans[mid]<x){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};