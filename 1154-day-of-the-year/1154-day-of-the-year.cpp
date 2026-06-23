class Solution {
public:
    int dayOfYear(string date) {
        vector<int>d={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int x =stoi(date.substr(0,4));
        if(x%400==0 || (x%4==0 && x%100 !=0)){
            d[2]++;
        }
        int m =stoi(date.substr(5,2));
        int day =stoi(date.substr(8,2));

        int sum=0;
        for(int i=1; i<m;i++){
            sum+=d[i];
        }
        return sum+day;
    }
};