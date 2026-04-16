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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        std::vector<std::tuple<int, int, TreeNode*>> stack;
        stack.push_back(std::make_tuple(-1001, 1001, root));
        while (!stack.empty()) {
            auto [min, max, top_elem] = stack.back();
            stack.pop_back();
            TreeNode* left = top_elem -> left;
            TreeNode* right = top_elem -> right;
            if (left != nullptr) {
                if (left -> val >= top_elem -> val || left -> val <= min) {
                    return false;
                }
                stack.push_back(std::make_tuple(min, top_elem -> val, left));
            }
            if (right != nullptr) {
                if (right -> val <= top_elem -> val || right -> val >= max) {
                    return false;
                }
                stack.push_back(std::make_tuple(top_elem -> val, max, right));
            }
        }
        return true;
    }
};
