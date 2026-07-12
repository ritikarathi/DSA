class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        vector<int>ans=temp;

        vector<long long>res(ans.size());
        vector<long long>elem(arr.size());
        long long sum=0;
        for(int i=0; i<ans.size();i++){
            sum+=ans[i];
            res[i]=sum;
        }
        sum=0;
        int count=0;
        for(int i=0; i<arr.size();i++){
            sum+=arr[i];
            elem[i]=sum;
            if(elem[i]==res[i]){
                count++;
            }
        }
        return count;
    }
};