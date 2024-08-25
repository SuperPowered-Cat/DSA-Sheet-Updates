int longestSubarrayWithSumK(vector<int> a, long long k) {
    int l = 0, r = 0;
    long long sum = 0;
    int len = 0;
    int n = a.size(); 
    while (r<n) {
        sum+=a[r];
        
        while (sum > k && l <= n) {
            sum-=a[l];
            l++;
        }

        if (sum == k) len = max(len, r - l + 1);

        r++;
    }

    return len;

}
