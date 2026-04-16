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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }
        queue<TreeNode*> nqueue;
        nqueue.push(root);
        string res = "[" + to_string(root->val);
        int nonempty = 1;
        bool first = true;
        while (nonempty > 0) {
            TreeNode* next = nqueue.front();
            nqueue.pop();
            if (next != nullptr) {
                nonempty--;
                if (!first)
                    res += ("," + to_string(next->val));
                else
                    first = false;
                nqueue.push(next->left);
                nqueue.push(next->right);
                if (next->left != nullptr)
                    nonempty++;
                if (next->right != nullptr)
                    nonempty++;
            } else {
                res += ",null";
            }
        }
        return res + ",]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 2) {
            return nullptr;
        }
        int i = 1, j;
        j = data.find(',', i);
        TreeNode* root = new TreeNode(stoi(data.substr(i, j-i)));
        queue<TreeNode*> nqueue;
        nqueue.push(root);
        i = j + 1;
        while ((j = data.find(',', i)) != std::string::npos) {
            TreeNode* node = nqueue.front();
            nqueue.pop();
            if (data[i] != 'n') {
                node -> left = new TreeNode(stoi(data.substr(i, j-i)));
                nqueue.push(node -> left);
            }
            i = j + 1;
            if ((j = data.find(',', i)) != std::string::npos) {
                if (data[i] != 'n') {
                    node -> right = new TreeNode(stoi(data.substr(i, j-i)));
                    nqueue.push(node -> right);
                }
                i = j + 1;
            } else
                break;
        }
        return root;
    }
};
