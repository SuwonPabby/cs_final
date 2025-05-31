#ifndef SMCVECTOR_HPP
#define SMCVECTOR_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class smcVector {
private:
  T *mData;
  unsigned mCapacity;
  unsigned mSize;
  const unsigned INITIAL_CAPACITY = 10;
  const unsigned CAPACITY_MULTIPLIER = 2;

public:
  // 기본 생성자
  smcVector() : mCapacity(INITIAL_CAPACITY), mSize(0) {
    mData = new T[mCapacity];
  }

  // 용량 지정 생성자
  smcVector(unsigned inCapacity) : mCapacity(inCapacity), mSize(0) {
    if (mCapacity == 0) {
      mCapacity = INITIAL_CAPACITY;
    }
    mData = new T[mCapacity];
  }

  // 복사 생성자
  smcVector(const smcVector<T> &other)
      : mCapacity(other.mCapacity), mSize(other.mSize) {
    mData = new T[mCapacity];
    for (unsigned i = 0; i < mSize; ++i) {
      mData[i] = other.mData[i];
    }
  }

  // 대입 연산자
  smcVector<T> &operator=(const smcVector<T> &other) {
    if (this != &other) {
      delete[] mData;

      mCapacity = other.mCapacity;
      mSize = other.mSize;
      mData = new T[mCapacity];

      for (unsigned i = 0; i < mSize; ++i) {
        mData[i] = other.mData[i];
      }
    }
    return *this;
  }

  // 소멸자
  ~smcVector() { delete[] mData; }

  // clear 메서드
  void clear() { mSize = 0; }

  // capacity 메서드
  unsigned capacity() const { return mCapacity; }

  // size 메서드
  unsigned size() const { return mSize; }

  // 인덱스 접근 연산자 (non-const)
  T &operator[](unsigned index) {
    if (index >= mSize) {
      throw std::out_of_range("Index out of range");
    }
    return mData[index];
  }

  // 인덱스 접근 연산자 (const)
  const T &operator[](unsigned index) const {
    if (index >= mSize) {
      throw std::out_of_range("Index out of range");
    }
    return mData[index];
  }

  // push_back 메서드
  void push_back(const T &value) {
    if (mSize >= mCapacity) {
      resize();
    }
    mData[mSize] = value;
    ++mSize;
  }

  // back 메서드
  T &back() {
    if (mSize == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return mData[mSize - 1];
  }

  // pop_back 메서드
  void pop_back() {
    if (mSize > 0) {
      --mSize;
    }
  }

  // 출력 연산자
  friend std::ostream &operator<<(std::ostream &os,
                                  const smcVector<T> &vector) {
    os << "[";
    for (unsigned i = 0; i < vector.mSize; ++i) {
      os << vector.mData[i];
      if (i < vector.mSize - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }

private:
  // resize 메서드
  void resize() {
    unsigned newCapacity = mCapacity * CAPACITY_MULTIPLIER;
    T *newData = new T[newCapacity];

    for (unsigned i = 0; i < mSize; ++i) {
      newData[i] = mData[i];
    }

    delete[] mData;
    mData = newData;
    mCapacity = newCapacity;
  }
};

#endif