#include<compare>
using namespace std;
#ifndef NULL
    #define NULL 0
#endif

#define stature(p) ((p) ? (p)->height() : -1)

template <typename T>
class BinNode
{
    private:
        T data; //Value
        BinNode* LC; //Left Child
        BinNode* RC; //Right Child
        BinNode* PR; //Parent
        int height; //Height

    public:
        BinNode(): LC(NULL),RC(NULL),PR(NULL), height(0){}
        BinNode(T e, T* PR = NULL, T* LC = NULL, T* RC = NULL, T* height = 0):data(e), PR(PR), LC(LC), RC(RC){}

        T value() const {return data;}
        const T value(int) const {return data;}
        void setValue(const T& val) {data = val;}

        int Height(int c = -1)
        {
            if(c == -1) return height;
            return height = c;
        }

        BinNode* Left(T* M = NULL)
        {
            T* Temp = LC;
            if(M != NULL) LC = M;
            return Temp;
        }
        const BinNode* Left() const
        {
            return LC;
        }

        BinNode* Right(T* M = NULL)
        {
            T* Temp = RC;
            if(M != NULL) RC = M;
            return Temp;
        }
        const BinNode* Right() const
        {
            return RC;
        }
        
        BinNode* Parent() const
        {
            return PR;
        }

        bool isLeaf() const
        {
            return LC == NULL and RC == NULL;
        }
        
        bool isRoot() const
        {
            return PR == NULL;
        }

        bool isLC() const
        {
            return PR != NULL and (this == this->PR->LC);
        }

        bool isRC() const
        {
            return PR != NULL and (this == this->PR->RC);
        }

        bool hasLC() const
        {
            return LC != NULL;
        }
    
        bool hasRC() const
        {
            return RC != NULL;
        }

        bool hasChild() const
        {
            return LC != NULL or RC != NULL;
        }

        bool hasBothChild() const
        {
            return LC != NULL and RC != NULL;
        }

        BinNode* sibling()
        {
            return isLC() ? this->PR->RC : this->PR->LC;
        }

        BinNode* uncle()
        {
            return this->PR->isLC() ? this->PR->PR->RC : this->PR->PR->LC;
        }

        BinNode* This()
        {
            return *this;
        }

        BinNode* insertAsLC(T const&);

        BinNode* insertAsRC(T const&);
        
        BinNode* succ(); //Direct successor, well defined in BST 

        BinNode* attachAsLC(BinNode* &t);
        
        BinNode* attachAsRC(BinNode* &t);

        template <typename VST> void IterLevel (VST&); // Iterate by level
        template <typename VST> void IterPre (VST&); // Iterate by Pre-root order
        template <typename VST> void IterMid (VST&); // Iterate by Mid-root order
        template <typename VST> void IterPost(VST&); // Iterate by Post-root order

        friend auto operator<=>(const BinNode& a, const BinNode& b)
        {
            return a.data <=> b.data;
        }
        friend auto operator<=>(const BinNode& a, const T& b)
        {
            return a.data <=> b;
        }
        friend auto operator<=>(const T& a, const BinNode& b)
        {
            return a <=> b.data;
        }
};

template <typename T> 
BinNode<T>* BinNode<T>::insertAsLC(T const& e)
{
    if(LC != NULL) return NULL;
    return LC = new BinNode(e, this);
}

template <typename T>
BinNode<T>* BinNode<T>::insertAsRC(T const& e)
{
    if(RC != NULL) return NULL;
    return RC = new BinNode(e, this);
}

template <typename T>
BinNode<T>* BinNode<T>::attachAsLC(BinNode* &t)
{
    if(LC != NULL) return NULL;
    return LC = t;
}

template <typename T>
BinNode<T>* BinNode<T>::attachAsRC(BinNode* &t)
{
    if(RC != NULL) return NULL;
    return RC = t;
}
