class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        
        int i=0;
        while(i<arr.size()){
            if(ans.empty() || ans.back()[1]<arr[i][0]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] =max(ans.back()[1], arr[i][1]);
            }
            i++;
            
        }
        return ans;
        
    }
};