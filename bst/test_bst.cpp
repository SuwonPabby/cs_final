#include "BST.hpp"
#include <iostream>

int main() {
  std::cout << "=== Binary Search Tree 테스트 ===" << std::endl;

  // BST 생성 및 삽입 테스트
  BST<int> bst;
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

  // 검색 테스트
  std::cout << "\n=== 검색 테스트 ===" << std::endl;
  int searchValues[] = {40, 25, 90, 10};
  for (int val : searchValues) {
    bool found = bst.find(val);
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
  BST<int> bst2(bst);
  std::cout << "원본 크기: " << bst.size() << ", 복사본 크기: " << bst2.size()
            << std::endl;
  std::cout << "복사본 in-order: ";
  bst2.inOrder();

  // 대입 연산자 테스트
  BST<int> bst3;
  bst3.insert(100);
  bst3 = bst;
  std::cout << "\n대입 연산자 테스트 - bst3 크기: " << bst3.size() << std::endl;
  std::cout << "bst3 in-order: ";
  bst3.inOrder();

  // clear() 테스트
  bst.clear();
  std::cout << "\nclear() 후 크기: " << bst.size() << std::endl;
  std::cout << "empty 상태: " << (bst.empty() ? "예" : "아니오") << std::endl;

  // 문자열 타입 테스트
  std::cout << "\n=== 문자열 타입 테스트 ===" << std::endl;
  BST<std::string> stringBst;
  std::string words[] = {"dog",  "cat", "elephant", "bird",
                         "fish", "ant", "zebra"};

  for (const std::string &word : words) {
    stringBst.insert(word);
  }

  std::cout << "문자열 BST in-order (알파벳 순): ";
  stringBst.inOrder();

  std::cout << "문자열 BST에서 'cat' 검색: "
            << (stringBst.find("cat") ? "찾음" : "없음") << std::endl;
  std::cout << "문자열 BST에서 'lion' 검색: "
            << (stringBst.find("lion") ? "찾음" : "없음") << std::endl;

  return 0;
}