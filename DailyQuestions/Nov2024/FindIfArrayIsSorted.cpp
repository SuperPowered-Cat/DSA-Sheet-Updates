// single pass with segment check - most optimised with popcount() fnc
class Solution {
public:

    int bitscount(int a) {
        // return bitset<32>(a).count();
        return __builtin_popcount(a);
    }

    bool canSortArray(vector<int>& nums) {
        int lastmax = INT_MIN;
        int minval = nums[0];
        int maxval = nums[0];
        int count = bitscount(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int newcount = bitscount(nums[i]);
            
            if (newcount == count) {
                minval = min(minval, nums[i]);
                maxval = max(maxval, nums[i]);
            }

            else {
                if (lastmax > minval) return false;
                
                count = bitscount(nums[i]);
                lastmax = maxval;
                maxval = nums[i];
                minval = nums[i];
            }
        }
        return lastmax < minval;
    }
};


// builtin_popcount() function - works with bubble sort
// class Solution {
// public:

//     bool bitcount(int a, int b) {

//         // useful for returning no of 1 bits, builtin library of GCG
//         return __builtin_popcount(a) == __builtin_popcount(b);
//     }

//     bool canSortArray(vector<int>& nums) {
//         vector<int> newarr;
//         for (int x : nums) newarr.push_back(x);
//         sort(nums.begin(), nums.end());

//         if (nums == newarr) return true;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 0; j< nums.size() - i - 1; j++) {
//                 if (newarr[j] > newarr[j+1]) {
//                     if (bitcount(newarr[j], newarr[j+1])) swap(newarr[j], newarr[j+1]);
//                 }
//             }
//         }
//         for (auto x : newarr) cout << x << " ";
//         return (nums == newarr);
//     }
// };

// bitset with bubble sort - leads to tle
// class Solution {
// public:

//     bool bitcount(int a, int b) {
//         string bita = bitset<9>(a).to_string();
//         string bitb = bitset<9>(b).to_string();

//         int acount = 0, bcount = 0;

//         for (int i = 0; i < 9; i++) {
//             if (bita[i] == '1') acount++;
//             if (bitb[i] == '1') bcount ++;

//             cout << a << " " << b << " ";
//             cout << bita << " " << bitb << endl;   
            
//         }

//         return (acount == bcount);
//     }

//     bool canSortArray(vector<int>& nums) {
//         vector<int> newarr;
//         for (int x : nums) newarr.push_back(x);
//         sort(nums.begin(), nums.end());

//         if (nums == newarr) return true;

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = 0; j< nums.size() - i - 1; j++) {
//                 if (newarr[j] > newarr[j+1]) {
//                     if (bitcount(newarr[j], newarr[j+1])) swap(newarr[j], newarr[j+1]);
//                 }
//             }
//         }
//         for (auto x : newarr) cout << x << " ";
//         return (nums == newarr);
//     }

// };
