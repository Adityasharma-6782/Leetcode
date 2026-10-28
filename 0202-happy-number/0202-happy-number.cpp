class Solution {
public:
    int sqrSum(int n){
        int sum = 0;
        while(n>0){
            int r = n%10;
            sum += (r*r);
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast!=1){
            slow = sqrSum(slow);
            fast = sqrSum(fast);
            fast = sqrSum(fast);
            if(slow==fast && slow!=1) return false;
        }
        return true;
    }
};