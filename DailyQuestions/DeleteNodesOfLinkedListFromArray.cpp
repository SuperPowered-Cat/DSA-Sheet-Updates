// **Q: Delete Nodes From Linked List Present in Array**

// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list 
// after removing all nodes from the linked list that have a value that exists in nums.

// Example 1:
// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
// Explanation:
// Remove the nodes with values 1, 2, and 3.

// Example 2:
// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
// Explanation:
// Remove the nodes with value 1.

// Example 3:
// Input: nums = [5], head = [1,2,3,4]
// Output: [1,2,3,4]
// Explanation:
// No node has value 5.

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// All elements in nums are unique.
// The number of nodes in the given list is in the range [1, 105].
// 1 <= Node.val <= 105
// The input is generated such that there is at least one node in the linked list that has a value not present in nums.


// CODE ---->

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // Unordered set for the complexity of 1.
        // Will have to handle the edge case where head is stored in num
        unordered_set<int> removables (nums.begin(), nums.end());
        ListNode *edgeCase = new ListNode(0); 
        edgeCase->next = head;
        ListNode *prev = edgeCase;
        ListNode *curr = head; 
        while (curr != NULL) {
            if (removables.count(curr->val)){
                prev->next = curr->next;
                // delete curr; 
                
            }
            else prev = curr;
            curr = prev->next;
        }
        return edgeCase->next;
    }
};