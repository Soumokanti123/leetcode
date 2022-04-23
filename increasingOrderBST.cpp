// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
// and every node has no left child and only one right child.
  
//   Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

// Input: root = [5,1,7]
// Output: [1,null,5,null,7]


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
    TreeNode* tmp = new TreeNode();
        TreeNode* node = tmp;
    TreeNode* increasingBST(TreeNode* root) {
       
        if(!root)return NULL;
        increasingBST(root->left);
        TreeNode* curr = new TreeNode(root->val);
        node->right = curr;
        node = node->right;
        increasingBST(root->right);
        return tmp->right;
        
    }
};
