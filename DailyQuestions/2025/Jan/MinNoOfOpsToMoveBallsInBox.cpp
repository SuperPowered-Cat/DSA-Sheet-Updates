// leetcode 1769
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06

class Solution {
public:
    vector<int> minOperations(string boxes) {
        // BRUTEFORCE - only for visualisation

        // int n = boxes.size(); // no of boxes
        // vector<int> ans(n, 0);

        // for(int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i != j && boxes[j] == '1') ans[i] += abs(i-j);
        //     }
        // }
        // return ans;

        // --------------------------------------------------


        // PROPER APPROACH USING O(N) / OR O(2N)
        
        int n = boxes.size();
        vector<int>ans(n, 0); // initialising answer array

        // using 4 variables to keep track of balls and moves each side
        // split because balls come from both left and right side
        int leftballs = 0, leftmoves = 0, rightballs = 0, rightmoves = 0;

        for (int i = 0; i < n; i++) {
            // FIRST HALF, GETTING LEFTBALLS AND MOVES  
            ans[i] += leftmoves; // summing up total moves
            if (boxes[i] == '1') leftballs++; // adding if we see ball
            leftmoves+=leftballs; // for each i, moves incr by balls seen

            // instead of seperate loop (given below) can simply do here
            // making an index j = n - 1 - i 
            // visualise a pincer closing in the array from both sides
            int j = n - 1 - i;
            ans[j] += rightmoves;
            if(boxes[j] == '1') rightballs++;
            rightmoves+=rightballs; 
        }

        // Seperate loop code if required
        // for (int i = n-1; i >=0; i--) {
        //     ans[i] += rightmoves;
        //     if (boxes[i] == '1') rightballs++;
        //     rightmoves+=rightballs; 
        // }
        
        return ans;
    }

};
