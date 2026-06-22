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
    vector<int>v;
    void dfs(TreeNode*r, bool ok, int st, int en){
        if(!ok){
        if(r==NULL)return;
            dfs(r->left, ok,  st, en);
            v.push_back(r->val);
            dfs(r->right, ok,  st, en);
        }
        else{
            if(r==NULL)return;
            int originalValue = r->val;
            if(originalValue==st){r->val = en;}
            if(originalValue==en){r->val = st;}
            dfs(r->left, ok, st, en);
            dfs(r->right, ok, st, en);
            return;
        }
    }

public:
    void recoverTree(TreeNode* root) {
        dfs(root, false, -1, -1);
        vector<int>s = v;
        sort(s.begin(), s.end());
    int st = 0;
    int en = 0;
    int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]!=v[i]&&cnt==0){
                st = v[i];
                cnt++;
            }
            else if(s[i]!=v[i]&&cnt==1){
                en = v[i];
                cnt++;
            }
        }
        dfs(root, true, st, en);

    }
};