#include "linked_list.h"
#include <iostream>

// TODO: LinkedList 클래스 구현 작성
LinkedList::LinkedList()
{
    size_ = 0;
    head_ = nullptr;
}

LinkedList::~LinkedList()
{
    for (int i = 0; i < size_; i++)
        delete head_;
}

void LinkedList::print()
{
    for (int i = 0; i < size_; i++) {
        std::cout << get(i) << ' ';
    }
}

void LinkedList::insert(int index, int value)
{
    Node* new_ = new Node(value);
    Node* pre = head_;
    Node* next = head_;
    for (int i = 0; i < index; i ++) {
        pre = pre->next_;
        next = next->next_;
    }
    next = next->next_;

    pre->next_ = new_;
    new_->next_ = next;

    size_++;
}

int LinkedList::get(int index)
{
    Node* n = head_;
    while(index--) {
        n = n->next_;
    }

    return n->value_;
}

void LinkedList::remove(int index)
{
    Node* pre = head_;
    for (int i = 0; i < index - 1; i++) {
        pre = pre->next_;
    }
    Node* cur = pre;
    cur = cur->next_; // index
    Node* next = cur;
    next = next->next_; // index + 1

    pre->next_ = next;
    delete cur;
    size_--;
}