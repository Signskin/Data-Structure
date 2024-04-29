#include "BinNode.cpp"
using namespace std;
#define BN BinNode<T>

template <typename T>
class BinTree
{
    protected:
        int _size;
        BN* _root;
        virtual int updateHeight(BinNode* x) // Update the Height of x
        {
            return x.Height(1 + max(stature(x->Left()) , stature(x->Right())));
        }
        void updateHeightAbove(BinNode* x) // Update the Height of x and its parent
        {
            while(x != NULL)
            {
                updateHeight(x);
                x = x->Parent();
            }
        }  
    public:
        BinTree() : _size(0), _root(NULL) {};
        ~BinTree() {if(0 < _size) remove(_root);}
        int size() const {return _size;}
        bool empty() const {return !_root;}
        BN* root() {return _root;}
        BN* This()
        {  
            return *this;
        }
        BN* insertAsRoot(T const& e)
        {
            if(_size != 0) return _root;
            return _root = new BinNode*(e);
        }
        BN* insertAsLC(BN* x, T const& e)
        {
            ++_size;
            x->insertAsLC(e);
            updateHeightAbove(x);
            return x->Left();
        }
        BN* insertAsRC(BN* x, T const& e)
        {
            ++_size;
            x->insertAsRC(e);
            updateHeightAbove(x);
            return x->Right();
        }
        BN* attachAsLC(BN* x, BN* t)
        {
            
        }
        BN* attachAsRC(BN* x, BN* t)
        {

        }
        int remove(BN* x)
        {

        }
        BN* secede(BN* x)
        {

        }
        template <typename VST> void IterLevel (VST&) // Iterate by level
        {

        }
        template <typename VST> void IterPre (VST&) // Iterate by Pre-root order
        {

        }
        template <typename VST> void IterMid (VST&) // Iterate by Mid-root order
        {

        }
        template <typename VST> void IterPost(VST&) // Iterate by Post-root order
        {

        }

        
};