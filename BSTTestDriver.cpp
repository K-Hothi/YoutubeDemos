#include <iostream>
#include "BST.cpp"

using namespace std;

int main(){

    BST* b = new BST();

    b->insert(1);
    b->insert(2);
    b->insert(3);
    b->insert(4);

    cout << "ElementCout: " << b->getElementCount() << endl;

    b->traverseInOrder(b->getRoot());



    cout << "Max: " << b->getMax(b->getRoot())->data << endl;
    cout << "Min: " << b->getMin(b->getRoot())->data << endl;

    // cout << b->search(2)->data;
    b->remove(b->search(1));
    b->traverseInOrder(b->getRoot());
    
    b->remove(b->search(2));
    b->traverseInOrder(b->getRoot());

    b->remove(b->search(4));
    b->traverseInOrder(b->getRoot());

    b->remove(b->search(3));
    b->traverseInOrder(b->getRoot());



    return 0;
}