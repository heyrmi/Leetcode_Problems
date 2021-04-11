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

//DFS solution
class Solution {
public: 
    int deepest = 0, sum = 0;                           //global variables
    
    
    int solveIt(TreeNode *root, int depth){
        if(!root) return 0;                             //current node is null
        if(!root->left && !root->right)                 //current node if leaf
            if(depth == deepest) sum += root->val;      //if depth is exactly equal to deepest add to sum 
            else if(depth > deepest) 
                sum = root->val, deepest = depth;       //found more deep node then update sum and deepest
        
        solveIt(root->left, depth+1);                   //recurse for the left tree
        solveIt(root->right, depth +1);                 //recurse for the right tree
        return sum;                                     //return the sum of the max-depth leaf nodes
    }
    
    
    
    int deepestLeavesSum(TreeNode* root){       
        int ans = solveIt(root, 0);                     //function call
         return ans;                                    //return final ans
    }
};


 
//BFS solution
class Solution {
public: 
    int deepestLeavesSum(TreeNode* root){ 
        int sum = 0, n;
        queue<TreeNode*> q;                             //for level order traversal
        q.push(root);                                   // push the root node
        while(!q.empty()){                              //while there is still elemnt in queue, iterate
            sum = 0, n = size(q);                       //reset sum for deeper level
            for(int i = 0; i<n; i++){                   //iterate over the no. of elements in queue
                auto top = q.front();                   //store top in front         
                q.pop();                                //pop the first element
                 sum += top -> val;                     //store the sum of the elements
                if(top -> left) q.push(top -> left);    //check for left elements
                if(top -> right) q.push(top -> right);  //check for right elements
            }
        }
        
        return sum;                                     //return final sum
    }  
};
