// Contruct a string which represents a binary tree given the root node
// Using Preorder Traversal (Root, Left, Right)

#include<iostream> 

using namespace std; 

typedef struct TreeNode{
    int val; 
    TreeNode* right; 
    TreeNode* left; 

    TreeNode(){
        val = 0; 
        right = NULL; 
        left = NULL; 
    }
    TreeNode(int _val){
        val = _val; 
        right = NULL; 
        left = NULL; 
    }
} TreeNode; 

TreeNode* makeTree1(){
    TreeNode* n1 = new TreeNode(10); 
    TreeNode* n2 = new TreeNode(20); 
    TreeNode* n3 = new TreeNode(30); 
    TreeNode* n4 = new TreeNode(40); 
    TreeNode* n5 = new TreeNode(50); 
    TreeNode* n6 = new TreeNode(60);

    n1->left = n2; 
    n1->right = n3; 

    n2->left = n4; 
    n2->right = n5; 

    n3->right = n6;  

    return n1; 
}

void preorder(TreeNode* root){
    if(root == NULL) return; 

    cout<<(root->val)<<" "; 
    preorder(root->left); 
    preorder(root->right); 
}

void preorderString(TreeNode* root, string &data){
    if(root == NULL){
        data += "NULL "; 
        return; 
    } 
    data += (to_string(root->val) + " "); 
    preorderString(root->left, data);
    preorderString(root->right, data);
}

string serialize(TreeNode* root){
    string data = ""; 
    preorderString(root, data); 
    data.pop_back(); 
    return data; 
}

int main(){
    TreeNode* root1 = makeTree1(); 
    preorder(root1); cout<<endl; 

    string serialRoot1 = serialize(root1); 
    cout<<serialRoot1<<endl; 
    cout<<(*serialRoot1.rbegin())<<endl; // Printing the last character. It should not be space

    return 0; 
}
