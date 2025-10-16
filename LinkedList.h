# ifndef LINKED_LIST_H
# define LINKED_LIST_H

template<typename T>
class LinkedList {
private:
    struct Node {
        Node(T value): value(value), prev(nullptr), next(nullptr) {}
        Node* prev;
        T value;
        Node* next;
    };

    Node* head_;
    Node* tail_;
    size_t size_;
public:
    LinkedList(): head_(nullptr), tail_(nullptr), size_(0) {}

    LinkedList(const LinkedList& list);
    LinkedList& operator=(const LinkedList& list);
    ~LinkedList() {
        Node* temp = head_;
        while (head_ && head_->next) {
            temp = head_;
            delete temp;
            head_ = head_->next;
        }
    }

    size_t size() const { return size_; }

    void push_head(T value) {
        Node* node = new Node(value);
        if (!head_) {
            head_ = node; return;
        }
        head_->prev = node;
        node->next = head_;
        head_ = node;
    }

    void push_head(const LinkedList& list);

    void push_tail(T value);
    void push_tail(const LinkedList& list);

    void pop_head();
    void pop_tail();

    void delete_node(T value);

    T& operator[](size_t idx);
    T operator[](size_t idx) const;
};

#endif // LINKED_LIST_H