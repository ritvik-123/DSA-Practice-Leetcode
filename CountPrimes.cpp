class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        int count = 1; // prime 2

        // Only process odd numbers
        for (int i = 3; i < n; i += 2)
        {
            if (isPrime[i])
            {
                count++;

                // Only start marking when i*i is inside range
                if (1LL * i * i < n)
                {
                    // multiples i*(i+1), etc. that are even
                    // don't matter, so jump by 2*i
                    for (long long j = 1LL * i * i; j < n; j += 2LL * i)
                    {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return count;
    }
};