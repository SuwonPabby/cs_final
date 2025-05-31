#ifndef SINGLYLIST_HPP
#define SINGLYLIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class SinglyList {
private:
  struct Node {
    T mData;
    Node *mNext;

    Node(const T &data) : mData(data), mNext(nullptr) {}
  };

  Node *mHead;
  unsigned mSize;

public:
  class Iterator {
  private:
    Node *mCurr;

  public:
    friend class SinglyList;

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

  // Constructor and destructor
  SinglyList() : mHead(nullptr), mSize(0) {}

  ~SinglyList() { clear(); }

  // Copy constructor and assignment operator
  SinglyList(const SinglyList &other) : mHead(nullptr), mSize(0) {
    copyFrom(other);
  }

  SinglyList &operator=(const SinglyList &other) {
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
    mSize = 0;
  }

  unsigned size() const { return mSize; }

  bool empty() const { return mSize == 0; }

  // Element access
  void push_front(const T &value) {
    Node *newNode = new Node(value);
    newNode->mNext = mHead;
    mHead = newNode;
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
    mHead = mHead->mNext;
    delete temp;
    --mSize;
  }

  void push_back(const T &value) {
    Node *newNode = new Node(value);

    if (!mHead) {
      mHead = newNode;
    } else {
      Node *current = mHead;
      while (current->mNext) {
        current = current->mNext;
      }
      current->mNext = newNode;
    }
    ++mSize;
  }

  // Iterator operations
  Iterator begin() const { return Iterator(mHead); }

  Iterator end() const { return Iterator(nullptr); }

  Iterator insert_after(Iterator &i, const T &val) {
    if (!i.mCurr) {
      push_front(val);
      return Iterator(mHead);
    }

    Node *newNode = new Node(val);
    newNode->mNext = i.mCurr->mNext;
    i.mCurr->mNext = newNode;
    ++mSize;

    return Iterator(newNode);
  }

  Iterator erase_after(Iterator &i) {
    if (!i.mCurr || !i.mCurr->mNext) {
      return Iterator(nullptr);
    }

    Node *nodeToDelete = i.mCurr->mNext;
    Node *nextNode = nodeToDelete->mNext;
    i.mCurr->mNext = nextNode;
    delete nodeToDelete;
    --mSize;

    return Iterator(nextNode);
  }

  // 리스트 뒤집기 (시험에서 자주 출제)
  void reverse() {
    Node *prev = nullptr;
    Node *current = mHead;
    Node *next = nullptr;

    while (current) {
      next = current->mNext;
      current->mNext = prev;
      prev = current;
      current = next;
    }

    mHead = prev;
  }

private:
  void copyFrom(const SinglyList &other) {
    for (Node *current = other.mHead; current; current = current->mNext) {
      push_back(current->mData);
    }
  }
};

#endif