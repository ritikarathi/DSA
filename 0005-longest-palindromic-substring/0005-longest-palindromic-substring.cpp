class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=1, maxlen2=1;
        int start=0, start2=0;
        for(int i=0; i<s.size();i++){
           if(i>0){
            int low= i-1, high =i+1; 
            
            while(low>=0 && high<s.size() && s[low]==s[high]){
                low--;
                high++;
            }
            if(high-low-1>maxlen){
                maxlen = high-low-1;
                start=low+1;
            }
           }
        }

        for(int i=0; i<s.size(); i++){
            if(i + 1 < s.size() && s[i]==s[i+1] ){
                int high =i+1;
                int low=i;
               while(low>=0 && high<s.size() && s[low]==s[high] ){
                low--;
                high++;
                }
                if(high-low-1 >maxlen2){
                maxlen2 = high-low-1;
                start2=low+1;
                }
            }
            
        }
        int mainlen =0, mainstart=0;
        if(maxlen>maxlen2){
            mainlen =maxlen;
            mainstart=start;
        }
        else{
            mainlen=maxlen2;
            mainstart=start2;
        }
        return s.substr(mainstart, mainlen);
        

    }

    
};