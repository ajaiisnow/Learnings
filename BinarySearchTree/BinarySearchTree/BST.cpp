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
        parent = 0;
    } 
    virtual ~Node_t()
    {
        left = 0;
        right = 0;
        parent = 0;
        value = 0;
        height = 0;
    }

    Node_t* left;
    Node_t* right;
    Node_t* parent;
    int     value;
    int     height;
}Node;


Node* Insert_BST_1(Node* tree, int value)
{
    if (tree == 0)
    {
        tree = new Node(value);
    }
    if (value > tree->value)
    {
        tree->right = Insert_BST_1(tree->right, value );
        tree->right->parent = tree;
    }
    else if (value < tree->value)
    {
        tree->left = Insert_BST_1( tree->left, value);
        tree->left->parent = tree;
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

int Search_height(Node*& Tree, int item)
{
    if( Tree == 0 ) return -1;
    if(item == Tree->value)
    {
        return 0;
    }
    if (item > Tree->value)
    {
        return Search_height( Tree->right, item)+1;
    }
    else if (item < Tree->value)
    {
        return Search_height( Tree->left, item )+1;
    }

}

Node* Search(Node*& BST, int item)
{
    if( BST == 0 ) return 0;
    else if( item == BST->value) return BST;
    else if( item  > BST->value ) return Search( BST->right, item );
    return Search( BST->left, item);
}
Node* SearchCommonFather(Node* BST, int val1, int val2)
{
    if( BST == 0) return 0;
    if( BST->value == val2 || BST->value == val1) return BST;
    Node* left_parent = SearchCommonFather( BST->left, val1, val2);
    Node* right_parent = SearchCommonFather( BST->right, val1, val2 );
    if( 0 != left_parent && 0 != right_parent ) return  BST;
    if (0 != left_parent )
    {
       return left_parent;
    }
    else if (0 != right_parent)
    {
        return right_parent;
    }
}

int HeigthDifferenceOfNode(Node*& BST, int item1, int item2)
{
   int height_item1 = Search_height( BST, item1 );
   int height_item2 = Search_height( BST, item2 );
   //int height_common_parent  = 
   return (height_item1 + height_item2);
}
void CleanUpTree( Node*& BST)
{
    if (0 == BST) return; 
    CleanUpTree(BST->left);
    delete BST->left;
    CleanUpTree( BST->right );
    delete BST->right;
}

//vector<int> TreeValues{6,4,5,2,1,3,18,15,16,27};
//vector<int> TreeValues2{ 11,5,3,4,2,1,6,7,15,14,12,17 };
//int main()
//{
//    Node* bst_tree = 0;
//    vector<int>::iterator itrBegin = TreeValues2.begin();
//    vector<int>::iterator itrEnd = TreeValues2.end();
//    while( itrBegin != itrEnd )
//    {
//        Insert_BST_2(bst_tree, *itrBegin);
//        ++itrBegin;
//    }
//    Node* node1 = Search(bst_tree, 1);
//    Node* node2 = Search(bst_tree, 4);
//
//    Node* nodeParent = SearchCommonFather( bst_tree, node1->value, node2->value);
//    int path_length = HeigthDifferenceOfNode(bst_tree, node1->value, node2->value) - 2* Search_height( bst_tree, nodeParent->value );
//
//   cout << "Height Differnece between nodes:" << path_length <<endl;
//
//   CleanUpTree( bst_tree );
//   delete bst_tree;
//   TreeValues.clear();
//    getchar();
//    return 0;
//}