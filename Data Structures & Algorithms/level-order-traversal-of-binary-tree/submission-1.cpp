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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr)
            return res;
        std::queue<TreeNode*> buffer;
        buffer.push(root);
        while (!buffer.empty()) {
            int len = buffer.size();
            std::vector<int> vals;
            for (int i = 0; i < len; i++) {
                TreeNode* node = buffer.front();
                vals.push_back(node -> val);
                if (node -> left != nullptr)
                    buffer.push(node -> left);
                if (node -> right != nullptr)
                    buffer.push(node -> right);
                buffer.pop();
            }
            res.push_back(vals);
        }
        return res;
    }
};
