class Solution {
  public:
    int findClosest(vector<int>& arr, int k) {
        // Code Here
        
        int mini=INT_MAX;
        int idx=0;
        for(int i=0; i<arr.size();i++){
            int ans=abs(arr[i]-k);
            if(ans<=mini){
                mini=ans;
                idx=i;
            }
        }
        return arr[idx];
    }
};