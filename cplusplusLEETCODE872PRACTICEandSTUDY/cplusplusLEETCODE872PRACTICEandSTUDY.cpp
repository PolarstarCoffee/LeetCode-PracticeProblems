// cplusplusLEETCODE872PRACTICEandSTUDY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> leaves1; //uses vector (essentially a dynamic array, can automatically resize itself upon addition or deletion of entries)
            vector<int> leaves2;
            dfs(root1, leaves1); //uses Depth first search function 
            dfs(root2, leaves2);

            return leaves1 == leaves2;
        }

        void dfs(TreeNode* node, vector<int>& leaves) { //DFS function 
            if (node == NULL) return; //Eliminates itself if the node is null
            if (node->left == NULL && node->right == NULL)
                leaves.push_back(node->val); //Adds a new entry at the end of the vector, after its current last entry. The content of val is copied (or moved) to the new element.
            dfs(node->left, leaves);
            dfs(node->right, leaves);
        }
};