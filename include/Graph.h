#pragma once

#include <unordered_map>
#include <vector>
#include <string>

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

private:
    std::vector<std::string> names;              // index -> city
    std::unordered_map<std::string, int> index;  // city -> index
    std::vector<std::vector<Edge>> adj;          // adj[u] = edges leaving u
};
