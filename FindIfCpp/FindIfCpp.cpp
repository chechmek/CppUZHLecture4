#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

int main()
{
    int elem_count = 10000000; // 10 000 000

    vector<int> int_vector;
    int_vector.reserve(elem_count);
    for (int i = 0; i < elem_count; ++i) {
        int_vector.push_back(i);
    }
    vector<string> str_vector;
    str_vector.reserve(elem_count);
    for (int i = 0; i < elem_count; ++i) {
        str_vector.push_back(std::to_string(i));
    }

    auto t1 = high_resolution_clock::now();
    vector<int>::iterator itInt = find_if(int_vector.begin(), int_vector.end(), 
        [elem_count](int i) {
        return i == elem_count - 1; 
        });
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_int_double = t2 - t1;
    cout << "int ms: " << ms_int_double.count() << endl;

    auto tStr1 = high_resolution_clock::now();
    vector<string>::iterator itStr = find_if(str_vector.begin(), str_vector.end(),
        [elem_count](string i) {
            return i == to_string(elem_count - 1);
        });
    auto tStr2 = high_resolution_clock::now();
    duration<double, std::milli> ms_str_double = tStr2 - tStr1;
    cout << "str ms: " << ms_str_double.count() << endl;
}
