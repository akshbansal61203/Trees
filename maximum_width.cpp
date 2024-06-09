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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int width=0;
        while(!q.empty()){
            int size=q.size();
            //index
            int ind=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int curr_id=q.front().second-ind;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0)first=curr_id;
                if(i==size-1)last=curr_id;
                if(node->left)q.push({node->left,(long long)curr_id*2+1});
                if(node->right)q.push({node->right,(long long)curr_id*2+2});
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};
