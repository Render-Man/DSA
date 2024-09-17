#include <stdio.h>
#include <iostream>


template<class TValue>  //generic type
struct SNode
{
    public:
        SNode* back;   //the next node
        
        TValue value;   // template value
        
        SNode(TValue val)
        {
            value = val;
            back = nullptr;
        }
};

template<class TValue>
struct Stack
{
    private:
        SNode<TValue>* first;   // the head node
        
    public:
        Stack() : first(nullptr) {}
        
    public:
        void push(TValue value)
        {
            SNode<TValue>* newNode = new SNode<TValue>(value);

            newNode->back = first;
            first = newNode;
        }

        TValue pop()
        {
           if(first == nullptr)
            {
                std::cout<<"Pop error: return null cause Stack is empty"<<std::endl;
                return NULL;
            }

            SNode<TValue>* result = first;
            first = first->back;
            return result->value;
        }
        
        TValue peek()
        {
            if(first == nullptr)
            {
                std::cout<<"Pop error: return null cause Stack is empty"<<std::endl;
                return NULL;
            }

            return first->value;
        }
        
        void clear()
        {
            first = nullptr;
        }
        
        
        void print()
        {
            if(first == nullptr)
            {
                std::cout << "Stack is Empty!" << std::endl;
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
    Stack<std::string> myStack;

    myStack.push("i am lustied");
    myStack.push("wtf");
    myStack.push("hey babi");
    myStack.push("adu man");

    myStack.print();

    auto popped = myStack.pop();
    auto peeked = myStack.peek();
    
    print("pop: \"" + popped + "\" and peek: \"" + peeked + "\"");
    
    myStack.print();

    print("finished");

    return 0;
}
