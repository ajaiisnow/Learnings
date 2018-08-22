#include<iostream>
#include <vector>
using namespace std;

typedef struct Node_T
{
    Node_T() : next(0) {}
    int value;
    Node_T* next;
}Node;


class SinglyLinkedList
{
private:
    Node* m_pHead;
    Node* m_pTail;

public:
    SinglyLinkedList() : m_pHead(0), m_pTail(0){};
    ~SinglyLinkedList()
    {
        Node* pCurr = m_pHead;
        Node* pPrev = m_pHead;
        while (pCurr != 0)
        {
            pPrev = pCurr;
            pCurr = pCurr->next;
            delete pPrev;
        }
    }
    void AddNode(int value)
    {
       Node* pNew = new Node();
       pNew->value = value;
       pNew->next = 0;

       if (m_pHead == 0)
        {
           m_pHead = pNew;
           m_pTail = pNew;
        }
        else
        {
            m_pTail->next = pNew;
            m_pTail = m_pTail->next;
        }
    }

    void Display()
    {
        cout <<  "Linked List is" << endl;
        Node* pCurr = m_pHead;
        while (pCurr != 0)
        {
            cout << pCurr->value << "    ";
            pCurr = pCurr->next;
        }
    }

    void Reversal()
    {
        vector<Node*> link_vector;
        Node* pCurr = m_pHead;
        Node* temp = 0;
        Node* prev = 0;

        while (pCurr != 0)
        {
            temp = pCurr->next;
            pCurr->next = prev;
            prev = pCurr;
            pCurr = temp;
        }
        m_pHead = prev;
    }
};

int main()
{
    SinglyLinkedList obj;
    obj.AddNode(1);
    obj.AddNode(2);
    obj.AddNode(3);
    obj.AddNode(4);
    obj.Display();

    obj.Reversal();
    cout << endl << "Reversed" << endl;
    obj.Display();
    return 0;
}

