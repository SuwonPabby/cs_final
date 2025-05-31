#include "smcVector.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "=== smcVector 테스트 ===" << std::endl;

  // 기본 생성자 테스트
  smcVector<int> vec1;
  std::cout << "빈 벡터 크기: " << vec1.size() << ", 용량: " << vec1.capacity()
            << std::endl;

  // push_back 테스트
  for (int i = 1; i <= 15; ++i) {
    vec1.push_back(i);
    std::cout << "push_back(" << i << ") - 크기: " << vec1.size()
              << ", 용량: " << vec1.capacity() << std::endl;
  }

  // 인덱스 접근 테스트
  std::cout << "\n인덱스 접근 테스트:" << std::endl;
  for (unsigned i = 0; i < vec1.size(); ++i) {
    std::cout << "vec1[" << i << "] = " << vec1[i] << " ";
  }
  std::cout << std::endl;

  // back() 및 pop_back() 테스트
  std::cout << "\nback() 테스트: " << vec1.back() << std::endl;

  std::cout << "\npop_back() 테스트:" << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << "제거 전 마지막 요소: " << vec1.back() << std::endl;
    vec1.pop_back();
    std::cout << "pop_back() 후 크기: " << vec1.size() << std::endl;
  }

  // 복사 생성자 테스트
  smcVector<int> vec2(vec1);
  std::cout << "\n복사 생성자 테스트:" << std::endl;
  std::cout << "원본 크기: " << vec1.size() << ", 복사본 크기: " << vec2.size()
            << std::endl;

  // 대입 연산자 테스트
  smcVector<int> vec3;
  vec3 = vec1;
  std::cout << "대입 연산자 테스트:" << std::endl;
  std::cout << "대입 후 vec3 크기: " << vec3.size() << std::endl;

  // clear() 테스트
  vec1.clear();
  std::cout << "\nclear() 후 vec1 크기: " << vec1.size() << std::endl;

  // 문자열 타입 테스트
  std::cout << "\n=== 문자열 타입 테스트 ===" << std::endl;
  smcVector<std::string> stringVec;
  stringVec.push_back("Hello");
  stringVec.push_back("World");
  stringVec.push_back("C++");

  for (unsigned i = 0; i < stringVec.size(); ++i) {
    std::cout << stringVec[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}