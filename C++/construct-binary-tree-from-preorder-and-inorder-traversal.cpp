// Time:  O(n)
// Space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            in_entry_idx_map.emplace(inorder[i], i);
        }
        return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size(),
                                            in_entry_idx_map);
    }

    // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
    // in[in_s : in_e - 1].
    TreeNode *ReconstructPreInOrdersHelper(const vector<int>& preorder, size_t pre_s, size_t pre_e,
                                           const vector<int>& inorder, size_t in_s, size_t in_e,
                                           const unordered_map<int, size_t>& in_entry_idx_map) {
        if (pre_s == pre_e || in_s == in_e) {
            return nullptr;
        }

        auto idx = in_entry_idx_map.at(preorder[pre_s]);
        auto left_tree_size = idx - in_s;

        auto node = new TreeNode(preorder[pre_s]);
        node->left = ReconstructPreInOrdersHelper(preorder, pre_s + 1, pre_s + 1 + left_tree_size,
                                                  inorder, in_s, idx, in_entry_idx_map);
        node->right = ReconstructPreInOrdersHelper(preorder, pre_s + 1 + left_tree_size, pre_e,
                                                   inorder, idx + 1, in_e, in_entry_idx_map);
        return node;
    }
};

// -----JF-----

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int pl, int pr, int il, int ir) {
      if (pl > pr) return NULL;
      TreeNode *res = new TreeNode(preorder[pl]);
      int pos = distance(inorder.begin(), find(inorder.begin(), inorder.end(), res->val));
      int left_size = pos - il, right_size = ir - pos - 1;
      res->left = build(preorder, inorder, pl + 1, pl + left_size, il, pos - 1);
      res->right = build(preorder, inorder, pl + left_size + 1, pr, pos + 1, ir);
      return res;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
