// leetcode 2558

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // priority queue (heap) for easy access of max element
        priority_queue<int> heap(gifts.begin(), gifts.end());
        // repeating k times
        for (int i = 0; i < k; i++) {
            int maxele = heap.top();
            heap.pop();
            // re-adding floor of sqrt of prev max element
            heap.push(floor(sqrt(maxele)));
        }

        // final answer
        long long ans = 0;

        // summation
        while(heap.size() > 0) {
            ans+=heap.top();
            heap.pop();
        }
        return ans;
    }
};
