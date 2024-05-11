#include "stack.h"

// TODO: Stack 클래스 구현 작성
Stack::Stack() {}

void Stack::push(int data)
{   // Stack의 정의에 맞게 데이터를 삽입한다.
    LinkedList::insert(0,data);
}
int Stack::pop() 
{   // Stack의 정의에 맞게 데이터를 꺼내고 적절한 메모리를 해제한다.
    int poppedData = peek(); // 스택의 맨 위 데이터를 가져옵니다.
    LinkedList::remove(0);   // 스택의 맨 위 데이터를 삭제합니다.
    return poppedData;       // 꺼낸 데이터를 반환합니다.
}
int Stack::peek()
{
    return LinkedList::get(0); // 스택의 맨 위 데이터를 반환합니다.
}

Stack& Stack::operator+=(int s) {
    push(s);
    return *this;
}