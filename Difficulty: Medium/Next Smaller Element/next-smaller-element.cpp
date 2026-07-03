class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int>st;
        vector<int>ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=arr[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};