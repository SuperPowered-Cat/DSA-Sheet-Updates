class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum=0;
        for (int i = 1; i<=N; i++) {
            int x = N/i;
            sum = sum + (i*x);
        }
    return sum;
    }
};
