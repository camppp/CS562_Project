#ifndef LZZ_ENABLE_INLINE
#include "smtc_NavSubmitFuncDefn.inl"
#endif
#define LZZ_INLINE inline
namespace smtc
{
  class Stack
  {
  private:
    struct Node
    {
      int data;
      Node* next;
      Node(int val) : data(val), next(nullptr) {}
    };
    Node* topNode;

  public:
    Stack() : topNode(nullptr) {}
    ~Stack()
    {
      while (!isEmpty())
      {
        pop();
      }
    }

    void push(int val)
    {
      Node* newNode = new Node(val);
      newNode->next = topNode;
      topNode = newNode;
    }

    void pop()
    {
      if (isEmpty())
      {
        return;
      }
      Node* temp = topNode;
      topNode = topNode->next;
      delete temp;
    }

    int top()
    {
      if (isEmpty())
      {
        throw std::out_of_range("Stack is empty");
      }
      return topNode->data;
    }

    bool isEmpty()
    {
      return topNode == nullptr;
    }
  };
}
