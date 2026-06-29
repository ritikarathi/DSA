class Solution {
public:
    string decode(string &s, int &i){
        string result="";
        int num=0;
        while(i<s.size()){
            char ch =s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
                i++;
            }
            else if(ch=='['){
                i++;
                string inner =decode(s,i);
                for(int k=0; k<num;k++){
                    result+=inner;
                }
                num=0;
            }
            else if(ch==']'){
                i++;
                return result;
            }
            else{
                result+=ch;
                i++;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};