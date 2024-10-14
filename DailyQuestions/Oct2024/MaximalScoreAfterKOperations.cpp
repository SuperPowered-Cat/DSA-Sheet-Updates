// leetcode 2530

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 0;
        priority_queue<int> maxHeap; // Heaps always for "Kth maxinmum/min element"
        for (int x : nums) maxHeap.push(x);
        for (int i = 0; i < k; i++) {
            long long temp = maxHeap.top();
            maxHeap.pop();
            score+=temp;
            maxHeap.push(ceil(temp/3.0)); // if we do divide by integer then wrong ans!
        }
        return score;
    }
};
