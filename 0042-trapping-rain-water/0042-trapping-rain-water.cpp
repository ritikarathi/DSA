class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int bottom =st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int left=st.top();
                int width =i-left-1;
                int wheight = min(height[left],height[i])-height[bottom];
                ans+= width*wheight;
            }
            st.push(i);
        }
        return ans;
    }
};