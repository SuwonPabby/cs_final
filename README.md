# C++ 자료구조 구현 프로젝트 (Final Term 대비)

이 프로젝트는 C++ 기말고사에서 자주 출제되는 모든 자료구조들을 구현한 완전한 코드 모음입니다.

## 📁 프로젝트 구조

```
cs_final/
├── vector/                    # smcVector (동적 배열)
│   ├── smcVector.hpp         # 헤더 및 구현
│   ├── test_vector.cpp       # 테스트 코드
│   └── Makefile              # 컴파일 설정
├── singlylist/               # SinglyList (단일 연결 리스트)
│   ├── SinglyList.hpp        # 헤더 및 구현
│   ├── test_singlylist.cpp   # 테스트 코드
│   └── Makefile              # 컴파일 설정
├── doublelist/               # DoubleList (이중 연결 리스트)
│   ├── DoubleList.hpp        # 헤더 및 구현
│   ├── test_doublelist.cpp   # 테스트 코드
│   └── Makefile              # 컴파일 설정
├── bst/                      # BST (이진 탐색 트리)
│   ├── BST.hpp               # 헤더 및 구현
│   ├── test_bst.cpp          # 테스트 코드
│   └── Makefile              # 컴파일 설정
├── hashmap/                  # HashMap (해시 맵)
│   ├── HashMap.hpp           # 헤더 및 구현
│   ├── test_hashmap.cpp      # 테스트 코드
│   └── Makefile              # 컴파일 설정
├── graph/                    # Graph (그래프)
│   ├── Graph.hpp             # 헤더 및 구현
│   ├── test_graph.cpp        # 테스트 코드
│   └── Makefile              # 컴파일 설정
└── README.md                 # 이 파일
```

## 🎯 Final Term 범위별 구현 자료구조

### Week 9: Vectors

- **smcVector**: 동적 배열 (std::vector와 유사)
- 자동 크기 조정, 인덱스 접근, push_back/pop_back

### Week 10: Linked Lists

- **SinglyList**: 단일 연결 리스트 (forward_list와 유사)
- **DoubleList**: 이중 연결 리스트 (std::list와 유사)
- Iterator 지원, 양방향 탐색

### Week 11: Trees

- **BST**: 이진 탐색 트리
- 삽입, 삭제, 탐색, 트리 순회 (In/Pre/Post/Level-order)

### Week 13: Hash Maps

- **HashMap**: 해시 맵 (std::unordered_map와 유사)
- Linear probing, 동적 rehashing, 충돌 처리

### Week 14-15: Graphs & Dijkstra

- **Graph**: 인접 리스트 기반 그래프
- **WeightedGraph**: 가중치 그래프
- BFS/DFS 탐색, 사이클 감지, Dijkstra 알고리즘

## 🚀 빠른 시작

각 자료구조를 테스트하려면 해당 폴더에서:

```bash
cd [폴더명]
make run    # 컴파일 후 바로 실행
```

또는 단계별로:

```bash
make        # 컴파일만
./test_*    # 실행
make clean  # 정리
```

## 📚 자료구조별 상세 설명

### 1. smcVector (동적 배열)

**위치**: `vector/`
**주요 기능**:

- 동적 메모리 관리 (초기 용량: 10, 2배씩 확장)
- `push_back()`, `pop_back()`, `operator[]`
- `size()`, `capacity()`, `clear()`

**시험 포인트**:

- pop_back 구현 (크기만 감소, 메모리는 유지)
- 용량 확장 로직
- 깊은 복사 (복사 생성자, 대입 연산자)

### 2. SinglyList (단일 연결 리스트)

**위치**: `singlylist/`
**주요 기능**:

- `push_front()`, `pop_front()`, `push_back()`
- `insert_after()`, `erase_after()`
- `reverse()` - 리스트 뒤집기

**시험 포인트**:

- 노드 연결/해제 로직
- reverse 알고리즘 구현
- Iterator 패턴

### 3. DoubleList (이중 연결 리스트)

**위치**: `doublelist/`
**주요 기능**:

- 양방향 삽입/삭제: `push_front()`, `push_back()`, `pop_front()`, `pop_back()`
- Iterator 지원: `begin()`, `end()`, `insert()`, `erase()`
- 양방향 탐색

**시험 포인트**:

- 이중 포인터 관리 (mNext, mPrev)
- Iterator 구현
- 임의 위치 삽입/삭제

### 4. BST (이진 탐색 트리)

**위치**: `bst/`
**주요 기능**:

- 삽입, 삭제, 검색 (O(log n) 평균)
- 트리 순회: In-order, Pre-order, Post-order, Level-order
- `findMin()`, `findMax()`, `height()`

**시험 포인트**:

- 노드 삭제 3가지 경우 (자식 0개, 1개, 2개)
- 트리 순회 알고리즘 (재귀 vs 반복)
- BST 성질 유지

### 5. HashMap (해시 맵)

**위치**: `hashmap/`
**주요 기능**:

- Linear probing으로 충돌 처리
- 동적 rehashing (로드팩터 0.7 초과시)
- `insert()`, `find()`, `remove()`, `operator[]`

**시험 포인트**:

- 해시 함수 구현
- 충돌 해결 (Linear probing)
- Rehashing 로직

### 6. Graph (그래프)

**위치**: `graph/`
**주요 기능**:

- 인접 리스트 표현
- BFS/DFS 탐색 (재귀, 반복)
- 사이클 감지, 연결성 검사
- Dijkstra 최단 경로 알고리즘

**시험 포인트**:

- BFS vs DFS 차이점
- 그래프 표현 방법
- Dijkstra 알고리즘 구현

## 🎯 시험 대비 핵심 포인트

### 자주 출제되는 구현 문제:

1. **smcVector::pop_back()** - 크기만 감소
2. **DoubleList 대입 연산자** - 깊은 복사
3. **SinglyList::reverse()** - 포인터 조작
4. **BST 노드 삭제** - 3가지 경우 처리
5. **그래프 BFS/DFS** - 큐/스택 사용

### 메모리 관리:

- 모든 동적 할당에 대응하는 해제
- 복사 생성자/대입 연산자에서 깊은 복사
- 자기 대입 방지 (`if (this != &other)`)

### 알고리즘 복잡도:

- Vector: 접근 O(1), 삽입 O(1) amortized
- Linked List: 삽입/삭제 O(1), 접근 O(n)
- BST: 모든 연산 O(log n) 평균, O(n) 최악
- HashMap: 모든 연산 O(1) 평균
- Graph: BFS/DFS O(V+E), Dijkstra O((V+E)log V)

## 🔧 컴파일 요구사항

- **C++11 이상**
- **g++ 컴파일러**
- 모든 구현이 헤더 파일에 포함됨 (템플릿 특성상)

## 📝 사용 예시

```cpp
// Vector 사용
smcVector<int> vec;
vec.push_back(10);
vec.push_back(20);
std::cout << vec[0] << std::endl; // 10

// BST 사용
BST<int> tree;
tree.insert(50);
tree.insert(30);
tree.inOrder(); // 정렬된 순서로 출력

// Graph 사용
Graph g(5, false); // 5개 정점, 무방향
g.addEdge(0, 1);
g.BFS(0); // BFS 탐색
```

이 프로젝트의 모든 구현은 시험에서 직접 묻는 형태로 작성되었습니다. 각 자료구조를 이해하고 핵심 메서드들을 손으로 구현할 수 있도록 연습하세요! 🎓
