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
    std::tuple<int, int> maxPathSumHelper(TreeNode* t) {
        if (t == nullptr) return std::tuple<int, int>{-1001, -1001};
        if (t -> left == nullptr && t -> right == nullptr) {
            return std::tuple<int, int>{
                t -> val, t -> val
            };
        }
        // if (t -> left == nullptr) {
        //     auto [rroot, rmax] = maxPathSumHelper(t -> right);
        //     int self_root = std::max({rroot + t -> val, t -> val});
        //     int self_max = std::max({rmax, rroot + t -> val, t -> val});
        //     return std::tuple<int, int>{self_root, self_max};
        // }
        // if (t -> right == nullptr) {
        //     auto [lroot, lmax] = maxPathSumHelper(t -> left);
        //     int self_root = std::max({lroot + t -> val, t -> val});
        //     int self_max = std::max({lmax, lroot + t -> val, t -> val});
        //     return std::tuple<int, int>{self_root, self_max};
        // }
        auto [lroot, lmax] = maxPathSumHelper(t -> left);
        auto [rroot, rmax] = maxPathSumHelper(t -> right);
        int self_root = std::max({lroot + t -> val, rroot + t -> val, t -> val});
        int self_max = std::max({lmax, rmax, lroot + rroot + t -> val, lroot + t -> val, rroot + t -> val, t -> val});
        return std::tuple<int, int>{self_root, self_max};
    }

    int maxPathSum(TreeNode* root) {
        auto [_, max] = maxPathSumHelper(root);
        return max;
    }
};
