#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list = LinkedList<int>();
    LinkedList<int> list2 = LinkedList<int>();
    list2.push_head(-1);

    list.push_head(1);
    list.push_head(2);
    list.push_head(3);
    list.push_tail(0);
    list.push_head(4);
    list.push_head(4);
    list.push_tail(4);
    list2 = list;

    std::cout << list << '(' << list.size() << ")\n";
    list2.delete_node(4);
    std::cout << list2 << '(' << list2.size() << ")\n";
}