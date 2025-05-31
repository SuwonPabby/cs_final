#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

// 인접 리스트를 사용한 그래프
class Graph {
private:
  std::vector<std::vector<int>> mAdjList;
  bool mIsDirected;
  int mVertices;

public:
  // Constructor
  Graph(int vertices, bool isDirected = false)
      : mIsDirected(isDirected), mVertices(vertices) {
    mAdjList.resize(vertices);
  }

  // Add edge
  void addEdge(int from, int to) {
    if (from >= 0 && from < mVertices && to >= 0 && to < mVertices) {
      mAdjList[from].push_back(to);
      if (!mIsDirected) {
        mAdjList[to].push_back(from);
      }
    }
  }

  // Remove edge
  void removeEdge(int from, int to) {
    if (from >= 0 && from < mVertices && to >= 0 && to < mVertices) {
      auto &edges = mAdjList[from];
      edges.erase(std::remove(edges.begin(), edges.end(), to), edges.end());

      if (!mIsDirected) {
        auto &reverseEdges = mAdjList[to];
        reverseEdges.erase(
            std::remove(reverseEdges.begin(), reverseEdges.end(), from),
            reverseEdges.end());
      }
    }
  }

  // Check if edge exists
  bool hasEdge(int from, int to) const {
    if (from >= 0 && from < mVertices && to >= 0 && to < mVertices) {
      const auto &edges = mAdjList[from];
      return std::find(edges.begin(), edges.end(), to) != edges.end();
    }
    return false;
  }

  // BFS traversal (시험에서 자주 출제)
  void BFS(int start) const {
    if (start < 0 || start >= mVertices)
      return;

    std::vector<bool> visited(mVertices, false);
    std::queue<int> q;

    std::cout << "BFS traversal starting from " << start << ": ";

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int current = q.front();
      q.pop();
      std::cout << current << " ";

      for (int neighbor : mAdjList[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    std::cout << std::endl;
  }

  // DFS traversal (시험에서 자주 출제)
  void DFS(int start) const {
    if (start < 0 || start >= mVertices)
      return;

    std::vector<bool> visited(mVertices, false);
    std::cout << "DFS traversal starting from " << start << ": ";
    DFSHelper(start, visited);
    std::cout << std::endl;
  }

  // DFS using stack (iterative)
  void DFSIterative(int start) const {
    if (start < 0 || start >= mVertices)
      return;

    std::vector<bool> visited(mVertices, false);
    std::stack<int> s;

    std::cout << "DFS (iterative) traversal starting from " << start << ": ";

    s.push(start);

    while (!s.empty()) {
      int current = s.top();
      s.pop();

      if (!visited[current]) {
        visited[current] = true;
        std::cout << current << " ";

        // 역순으로 추가하여 작은 번호부터 방문하도록 함
        for (auto it = mAdjList[current].rbegin();
             it != mAdjList[current].rend(); ++it) {
          if (!visited[*it]) {
            s.push(*it);
          }
        }
      }
    }
    std::cout << std::endl;
  }

  // Check if graph is connected (무방향 그래프용)
  bool isConnected() const {
    if (mIsDirected)
      return false; // 방향 그래프는 강연결성 체크가 복잡함

    std::vector<bool> visited(mVertices, false);
    DFSHelper(0, visited);

    for (bool v : visited) {
      if (!v)
        return false;
    }
    return true;
  }

  // Detect cycle in undirected graph
  bool hasCycleUndirected() const {
    if (mIsDirected)
      return false;

    std::vector<bool> visited(mVertices, false);

    for (int i = 0; i < mVertices; ++i) {
      if (!visited[i]) {
        if (hasCycleUndirectedHelper(i, -1, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  // Detect cycle in directed graph
  bool hasCycleDirected() const {
    if (!mIsDirected)
      return false;

    std::vector<int> color(mVertices, 0); // 0: white, 1: gray, 2: black

    for (int i = 0; i < mVertices; ++i) {
      if (color[i] == 0) {
        if (hasCycleDirectedHelper(i, color)) {
          return true;
        }
      }
    }
    return false;
  }

  // Print graph
  void printGraph() const {
    std::cout << "Graph (vertices=" << mVertices << ", directed=" << mIsDirected
              << "):" << std::endl;
    for (int i = 0; i < mVertices; ++i) {
      std::cout << i << ": ";
      for (int neighbor : mAdjList[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  // Get number of vertices
  int getVertices() const { return mVertices; }

private:
  void DFSHelper(int vertex, std::vector<bool> &visited) const {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (int neighbor : mAdjList[vertex]) {
      if (!visited[neighbor]) {
        DFSHelper(neighbor, visited);
      }
    }
  }

  bool hasCycleUndirectedHelper(int vertex, int parent,
                                std::vector<bool> &visited) const {
    visited[vertex] = true;

    for (int neighbor : mAdjList[vertex]) {
      if (!visited[neighbor]) {
        if (hasCycleUndirectedHelper(neighbor, vertex, visited)) {
          return true;
        }
      } else if (neighbor != parent) {
        return true; // Back edge found
      }
    }
    return false;
  }

  bool hasCycleDirectedHelper(int vertex, std::vector<int> &color) const {
    color[vertex] = 1; // Gray

    for (int neighbor : mAdjList[vertex]) {
      if (color[neighbor] == 1) {
        return true; // Back edge to gray vertex
      }
      if (color[neighbor] == 0 && hasCycleDirectedHelper(neighbor, color)) {
        return true;
      }
    }

    color[vertex] = 2; // Black
    return false;
  }
};

// 가중치가 있는 그래프 (Dijkstra용)
class WeightedGraph {
private:
  struct Edge {
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
  };

  std::vector<std::vector<Edge>> mAdjList;
  bool mIsDirected;
  int mVertices;

public:
  WeightedGraph(int vertices, bool isDirected = false)
      : mIsDirected(isDirected), mVertices(vertices) {
    mAdjList.resize(vertices);
  }

  void addEdge(int from, int to, int weight) {
    if (from >= 0 && from < mVertices && to >= 0 && to < mVertices) {
      mAdjList[from].push_back(Edge(to, weight));
      if (!mIsDirected) {
        mAdjList[to].push_back(Edge(from, weight));
      }
    }
  }

  // Dijkstra's algorithm (시험에서 자주 출제)
  std::vector<int> dijkstra(int start) const {
    std::vector<int> distance(mVertices, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
      int dist = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      if (dist > distance[u])
        continue;

      for (const Edge &edge : mAdjList[u]) {
        int v = edge.to;
        int weight = edge.weight;

        if (distance[u] + weight < distance[v]) {
          distance[v] = distance[u] + weight;
          pq.push({distance[v], v});
        }
      }
    }

    return distance;
  }

  void printDistances(int start) const {
    std::vector<int> distances = dijkstra(start);
    std::cout << "Shortest distances from vertex " << start << ":" << std::endl;
    for (int i = 0; i < mVertices; ++i) {
      std::cout << "To " << i << ": ";
      if (distances[i] == INT_MAX) {
        std::cout << "INF";
      } else {
        std::cout << distances[i];
      }
      std::cout << std::endl;
    }
  }
};

#endif