// leetcode 2593

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> hp;
        vector<bool> bl(nums.size(), false);
        long long score = 0;

        for (int i = 0; i < nums.size(); i++) hp.push({ nums[i], i});

        while (!hp.empty()) {
            auto [x, i] = hp.top();
            hp.pop();

            if (bl[i]) continue;

            score+=x;
            bl[i] = true;
            if (i>0) bl[i-1] = true;
            if (i<nums.size()-1) bl[i+1] = true;
        }
        return score;



    }
};
