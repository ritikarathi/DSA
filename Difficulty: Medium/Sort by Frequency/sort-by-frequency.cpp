class Solution {
  public:
    string frequencySort(string &s) {
        // code here
        vector<int>freq(26,0);
        for(int i=0; i<s.size();i++){
            freq[s[i]-'a']++;
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            ans.push_back({freq[i],(i+'a')});
        }
        sort(ans.begin(),ans.end());
        string res="";
        for(int i=0; i<ans.size();i++){
            int n=ans[i].first;
            char ch =ans[i].second;
            while(n>0){
                res+=ch;
                n--;
            }
        }
        return res;
        
    }
};