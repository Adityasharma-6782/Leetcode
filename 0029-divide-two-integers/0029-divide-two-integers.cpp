class Solution {
public:
    int divide(int dividend, int divisor) {

    if (dividend == 0)
        return 0;

    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);

    long long ans = 0;

    for (int i = 31; i >= 0; i--) {

        if ((b << i) <= a) {
            a -= (b << i);
            ans += (1LL << i);
        }
    }

    // Sign
    if ((dividend < 0) != (divisor < 0))
        ans = -ans;

     // Overflow
    if (ans > INT_MAX)
        return INT_MAX;

    if (ans < INT_MIN)
        return INT_MIN;

    return ans;
}
};