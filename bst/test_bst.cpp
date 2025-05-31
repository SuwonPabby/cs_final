#include "BST.hpp"
#include <iostream>

int main() {
  std::cout << "=== SMCNumberBST 테스트 ===" << std::endl;

  // BST 생성 및 삽입 테스트
  SMCNumberBST bst;
  std::cout << "빈 트리 크기: " << bst.size() << std::endl;

  // 노드 삽입
  std::cout << "\n노드 삽입 테스트:" << std::endl;
  int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
  for (int val : values) {
    bst.insert(val);
    std::cout << val << " 삽입 - 크기: " << bst.size() << std::endl;
  }

  // 트리 순회 테스트 (시험에서 자주 출제)
  std::cout << "\n=== 트리 순회 테스트 ===" << std::endl;
  bst.inOrder();    // In-order: 정렬된 순서로 출력
  bst.preOrder();   // Pre-order: 루트 먼저
  bst.postOrder();  // Post-order: 루트 마지막
  bst.levelOrder(); // Level-order: 레벨별 순회

  // 출력 연산자 테스트
  std::cout << "\n출력 연산자 테스트 (ascending order): " << bst << std::endl;

  // 검색 테스트 (find -> contains로 변경)
  std::cout << "\n=== 검색 테스트 ===" << std::endl;
  int searchValues[] = {40, 25, 90, 10};
  for (int val : searchValues) {
    bool found = bst.contains(val);
    std::cout << val << " 검색: " << (found ? "찾음" : "없음") << std::endl;
  }

  // 최솟값/최댓값 테스트
  std::cout << "\n최솟값: " << bst.findMin() << std::endl;
  std::cout << "최댓값: " << bst.findMax() << std::endl;
  std::cout << "트리 높이: " << bst.height() << std::endl;

  // 삭제 테스트
  std::cout << "\n=== 삭제 테스트 ===" << std::endl;

  // Case 1: 리프 노드 삭제
  std::cout << "10 삭제 (리프 노드):" << std::endl;
  bst.remove(10);
  bst.inOrder();
  std::cout << "삭제 후 크기: " << bst.size() << std::endl;

  // Case 2: 한 자식을 가진 노드 삭제
  std::cout << "\n25 삭제 (한 자식):" << std::endl;
  bst.remove(25);
  bst.inOrder();
  std::cout << "삭제 후 크기: " << bst.size() << std::endl;

  // Case 3: 두 자식을 가진 노드 삭제
  std::cout << "\n30 삭제 (두 자식):" << std::endl;
  bst.remove(30);
  bst.inOrder();
  std::cout << "삭제 후 크기: " << bst.size() << std::endl;

  // 루트 노드 삭제
  std::cout << "\n50 삭제 (루트 노드):" << std::endl;
  bst.remove(50);
  bst.inOrder();
  std::cout << "삭제 후 크기: " << bst.size() << std::endl;

  // 복사 생성자 테스트
  std::cout << "\n=== 복사 생성자 테스트 ===" << std::endl;
  SMCNumberBST bst2(bst);
  std::cout << "원본 크기: " << bst.size() << ", 복사본 크기: " << bst2.size()
            << std::endl;
  std::cout << "복사본 in-order: ";
  bst2.inOrder();
  std::cout << "복사본 출력 연산자: " << bst2 << std::endl;

  // 대입 연산자 테스트
  SMCNumberBST bst3;
  bst3.insert(100);
  bst3 = bst;
  std::cout << "\n대입 연산자 테스트 - bst3 크기: " << bst3.size() << std::endl;
  std::cout << "bst3 in-order: ";
  bst3.inOrder();
  std::cout << "bst3 출력 연산자: " << bst3 << std::endl;

  // clear() 테스트
  bst.clear();
  std::cout << "\nclear() 후 크기: " << bst.size() << std::endl;
  std::cout << "empty 상태: " << (bst.empty() ? "예" : "아니오") << std::endl;
  std::cout << "clear 후 출력 연산자: " << bst << std::endl;

  // 새로운 트리로 contains 테스트
  std::cout << "\n=== 새로운 트리로 contains 테스트 ===" << std::endl;
  SMCNumberBST newBst;
  int testValues[] = {15, 10, 20, 8, 12, 25, 6, 11, 13, 22, 27};

  for (int val : testValues) {
    newBst.insert(val);
  }

  std::cout << "새로운 트리: " << newBst << std::endl;

  std::cout << "\ncontains 테스트:" << std::endl;
  int containsTest[] = {15, 6, 25, 30, 8, 100};
  for (int val : containsTest) {
    std::cout << "contains(" << val
              << "): " << (newBst.contains(val) ? "true" : "false")
              << std::endl;
  }

  return 0;
}