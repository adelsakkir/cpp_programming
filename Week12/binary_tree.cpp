#include <iostream>
#include <memory>
using namespace std;

class Node{
    public:
        int item;
        
        shared_ptr<Node> lc;
        shared_ptr<Node> rc;
        weak_ptr<Node> p;

        Node(int x): item(x) {};
        ~Node(){cout<<"~Node("<<item<<")"<< endl;};

};

int main(){
    shared_ptr<Node> root = make_shared<Node>(2); // root is a pointer to root node
    root->lc = make_shared<Node>(1);
    root->rc = make_shared<Node>(3);

    root->lc->p = root;
    root->rc->p = root;

    cout<< (*root).item << endl;


    // root.rc = make_unique<Node>(Node(11));
    // root.p(nullptr);
}