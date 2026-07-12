class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>idx(arr.size());
        vector<int>elem(arr.size());
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            elem[i]=sum;
        }
        sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=i;
            idx[i]=sum;
        }
        int count=0; 
        for(int i=0;i<arr.size();i++){
            if(idx[i]==elem[i]){
                count++;
            }
        }
        return count;
    }
};