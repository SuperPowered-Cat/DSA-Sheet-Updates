// leetcode 
// 

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // derived array is made by using real[i] and real[i+1] xor'd
        // this is same for every element in the derived aray
        // so for every element in the array, 2 of each of real array 
        // is used

        // therefore, the xor of the entire array should be 0
        // because its itself a xor of all the elements of array - twice
        int x = 0; // originally answer is 0, as 0xora = a
        for (auto derive : derived) x^=derive; // xor of entire derived
        return x == 0; // if 0, array exists (arrayxorarray = 0)
    }
};
