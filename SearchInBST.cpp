// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Input: root = [4,2,7,1,3], val = 5
// Output: []

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
    void dfs(TreeNode* root, int val, TreeNode* &ans){
        if(!root)return;
        if(root->val == val) ans = root;
        if(root->val > val)dfs(root->left, val, ans);
        else if(root->val < val)dfs(root->right, val, ans);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        dfs(root, val, ans);
        return ans;
    }
};
