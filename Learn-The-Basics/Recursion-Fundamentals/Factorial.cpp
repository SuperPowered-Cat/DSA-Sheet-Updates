
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        long long fact = 1;
        int curr = 1;
        vector <long long> factorials;
        
        while (fact<=n) {
            factorials.push_back(fact);
            curr++;
            fact=fact*curr;
        }
        return factorials;
    }
};
