#include <iostream>

template<typename T>
void Faster_copy(T a_begin, T b_begin, int size) {
    long long* ptr_1 = (long long*)(a_begin);
    long long* ptr_b = (long long*)(b_begin);
    int count = sizeof(T) * size / sizeof(long long);
    for(int i = 0; i < count; ++i) {
        *(ptr_b ++) = *(ptr_1 ++);
    }

    int* ptr_2 = (int*)ptr_1;
    int* ptr_2b = (int*)ptr_b;
    count = ((sizeof(T) * size) % sizeof(long long)) / sizeof(int);
    for(int i = 0; i < count; ++i) {
        *(ptr_2b ++) = *(ptr_2++);
    }
    char* ptr_3 = (char*)ptr_2;
    char* ptr_3b = (char*)ptr_2b;
    count = ((sizeof(T) * size) % sizeof(long long)) % sizeof(int);
    for (int i = 0; i < count; ++i) {
        *(ptr_3b++) = *(ptr_3++);
    }
}

int main() {
    const int n = 10;
    char mas_a[n] = { 0,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 };
    char mas_b[n];
    Faster_copy(mas_a, mas_b, n);

    for (int i = 0; i < n; ++i) {
        std::cout << (int)mas_b[i] << std::endl;
    }
    return 0;
}
