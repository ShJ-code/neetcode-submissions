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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return root;

        return bfs(root, nullptr, false, target);
    }

private:
    TreeNode* bfs(TreeNode* node, TreeNode* parent, bool is_left, int target) {
        if (node->left)
            bfs(node->left, node, true, target);
        if (node->right)
            bfs(node->right, node, false, target);
        
        if (node->left == nullptr &&
            node->right == nullptr &&
            node->val == target) {
            if (parent != nullptr) {
                if (is_left) { parent->left = nullptr; }
                else { parent->right = nullptr; }
            } else {
                return nullptr;
            }
        }

        return node;
    }
};