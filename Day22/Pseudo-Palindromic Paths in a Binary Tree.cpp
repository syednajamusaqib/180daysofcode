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
    void path(TreeNode* root, vector<int>& freq, int& count){
        if(!root) return;
        // Increment frequency of Node value
        freq[root->val]++;

        path(root->left, freq, count);
        path(root->right,freq,count);

        if(!root->left && !root->right){
            // It means we have reached at the end and now check for 
            // Palindrome
            int check = 0;
            for(auto x: freq){
                if(x%2 != 0) check++;
            }

            if(check <= 1) count++;
        }

        freq[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> freq(10,0);
        path(root, freq, count);
        return count;
    }
};
