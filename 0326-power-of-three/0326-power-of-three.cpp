class Solution {
public:
    bool isPowerOfThree(int n) {
        bool flag=false;
        for(long long i=1; i<=n; i=i*3){
            if(i==n) flag=true;
        }
        return flag;
    }
};