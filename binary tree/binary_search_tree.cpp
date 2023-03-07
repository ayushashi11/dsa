#include<iostream>
using namespace std;
struct TreeNode{
    int dat;
    TreeNode *left=nullptr, *right=nullptr;
};
void insert(TreeNode* &root, int key){
    if(root==nullptr){
        root = new TreeNode;
        root->dat = key;
        return;
    }
    if(key>root->dat){
        insert(root->right, key);
    }
    else{
        insert(root->left, key);
    }
}
void inorder(TreeNode* root){
    if(!root) 
    return;
    inorder(root->left);
    cout<<root->dat<<"\t";
    inorder(root->right);
}
TreeNode* createBST(int arr[], int n){
    TreeNode *root = nullptr;
    for(int i=0; i<n; i++){
        insert(root, arr[i]);
    }
    return root;
}
void delete_(TreeNode* &root, int key){
    if(root==nullptr) return;
    if(root->dat==key){
        if(root->left==nullptr){
            root=root->right;
        }
        else if(root->right==nullptr){
            root=root->left;
        }
        else{
            TreeNode *curr = root->right;
            while(curr->left!=nullptr){
                curr=curr->left;
            }
            int temp = curr->dat;
            delete_(curr, temp);
            root->dat = temp;
        }
    }
    else if(root->left!=nullptr&&key<root->dat){
        delete_(root->left, key);
    }
    else if(root->right!=nullptr&&key>root->dat){
        delete_(root->left, key);
    }
    else return;
}
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"enter the "<<(i+1)<<"th element: ";
        cin>>arr[i];
    }
    inorder(createBST(arr,n));
}
