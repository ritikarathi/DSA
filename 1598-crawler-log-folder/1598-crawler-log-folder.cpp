class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;
        for(int i=0; i<logs.size();i++){
            if(!st.empty() && logs[i]=="../"){
                st.pop();
            }
            else if(logs[i]=="./" || logs[i]=="../"){
                continue;
            }
            else{
                st.push(1);
            }
        }
        return st.size();
    }
};