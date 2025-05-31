#include "HashMap.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "=== HashMap 테스트 ===" << std::endl;

  // HashMap 생성 및 삽입 테스트
  HashMap<std::string, int> hashMap;
  std::cout << "빈 맵 크기: " << hashMap.size() << std::endl;
  std::cout << "로드 팩터: " << hashMap.loadFactor() << std::endl;

  // 삽입 테스트
  std::cout << "\n=== 삽입 테스트 ===" << std::endl;
  hashMap.insert("apple", 100);
  hashMap.insert("banana", 200);
  hashMap.insert("cherry", 300);
  hashMap.insert("date", 400);
  hashMap.insert("elderberry", 500);

  std::cout << "삽입 후 크기: " << hashMap.size() << std::endl;
  std::cout << "로드 팩터: " << hashMap.loadFactor() << std::endl;

  // 검색 및 접근 테스트
  std::cout << "\n=== 검색 테스트 ===" << std::endl;
  std::string keys[] = {"apple", "banana", "grape", "cherry", "orange"};
  for (const std::string &key : keys) {
    bool found = hashMap.find(key);
    std::cout << key << " 검색: " << (found ? "찾음" : "없음");
    if (found) {
      std::cout << " (값: " << hashMap.at(key) << ")";
    }
    std::cout << std::endl;
  }

  // operator[] 테스트
  std::cout << "\n=== operator[] 테스트 ===" << std::endl;
  std::cout << "hashMap[\"apple\"]: " << hashMap["apple"] << std::endl;
  std::cout << "hashMap[\"new_key\"]: " << hashMap["new_key"] << " (새로 생성)"
            << std::endl;
  std::cout << "삽입 후 크기: " << hashMap.size() << std::endl;

  // 값 업데이트 테스트
  std::cout << "\n=== 값 업데이트 테스트 ===" << std::endl;
  hashMap["apple"] = 999;
  std::cout << "apple 값 업데이트 후: " << hashMap["apple"] << std::endl;
  hashMap.insert("banana", 888); // 기존 키에 새 값
  std::cout << "banana 값 업데이트 후: " << hashMap["banana"] << std::endl;

  // 테이블 출력 (내부 구조 확인)
  std::cout << "\n=== 해시 테이블 내부 구조 ===" << std::endl;
  hashMap.printTable();

  // 삭제 테스트
  std::cout << "\n=== 삭제 테스트 ===" << std::endl;
  std::cout << "cherry 삭제 전:" << std::endl;
  std::cout << "cherry 존재: " << (hashMap.find("cherry") ? "예" : "아니오")
            << std::endl;

  hashMap.remove("cherry");
  std::cout << "\ncherry 삭제 후:" << std::endl;
  std::cout << "cherry 존재: " << (hashMap.find("cherry") ? "예" : "아니오")
            << std::endl;
  std::cout << "삭제 후 크기: " << hashMap.size() << std::endl;

  // 많은 데이터 삽입으로 rehashing 테스트
  std::cout << "\n=== Rehashing 테스트 ===" << std::endl;
  std::cout << "많은 데이터 삽입 전 용량과 로드팩터:" << std::endl;
  hashMap.printTable();

  for (int i = 0; i < 10; ++i) {
    std::string key = "key" + std::to_string(i);
    hashMap.insert(key, i * 10);
  }

  std::cout << "\n많은 데이터 삽입 후:" << std::endl;
  std::cout << "크기: " << hashMap.size() << std::endl;
  std::cout << "로드 팩터: " << hashMap.loadFactor() << std::endl;

  // 복사 생성자 테스트
  std::cout << "\n=== 복사 생성자 테스트 ===" << std::endl;
  HashMap<std::string, int> hashMap2(hashMap);
  std::cout << "원본 크기: " << hashMap.size()
            << ", 복사본 크기: " << hashMap2.size() << std::endl;
  std::cout << "복사본에서 apple 검색: "
            << (hashMap2.find("apple") ? "찾음" : "없음") << std::endl;

  // 대입 연산자 테스트
  HashMap<std::string, int> hashMap3;
  hashMap3.insert("test", 123);
  hashMap3 = hashMap;
  std::cout << "\n대입 연산자 테스트 - hashMap3 크기: " << hashMap3.size()
            << std::endl;

  // clear() 테스트
  hashMap.clear();
  std::cout << "\nclear() 후 크기: " << hashMap.size() << std::endl;
  std::cout << "empty 상태: " << (hashMap.empty() ? "예" : "아니오")
            << std::endl;

  // 정수 키 테스트
  std::cout << "\n=== 정수 키 테스트 ===" << std::endl;
  HashMap<int, std::string> intMap;
  intMap.insert(1, "one");
  intMap.insert(2, "two");
  intMap.insert(3, "three");
  intMap.insert(12, "twelve"); // 해시 충돌 가능성
  intMap.insert(23, "twenty-three");

  std::cout << "정수 맵 크기: " << intMap.size() << std::endl;
  std::cout << "키 2의 값: " << intMap[2] << std::endl;
  std::cout << "키 12의 값: " << intMap[12] << std::endl;

  intMap.printTable();

  return 0;
}