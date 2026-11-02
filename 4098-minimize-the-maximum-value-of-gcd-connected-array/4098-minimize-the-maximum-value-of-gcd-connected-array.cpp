class Solution {
public:
    int solve(int x){
        if(x%2==0){
            return 2;
        }
        for(int i=3;i*i<=x;i+=2){
            if(x%i==0){
                return i;
            }
        }
        return x;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1) return -1;
        int p=solve(value);
        int left=value-p;
        int leftidx=2*index;
        if(index>0 && left<leftidx) return -1;

        int right=n-index-1;
        if(right==0){
            return value;
        }
        return 2LL*(right-1)+value+p;
    }
};