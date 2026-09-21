class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
            int idx=pq.top().second;
            arr[idx]=count;
            pq.pop();
            count++;
        }
    }
};