class Solution {
public:
    int bitwiseComplement(int n) {
        int x=n;
        int i=1,k=0;
        if(n==0){
            return 1;
        }
        while(x!=0){
            x = x >> 1;
            k=(k<<1) | 1;
            i++;
        }
        int ans = n^k;
        return ans ;
        
    }
};
