// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
  struct Item {
    T item;
    Item* next;
  };
  Item* first;
  Item* last;

 public:
    TPQueue(): first(nullptr), last(nullptr) {}
    void push(const T& value) {
      Item* temp = new Item;
      temp->item = value;
      temp->next = nullptr;
      if (first == nullptr) { //Если один
        first = temp;
        last = temp;
        return;//закончили на этом
      }
      if (last->item.prior < value.prior) {
        temp->next = first;
        first = temp;
        return;//и на этом закончили
      }
      Item* i = first;
      bool f = i->next != nullptr && i->next->item.prior >= value.prior;
      while (f) {
        i = i->next;
        f = i->next != nullptr && i->next->item.prior >= value.prior;
      }
      temp->next = i->next;
      i->next = temp;
      if (temp->next == nullptr)
      last = temp;
      delete f;
    }
    const T pop() {
      Item* temp = first;
      T otv = temp->item;
      first = first->next;
      delete temp;
      return otv;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
