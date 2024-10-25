#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <memory>

using MY_TYPE = int;

class SinglyLinkedList {
private:
  struct Node {
    const MY_TYPE data;
    std::unique_ptr<Node> next;
    explicit Node(const MY_TYPE _data) : data{_data}, next{nullptr} {};
    ~Node() {
      std::cout << "Node destructor working...\n";
    }
  };
  std::unique_ptr<Node> first_;
  Node* last_;
  size_t size_;
public:
  size_t GetSize() const;
  int PushBack(const MY_TYPE inp);
  int Remove(const MY_TYPE inp);
  SinglyLinkedList();
  ~SinglyLinkedList();

  SinglyLinkedList(const SinglyLinkedList& other) = delete;
  SinglyLinkedList(SinglyLinkedList&& tmp) = delete;
  SinglyLinkedList& operator=(const SinglyLinkedList& other) = delete;
  SinglyLinkedList& operator=(SinglyLinkedList&& tmp) = delete;

  friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list);
};

#endif // SINGLY_LINKED_LIST_HPP