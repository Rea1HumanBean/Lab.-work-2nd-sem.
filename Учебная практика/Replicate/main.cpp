#include <iostream>

void copy(int* a, int * b, int N){
    unsigned long long* pick_up = reinterpret_cast<unsigned long long*>(a);
    unsigned long long* put = reinterpret_cast<unsigned long long*>(b);

    for (int i = 0; i < N / 2 + N % 2; i++) {
        *(put++) = *(pick_up++);
    }
}

int main() {  
    const int N = 10;
    int array_1[N] = { 1, 2, 3, 4 , 5, 6, 7, 8, 9 ,0};
    int array_2[N] = { 0 };
    
    copy(array_1, array_2, N);

    for (int i = 0; i < N; i++) {
        std::cout << array_2[i] << ' ';
    }
}
