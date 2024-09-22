// leetcode 

//**Q: K-th Smallest in Lexicographical Order**

// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

// Example 1:
// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number 
// is 10.

// Example 2:
// Input: n = 1, k = 1
// Output: 1

// Constraints:
// 1 <= k <= n <= 109


// BRUTEFORCE APPROACH

// class Solution {
// public:
//     long long findKthNumber(long long n, long long k) {
//         vector <string> nums;
//         for (long long i = 1; i <= n; i++) {
//             string temp = to_string(i);
//             nums.push_back(temp);
//         }
//         sort (nums.begin(), nums.end());
//         long long x = stoi(nums[k-1]);
//         return x;
//     }
// };


// BETTER APPROACH

// class Solution {
// public:
//     long long findKthNumber(long long n, long long k) {
//     vector<long long> ans;
//     long long curr = 1;
//     for (long long i = 0; i < n; i++) {
//         ans.push_back(curr);
//         if (curr*10 <= n) curr = curr*10;
//         else {
//             if (curr >= n) curr = curr/10;
//             curr++;
//             while (curr % 10 == 0) curr = curr/10;
//             } 
//         }
//         long long x = ans[k-1];
//         return x;
//     }
// };


// OPTIMAL

class Solution {
public:
    long long findKthNumber(long long n, long long k) {
        long long curr = 1;
        k--;
        while (k>0) {
            long long dist = getDistance(curr, curr+1, n);
            if (k<dist) {
                curr*=10;
                k--;
            }
            else {
                curr++;
                k-=dist;
            }
        }
        return curr;
    }

    long long getDistance(long long left, long long right, long long n) {
        long long dist = 0;
        while (left <= n) {
            long long count = min(right, n+1) - left;
            dist+=count;
            left*=10;
            right*=10;
        }
        return dist;
    }
};
