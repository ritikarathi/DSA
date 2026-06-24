class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        vector<int>freq(26,0);
        for(int i=0; i<p.size();i++){
            freq[p[i]-'a']++;
        }
        int start=0,end=0;
        int minlen=INT_MAX,left=-1;
        int count=0;
        while(end<s.size()){
            if(freq[s[end]-'a']>0){
                count++;
            }
            freq[s[end]-'a']--;
            while(count==p.size()){
                if(end-start+1<minlen){
                    minlen =end-start+1;
                    left=start;
                }
                freq[s[start]-'a']++;
                if(freq[s[start]-'a']>0){
                    count--;
                }
                start++;
            }
            end++;
        }
        if(left==-1){
            return "";
        }
        return s.substr(left,minlen);
    }
};