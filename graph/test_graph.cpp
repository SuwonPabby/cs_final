#include "Graph.hpp"
#include <iostream>

int main() {
  std::cout << "=== Graph 테스트 ===" << std::endl;

  // 무방향 그래프 테스트
  std::cout << "\n=== 무방향 그래프 테스트 ===" << std::endl;
  Graph undirectedGraph(6, false);

  // 간선 추가
  undirectedGraph.addEdge(0, 1);
  undirectedGraph.addEdge(0, 2);
  undirectedGraph.addEdge(1, 3);
  undirectedGraph.addEdge(2, 3);
  undirectedGraph.addEdge(3, 4);
  undirectedGraph.addEdge(4, 5);

  std::cout << "무방향 그래프 구조:" << std::endl;
  undirectedGraph.printGraph();

  // 간선 존재 확인
  std::cout << "\n간선 존재 확인:" << std::endl;
  std::cout << "간선 (0,1): "
            << (undirectedGraph.hasEdge(0, 1) ? "존재" : "없음") << std::endl;
  std::cout << "간선 (1,0): "
            << (undirectedGraph.hasEdge(1, 0) ? "존재" : "없음") << std::endl;
  std::cout << "간선 (0,5): "
            << (undirectedGraph.hasEdge(0, 5) ? "존재" : "없음") << std::endl;

  // BFS 탐색 (시험에서 자주 출제)
  std::cout << "\n=== BFS 탐색 ===" << std::endl;
  undirectedGraph.BFS(0);
  undirectedGraph.BFS(3);

  // DFS 탐색 (시험에서 자주 출제)
  std::cout << "\n=== DFS 탐색 ===" << std::endl;
  undirectedGraph.DFS(0);
  undirectedGraph.DFS(3);

  // DFS 반복적 구현
  std::cout << "\n=== DFS (반복적) 탐색 ===" << std::endl;
  undirectedGraph.DFSIterative(0);

  // 연결성 확인
  std::cout << "\n그래프 연결성: "
            << (undirectedGraph.isConnected() ? "연결됨" : "연결 안됨")
            << std::endl;

  // 사이클 검출
  std::cout << "무방향 그래프 사이클: "
            << (undirectedGraph.hasCycleUndirected() ? "있음" : "없음")
            << std::endl;

  // 방향 그래프 테스트
  std::cout << "\n=== 방향 그래프 테스트 ===" << std::endl;
  Graph directedGraph(5, true);

  directedGraph.addEdge(0, 1);
  directedGraph.addEdge(1, 2);
  directedGraph.addEdge(2, 3);
  directedGraph.addEdge(3, 1); // 사이클 생성
  directedGraph.addEdge(0, 4);

  std::cout << "방향 그래프 구조:" << std::endl;
  directedGraph.printGraph();

  std::cout << "\n방향 그래프 BFS/DFS:" << std::endl;
  directedGraph.BFS(0);
  directedGraph.DFS(0);

  std::cout << "방향 그래프 사이클: "
            << (directedGraph.hasCycleDirected() ? "있음" : "없음")
            << std::endl;

  // 간선 제거 테스트
  std::cout << "\n=== 간선 제거 테스트 ===" << std::endl;
  std::cout << "간선 (3,1) 제거 전:" << std::endl;
  directedGraph.printGraph();

  directedGraph.removeEdge(3, 1);
  std::cout << "\n간선 (3,1) 제거 후:" << std::endl;
  directedGraph.printGraph();
  std::cout << "방향 그래프 사이클: "
            << (directedGraph.hasCycleDirected() ? "있음" : "없음")
            << std::endl;

  // 가중치 그래프 및 Dijkstra 테스트
  std::cout << "\n=== 가중치 그래프 및 Dijkstra 알고리즘 테스트 ==="
            << std::endl;
  WeightedGraph weightedGraph(5, true);

  weightedGraph.addEdge(0, 1, 10);
  weightedGraph.addEdge(0, 4, 5);
  weightedGraph.addEdge(1, 2, 1);
  weightedGraph.addEdge(1, 4, 2);
  weightedGraph.addEdge(2, 3, 4);
  weightedGraph.addEdge(3, 0, 7);
  weightedGraph.addEdge(3, 2, 6);
  weightedGraph.addEdge(4, 1, 3);
  weightedGraph.addEdge(4, 2, 9);
  weightedGraph.addEdge(4, 3, 2);

  std::cout << "정점 0에서 모든 정점까지의 최단 거리:" << std::endl;
  weightedGraph.printDistances(0);

  std::cout << "\n정점 1에서 모든 정점까지의 최단 거리:" << std::endl;
  weightedGraph.printDistances(1);

  // 연결되지 않은 그래프 테스트
  std::cout << "\n=== 연결되지 않은 그래프 테스트 ===" << std::endl;
  Graph disconnectedGraph(4, false);
  disconnectedGraph.addEdge(0, 1);
  disconnectedGraph.addEdge(2, 3);

  std::cout << "연결되지 않은 그래프:" << std::endl;
  disconnectedGraph.printGraph();
  std::cout << "연결성: "
            << (disconnectedGraph.isConnected() ? "연결됨" : "연결 안됨")
            << std::endl;

  std::cout << "\n각 구성 요소에서 BFS:" << std::endl;
  disconnectedGraph.BFS(0);
  disconnectedGraph.BFS(2);

  return 0;
}