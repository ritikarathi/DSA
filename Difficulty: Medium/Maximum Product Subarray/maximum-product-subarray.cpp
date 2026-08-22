class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int maxProd=arr[0];
        int minProd=arr[0];
        int ans=arr[0];
        
        for(int i=1;i<arr.size();i++){
            int maxi =max({arr[i],maxProd*arr[i],minProd*arr[i]});
            int mini =min({arr[i],maxProd*arr[i],minProd*arr[i]});
            
            maxProd=maxi;
            minProd=mini;
            ans=max(ans,maxProd);
        }
        return ans;
    }
};