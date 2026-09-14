class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int start=0,end=arr.size()-1,mid=0;
        int idx=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]>=x){
                idx=mid;
                end=mid-1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
            
        }
        return idx;
    }
};