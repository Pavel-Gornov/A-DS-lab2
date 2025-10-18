#include <iostream>
#include "LinkedList.h"
#include <random>

struct Lodger {
    char name[64];
    size_t age;
};

std::ostream& operator<<(std::ostream& os, Lodger lodger) {
    os << lodger.name << " (" << lodger.age << ")";
    return os;
}

void task_9(size_t n) {
    const char NAMES[][64] = {"Иван", "Виктор", "Анастасия", "Александр", "Елизавета", "Олег", "Галина", "Владислав", "Виктория", "Михаил"};
    std::random_device rd = std::random_device();
    std::mt19937_64 rand_int = std::mt19937_64(rd());
    std::uniform_int_distribution<size_t> ages = std::uniform_int_distribution<size_t>(16, 50);
    
    LinkedList<Lodger> addres_book[10];
    std::uniform_int_distribution<size_t> idx = std::uniform_int_distribution<size_t>(0, 9);

    for (size_t i = 0; i < n; i++) {
        Lodger l = Lodger();
        strcpy_s(l.name, NAMES[idx(rand_int)]);
        l.age = ages(rand_int);

        addres_book[idx(rand_int)].push_head(l);
    }
    std::cout << "Адресная книга:\n";
    for (size_t i = 0; i < 10; i++) {
        if (!addres_book[i].empty())
            std::cout << " \tКвартира №" << i + 1 << ": " << addres_book[i] << "\n";
    }
}


int main() {
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    std::ios::sync_with_stdio(false);

    task_9(25);
}