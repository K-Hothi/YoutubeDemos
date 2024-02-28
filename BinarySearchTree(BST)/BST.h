#ifndef BST_H
#define BST_H

#include <iostream>
#include "BSTNode.cpp"
using namespace std;

class BST{
    private:
        BSTNode* root;
        int elementCount;

        BSTNode* insertr(BSTNode* root, BSTNode* nn);

        BSTNode* searchr(BSTNode* root, int key);

        BSTNode* remover(BSTNode* root, BSTNode* toRemove);

    public:
        BST();
        
        //creates BSTNode with data=value and inserts node into BST
        bool insert(int value);

        BSTNode* search(int key);

        BSTNode* remove(BSTNode* toRemove);

        //finds BSTNode with highest data value in subtree with root = root
        BSTNode* getMax(BSTNode* root);

        BSTNode* getMin(BSTNode* root);

        int getElementCount();

        void traverseInOrder(BSTNode* current);

        BSTNode* getRoot();

        //end


};
#endif