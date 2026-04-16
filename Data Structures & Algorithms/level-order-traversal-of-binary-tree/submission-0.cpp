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
            std::vector<TreeNode*> curr;
            std::vector<int> vals;
            while (!buffer.empty()) {
                curr.push_back(buffer.front());
                buffer.pop();
            }
            for (TreeNode* node : curr) {
                if (node -> left != nullptr)
                    buffer.push(node -> left);
                if (node -> right != nullptr)
                    buffer.push(node -> right);
                vals.push_back(node -> val);
            }
            res.push_back(vals);
        }
        return res;
    }
};
