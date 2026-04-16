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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        std::vector<TreeNode*> stack;

        while (!stack.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stack.push_back(curr);
                curr = curr -> left;
            }
            curr = stack.back();
            stack.pop_back();
            k--;
            if (k == 0) return curr -> val;
            curr = curr -> right;
        }
        
        return -1;
    }
};
