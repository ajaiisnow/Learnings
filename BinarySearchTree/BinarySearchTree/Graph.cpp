#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


class Graph_Matrix
{
private:
    int **m_pMat;
    int m_nodes;

public:
    Graph_Matrix(int nNodes)
    {
        m_pMat = new int*[nNodes];
        for (int i = 0; i < nNodes; i++)
        {
            m_pMat[i] = new int[nNodes];
            memset(m_pMat[i], 0, sizeof(int)*nNodes );
        }
        m_nodes = nNodes;
    }

    virtual ~Graph_Matrix()
    {
        for(int i = 0; i < m_nodes; i++)
        {
            delete[] m_pMat[i];
        }
        delete[] m_pMat;
    }

    void AddEdges(int edge_start, int edge_end)
    {
        if (edge_start < m_nodes && edge_end < m_nodes)
        {
            m_pMat[edge_start][edge_end] = 1;
        }
        else
            throw invalid_argument("Edges refered are out of bound");
    }

    void DisplayGraph()
    {
        for (int i = 0; i < m_nodes; i++)
        {
            for (int j = 0; j < m_nodes; j++)
            {
                cout << m_pMat[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void DFS( int traversal_start_node)
    {
        bool* visited_nodes = new bool[m_nodes];
        memset(visited_nodes, false, m_nodes);
        DFS_Traversal(traversal_start_node, visited_nodes);
    }

    void BFS( int traversal_start_node )
    {
        bool* visited_nodes = new bool[m_nodes];
        memset(visited_nodes, false, m_nodes);
        vector<int> Nodes;
        Nodes.push_back(traversal_start_node);
        BFS_Traversal(Nodes, visited_nodes);
    }

private:
    void DFS_Traversal(int start_node, bool* visited_nodes)
    {
        if (visited_nodes[start_node] == false )
        {
            visited_nodes[start_node] = true;
            cout << "  " << start_node;
            for (int i = 0; i < m_nodes; i++)
            {
                if (visited_nodes[i] == false && 1 == m_pMat[start_node][i])
                {
                    DFS_Traversal(i, visited_nodes);
                }
            }
        }
        return;
    }

    void BFS_Traversal(vector<int>& Nodes, bool* visited_nodes)
    {
        if (Nodes.empty())
        {
            return;
        }

        int start_node = Nodes.back();
        Nodes.pop_back();
        for(int i = 0; i < m_nodes; i++)
        {
            if (visited_nodes[i] == false && 1 == m_pMat[start_node][i])
            {
                cout << "   " << i;
                visited_nodes[i] = true;
                Nodes.push_back(i);
            }
        }
        BFS_Traversal(Nodes, visited_nodes);
    }
};


int main(int argc, char* argv[])
{
    /*Graph_Matrix myGraph(4);
    myGraph.AddEdges(0, 2);
    myGraph.AddEdges(0, 1);
    myGraph.AddEdges(2, 0);
    myGraph.AddEdges(1, 3);
    myGraph.AddEdges(1, 2);
    myGraph.AddEdges(3, 2);*/

    Graph_Matrix myGraph(6);
    myGraph.AddEdges(0, 1);
    myGraph.AddEdges(0, 2);
    myGraph.AddEdges(1, 3);
    myGraph.AddEdges(1, 4);
    myGraph.AddEdges(3, 5);
    myGraph.AddEdges(5, 4);
    myGraph.AddEdges(2, 3);

    myGraph.DisplayGraph();
    //BFS
    myGraph.BFS(0);

    return 0;
}