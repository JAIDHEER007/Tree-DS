#include<iostream> 
#include<sstream>

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

string makeTree1(){
    return "10 20 40 NULL NULL 50 NULL NULL 30 NULL 60 NULL NULL"; 
}

string makeTree2(){
    return "10 20 NULL NULL 30 NULL NULL"; 
}

string makeTree3(){
    return "10 20 NULL NULL NULL"; 
}

string makeTree4(){
    return "10 20 30 NULL 40 NULL NULL NULL NULL"; 
}

string makeTree5(){
    return "10 NULL NULL"; 
}

string makeTree6(){
    return "NULL"; 
}

void inorder(TreeNode* root){
    if(root == NULL) return; 

    inorder(root->left); 
    cout<<(root->val)<<" "; 
    inorder(root->right); 
}

void postorder(TreeNode* root){
    if(root == NULL) return; 

    postorder(root->left); 
    postorder(root->right); 
    cout<<(root->val)<<" "; 
}

void preorder(TreeNode* root){
    if(root == NULL) return; 

    cout<<(root->val)<<" "; 
    preorder(root->left); 
    preorder(root->right); 
}

TreeNode* preorderContruct(stringstream &ss){
    string token; 
    ss >> token; 

    if(token == "NULL") return NULL; 

    TreeNode* root = new TreeNode(stoi(token)); 
    root->left = preorderContruct(ss); 
    root->right = preorderContruct(ss); 

    return root;
}

TreeNode* deserialize(string data){
    stringstream ss(data); 
    return preorderContruct(ss); 
}

int main(){

    // Tree1
    TreeNode* root1 = deserialize(makeTree1()); 
    
    inorder(root1); cout<<endl; 
    postorder(root1); cout<<endl; 
    preorder(root1); cout<<endl;


    // Tree2
    TreeNode* root2 = deserialize(makeTree2()); 
    
    inorder(root2); cout<<endl; 
    postorder(root2); cout<<endl; 
    preorder(root2); cout<<endl;

    // Tree3
    TreeNode* root3 = deserialize(makeTree3()); 
    
    inorder(root3); cout<<endl; 
    postorder(root3); cout<<endl; 
    preorder(root3); cout<<endl;


    // Tree4
    TreeNode* root4 = deserialize(makeTree4()); 
    
    inorder(root4); cout<<endl; 
    postorder(root4); cout<<endl; 
    preorder(root4); cout<<endl;

    // Tree5
    TreeNode* root5 = deserialize(makeTree5()); 
    
    inorder(root5); cout<<endl; 
    postorder(root5); cout<<endl; 
    preorder(root5); cout<<endl;


    // Tree6
    TreeNode* root6 = deserialize(makeTree6()); 
    
    inorder(root6); cout<<endl; 
    postorder(root6); cout<<endl; 
    preorder(root6); cout<<endl;

    return 0; 
}