#include <stdio.h>
#include <iostream>

//queue: (last)-<-()-<-()-<-(first)

template<class TValue>  //generic type
struct QNode
{
    public:
        QNode* back;   //the next node
        
        TValue value;   // template value
        
        QNode(TValue val)
        {
            value = val;
            back = nullptr;
        }
};

template<class TValue>
struct Queue
{
    private:
        QNode<TValue>* first;   // the head node
        QNode<TValue>* last;
        
    public:
        Queue() : first(nullptr) {}
        
    public:
        void enqueue(TValue value)
        {
            QNode<TValue>* newNode = new QNode<TValue>(value);

            if(first == nullptr)
            {
                first = last = newNode;
                return;
            }

            last->back = newNode;
            last = newNode;
        }
        
        TValue dequeue()
        {
            if(last == nullptr)
            {
                std::cout<<"Dequeue error: return null cause Queue is empty"<<std::endl;
                return NULL;
            }

            QNode<TValue>* result = first;
            first = first->back;
            return result->value;
        }
        
        void clear()
        {
            first = nullptr;
            last = nullptr;
        }
        
        int count() const // ham la const, ko thay doi gia tri nao cua Queue ma chi lay count.
        {
            int cnt = 0;
            QNode<TValue>* current = first;
            while(current != nullptr)
            {
                current = current->back;
                cnt++;
            }
            
            return cnt;
        }
        
        
        void print()
        {
            if(first == nullptr)
            {
                std::cout << "Queue is Empty!" << std::endl;
                return;
            }
            QNode<TValue>* current = first;
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
    Queue<std::string> myQueue;

    myQueue.enqueue("i am lustied");
    myQueue.enqueue("wtf");
    myQueue.enqueue("hey babi");
    myQueue.enqueue("adu man");

    myQueue.print();

    auto dequeuedVal = myQueue.dequeue();
    auto dequeuedVal2 = myQueue.dequeue();
    
    print("deuqued: \"" + dequeuedVal + "\" and \"" + dequeuedVal2 + "\"");
    
    myQueue.print();

    print("finished");

    return 0;
}
