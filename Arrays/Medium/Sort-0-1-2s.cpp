class Solution {
public:
    void sortColors(vector<int>& nums) {
        // can be solved using sort algo also
        
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while (mid<=high) {
            //case 1 arr[mid] = 0
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            
            // case 2 arr[mid] = 1
            else if (nums[mid] == 1) mid++;

            // case 3 arr[mid] = low
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }


};
