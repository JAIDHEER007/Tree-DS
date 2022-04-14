#include<iostream>
#include<fstream>
#include<vector>
#include<cctype>
#include<random>
#include<queue>

using namespace std;

using u32    = uint_least32_t; 
using engine = std::mt19937;

random_device os_seed;
const u32 seed = os_seed();
engine generator( seed );

typedef struct TreeNode{
    int val; 
    TreeNode* left; 
    TreeNode* right; 

    TreeNode(int _val = 0){
        val = _val; 
        left = NULL; 
        right = NULL; 
    }
} TreeNode; 

void dfs(vector<int> &nums, int start, int end, 
        TreeNode* root, bool isRight){
        
    if(root){
        if(end >= start){
            uniform_int_distribution<u32> midDst(start, end); 
            uniform_int_distribution<u32> lrDst(1, 1000); 

            int mid = midDst(generator);
            TreeNode* newRoot = new TreeNode(nums[mid]); 

            if(isRight)
                root->right = newRoot; 
            else
                root->left = newRoot; 

            bool lrBool = lrDst(generator) & 1; 

            dfs(nums, start, (mid - 1), newRoot, lrBool); 
            dfs(nums, (mid + 1), end, newRoot, !lrBool); 
        }
    }
}

TreeNode* genTree(vector<int> &nums){
    TreeNode* dummyRoot = new TreeNode(); 

    int n = nums.size(); 
    dfs(nums, 0, (n - 1), dummyRoot, false); 

    TreeNode* root = dummyRoot->left; 
    delete dummyRoot; 

    return root; 
}

int maxDepth(TreeNode* root){
    if(root == NULL) return 0; 

    // Remove this afterwards
    if((root->left == NULL) && (root->right == NULL)) return 1; 

    int leftHeight = (root->left)?(maxDepth(root->left)):0; 
    int rightHeight = (root->right)?(maxDepth(root->right)):0;

    return max(leftHeight, rightHeight) + 1; 
}

int main(){
    // change the number of test cases
    int nInputs = 14;

    // test case files should be input1.txt, input2.txt, ..., inputN.txt format
    for(int i = 1; i <= nInputs; i++){
        string filename = "input" + to_string(i) + ".txt"; 

        ifstream fin(filename); 
        if(!fin.is_open()){
            cout<<"Cannot Open the test case"<<endl;
            return 0; 
        }

        cout<<"======== TestCase "<<i<<" ========"<<endl;


        // Write input and output here
        // Instead of cin use fin

        // ===== START =====
        int n; fin>>n; 
        vector<int> nums(n); 

        for(int i = 0; i < n; ++i)
            fin >> nums[i]; 

        TreeNode* root = genTree(nums);  
        cout<<maxDepth(root)<<endl;
        

        // ===== END =====
    }
    
    return 0; 
}