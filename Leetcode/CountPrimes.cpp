// Leetcode #204 Counting primes
// This is a solution based on the sieve of erastothenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, false);
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(primes.at(i) == false)
            {
                count++;
                int current = i;
                int multiplier = 1;
                while(current < n)
                {
                    primes.at(current) = true;
                    current = i * multiplier;
                    multiplier++;
                }
            }
        }
        return count;
    }
};
