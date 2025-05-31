#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class DoubleList {
private:
  struct Node {
    T mData;
    Node *mNext;
    Node *mPrev;

    Node(const T &data) : mData(data), mNext(nullptr), mPrev(nullptr) {}
  };

  Node *mHead;    // Pointer to "head" node
  Node *mTail;    // Pointer to "tail" node
  unsigned mSize; // Tracks the size of the list

public:
  class Iterator {
  private:
    Node *mCurr;

  public:
    friend class DoubleList;

    Iterator() : mCurr(nullptr) {}
    Iterator(Node *in) : mCurr(in) {}

    // Iterator operations
    Iterator &operator++() {
      if (mCurr) {
        mCurr = mCurr->mNext;
      }
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    Iterator &operator--() {
      if (mCurr) {
        mCurr = mCurr->mPrev;
      }
      return *this;
    }

    Iterator operator--(int) {
      Iterator temp = *this;
      --(*this);
      return temp;
    }

    T &operator*() {
      if (!mCurr) {
        throw std::runtime_error("Dereferencing null iterator");
      }
      return mCurr->mData;
    }

    const T &operator*() const {
      if (!mCurr) {
        throw std::runtime_error("Dereferencing null iterator");
      }
      return mCurr->mData;
    }

    bool operator==(const Iterator &other) const {
      return mCurr == other.mCurr;
    }

    bool operator!=(const Iterator &other) const {
      return mCurr != other.mCurr;
    }
  };

  // Constructors and destructor
  DoubleList() : mHead(nullptr), mTail(nullptr), mSize(0) {}

  ~DoubleList() { clear(); }

  // Copy constructor and assignment operator
  DoubleList(const DoubleList &other)
      : mHead(nullptr), mTail(nullptr), mSize(0) {
    copyFrom(other);
  }

  DoubleList &operator=(const DoubleList &other) {
    if (this != &other) {
      clear();
      copyFrom(other);
    }
    return *this;
  }

  // Basic operations
  void clear() {
    while (mHead) {
      Node *temp = mHead;
      mHead = mHead->mNext;
      delete temp;
    }
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
  }

  unsigned size() const { return mSize; }

  // Element access
  void push_front(const T &value) {
    Node *newNode = new Node(value);

    if (!mHead) {
      mHead = mTail = newNode;
    } else {
      newNode->mNext = mHead;
      mHead->mPrev = newNode;
      mHead = newNode;
    }
    ++mSize;
  }

  T &front() {
    if (!mHead) {
      throw std::runtime_error("List is empty");
    }
    return mHead->mData;
  }

  void pop_front() {
    if (!mHead)
      return;

    Node *temp = mHead;
    if (mHead == mTail) {
      mHead = mTail = nullptr;
    } else {
      mHead = mHead->mNext;
      mHead->mPrev = nullptr;
    }
    delete temp;
    --mSize;
  }

  void push_back(const T &value) {
    Node *newNode = new Node(value);

    if (!mTail) {
      mHead = mTail = newNode;
    } else {
      mTail->mNext = newNode;
      newNode->mPrev = mTail;
      mTail = newNode;
    }
    ++mSize;
  }

  T &back() {
    if (!mTail) {
      throw std::runtime_error("List is empty");
    }
    return mTail->mData;
  }

  void pop_back() {
    if (!mTail)
      return;

    Node *temp = mTail;
    if (mHead == mTail) {
      mHead = mTail = nullptr;
    } else {
      mTail = mTail->mPrev;
      mTail->mNext = nullptr;
    }
    delete temp;
    --mSize;
  }

  // Iterator operations
  Iterator begin() const { return Iterator(mHead); }

  Iterator end() const { return Iterator(nullptr); }

  Iterator erase(Iterator &i) {
    if (!i.mCurr) {
      return i;
    }

    Node *nodeToDelete = i.mCurr;
    Node *nextNode = nodeToDelete->mNext;

    // 이전 노드 연결 업데이트
    if (nodeToDelete->mPrev) {
      nodeToDelete->mPrev->mNext = nodeToDelete->mNext;
    } else {
      mHead = nodeToDelete->mNext;
    }

    // 다음 노드 연결 업데이트
    if (nodeToDelete->mNext) {
      nodeToDelete->mNext->mPrev = nodeToDelete->mPrev;
    } else {
      mTail = nodeToDelete->mPrev;
    }

    delete nodeToDelete;
    --mSize;

    return Iterator(nextNode);
  }

  Iterator insert(Iterator &i, const T &val) {
    Node *newNode = new Node(val);

    if (!i.mCurr) {
      // end()에 삽입하는 경우 (push_back과 동일)
      if (!mTail) {
        mHead = mTail = newNode;
      } else {
        mTail->mNext = newNode;
        newNode->mPrev = mTail;
        mTail = newNode;
      }
    } else {
      // 중간에 삽입
      newNode->mNext = i.mCurr;
      newNode->mPrev = i.mCurr->mPrev;

      if (i.mCurr->mPrev) {
        i.mCurr->mPrev->mNext = newNode;
      } else {
        mHead = newNode;
      }

      i.mCurr->mPrev = newNode;
    }

    ++mSize;
    return Iterator(newNode);
  }

private:
  void copyFrom(const DoubleList &other) {
    for (Node *current = other.mHead; current; current = current->mNext) {
      push_back(current->mData);
    }
  }
};

#endif