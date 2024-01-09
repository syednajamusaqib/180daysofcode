class Solution {
public:

    void inorder(TreeNode* root, string& s){
        if(root == NULL ) return ;

        if(root -> left == NULL && root -> right == NULL){
            s += to_string(root->val) + "_";
            return ;
        }
        inorder(root->left,s);
        inorder(root->right,s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";

        inorder(root1,s1);
        inorder(root2,s2);

        return s1 == s2;
    }
};
