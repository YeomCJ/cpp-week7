#include "queue.h"
#include <iostream>

// TODO: Queue 클래스 구현 작성
Queue::Queue() {}

void Queue::push(int data)
{ // Queue의 정의에 맞게 데이터를 삽입한다.
    LinkedList::insert(size_,data);
}
int Queue::pop()
{ // Queue의 정의에 맞게 데이터를 꺼내고 적절한 메모리를 해제한다.
    int data = peek();
    LinkedList::remove(0);
    return data;
}
int Queue::peek()
{
    return LinkedList::get(0);
}

Queue& Queue::operator+=(int data)
{
    push(data);
    return *this;
}
