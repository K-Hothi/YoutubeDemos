class BSTNode{
    public:
        int data;
        BSTNode* left;
        BSTNode* right;

        BSTNode(){
            data = -1;
            left = nullptr;
            right = nullptr;
        }
        
        BSTNode(int  value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};