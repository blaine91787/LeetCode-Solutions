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

    /**
     * Returns a 2-dimensional vector of integers.
     *
     * A queue is created to hold the root value. If root is not null, the queue
     * containing root is passed with a pointer to the vector which will store
     * the each level. Otherwise an empty vector is returned.
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        } else {
            return v1;
        }
        return *(helper(q, &v1));
    }

    /**
     * Returns a pointer to a 2-dimensional vector.
     *
     * q1 is the queue that will be used to pop the current root. Queue q2
     * will be used to store the current root's children. v2 will store the
     * values contained in the roots being popped off q1. Before popping, it
     * checks for a null value and ignores if null.
     *
     * When q1 is empty, v2 will be added to v1.
     *
     * If q2 is empty then v1 is returned, otherwise recurse with q2 and v1 as
     * the new parameters.
     */
    vector<vector<int>>* helper(queue<TreeNode*> q1, vector<vector<int>>* v1){
        queue<TreeNode*> q2;
        vector<int> v2;
        while(!q1.empty()){
            if(q1.front()){
                TreeNode* root = q1.front();
                q1.pop();
                v2.push_back(root->val);
                if(root->left)
                    q2.push(root->left);
                if(root->right)
                    q2.push(root->right);
            }
        }
        v1->push_back(v2);
        if(q2.empty())
            return v1;
        else
            helper(q2, v1);
        return v1;
    }
};
