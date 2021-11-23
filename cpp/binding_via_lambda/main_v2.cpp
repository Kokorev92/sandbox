#include <functional>
#include <iostream>
#include <utility>

using namespace std;

class Worker {
public:
    Worker() {}

    float get_data() {
        return data_;
    }

private:
    float data_ = 0.53;
};

class Displayer {
public:
    Displayer(std::function<float()>& func) : func_(func) {}

    void display() {
        if (func_ != nullptr) {
            cout << func_() << endl;
        }
    }

private:
    std::function<float()>& func_;
};

Worker w;

std::function<float()> getter = []() -> float { return w.get_data(); };


int main() {
    Displayer d(getter);

    d.display();

    getter = []() -> float { return 0.111; };

    d.display();

    getter = nullptr;

    d.display();

    return 0;
}