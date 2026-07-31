class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int start=0,end=0;
        vector<int>freq(256,0);
        int ans=0;
        while(end<s.size()){
            freq[s[end]-'a']++;
            while(freq[s[end]-'a']>1){
                freq[s[start]-'a']--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
