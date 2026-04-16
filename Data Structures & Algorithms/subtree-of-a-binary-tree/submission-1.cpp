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
private:
    bool isSame(TreeNode* first, TreeNode* second) {
        if (first == nullptr && second == nullptr) {
            return true;
        }
        if (first == nullptr || second == nullptr) {
            return false;
        }
        return first -> val == second -> val && isSame(first -> left, second -> left) && isSame(first -> right, second -> right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        // if (root -> val == subRoot -> val)
        //     return (isSubtree(root -> left, subRoot -> left) && isSubtree(root -> right, subRoot -> right)) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        // else
        //     return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        return isSame(root, subRoot) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
