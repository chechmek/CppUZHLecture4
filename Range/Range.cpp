#include <iostream>

using namespace std;

class range {
private:
    int a;
    int b;

public:
    class r_iterator {
        int* ptr;
    public:
        r_iterator(int* p) : ptr(p) {}
        int* begin() {
            return ptr;
        }
        int* end() {
            return nullptr;
        }
        int& operator++() {
            ++*ptr;
            return *ptr;
        }
        friend bool operator!= (const r_iterator& a, const r_iterator& b) { return *a.ptr != *b.ptr + 1; };
        int operator*() const { return *ptr; }
    };

    range(int a, int b) {
        this->a = a;
        this->b = b;
    };

    r_iterator begin() {
        return r_iterator(&a);
    }
    r_iterator end() {
        return r_iterator(&b);
    }
};


int main()
{
    for (auto i : range(10, 200))
        cout << i << endl;
}