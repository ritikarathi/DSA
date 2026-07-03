class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>st;
        vector<int>prevS(nums.size(),1);
        vector<int>nextS(nums.size(),1);

        for(int i=0; i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                prevS[i]=i-st.top();
            }
            else{
                prevS[i]=i+1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nextS[i]=st.top()-i;
            }
            else{
                nextS[i]=nums.size()-i;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        vector<int>prevG(nums.size(),1);
        vector<int>nextG(nums.size(),1);

        for(int i=0; i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                prevG[i]=i-st.top();
            }
            else{
                prevG[i]=i+1;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nextG[i]=st.top()-i;
            }
            else{
                nextG[i]=nums.size()-i;
            }
            st.push(i);
        }

        long long maxi =0;
        long long mini =0;
        for(int i=0; i<nums.size();i++){
            maxi+=1ll*nextG[i]*prevG[i]*nums[i];
            mini+=1ll*nextS[i]*prevS[i]*nums[i];
        }
        return maxi-mini;
        
    }
};