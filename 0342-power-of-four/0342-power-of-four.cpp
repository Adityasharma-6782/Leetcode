class Solution {
public:
    bool isPowerOfFour(int n) {
        bool flag=false;
        for(long long i=1; i<=n; i=i*4){
            if(i==n) flag=true;
        }
        return flag;
    }
};