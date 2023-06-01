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

    NodeLinkedList<T> *position(int pos) {
        NodeLinkedList<T> *p;
        int i;

        if ((pos > size) || (pos < 0))
            throw "ERROR: invalid position!";

        // Posiciona na célula desejada
        p = first;
        for (i = 0; i < pos; i++) {
            p = p->next;
        }

        return p;
    }

    NodeLinkedList<T> *position_before(int pos) {
        NodeLinkedList<T> *p;
        int i;

        if ((pos > size) || (pos <= 0))
            throw "ERRO: Posicao Invalida!";

        // Posiciona na célula anterior a desejada
        p = first;
        for (i = 1; i < pos; i++) {
            p = p->next;
        }

        return p;
    }

  public:
    LinkedList() {
        first = nullptr;
        last = first;
        size = 0;
    }

    ~LinkedList() {
        clear();
        delete first;
    }

    int get_size() {
        return this->size;
    }

    T get_item(int pos) {
        NodeLinkedList<T> *p;
        p = position(pos);
        return p->item;
    }

    // T& operator[](int pos) {
    //     NodeLinkedList<T> *p;
    //     p = position(pos);
    //     return p->item;
    // }

    void set_item(T item, int pos) {
        NodeLinkedList<T> *p;

        p = position(pos);
        p->item = item;
    }

    void push_front(T item) {
        NodeLinkedList<T> *node = new NodeLinkedList<T>();

        node->item = item;
        node->next = first;
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
        }
        else
            push_front(item);
    }

    void insert(T item, int pos) {
        NodeLinkedList<T> *p, *node = new NodeLinkedList<T>();
        p = position_before(pos);

        node->item = item;
        node->next = p->next;
        p->next->prev = node;
        p->next = node;
        node->prev = p;
        size++;

        if (node->prox == nullptr)
            last = node;
    }

    T pop_front() {
        T aux;
        NodeLinkedList<T> *p;

        if (size == 0)
            throw "ERROR: Empty list!";

        p = first;
        first = p->next;
        first->prev = nullptr;
        size--;

        if (first->prox == nullptr)
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

        p = position(size);
        last = p->prev;
        last->next = nullptr;
        size--;

        aux = p->item;

        delete p;
        return aux;
    }

    T erase(int pos) {
        T aux;
        NodeLinkedList<T> *p, *q;

        if (size == 0)
            throw "ERRO: Lista vazia!";

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

    int find(T c) {
        int pos = -1;
        NodeLinkedList<T> *p;

        if (size == 0)
            throw "ERRO: Lista vazia!";

        p = first;
        for (int i = 0; p != nullptr; i++) {
            if (p->item == c) {
                pos = i;
                break;
            }
            p = p->next;
        }

        return pos;
    }

    void clear() {
        NodeLinkedList<T> *p;

        p = first;
        while (p != nullptr) {
            first = p->next;
            delete p;
            p = first;
        }
        first = nullptr;
        last = nullptr;
        size = 0;
    }
};
