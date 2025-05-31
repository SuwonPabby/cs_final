#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>
#include <stdexcept>

template <typename T> class BST {
private:
  struct Node {
    T mData;
    Node *mLeft;
    Node *mRight;

    Node(const T &data) : mData(data), mLeft(nullptr), mRight(nullptr) {}
  };

  Node *mRoot;
  unsigned mSize;

public:
  // Constructor and destructor
  BST() : mRoot(nullptr), mSize(0) {}

  ~BST() { clear(); }

  // Copy constructor and assignment operator
  BST(const BST &other) : mRoot(nullptr), mSize(0) { copyFrom(other.mRoot); }

  BST &operator=(const BST &other) {
    if (this != &other) {
      clear();
      copyFrom(other.mRoot);
    }
    return *this;
  }

  // Basic operations
  void clear() {
    clearHelper(mRoot);
    mRoot = nullptr;
    mSize = 0;
  }

  unsigned size() const { return mSize; }

  bool empty() const { return mSize == 0; }

  // Insert and search operations
  void insert(const T &value) { mRoot = insertHelper(mRoot, value); }

  bool find(const T &value) const { return findHelper(mRoot, value); }

  void remove(const T &value) { mRoot = removeHelper(mRoot, value); }

  // Tree traversals (시험에서 자주 출제)
  void inOrder() const {
    std::cout << "In-order: ";
    inOrderHelper(mRoot);
    std::cout << std::endl;
  }

  void preOrder() const {
    std::cout << "Pre-order: ";
    preOrderHelper(mRoot);
    std::cout << std::endl;
  }

  void postOrder() const {
    std::cout << "Post-order: ";
    postOrderHelper(mRoot);
    std::cout << std::endl;
  }

  void levelOrder() const {
    std::cout << "Level-order: ";
    levelOrderHelper();
    std::cout << std::endl;
  }

  // Tree properties
  int height() const { return heightHelper(mRoot); }

  T findMin() const {
    if (!mRoot) {
      throw std::runtime_error("Tree is empty");
    }
    Node *current = mRoot;
    while (current->mLeft) {
      current = current->mLeft;
    }
    return current->mData;
  }

  T findMax() const {
    if (!mRoot) {
      throw std::runtime_error("Tree is empty");
    }
    Node *current = mRoot;
    while (current->mRight) {
      current = current->mRight;
    }
    return current->mData;
  }

private:
  void clearHelper(Node *node) {
    if (node) {
      clearHelper(node->mLeft);
      clearHelper(node->mRight);
      delete node;
    }
  }

  Node *insertHelper(Node *node, const T &value) {
    if (!node) {
      ++mSize;
      return new Node(value);
    }

    if (value < node->mData) {
      node->mLeft = insertHelper(node->mLeft, value);
    } else if (value > node->mData) {
      node->mRight = insertHelper(node->mRight, value);
    }
    // 중복 값은 삽입하지 않음

    return node;
  }

  bool findHelper(Node *node, const T &value) const {
    if (!node) {
      return false;
    }

    if (value == node->mData) {
      return true;
    } else if (value < node->mData) {
      return findHelper(node->mLeft, value);
    } else {
      return findHelper(node->mRight, value);
    }
  }

  Node *removeHelper(Node *node, const T &value) {
    if (!node) {
      return node;
    }

    if (value < node->mData) {
      node->mLeft = removeHelper(node->mLeft, value);
    } else if (value > node->mData) {
      node->mRight = removeHelper(node->mRight, value);
    } else {
      // 삭제할 노드를 찾음
      --mSize;

      // Case 1: 자식이 없음
      if (!node->mLeft && !node->mRight) {
        delete node;
        return nullptr;
      }
      // Case 2: 한 쪽 자식만 있음
      else if (!node->mLeft) {
        Node *temp = node->mRight;
        delete node;
        return temp;
      } else if (!node->mRight) {
        Node *temp = node->mLeft;
        delete node;
        return temp;
      }
      // Case 3: 두 자식 모두 있음
      else {
        Node *successor = findMinNode(node->mRight);
        node->mData = successor->mData;
        node->mRight = removeHelper(node->mRight, successor->mData);
        ++mSize; // removeHelper에서 감소시킨 것을 복원
      }
    }

    return node;
  }

  Node *findMinNode(Node *node) const {
    while (node->mLeft) {
      node = node->mLeft;
    }
    return node;
  }

  void inOrderHelper(Node *node) const {
    if (node) {
      inOrderHelper(node->mLeft);
      std::cout << node->mData << " ";
      inOrderHelper(node->mRight);
    }
  }

  void preOrderHelper(Node *node) const {
    if (node) {
      std::cout << node->mData << " ";
      preOrderHelper(node->mLeft);
      preOrderHelper(node->mRight);
    }
  }

  void postOrderHelper(Node *node) const {
    if (node) {
      postOrderHelper(node->mLeft);
      postOrderHelper(node->mRight);
      std::cout << node->mData << " ";
    }
  }

  void levelOrderHelper() const {
    if (!mRoot)
      return;

    std::queue<Node *> q;
    q.push(mRoot);

    while (!q.empty()) {
      Node *current = q.front();
      q.pop();

      std::cout << current->mData << " ";

      if (current->mLeft) {
        q.push(current->mLeft);
      }
      if (current->mRight) {
        q.push(current->mRight);
      }
    }
  }

  int heightHelper(Node *node) const {
    if (!node) {
      return -1;
    }

    int leftHeight = heightHelper(node->mLeft);
    int rightHeight = heightHelper(node->mRight);

    return 1 + std::max(leftHeight, rightHeight);
  }

  void copyFrom(Node *node) {
    if (node) {
      insert(node->mData);
      copyFrom(node->mLeft);
      copyFrom(node->mRight);
    }
  }
};

#endif