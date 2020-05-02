#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outsode those statements
// template <typename vertex>
class Graph
{
private:
    size_t size = 0;
    struct vertexNode
    {
        string V;
        vector<double> weight;
        vector<string> adjacentVertices;
        // BinaryHeap<double> newheap =
        BinaryHeap<double> newHeap(vector<double> &a);
    };

    vector<vertexNode> allNodes;

public:
    Graph(std::string filename)
    {
        std::fstream fin;                 // instantiates a filestream variable
        fin.open(filename, std::ios::in); // assigns to it the content of the maze file
        if (fin.fail())
        {
            std::cout << "File cannot be opened." << std::endl;
            return;
        }

        std::string temp, line;
        getline(fin, line);

        size = std::stoi(line);
        // cout << "size is: " << size;

        while (getline(fin, line))
        {

            vertexNode newNode;
            std::stringstream ss_qualifier(line);
            newNode.V = line[0];
            // cout << "new Node is: " << line[0] << endl;
            getline(ss_qualifier, temp, ' ');
            int i = 0;
            while (getline(ss_qualifier, temp, ' '))
            {
                // getline(ss_qualifier, temp, ' ');
                newNode.adjacentVertices.push_back(temp);
                // i++;
                // cout << " pushed back :" << temp << endl;
                getline(ss_qualifier, temp, ' ');
                newNode.weight.push_back(std::stod(temp));
                // cout << " weight : " << temp << endl;
            }
            newNode.newHeap(newNode.weight);
            allNodes.push_back(newNode);
        }

        // BinaryHeap<vertexNode> newHeap = BinaryHeap<vertexNode>(allNodes);
    }

    vector<vertexNode> getNodes()
    {
        return allNodes;
    }

    size_t getSize()
    {
        return size;
    }

    double getCost(string a, string b)
    {
        for (int i = 0; i < getNodeFromString(a).adjacentVertices.size(); i++)
        {
            // cout << "cost from" << a << "to " << getNodeFromString(a).adjacentVertices[i] << " is:" << getNodeFromString(a).weight[i];
            if (getNodeFromString(a).adjacentVertices[i] == b)
            {

                return getNodeFromString(a).weight[i];
            }
        }
        return 0;
    }
    bool isConnected(string a, string b)
    {
        for (int i = 0; i < getNodeFromString(a).adjacentVertices.size(); i++)
        {
            if (getNodeFromString(a).adjacentVertices[i] == b)
            {
                return true;
            }
        }
        return false;
    }

    vertexNode getNodeFromString(string b)
    {

        try
        {

            for (int j = 0; j < allNodes.size(); j++)
            {
                if (allNodes[j].V == b)
                {
                    return allNodes[j];
                }
            }
        }
        catch (IllegalArgumentException)
        {
            cout << "IllegalArgumentException" << endl;
        }
    }

    void showList()
    {
        cout << "list of nodes :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "cost from " << allNodes[i].V << " to " << endl;
            for (int j = 0; j < allNodes[i].adjacentVertices.size(); j++)
            {
                cout << allNodes[i].adjacentVertices[j] << " is: " << allNodes[i].weight[j] << endl;
            }
        }
    }
    // friend::ostream &operator<<(std::ostream &out,const vertexNode & aNode)
    // {
    //     if()
    // }
};

#endif
