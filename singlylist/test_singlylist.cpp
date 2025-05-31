#include "SinglyList.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "=== SinglyList 테스트 ===" << std::endl;

  // 기본 생성자 테스트
  SinglyList<int> list1;
  std::cout << "빈 리스트 크기: " << list1.size() << std::endl;

  // push_front 테스트
  std::cout << "\npush_front 테스트:" << std::endl;
  for (int i = 1; i <= 5; ++i) {
    list1.push_front(i);
    std::cout << "push_front(" << i << ") - 크기: " << list1.size()
              << std::endl;
  }

  // Iterator를 이용한 순회
  std::cout << "\n순회 테스트: ";
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // push_back 테스트
  std::cout << "\npush_back 테스트:" << std::endl;
  list1.push_back(10);
  list1.push_back(20);
  std::cout << "push_back 후: ";
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // front() 및 pop_front() 테스트
  std::cout << "\nfront(): " << list1.front() << std::endl;
  std::cout << "pop_front 테스트:" << std::endl;
  for (int i = 0; i < 3; ++i) {
    std::cout << "제거 전 front: " << list1.front() << std::endl;
    list1.pop_front();
    std::cout << "pop_front 후 크기: " << list1.size() << std::endl;
  }

  std::cout << "남은 요소들: ";
  for (auto it = list1.begin(); it != list1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // insert_after 테스트
  std::cout << "\ninsert_after 테스트:" << std::endl;
  auto it = list1.begin();
  auto insertedIt = list1.insert_after(it, 99);
  std::cout << "첫 번째 요소 뒤에 99 삽입 후: ";
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // erase_after 테스트
  std::cout << "\nerase_after 테스트:" << std::endl;
  it = list1.begin();
  list1.erase_after(it);
  std::cout << "첫 번째 요소 뒤 삭제 후: ";
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // reverse 테스트 (시험에서 자주 출제)
  std::cout << "\nreverse 테스트:" << std::endl;
  std::cout << "reverse 전: ";
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  list1.reverse();
  std::cout << "reverse 후: ";
  for (auto iter = list1.begin(); iter != list1.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  // 복사 생성자 테스트
  SinglyList<int> list2(list1);
  std::cout << "\n복사 생성자 테스트:" << std::endl;
  std::cout << "원본 크기: " << list1.size()
            << ", 복사본 크기: " << list2.size() << std::endl;

  // 대입 연산자 테스트
  SinglyList<int> list3;
  list3 = list1;
  std::cout << "대입 연산자 테스트 - list3 크기: " << list3.size() << std::endl;

  // clear() 테스트
  list1.clear();
  std::cout << "\nclear() 후 list1 크기: " << list1.size() << std::endl;

  // 문자열 타입 테스트
  std::cout << "\n=== 문자열 타입 테스트 ===" << std::endl;
  SinglyList<std::string> stringList;
  stringList.push_front("World");
  stringList.push_front("Hello");
  stringList.push_back("!");

  std::cout << "문자열 리스트: ";
  for (auto iter = stringList.begin(); iter != stringList.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  return 0;
}