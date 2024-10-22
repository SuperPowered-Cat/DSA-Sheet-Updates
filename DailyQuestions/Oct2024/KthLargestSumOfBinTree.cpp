// leetcode 2583

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector <long long> storage;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                sum+=(long long)curr->val;
            }
            storage.push_back(sum);
        }
        sort(storage.begin(), storage.end());
        if (storage.size() < k) return -1;
        long long ans = storage[storage.size()-k];
        return ans;
    }
};
