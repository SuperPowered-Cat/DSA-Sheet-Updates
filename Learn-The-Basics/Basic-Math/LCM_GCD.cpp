class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector <long long> ans(2);
        int a = A;
        int b = B;
        while (a!=0 && b != 0) {
            if (a>b) a = a%b;
            else b = b%a;
        }
        if (a == 0) ans[1] = b;
        else ans[1] = a;
        ans[0] = (A*B)/ans[1];
        return ans;
    }
    
};
