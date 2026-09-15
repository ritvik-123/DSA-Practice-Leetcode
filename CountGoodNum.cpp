class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long MOD = 1e9+7;
        long long oddpower = n/2;
        long long evenpower = (n+1)/2;
        long long a = power(4,oddpower, MOD);
        long long b = power(5,evenpower, MOD);
        return (a*b)%MOD;
    }
    long long power(long long n, long long exp, long long MOD)
    {
        if(exp == 0)
        {
            return 1;
        }
        long long half = power(n, exp/2, MOD);
        long long result = half * half % MOD;
        if(exp%2 == 1)
        {
            result = (result * n) % MOD;
        }
        return result;
    }
};