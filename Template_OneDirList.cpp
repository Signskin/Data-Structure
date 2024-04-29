#include<iostream>
using namespace std;
template <typename T>
class List
{
    typedef size_t rank;
    private:
        struct Node
        {
            T data;
            Node *next;
        };
        Node *head;
        Node *tail;
        rank Size;

    public:
        List() : head(NULL), tail(NULL), Size(0){}
        ~List()
        {
            auto Cur = head;
            auto Lst = head;
            while(Cur != NULL)
            {
                Lst = Cur;
                Cur = Cur -> next;
                delete Lst;
            }
        }
        void push(T data)
        {
            auto Temp = new Node;
            Temp->data = data;
            Temp->next = NULL;
            if(Size == 0)
            {
                head = tail = Temp;
            }
            else
            {
                tail->next = Temp;
                tail = Temp;
            }
            ++Size;
            return;
        }
        void remove(rank r)
        {
            if(r == 1)
            {
                auto Temp = head;
                head = head->next;
                tail = head;
                delete Temp;
                return;
            }
            if(r > Size) return;
            auto Iter = head;
            auto backup = r;
            while(Iter->next != NULL and --backup > 1) Iter = Iter->next;
            auto Temp = Iter -> next;
            Iter->next = Temp -> next;
            delete Temp;
            if(r == Size) tail = Iter;
            Size--;
            return;
        }
        void insert(T data, rank r)
        {
            if(r == Size)
            {
                push(data);
                return;
            }
            auto Temp = new Node;
            Temp->data = data;
            Temp->next = NULL;
            if(r == 0)
            {  
                Temp->next = head;
                head = Temp;
                return;
            }
            auto Iter = head;
            while(Iter->next != NULL and --r) Iter = Iter->next;
            Temp->next = Iter-> next;
            Iter->next = Temp;
            Size++;
            return;
        }
        void print() const
        {
            auto Iter = head;
            while(Iter != NULL)
            {
                cout<<Iter->data<<" ";
                Iter = Iter->next;
            }
            cout<<endl;
            return;
        }
        T at(rank r)
        {
            // If you try to visit an invalid rank, it will return a default object
            if(r > Size) return T();
            auto Iter = head;
            while(Iter->next != NULL and --r) Iter = Iter -> next;
            return Iter->data;
        }
        rank size() const {return Size;}
};

template <typename T>
class lessList
{
    typedef size_t rank;
    private:
        struct Node
        {
            T data;
            Node *next;
        };
        Node *head;
        rank Size;

    public:
        lessList():head(NULL), Size(0){}
        ~lessList()
        {
            auto Cur = head;
            auto Lst = head;
            while(Cur != NULL)
            {
                Lst = Cur;
                Cur = Cur -> next;
                delete Lst;
            }
        }
        void insert(T data)
        {
            auto Temp = new Node;
            Temp->data = data;
            Temp->next = NULL;
            if(Size == 0)
            {
                head = Temp;
                ++Size;
                return;
            }
            if(Size == 1)
            {
                if(data < head->data)
                {
                    Temp -> next = head -> next;
                    head = Temp;
                    ++Size;
                    return;
                }
                else
                {
                    head -> next = Temp;
                    ++Size;
                    return;
                }
            }
            auto Iter = head;
            while(Iter != NULL and Iter->next != NULL and data > Iter->next->data) Iter = Iter -> next;
            Temp->next = Iter->next;
            Iter->next = Temp;
            ++Size;
        }
        void remove(rank r)
        {
            if(r == 1)
            {
                auto Temp = head;
                head = head->next;
                delete Temp;
                return;
            }
            if(r > Size) return;
            auto Iter = head;
            while(Iter->next != NULL and --r > 1) Iter = Iter->next;
            auto Temp = Iter -> next;
            Iter->next = Temp -> next;
            delete Temp;
            Size--;
            return;
        }
        void print() const
        {
            auto Iter = head;
            while(Iter != NULL)
            {
                cout<<Iter->data<<" ";
                Iter = Iter->next;
            }
            cout<<endl;
            return;
        }
        T at(rank r)
        {
            // If you try to visit an invalid rank, it will return a default object
            if(r > Size) return T();
            auto Iter = head;
            while(Iter->next != NULL and --r) Iter = Iter -> next;
            return Iter->data;
        }
        rank size() const {return Size;}
};

int main()
{
    List<int> Obj;
    Obj.print();
    Obj.push(1);
    Obj.push(2);
    Obj.push(3);
    Obj.print();
    Obj.remove(3);
    Obj.print();
    Obj.push(4);
    Obj.print();
    cout<<Obj.size()<<endl;
    cout<<Obj.at(2)<<endl;
    return 0;
}