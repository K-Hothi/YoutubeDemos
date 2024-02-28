  #include <iostream>

#include "BST.h"

using namespace std;

BST::BST(){
    root = nullptr;
    elementCount = 0;
}

BSTNode* BST::insertr(BSTNode* root, BSTNode* nn){
    if(root == nullptr){
        return nn;
    }
    else{
        if(root->data > nn->data){
            root->left = insertr(root->left, nn);
        }
        else{
            root->right = insertr(root->right, nn);
        }
    }

    return root;
}

//creates BSTNode with data=value and inserts node into BST
bool BST::insert(int value){
     BSTNode* newNode = new BSTNode(value);
     
     root = insertr(root, newNode);

     elementCount++;

     return true;

}

BSTNode* BST::searchr(BSTNode* root, int key){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->data == key){
        return root;
    }
    else{
        if(root->data > key){
            return searchr(root->left, key);
        }
        else{
            return searchr(root->right, key);
        }
    }

    return root;
}


BSTNode* BST::search(int key){
    return searchr(root, key);
}

BSTNode* BST::remover(BSTNode* root, BSTNode* toRemove){
    if(root == nullptr){
        return nullptr;
    }
    
    else if(root->data > toRemove->data){
        root->left = remover(root->left, toRemove);
    }
    else if(root->data < toRemove->data){
        root->right = remover(root->right, toRemove);
    }
    else{
        if(root->left == nullptr){
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
    
        BSTNode* successor = getMin(root->right);
        root->data = successor->data;
        root->right = remover(root->right, successor);
    }

    return root;
}
BSTNode* BST::remove(BSTNode* toRemove){
    root  = remover(root, toRemove);
    elementCount--;
    return root;
    
}

//finds BSTNode with highest data value in subtree with root = root
BSTNode* BST::getMax(BSTNode* root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->right == nullptr){
        return root;
    }
    return getMax(root->right);
}

BSTNode* BST::getMin(BSTNode* root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->left == nullptr){
        return root;
    }
    return getMin(root->left);
}

int BST::getElementCount(){
    return elementCount;
}

void BST::traverseInOrder(BSTNode* root){
    if(elementCount <= 0){
        cout << "Empty BST";
        return;
    }
    if(root == nullptr){
        cout << endl;
        return;
    }
    traverseInOrder(root->left);
    cout << root->data << ", ";
    traverseInOrder(root->right);
}

BSTNode* BST::getRoot(){
    return root;
}