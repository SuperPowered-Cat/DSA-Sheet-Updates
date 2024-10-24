// leetcode 951

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2); // seperate dfs function for ease of understanding
        
    }

    bool dfs(TreeNode* root1, TreeNode* root2) {
        // 4 base conditions
        if(root1 != NULL && root2 == NULL) return false; 
        if (root2 != NULL && root1 == NULL) return false;
        if (root1 == NULL && root2 == NULL) return true; // our target
        if (root1->val != root2->val) return false;

        // first checking with zero flip at each level == same value of left and right
        bool noFlip = (dfs(root1->left, root2->left) && dfs(root1->right, root2->right));
        // now checking with flip, so inverted value
        bool Flip = (dfs(root1->left, root2->right) && dfs(root1->right, root2->left));
        // we do this because we need to check whether 
        // each NODE of the tree can be flipped at certain level to make the code run  
        
        // finally verifying if the trees are same with no flips or flips
        return noFlip || Flip;
    }

};
