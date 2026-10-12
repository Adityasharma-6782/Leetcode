class Solution {
public:
    bool isPowerOfThree(int n) {
        bool flag=false;
        for(int i=0; pow(3,i)<=n; i++){
            if(pow(3,i)==n) flag=true;
        }
        return flag;
    }
};