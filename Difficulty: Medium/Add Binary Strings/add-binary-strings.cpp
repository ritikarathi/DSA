class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // code here
        int first=s1.size()-1,second=s2.size()-1;
        
        int carry=0;
        string ans="";
        while(first>=0 || second>=0 ||carry){
            int sum=carry;
            if(first>=0){
                sum+=s1[first]-'0';
            }
            if(second>=0){
                sum+=s2[second]-'0';
            }
            ans.push_back((sum%2)+'0');
            carry=sum/2;
            first--;
            second--;
        }
        reverse(ans.begin(),ans.end());
        int k=0;
        while(k<ans.size() && ans[k]=='0'){
            k++;
        }
        
        return ans.substr(k);
        
    }
};