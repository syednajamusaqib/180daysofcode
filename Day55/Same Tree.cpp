class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val){
            bool left  = isSameTree(p->left,q->left);
            bool right = isSameTree(p->right,q->right);
            return left && right; 
        }
        return false;
    }
};
