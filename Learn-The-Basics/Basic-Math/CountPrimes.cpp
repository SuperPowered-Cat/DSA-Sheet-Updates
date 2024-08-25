class Solution {
public:
    int countPrimes(int n) {

        // If n is less than or equal to 2, there are no primes less than n
        if (n <= 2) return 0;

        // Create a boolean vector 'prime' initialized to true, indicating that all numbers are prime initially
        vector<bool> prime(n, true);

        // 0 and 1 are not prime numbers, so mark them as false
        prime[0] = prime[1] = false;

        // Start checking for prime numbers from 2 onwards
        for (int i = 2; i * i < n; i++) {
            // If 'i' is prime, mark all multiples of 'i' as non-prime
            if (prime[i]) {
                // Start marking from i*i as all smaller multiples would have been marked by smaller primes
                for (int j = i * i; j < n; j += i) 
                    prime[j] = false;
            }
        }

        // Count the number of primes less than n
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == true) 
                count++;
        }

        // Return the total count of prime numbers less than n
        return count;
    }
};
