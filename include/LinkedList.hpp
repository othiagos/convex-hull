#pragma once

template <typename T>
struct NodeLinkedList {
    NodeLinkedList *next = nullptr;
    NodeLinkedList *prev = nullptr;
    T item;
};

template <typename T>
class LinkedList {
  private:
    NodeLinkedList<T> *first;
    NodeLinkedList<T> *last;
    int size;

    NodeLinkedList<T> *position(int pos) const {
        NodeLinkedList<T> *p = first;

        if ((pos > size) || (pos < 0))
            throw "ERROR: invalid position!";

        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        return p;
    }

    NodeLinkedList<T> *position_before(int pos) {
        NodeLinkedList<T> *p = first;
        int i;

        if ((pos > size) || (pos <= 0))
            throw "ERROR: invalid position!";

        for (i = 1; i < pos; i++) {
            p = p->next;
        }
        return p;
    }

  public:
    LinkedList() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    LinkedList(const LinkedList<T> &o) {
        first = nullptr;
        last = nullptr;
        size = 0;

        for (int i = 0; i < o.get_size(); i++) {
            T item = o.get_item(i);
            this->push_back(T(item));
        }
    }

    ~LinkedList() {
        clear();
    }

    int get_size() const {
        return this->size;
    }

    T get_item(int pos) const {
        NodeLinkedList<T> *p;
        p = position(pos);
        return p->item;
    }

    T &operator[](int pos) {
        NodeLinkedList<T> *p;
        p = position(pos);
        return p->item;
    }

    void set_item(T item, int pos) {
        NodeLinkedList<T> *p;

        p = position(pos);
        p->item = item;
    }

    void push_front(T item) {
        NodeLinkedList<T> *node = new NodeLinkedList<T>();

        node->item = item;
        node->next = first;
        if (first != nullptr)
            first->prev = node;
        first = node;
        size++;

        if (node->next == nullptr)
            last = node;
    }

    void push_back(T item) {

        if (size != 0) {
            NodeLinkedList<T> *node = new NodeLinkedList<T>();
            node->item = item;
            node->prev = last;
            last->next = node;
            last = node;
            size++;
        } else
            push_front(item);
    }

    void insert(T item, int pos) {
        if (pos != 0) {
            NodeLinkedList<T> *p, *node = new NodeLinkedList<T>();
            p = position_before(pos);

            node->item = item;
            node->next = p->next;
            if (p->next != nullptr)
                p->next->prev = node;
            p->next = node;
            node->prev = p;
            size++;

            if (node->next == nullptr)
                last = node;
        } else
            push_front(item);
    }

    T pop_front() {
        T aux;
        NodeLinkedList<T> *p;

        if (size == 0)
            throw "ERROR: Empty list!";

        p = first;
        first = p->next;
        if (first != nullptr)
            first->prev = nullptr;
        size--;

        if (first != nullptr && first->next == nullptr)
            last = first;

        if (first == nullptr)
            last = first;

        aux = p->item;
        delete p;

        return aux;
    }

    T pop_back() {
        T aux;
        NodeLinkedList<T> *p;

        if (size == 0)
            throw "ERROR: Empty list!";

        p = position(size - 1);
        last = p->prev;
        if (last != nullptr)
            last->next = nullptr;
        else
            first = nullptr;
        size--;

        aux = p->item;

        delete p;
        return aux;
    }

    T erase(int pos) {
        T aux;
        NodeLinkedList<T> *p;

        if (size == 0)
            throw "ERROR: Empty list!";

        if (pos == 0)
            return pop_front();

        if (pos == size - 1)
            return pop_back();

        p = position(pos);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        size--;

        aux = p->item;
        delete p;
        return aux;
    }

    void clear() {
        NodeLinkedList<T> *p;

        p = first;
        while (p != nullptr) {
            first = p->next;
            delete p;
            p = first;
        }
        last = nullptr;
        size = 0;
    }
};
