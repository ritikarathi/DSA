class Solution {
  public:
    bool isCheck(vector<int>&freq){
        int val=0;
        int idx=0;
        for(int i=0; i<26;i++){
            if(freq[i]!=0){
                val=freq[i];
                idx=i;
                break;
            }
        }
        for(int i=idx+1;i<26;i++){
            if(freq[i]!=0 && freq[i]!=val){
                return false;
            }
            if(freq[i]==0){
                continue;
            }
        }
        return true;
    }
    bool sameFreq(string& s) {
        // code here
        vector<int>freq(26,0);
        for(int i=0; i<s.size();i++){
            freq[s[i]-'a']++;
        }
        if(isCheck(freq)){
            return true;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            freq[i]--;
            if(isCheck(freq)){
                return true;
            }
            freq[i]++;
        }
        return false;
    }
};