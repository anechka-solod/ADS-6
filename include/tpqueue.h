// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            pop();
        }
    }
    void push(const T& item) {
      Node* newNode = new Node(item);
      if (!head || head->data.prior < item.prior) {
        newNode->next = head;
        head = newNode;
        return;
      }
      Node* current = head;
      while (current->next && current->next->data.prior >= item.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
    T pop() {
      if (!head) throw "Queue is empty";
      Node* temp = head;
      T data = head->data;
      head = head->next;
      delete temp;
      return data;
    }
    bool isEmpty() const {
      return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
