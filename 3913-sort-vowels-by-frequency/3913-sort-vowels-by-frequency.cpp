class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int>freq;
        vector<char>vowels;
        unordered_map<char,int>idx;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                freq[s[i]]++;
                if(idx.find(s[i])==idx.end()){
                    idx[s[i]]=i;
                }
            }
        }
        for(auto it =freq.begin();it!=freq.end();it++){
            vowels.push_back(it->first);
        }

        sort(vowels.begin(),vowels.end(),[&](char a , char b){
            if(freq[a]!=freq[b]){
                return freq[a]>freq[b];
            }
            return idx[a]<idx[b];
        });

        vector<char>ans;
        for(int i=0; i<vowels.size();i++){
            int count = freq[vowels[i]];
            while(count--){
                ans.push_back(vowels[i]);
            }
        }
        int j=0; 
        string st="";
        for(int i=0; i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                st.push_back(ans[j]);
                j++;
            }
            else{
                st.push_back(s[i]);
            }
        }
        return st;
    }
};