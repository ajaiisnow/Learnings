#include <iostream>
#include <vector>
using namespace std;
typedef struct Node_t
{
public:
    Node_t( int val)
    {
        left = 0;
        right = 0;
        value = val;
        height = 0;
    } 
    virtual ~Node_t(){}

    Node_t* left;
    Node_t* right;
    int     value;
    int     height;
}Node;


Node* Insert_BST_1(Node*& tree, int value)
{
    if (tree == 0)
    {
        tree = new Node(value);
    }
    if (value > tree->value)
    {
        tree->right = Insert_BST_1(tree->right, value );
    }
    else if (value < tree->value)
    {
        tree->left = Insert_BST_1( tree->left, value);
    }
    return tree;
}

void Insert_BST_2(Node*& tree, int value)
{
    if (tree == 0)
    {
        tree = new Node(value);
    }
    if (value > tree->value)
    {
        Insert_BST_2(tree->right, value);
    }
    else if (value < tree->value)
    {
        Insert_BST_2(tree->left, value);
    }
}

int Search(Node*& Tree, int item)
{
    if( Tree == 0 ) return -1;
    if(item == Tree->value)
    {
        return 0;
    }
    if (item > Tree->value)
    {
        return Search( Tree->right, item)+1;
    }
    else if (item < Tree->value)
    {
        return Search( Tree->left, item )+1;
    }

}

int HeigthDifferenceOfNode(Node*& BST, int item1, int item2)
{
    return ( Search(BST, item1) + Search(BST, item2 ));
}

vector<int> TreeValues= {5,4,2,1,3,18,15,16,27};
int main()
{
    Node* bst_tree = 0;
    vector<int>::iterator itrBegin = TreeValues.begin();
    vector<int>::iterator itrEnd = TreeValues.end();
    while( itrBegin != itrEnd )
    {
        Insert_BST_2(bst_tree, *itrBegin);
        ++itrBegin;
    }

    int Height = HeigthDifferenceOfNode( bst_tree, 3, 16);
    cout << "Height Differnece between nodes:" << Height <<endl;

    getchar();
    return 0;
}