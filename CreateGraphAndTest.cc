#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv)
{

    //Begin your code here. Feel free to add any helper functions or classes you need,
    //as long as we only have to call this function to run the specified assignment.
    string GRAPH_FILE = argv[1];
    string ADJACENCY_QUERYFILE = argv[2];

    Graph newGraph(GRAPH_FILE);
    ifstream in(ADJACENCY_QUERYFILE);
    string line, vertexA, vertexB;

    while (getline(in, line))
    {
        stringstream temp(line);
        string temp2;
        while (getline(temp, temp2, ' '))
        {
            vertexA = temp2;
            getline(temp, temp2, ' ');
            vertexB = temp2;
        }
        if (newGraph.isConnected(vertexA, vertexB))
        {
            cout << vertexA << ' ' << vertexB << ": connected " << newGraph.getCost(vertexA, vertexB) << endl;
        }
        else
        {
            cout << vertexA << ' ' << vertexB << ": not_connected " << endl;
        }
    }

    // newGraph.showList();

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <GRAPH_File>"
             << "<ADJACENCY_QUERYFILE>" << endl;
        return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}