class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int maxi=0;
        char ch;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>maxi){
                maxi=freq[i];
                ch=i+'a';
            }
        }
        return ch;
    }
};