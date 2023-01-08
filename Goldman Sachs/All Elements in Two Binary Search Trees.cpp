class Solution {
public:
    vector<int>v;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper(root1);
        helper(root2);
        sort(v.begin(),v.end());
        return v;
        
    }
    
    public:
        void helper(TreeNode* root)
        {
            if(root != NULL)
            { 
                helper(root->left);
                v.push_back(root->val);
                helper(root->right);
            }
        
        }
};