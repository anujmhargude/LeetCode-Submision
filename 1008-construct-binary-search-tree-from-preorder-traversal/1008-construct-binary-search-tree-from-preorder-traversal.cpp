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
    // TreeNode* build(TreeNode* root,int k){
    //     if(root == NULL){
    //         TreeNode* newNode = new TreeNode(k);
    //         return newNode;
    //     }
    //     if(root != NULL && root->val < k){
    //         root->right = build(root->right,k);
    //     }
    //     if(root != NULL && root->val > k){
    //         root->left = build(root->left,k);
    //     }
    //     return root;
    // }

    TreeNode* buildBST(vector<int>& pre,int& i,int bound){
        if(i >= pre.size() || pre[i] > bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        root->left = buildBST(pre,i,root->val);
        root->right= buildBST(pre,i,bound);
        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode* root = new TreeNode(preorder[0]);
        // for(int i = 1;i < preorder.size();i++){
        //     root = build(root,preorder[i]);
        // }
        // return root;
        int i = 0;
        return buildBST(preorder,i,INT_MAX);
    }
};