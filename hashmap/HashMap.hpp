#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename Key, typename Value> class HashMap {
private:
  struct KeyValuePair {
    Key key;
    Value value;
    bool isEmpty;
    bool isDeleted;

    KeyValuePair() : isEmpty(true), isDeleted(false) {}
    KeyValuePair(const Key &k, const Value &v)
        : key(k), value(v), isEmpty(false), isDeleted(false) {}
  };

  std::vector<KeyValuePair> mTable;
  unsigned mSize;
  unsigned mCapacity;
  const double MAX_LOAD_FACTOR = 0.7;
  const unsigned INITIAL_CAPACITY = 11; // 소수로 시작

public:
  // Constructor and destructor
  HashMap() : mSize(0), mCapacity(INITIAL_CAPACITY) {
    mTable.resize(mCapacity);
  }

  explicit HashMap(unsigned capacity) : mSize(0), mCapacity(capacity) {
    if (mCapacity == 0) {
      mCapacity = INITIAL_CAPACITY;
    }
    mTable.resize(mCapacity);
  }

  ~HashMap() = default;

  // Copy constructor and assignment operator
  HashMap(const HashMap &other)
      : mTable(other.mTable), mSize(other.mSize), mCapacity(other.mCapacity) {}

  HashMap &operator=(const HashMap &other) {
    if (this != &other) {
      mTable = other.mTable;
      mSize = other.mSize;
      mCapacity = other.mCapacity;
    }
    return *this;
  }

  // Basic operations
  void clear() {
    mTable.clear();
    mTable.resize(mCapacity);
    mSize = 0;
  }

  unsigned size() const { return mSize; }

  bool empty() const { return mSize == 0; }

  double loadFactor() const { return static_cast<double>(mSize) / mCapacity; }

  // Hash table operations
  void insert(const Key &key, const Value &value) {
    if (loadFactor() >= MAX_LOAD_FACTOR) {
      rehash();
    }

    unsigned index = findSlot(key);

    if (mTable[index].isEmpty || mTable[index].isDeleted) {
      mTable[index] = KeyValuePair(key, value);
      ++mSize;
    } else if (mTable[index].key == key) {
      // 키가 이미 존재하면 값을 업데이트
      mTable[index].value = value;
    }
  }

  bool find(const Key &key) const {
    unsigned index = hash(key);
    unsigned originalIndex = index;

    do {
      if (mTable[index].isEmpty) {
        return false;
      }
      if (!mTable[index].isDeleted && mTable[index].key == key) {
        return true;
      }
      index = (index + 1) % mCapacity;
    } while (index != originalIndex);

    return false;
  }

  Value &at(const Key &key) {
    unsigned index = hash(key);
    unsigned originalIndex = index;

    do {
      if (mTable[index].isEmpty) {
        throw std::runtime_error("Key not found");
      }
      if (!mTable[index].isDeleted && mTable[index].key == key) {
        return mTable[index].value;
      }
      index = (index + 1) % mCapacity;
    } while (index != originalIndex);

    throw std::runtime_error("Key not found");
  }

  const Value &at(const Key &key) const {
    unsigned index = hash(key);
    unsigned originalIndex = index;

    do {
      if (mTable[index].isEmpty) {
        throw std::runtime_error("Key not found");
      }
      if (!mTable[index].isDeleted && mTable[index].key == key) {
        return mTable[index].value;
      }
      index = (index + 1) % mCapacity;
    } while (index != originalIndex);

    throw std::runtime_error("Key not found");
  }

  Value &operator[](const Key &key) {
    try {
      return at(key);
    } catch (const std::runtime_error &) {
      // 키가 존재하지 않으면 기본값으로 삽입
      insert(key, Value{});
      return at(key);
    }
  }

  void remove(const Key &key) {
    unsigned index = hash(key);
    unsigned originalIndex = index;

    do {
      if (mTable[index].isEmpty) {
        return; // 키가 존재하지 않음
      }
      if (!mTable[index].isDeleted && mTable[index].key == key) {
        mTable[index].isDeleted = true;
        --mSize;
        return;
      }
      index = (index + 1) % mCapacity;
    } while (index != originalIndex);
  }

  // 디버깅용 함수
  void printTable() const {
    std::cout << "Hash Table (size=" << mSize << ", capacity=" << mCapacity
              << "):" << std::endl;
    for (unsigned i = 0; i < mCapacity; ++i) {
      std::cout << "[" << i << "] ";
      if (mTable[i].isEmpty) {
        std::cout << "EMPTY";
      } else if (mTable[i].isDeleted) {
        std::cout << "DELETED";
      } else {
        std::cout << "(" << mTable[i].key << ", " << mTable[i].value << ")";
      }
      std::cout << std::endl;
    }
  }

private:
  unsigned hash(const Key &key) const {
    std::hash<Key> hasher;
    return hasher(key) % mCapacity;
  }

  unsigned findSlot(const Key &key) const {
    unsigned index = hash(key);
    unsigned originalIndex = index;

    do {
      if (mTable[index].isEmpty || mTable[index].isDeleted ||
          mTable[index].key == key) {
        return index;
      }
      index = (index + 1) % mCapacity;
    } while (index != originalIndex);

    return index; // 이론적으로 여기에 도달하면 안 됨
  }

  void rehash() {
    std::vector<KeyValuePair> oldTable = std::move(mTable);
    unsigned oldCapacity = mCapacity;

    mCapacity = nextPrime(mCapacity * 2);
    mTable.clear();
    mTable.resize(mCapacity);
    mSize = 0;

    // 기존 요소들을 새 테이블에 다시 삽입
    for (unsigned i = 0; i < oldCapacity; ++i) {
      if (!oldTable[i].isEmpty && !oldTable[i].isDeleted) {
        insert(oldTable[i].key, oldTable[i].value);
      }
    }
  }

  unsigned nextPrime(unsigned n) const {
    while (!isPrime(n)) {
      ++n;
    }
    return n;
  }

  bool isPrime(unsigned n) const {
    if (n < 2)
      return false;
    if (n == 2)
      return true;
    if (n % 2 == 0)
      return false;

    for (unsigned i = 3; i * i <= n; i += 2) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
};

#endif