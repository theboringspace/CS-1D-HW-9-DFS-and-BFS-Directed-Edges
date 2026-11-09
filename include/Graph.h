#pragma once

#include <unordered_map>
#include <vector>
#include <string>

/// Classification of an edge during a traversal.
enum class EdgeLabel
{
    UNEXPLORED, ///< Not yet examined from either endpoint.
    DISCOVERY,  ///< Led to an unvisited city; part of the BFS tree.
    CROSS       ///< Connected to an already-visited city; not part of the tree.
};

struct Edge
{
    int to;
    int weight;
};

class Graph
{
public:
    int addVertex(const std::string& name);      // returns its index
    void addEdge(const std::string& from, const std::string& to, int w);
    void print() const;

    int indexOf(const std::string& name) const;  // throws if unknown
    int vertexCount() const { return static_cast<int>(names.size()); }

    void dfs();

private:
    std::vector<std::string> names;              // index -> city
    std::unordered_map<std::string, int> index;  // city -> index
    std::vector<std::vector<Edge>> adj;          // adj[u] = edges leaving u
};
