#include<iostream>

using namespace std;
class num2;
class num1 {
    int a;
    public:
    num1(int a) {
        this->a = a;
    }

    friend int max(num1, num2);
};

class num2 {
    int b;
    public:
    num2(int b) {
        this->b = b;
    }
    friend int max(num1, num2);
};

int max(num1 x, num2 y) {
    if(x.a > y.b)
        return x.a;
    return y.b;
}

int main() {
    num1 a(2);
    num2 b(4);

    cout << "Maximum no. is " << max(a, b) << endl;
    return 0;
}