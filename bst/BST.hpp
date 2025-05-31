#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>
#include <stdexcept>

struct BSTNode {
  // Value stored in this node
  int number;
  // Pointer to left child
  BSTNode *left;
  // Pointer to right child
  BSTNode *right;

  BSTNode(int num) : number(num), left(nullptr), right(nullptr) {}
};

class SMCNumberBST {
private:
  BSTNode *mRoot;
  unsigned mSize;

public:
  // Constructor
  SMCNumberBST() : mRoot(nullptr), mSize(0) {}

  // Destructor
  ~SMCNumberBST() { clear(); }

  // Copy constructor and assignment operator
  SMCNumberBST(const SMCNumberBST &other) : mRoot(nullptr), mSize(0) {
    copyFrom(other.mRoot);
  }

  SMCNumberBST &operator=(const SMCNumberBST &other) {
    if (this != &other) {
      clear();
      copyFrom(other.mRoot);
    }
    return *this;
  }

  // Clear the tree
  void clear() {
    clearHelper(mRoot);
    mRoot = nullptr;
    mSize = 0;
  }

  // Get the size
  unsigned size() const { return mSize; }

  bool empty() const { return mSize == 0; }

  // Insert a number into the BST
  void insert(int num) { mRoot = insertHelper(mRoot, num); }

  // Find out whether a number is in the BST
  bool contains(int num) const { return containsHelper(mRoot, num); }

  // Removes a number from the BST, if it exists
  void remove(int num) { mRoot = removeHelper(mRoot, num); }

  // Output the the contents of the tree, in ascending order
  friend std::ostream &operator<<(std::ostream &os, const SMCNumberBST &tree) {
    tree.inOrderHelper(tree.mRoot, os);
    return os;
  }

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

  int findMin() const {
    if (!mRoot) {
      throw std::runtime_error("Tree is empty");
    }
    BSTNode *current = mRoot;
    while (current->left) {
      current = current->left;
    }
    return current->number;
  }

  int findMax() const {
    if (!mRoot) {
      throw std::runtime_error("Tree is empty");
    }
    BSTNode *current = mRoot;
    while (current->right) {
      current = current->right;
    }
    return current->number;
  }

private:
  void clearHelper(BSTNode *node) {
    if (node) {
      clearHelper(node->left);
      clearHelper(node->right);
      delete node;
    }
  }

  BSTNode *insertHelper(BSTNode *node, int value) {
    if (!node) {
      ++mSize;
      return new BSTNode(value);
    }

    if (value < node->number) {
      node->left = insertHelper(node->left, value);
    } else if (value > node->number) {
      node->right = insertHelper(node->right, value);
    }
    // 중복 값은 삽입하지 않음

    return node;
  }

  bool containsHelper(BSTNode *node, int value) const {
    if (!node) {
      return false;
    }

    if (value == node->number) {
      return true;
    } else if (value < node->number) {
      return containsHelper(node->left, value);
    } else {
      return containsHelper(node->right, value);
    }
  }

  BSTNode *removeHelper(BSTNode *node, int value) {
    if (!node) {
      return node;
    }

    if (value < node->number) {
      node->left = removeHelper(node->left, value);
    } else if (value > node->number) {
      node->right = removeHelper(node->right, value);
    } else {
      // 삭제할 노드를 찾음
      --mSize;

      // Case 1: 자식이 없음
      if (!node->left && !node->right) {
        delete node;
        return nullptr;
      }
      // Case 2: 한 쪽 자식만 있음
      else if (!node->left) {
        BSTNode *temp = node->right;
        delete node;
        return temp;
      } else if (!node->right) {
        BSTNode *temp = node->left;
        delete node;
        return temp;
      }
      // Case 3: 두 자식 모두 있음
      else {
        BSTNode *successor = findMinNode(node->right);
        node->number = successor->number;
        node->right = removeHelper(node->right, successor->number);
        ++mSize; // removeHelper에서 감소시킨 것을 복원
      }
    }

    return node;
  }

  BSTNode *findMinNode(BSTNode *node) const {
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  void inOrderHelper(BSTNode *node) const {
    if (node) {
      inOrderHelper(node->left);
      std::cout << node->number << " ";
      inOrderHelper(node->right);
    }
  }

  void inOrderHelper(BSTNode *node, std::ostream &os) const {
    if (node) {
      inOrderHelper(node->left, os);
      os << node->number << " ";
      inOrderHelper(node->right, os);
    }
  }

  void preOrderHelper(BSTNode *node) const {
    if (node) {
      std::cout << node->number << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  void postOrderHelper(BSTNode *node) const {
    if (node) {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      std::cout << node->number << " ";
    }
  }

  void levelOrderHelper() const {
    if (!mRoot)
      return;

    std::queue<BSTNode *> q;
    q.push(mRoot);

    while (!q.empty()) {
      BSTNode *current = q.front();
      q.pop();

      std::cout << current->number << " ";

      if (current->left) {
        q.push(current->left);
      }
      if (current->right) {
        q.push(current->right);
      }
    }
  }

  int heightHelper(BSTNode *node) const {
    if (!node) {
      return -1;
    }

    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);

    return 1 + std::max(leftHeight, rightHeight);
  }

  void copyFrom(BSTNode *node) {
    if (node) {
      insert(node->number);
      copyFrom(node->left);
      copyFrom(node->right);
    }
  }
};

#endif