class Solution{
    public:
    
    // TIME LIMIT FOR EXCEED FOR THIS - BRUTEFORCE W TWO LOOPS.
    // int lenOfLongSubarr(int A[],  int N, int K) 
    // { 
        
    //     int l = 0;
    //     for (int i = 0; i < N; i++) {
    //         long sum = 0;
    //         for (int j = i; j < N; j++) {
    //             sum+=A[j];
    //             if (sum == K) l = max(l, (j - i +1));
    //         }
            
    //     }
    //     return l;
        
    // } 
    
    
    // optimum will use SLIDING WINDOW!!! {ONLY WORKS FOR POSITIVES :(( }))
    // int lenOfLongSubarr(int A[],  int N, int K) 
    // {
    //     int l = 0;
    //     int r = 0;
    //     int sum = 0;
    //     int length = 0;
        
    //     // iterate till right is less than N
    //     while (r < N) {
    //         sum+=A[r];
    //         while (sum>K && l<=r) {
    //             sum = sum - A[l];
    //             l++;
    //         }
            
    //         if (sum == K) length = max(length, r - l + 1);
    //         r++;
    //     }
    //     return length;
    // }
    
    
    // true optimum (using HASHING)
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        map<long long, int> sumMap;
        int sum = 0;
        int maxlen = 0;
        for (int i = 0; i < N; i++ ) {
            sum+=A[i];
            
            if (sum == K) maxlen = max(maxlen, i+1);
            
            long long rem = sum - K;
            if (sumMap.find(rem) != sumMap.end()) {
                int len = i - sumMap[rem];
                maxlen = max(maxlen, len);
            }
            
            // if sum already exists then hashmap should not upddate it
            // sumMap[sum] = i;
            
            if (sumMap.find(sum) == sumMap.end()) sumMap[sum] = i;
        }
        
        return maxlen;
    }

};
