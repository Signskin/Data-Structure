#include<iostream>
#include<cstring>
using namespace std;
using Item = unsigned long;
class Stack
{
    private:
        static const int MAX = 10;
        Item *pitems;
        int size;
        int top;
    public:
        Stack(int n = MAX);
        Stack(const Stack& st);
        ~Stack();

        bool isempty() const;
        bool isfull() const;
        bool push(const Item& item);
        bool pop(Item& item);

        Stack& operator=(const Stack & st);
};
Stack::Stack(int n):size(n), top(0)
{
    pitems = new Item[size];
}
Stack::Stack(const Stack& st):size(st.size), top(st.top)
{
    pitems = new Item[size];
    memcpy(pitems, st.pitems, top*sizeof(Item));
}
Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return !top;
}
bool Stack::isfull() const 
{
    return top == size;
}
bool Stack::push(const Item& item)
{
    if(top == size) return false;
    *(pitems + (top++)) = item;
    return true;
}
bool Stack::pop(Item& item)
{
    if(!top) return false;
    item = *(pitems + (--top));
    return true;
}
Stack& Stack::operator=(const Stack& st)
{
    if(&st == this) return *this;
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    memcpy(pitems, st.pitems, top*sizeof(Item));
    return *this;
}
int main()
{
    Stack st;
    char ch;
    Item po;
    cout<<"Please enter A to add a purchase order.\nP to process a PO, or Q to quit.\n";
    while(cin >> ch and ch!='Q')
    {
        while(cin.get() != '\n') continue;
        if(!isalpha(ch))
        {
            cout<<'\a';continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a':
                cout<<"Enter a PO number to add:\n";
                cin>>po;
                if(st.isfull())
                    cout<<"stack already full\n";
                else 
                    st.push(po);
                break;
            case 'p':
            case 'P':
                if(st.isempty())
                    cout<<"stack already empty\n";
                else
                {
                    st.pop(po);
                    cout<<"PO #"<<po<<" popped\n";
                }
                break;
        }
        cout<<"Please enter A to add a purchase order.\nP to process a PO, or Q to quit.\n";
    }
    cout<<"Bye\n";
    return 0;
}