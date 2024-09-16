#include <stdio.h>
#include <iostream>

void test_linked_list_int();
void test_linked_list_string();

template<class TValue>  //generic type
struct LinkedNode
{
    public:
        LinkedNode* next;   //the next node
        
        TValue value;   // template value
        
        LinkedNode(TValue val)
        {
            this->value = val;
            next = nullptr;
        }
};

template<class TValue>
struct LinkedList
{
    private:
        LinkedNode<TValue>* head;   // the head node
        
    public:
        LinkedList() : head(nullptr) 
        {
            //std::cout << "Created a linked list, type = " << typeid(TValue).name() << std::endl;
            std::cout<<std::endl;
        }
        
    public:
        void add(TValue value)
        {
            LinkedNode<TValue>* newNode = new LinkedNode<TValue>(value);

            if(!initialized())
            {
                head = newNode;
                //std::cout << "first element is added to the head " << std::endl;
                return;
            }
            
            LinkedNode<TValue>* current = head;
            
            while(current->next != nullptr)
            {
                current = current->next;
            }
            
            current->next = newNode;
        }
        
        int indexof(TValue value)
        {
            int index = 0;
            LinkedNode<TValue>* current = head;
            
            while(current != nullptr && current->value != value)
            {
                current = current->next;
                index++;
            }
            
            return index;
        }
        
        void insertBefore(int index, TValue value)
        {
            if(index < 0)
            {
                std::cout<<"insert Before error: "index<< " is negative"<<std::endl;
                return;
            }
            
            if(index == 0)
            {
                LinkedNode<TValue>* newHead = new LinkedNode<TValue>(value);
                newHead->next = head;
                head = newHead;
                return;
            }
                
            LinkedNode<TValue>* current = head;
            LinkedNode<TValue>* last = nullptr;
            int i = 0;
            
            while(current != nullptr)
            {
                if(i == index)
                {
                    LinkedNode<TValue>* newNode = new LinkedNode<TValue>(value);
                    newNode->next = current;
                    last->next = newNode;
                    
                    return;
                }
                
                i++;
                current = current->next;
            }
        }
        
        void insertAfter(int index, TValue value)
        {
            if(index < 0)
            {
                std::cout<<"insert Before error: "index<< " is negative"<<std::endl;
                return;
            }
            
            if(index == 0)
            {
                LinkedNode<TValue>* newHead = new LinkedNode<TValue>(value);
                newHead->next = head;
                head = newHead;
                return;
            }
                
            LinkedNode<TValue>* current = head;
            int i = 0;
            
            while(current != nullptr)
            {
                if(i == index)
                {
                    LinkedNode<TValue>* newNode = new LinkedNode<TValue>(value);
                    newNode->next = current->next;
                    current->next = newNode;
                    
                    return;
                }
                
                i++;
                current = current->next;
            }
        }
        
        void replace(TValue oldVal, TValue newVal)
        {
            LinkedNode<TValue>* current = head;
            
            while(current != nullptr)
            {
                current = current->next;
                
                if(current->value == oldVal)
                {
                    current->value = newVal;
                    return;
                }
            }
            
            std::cout<<"replaceAt error: "<<oldVal<<" not found"<<std::endl;;
        }
        
        void replaceAt(int index, TValue value)
        {
            if(index < 0)
            {
                std::cout<<"replaceAt error: index "<<index<<" is out of range"<<std::endl;
                return;
            }
                
            int i = 0;
            LinkedNode<TValue>* current = head;
            
            while(current != nullptr)
            {
                current = current->next;
                i++;
                
                if(i == index)
                {
                    current->value = value;
                    return;
                }
            }
            
            std::cout<<"replaceAt error: index "<<index<<" is out of range"<<std::endl;;
        }
        
        bool remove(TValue value)   //remove first matched Tvalue
        {
            if(!initialized())
                return false;
                
            LinkedNode<TValue>* current = head;
            LinkedNode<TValue>* last = nullptr;
            
            while(current != nullptr)
            {
                if(current->value != value)
                {
                    current = current->next;
                    last = current;
                    continue;
                }
                
                if(last == nullptr)     // node to be removed is head
                {
                    head = current->next;
                    return true;
                }
                
                last->next = current->next;
                
                return true;
            }
            
            return false;
        }
        
        bool removeAt(int index)
        {
            if(!initialized())
                return false;
                
            if(index == 0)
            {
                head = head->next;
                return true;
            }
                
            LinkedNode<TValue>* current = head;
            LinkedNode<TValue>* last = nullptr;
            int i = 0;
            
            while(current != nullptr)
            {
                if(i == index)
                {
                    last->next = current->next;
                    
                    return true;
                }
                
                i++;
                current = current->next;
            }
            
            return false;
        }
        
        bool removeAll(TValue value)    //remove all matched Tvalue
        {
            if(!initialized())
                return false;
                
            LinkedNode<TValue>* current = head;
            LinkedNode<TValue>* last = nullptr;
            bool any = false;
            while(current != nullptr)
            {
                if(current->value != value)
                {
                    last = current;
                    current = current->next;
                    
                    continue;
                }            
                
                if(last == nullptr)     // node to be removed is head
                {
                    head = current->next;
                }
                else
                {
                    last->next = current->next;
                }
                current = current->next;
                    
                any = true;
            }
            
            return any;
        }
        
        void clear()
        {
            head = nullptr;
        }
        
        bool initialized()
        {
            return head != nullptr;
        }
        
        int count()
        {
            int cnt = 0;
            LinkedNode<TValue>* current = head;
            while(current != nullptr)
            {
                current = current->next;
                cnt++;
            }
            
            return cnt;
        }
        
        
        void print()
        {
            if(!initialized())
            {
                std::cout << "Linked List is Empty!" << std::endl;
                return;
            }
            int cnt = 0;
            LinkedNode<TValue>* current = head;
            while(current != nullptr)
            {
                cnt++;
                std::cout <<"("<< (current->value) << ") -> ";
                current = current->next;
            }
            
            std::cout << "null. ";
            std::cout << "(with count: " << cnt <<")" << std::endl;
        }
};


int main()
{
    test_linked_list_int();
    test_linked_list_string();
    
    std::cout<<"finished";

    return 0;
}

void test_linked_list_int()
{
    LinkedList<int> myLinkedList;
    
    myLinkedList.add(99);
    myLinkedList.add(200);
    
    myLinkedList.print();
    
    std::cout<<"index of 200 is: "<<myLinkedList.indexof(200)<<std::endl;
    
    myLinkedList.remove(99);
    myLinkedList.removeAt(0);
    
    std::cout<<"after remove(99) and removeAt(0)"<<std::endl;
    
    myLinkedList.print();
}

void test_linked_list_string()
{
    LinkedList<std::string> myLinkedList;
    
    myLinkedList.add("nah bro");
    myLinkedList.add("ah shiet");
    myLinkedList.add("ngu vcl");
    myLinkedList.add("nah bro");
    myLinkedList.print();
    
    std::cout<<"after remove all \"nah bro\" "<<std::endl;
    
    myLinkedList.removeAll("nah bro");
    myLinkedList.print();
    
    std::cout<<"inserting"<<std::endl;
    
    myLinkedList.insertBefore(0, "breforegay");
    myLinkedList.insertAfter(1, "aftergay");
    myLinkedList.print();
    
    std::cout<<"replacing"<<std::endl;
    
    myLinkedList.replace("ah shiet", "shitt");
    myLinkedList.replaceAt(3, "urgay");
    myLinkedList.replaceAt(5, "urnotgay");
    myLinkedList.print();
}
