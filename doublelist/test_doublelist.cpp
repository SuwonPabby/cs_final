#include "DoubleList.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "=== DoubleList 테스트 ===" << std::endl;

  // 기본 생성자 테스트
  DoubleList<int> list1;
  std::cout << "빈 리스트 크기: " << list1.size() << std::endl;

  // push_back 테스트
  std::cout << "\npush_back 테스트:" << std::endl;
  for (int i = 1; i <= 5; ++i) {
    list1.push_back(i);
    std::cout << "push_back(" << i << ") - 크기: " << list1.size() << std::endl;
  }

  // push_front 테스트
  std::cout << "\npush_front 테스트:" << std::endl;
  for (int i = 10; i <= 12; ++i) {
    list1.push_front(i);
    std::cout << "push_front(" << i << ") - 크기: " << list1.size()
              << std::endl;
  }

  // Iterator를 이용한 순회 (forward)
  std::cout << "\nIterator를 이용한 순회 (앞에서 뒤로):" << std::endl;
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // front(), back() 테스트
  std::cout << "\nfront(): " << list1.front() << std::endl;
  std::cout << "back(): " << list1.back() << std::endl;

  // pop_front, pop_back 테스트
  std::cout << "\npop_front 테스트:" << std::endl;
  std::cout << "제거 전 front: " << list1.front() << std::endl;
  list1.pop_front();
  std::cout << "pop_front 후 크기: " << list1.size()
            << ", 새로운 front: " << list1.front() << std::endl;

  std::cout << "\npop_back 테스트:" << std::endl;
  std::cout << "제거 전 back: " << list1.back() << std::endl;
  list1.pop_back();
  std::cout << "pop_back 후 크기: " << list1.size()
            << ", 새로운 back: " << list1.back() << std::endl;

  // insert 테스트
  std::cout << "\ninsert 테스트:" << std::endl;
  auto it = list1.begin();
  ++it; // 두 번째 위치
  auto insertedIt = list1.insert(it, 99);
  std::cout << "두 번째 위치에 99 삽입 후:" << std::endl;
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // erase 테스트
  std::cout << "\nerase 테스트:" << std::endl;
  std::cout << "삽입된 99 제거:" << std::endl;
  auto erasedIt = list1.erase(insertedIt);
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // 복사 생성자 테스트
  DoubleList<int> list2(list1);
  std::cout << "\n복사 생성자 테스트:" << std::endl;
  std::cout << "원본 크기: " << list1.size()
            << ", 복사본 크기: " << list2.size() << std::endl;
  std::cout << "복사본 내용: ";
  for (auto iter = list2.begin(); iter != list2.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // 대입 연산자 테스트
  DoubleList<int> list3;
  list3.push_back(100);
  list3 = list1;
  std::cout << "\n대입 연산자 테스트:" << std::endl;
  std::cout << "대입 후 list3 크기: " << list3.size() << std::endl;
  std::cout << "list3 내용: ";
  for (auto iter = list3.begin(); iter != list3.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // clear() 테스트
  list1.clear();
  std::cout << "\nclear() 후 list1 크기: " << list1.size() << std::endl;

  // 문자열 타입 테스트
  std::cout << "\n=== 문자열 타입 테스트 ===" << std::endl;
  DoubleList<std::string> stringList;
  stringList.push_back("Hello");
  stringList.push_back("World");
  stringList.push_front("Hi");

  std::cout << "문자열 리스트: ";
  for (auto iter = stringList.begin(); iter != stringList.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  return 0;
}