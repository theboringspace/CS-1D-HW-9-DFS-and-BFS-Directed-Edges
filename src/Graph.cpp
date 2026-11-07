#include "Graph.h"

#include <iostream>
#include <stdexcept>

void Graph::dfs()
{
    std::cout << "We are dfs'ing it gang.";
}

// Adds a city if it isn't already present; returns its index either way.
int Graph::addVertex(const std::string& name)
{
    auto it = index.find(name);
    if (it != index.end())
        return it->second;

    int id = static_cast<int>(names.size());
    names.push_back(name);
    index[name] = id;
    adj.emplace_back();
    return id;
}

// Looks up a city's index. Throws so a misspelled name fails loudly.
int Graph::indexOf(const std::string& name) const
{
    auto it = index.find(name);
    if (it == index.end())
        throw std::out_of_range("Unknown city: " + name);
    return it->second;
}

// Adds a one-way edge from -> to. Both cities must already exist.
void Graph::addEdge(const std::string& from, const std::string& to, int w)
{
    int u = indexOf(from);
    int v = indexOf(to);
    adj[u].push_back({v, w});
}

// Lists every city followed by its outgoing edges and their weights.
void Graph::print() const
{
    for (int u = 0; u < vertexCount(); ++u)
    {
        std::cout << names[u] << " (" << adj[u].size() << " outgoing)\n";
        if (adj[u].empty())
            std::cout << "    (none)\n";
        for (const Edge& e : adj[u])
            std::cout << "    -> " << names[e.to] << ", " << e.weight << " mi\n";
    }
}
