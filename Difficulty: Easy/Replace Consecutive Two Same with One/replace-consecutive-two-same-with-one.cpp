class Solution {
  public:
    string removeDuplicates(string& s) {
        // code here.
        string st ="";
        st.push_back(s[0]);
        for(int i=1; i<s.size();i++){
            if(st.back()!=s[i]){
                st.push_back(s[i]);
            }
        }
        return st;
    }
};