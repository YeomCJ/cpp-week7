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
    delete head_;
}

// 각 노드의 데이터를 출력합니다.
void LinkedList::print()
{
    Node* current = head_;
    int n = size_;
    while (n--) {
        std::cout << current->value_ << " "; 
        current = current->next_;
    }
    std::cout << std::endl;
}

void LinkedList::insert(int index, int value)
{
    if (index < 0 || index > size_) {
        std::cerr << "Invalid index\n";
        return;
    }
    Node* new_ = new Node(value);
    if (index == size_) { // 맨 뒤에 삽입하는 경우
        if (size_ == 0) { // 리스트가 비어있는 경우
            head_ = new_;
        } else {
            Node* current = head_;
            for (int i = 0; i < index - 1; i++) {
                current = current->next_;
            }
            current->next_ = new_;
        }
    } else if (index == 0) { // 맨 앞에 삽입하는 경우
        new_->next_ = head_;
        head_ = new_;
    } else { // 중간에 삽입하는 경우
        Node* pre = head_;
        for (int i = 0; i < index - 1; i++) {
            pre = pre->next_;
        }
        new_->next_ = pre->next_;
        pre->next_ = new_;
    }
    size_++;
}

void LinkedList::remove(int index)
{
    if (index < 0 || index > size_) {
        std::cerr << "Invalid index\n";
        return;
    }
    Node* temp;
    if (index == 0) {
        temp = head_;
        head_ = head_->next_;
    } else {
        Node* pre = head_;
        for (int i = 0; i < index - 1; i++) {
            pre = pre->next_;
        }
        temp = pre->next_;
        pre->next_ = temp->next_;
    }
    delete temp;
    size_--;
}
int LinkedList::get(int index)
{
    Node* n = head_;
    while(index--) {
        n = n->next_;
    }

    return n->value_;
}