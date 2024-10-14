#include "SinglyLinkedList.hpp"

size_t SinglyLinkedList::GetSize() const {
  return size_;
}

int SinglyLinkedList::PushBack(MY_TYPE inp) {
  try {
    if (size_ == 0) {
      first_ = std::make_unique<Node>(inp);
      last_ = first_.get();
    }
    else {
      if (last_ == nullptr) {
        throw std::runtime_error("Error! In SinglyLinkedList::Push!\n");
      }
      last_->next = std::make_unique<Node>(inp);
      last_ = last_->next.get();
    }
    size_++;
    return 0;
  }
  catch (const std::bad_alloc& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}

int SinglyLinkedList::Remove(MY_TYPE inp) {
  if (size_ == 0) {
    std::cout << "Nothing to remove, the list is empty!\n";
    return 1;
  }
  if (first_->data == inp) {
    auto tmp = std::move(first_);
    first_ = std::move(tmp->next);
    size_--;
    return 0;
  }
  auto tmp = first_.get();
  if (tmp == nullptr) {
    throw std::runtime_error("Error! In SinglyLinkedList::Remove!\n");
  }
  while (tmp->next != nullptr) {
    if (tmp->next->data == inp) {
      auto toDelete = std::move(tmp->next);
      tmp->next = std::move(toDelete->next);
      size_--;
      if (tmp->next == nullptr) {
        last_ = tmp;
      }
      return 0;
    }
    tmp = tmp->next.get();
  }
  std::cout << "Not found this number in the list!\n";
  return 0;
}


SinglyLinkedList::SinglyLinkedList() {
  first_ = nullptr;
  last_ = nullptr;
  size_ = 0;
}

SinglyLinkedList::~SinglyLinkedList() {
  //std::cout << "In the destructor...\n";
  if (first_ == nullptr) {
    return;
  }
  while (first_ != nullptr) {
    first_ = std::move(first_->next);
  }
}


std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list) {
  if (list.GetSize() == 0) {
    out << "No elements in the list!\n";
    return out;
  }
  auto tmp = list.first_.get();
  if (tmp == nullptr) {
    throw std::runtime_error("Error! In SinglyLinkedList::operator<<!\n");
  }
  while (tmp->next != nullptr) {
    out << tmp->data << " ";
    tmp = tmp->next.get();
  }
  out << tmp->data << "\n";
  return out;
}