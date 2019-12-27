#include<iostream>
struct TreeNode{
    int dat;
    TreeNode *leftSibling=NULL,*rightSibling=NULL;
    TreeNode(int dat){
        this->dat = dat;
    }
    bool append(TreeNode *new_node, int depth){
        if(!(this->append_in_existing_layer(new_node,depth))){
            this->create_layer_and_append(new_node);
            return true;
        }
        return false;
    }
    void print(int depth){
        if(depth == 0){
            std::cout<<this->dat<<" ";
        }
        else{
            if(this->rightSibling != NULL){
                this->leftSibling->print(depth-1);
                this->rightSibling->print(depth-1);
            }
            else if(this->leftSibling != NULL){
                this->leftSibling->print(depth-1);
            }
        }
    }
    int pop(bool path[],bool &done){
        
    }
    protected:
    void create_layer_and_append(TreeNode *new_node){
        TreeNode *curr = this->leftSibling;
        while(curr->leftSibling != NULL) curr = curr->leftSibling;
        curr->leftSibling = new_node;
    }
    bool append_in_existing_layer(TreeNode *new_node,int depth){
        if(depth == 0){
            if(this->leftSibling == NULL){
                this->leftSibling = new_node;
                return true;
            }
            else if (this->rightSibling == NULL)
            {
                this->rightSibling = new_node;
                return true;
            }
            return false;
        }
        return (this->leftSibling->append_in_existing_layer(new_node,depth-1) || this->rightSibling->append_in_existing_layer(new_node,depth-1));
    }
};
struct BinaryTree{
    TreeNode *root = NULL;
    int append(int val){
        TreeNode *new_node = new TreeNode(val);
        if(this->root == NULL){
            this->root = new_node;
            this->depth += 1;
            return 0;
        }
        bool new_node_created = (this->root->append(new_node,this->depth));
        if(new_node_created){
            this->depth += 1;
        }
        return 0;
    }
    void print(){
        if(this->root == NULL){
            return;
        }
        for(int d=0; d<=this->depth+1; d+=1){
            this->root->print(d);
            std::cout<<"\n";
        }
    }
    protected:
    int depth = -1;
};
int main(int argc, char const *argv[])
{
    BinaryTree bt;
    for(int i=1; i<11; i+=1){
        bt.append(i);
    }
    bt.print();
    std::cout<<bt.root->leftSibling->leftSibling->dat;
    return 0;
}

