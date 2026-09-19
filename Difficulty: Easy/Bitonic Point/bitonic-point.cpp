class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int start=0,end=arr.size()-1,mid=0;
        int ans=arr[0];
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return arr[mid];
            }
            else if(arr[mid]<arr[mid+1]){
                ans=arr[mid];
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
        
    }
};