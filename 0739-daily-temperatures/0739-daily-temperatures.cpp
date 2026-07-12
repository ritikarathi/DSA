class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(),-1);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int>res(ans.size());
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){
                res[i]=0;
                continue;
            }
            res[i]=ans[i]-i;
        }
        return res;

    }
};