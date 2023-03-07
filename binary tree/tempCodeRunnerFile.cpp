#include<iostream>
using namespace std;

struct TreeNode{
    int dat;
    TreeNode *left=nullptr, *right=nullptr;
};

TreeNode *createBT(){
    TreeNode *root = new TreeNode;
    cout<<"Enter datum:";
    cin>>root->dat;
    if(root->dat==-1){return nullptr;}
    cout<<"Enter the left child of "<<root->dat<<endl;
    root->left=createBT();
    cout<<"Enter the right child of "<<root->dat<<endl;
    root->right=createBT();
    return root;
} 

bool printAncestors(TreeNode *root, int ancestor){
    if(root->dat==ancestor) return true;
    if(root->left!=nullptr&&printAncestors(root->left, ancestor)){
        cout<<root->dat<<endl;
        return true;
    }
    if(root->right!=nullptr&&printAncestors(root->right, ancestor)){
        cout<<root->dat<<endl;
        return true;
    }
    return false;
}

void printParent(TreeNode *root, int key){
    if(root==nullptr) return;
    if(root->left!=nullptr){
        if(root->left->dat==key){
            cout<<"parent of "<<key<<" is "<<root->dat<<endl;
        }
        else{
            printParent(root->left,key);
        }
    }
    if(root->right!=nullptr){
        if(root->right->dat==key){
            cout<<"parent of "<<key<<" is "<<root->dat<<endl;
        }
        else{
            printParent(root->right,key);
        }
    }
}

int depth(TreeNode* root, int depthSoFar=0){
    if(root==nullptr) return depthSoFar;
    //cout<<root->dat<<" "<<depthSoFar<<endl;
    int max = depth(root->left, depthSoFar+1), temp;
    if((temp=depth(root->right, depthSoFar+1))>max) max=temp;
    return max;
}

int nLeafs(TreeNode *root){
    if(root==nullptr) return 0;
    if(root->left==nullptr&&root->right==nullptr) return 1;
    return nLeafs(root->left)+nLeafs(root->right);
}

int main(){
    TreeNode *root = (createBT());
    printAncestors(root, 4);
    printParent(root,5);
    cout<<depth(root)<<endl;
    cout<<nLeafs(root)<<endl;
}
