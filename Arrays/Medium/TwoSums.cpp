class Solution {
public:

    // if yes/no return (no need to return a vector array)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     int l = 0;
    //     int r = nums.size()-1;
    //     int sum = 0;
    //     vector <int> index;
    //     while (l < r) {
    //         sum = nums[l] + nums[r];
    //         if (sum == target) {
    //             index.push_back(l);
    //             index.push_back(r);
    //             return index;
    //         }
    //         else if (sum < target) l++;
    //         else r--;
    //     }
    //     return index;
        
    // }
    vector<int> twoSum(vector<int>& nums, int target) { 
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (index.find(rem) != index.end()) return {index[rem], i};
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};

