#include <iostream>

using namespace std;

/**
 * \brief Class A
 *
 */
class A_class {
public:
    A_class(int a) : a_(a){};

    int get() {
        return a_;
    }

private:
    int a_;
};

/**
 * \brief Class B
 *
 */
class B_class {
public:
    B_class(int a, int b) : a_(a), b_(b){};

    int get() {
        return a_ + b_;
    }

private:
    int a_;
    int b_;
};

/**
 * \brief Class container, including classes A and B
 *
 */
class Container {
public:
    Container(int a, int b, int c) : a_class_(a), b_class_(b, c){};

    int get_a() {
        return a_class_.get();
    }

    int get_b() {
        return b_class_.get();
    }

private:
    A_class a_class_;
    B_class b_class_;
};

int main() {
    Container c = Container(4, 8, 2);
    cout << c.get_a() << endl;
    cout << c.get_b() << endl;
    return 0;
}