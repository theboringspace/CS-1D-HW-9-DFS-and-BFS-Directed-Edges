#include <iostream>

#include "Graph.h"

using namespace std;

int main()
{
    Graph g;

    const string cities[] = {
        "Seattle", "San Francisco", "Los Angeles", "Denver",
        "Kansas City", "Chicago", "Boston", "New York",
        "Atlanta", "Miami", "Dallas", "Houston"
    };
    for (const string& c : cities)
        g.addVertex(c);

    // Directed edges: from -> to, miles
    g.addEdge("Seattle",       "San Francisco",  807);
    g.addEdge("Seattle",       "Denver",        1331);
    g.addEdge("San Francisco", "Los Angeles",    381);
    g.addEdge("Los Angeles",   "Denver",        1015);
    g.addEdge("Denver",        "San Francisco", 1267);
    g.addEdge("Denver",        "Chicago",       1003);
    g.addEdge("Kansas City",   "Denver",         599);
    g.addEdge("Kansas City",   "Chicago",        533);
    g.addEdge("Kansas City",   "Los Angeles",   1663);
    g.addEdge("Kansas City",   "New York",      1260);
    g.addEdge("Kansas City",   "Atlanta",        864);
    g.addEdge("Chicago",       "Seattle",       2097);
    g.addEdge("Chicago",       "Boston",         983);
    g.addEdge("Boston",        "New York",       214);
    g.addEdge("New York",      "Chicago",        787);
    g.addEdge("New York",      "Atlanta",        888);
    g.addEdge("Dallas",        "Kansas City",    496);
    g.addEdge("Dallas",        "Los Angeles",   1435);
    g.addEdge("Dallas",        "Atlanta",        781);
    g.addEdge("Atlanta",       "Houston",        810);
    g.addEdge("Atlanta",       "Miami",          661);
    g.addEdge("Houston",       "Dallas",         239);
    g.addEdge("Miami",         "Houston",       1187);

    g.print();

    return 0;
}
