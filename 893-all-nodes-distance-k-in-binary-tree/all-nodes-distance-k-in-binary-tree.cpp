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
    private:
    void storeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        storeParent(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level==k)break;
            for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
             if(node->left&&!vis[node->left]){
                vis[node->left]=true;
                q.push(node->left);
             }
              if(node->right&&!vis[node->right]){
                vis[node->right]=true;
                q.push(node->right);
             }
             if(parent[node]&&!vis[parent[node]]){
                vis[parent[node]]=true;
                q.push(parent[node]);
             }
             
            }
            curr_level++;

        }
        while(!q.empty()){
             ans.push_back(q.front()->val);
             q.pop();
        }
        return ans;
    }
};