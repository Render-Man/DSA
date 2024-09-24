#include <stdio.h>
#include <iostream>


template<class TValue>  //generic type
struct TNode
{
    public:
        TNode* left;  
        TNode* right;
        
        TValue value;   // template value
        
        SNode(TValue val)
        {
            value = val;
            back = nullptr;
        }
};

template<class TValue>
struct Tree
{
    private:
        TNode<TValue>* root;   // the head node
        
    public:
        Tree() : first(nullptr) {}
        
    public:
        void add(TValue value)
        {
            TNode<TValue> newNode = new TNode<TValue>(value);
            
            if(root ==  nullptr)
            {
                root = newNode;
                return;
            }

            TNode<TValue>* current = root;
            while (current != nullptr)
            {
                TNode<TValue>* leftNode = current->left;

                if(leftNode != nullptr && leftNode->value)
                {

                }
            }
            
        }
    
        void preOrderTraversal()
        {

        }

        void inOrderTraversal()
        {

        }

        void postOrderTraversal()
        {

        }
        
        void clear()
        {
            first = nullptr;
        }
        
        
        void visualize()
        {
            if(first == nullptr)
            {
                std::cout << "Tree is Empty!" << std::endl;
                return;
            }
            SNode<TValue>* current = first;
            while(current != nullptr)
            {
                std::cout <<"("<< (current->value) << ")";
                if(current->back != nullptr)
                    std::cout<<" -> ";
                current = current->back;
            }
            std::cout<<std::endl;
        }
};

void print(std::string message)
{
    std::cout<<message<<std::endl;
}


int main()
{
    Tree<int> myTree;

    myTree.add(10);
    myTree.add(11);
    myTree.add(7);
    myTree.add(5);
    myTree.add(20);

    myTree.visualize();

    print("finished");

    return 0;
}
