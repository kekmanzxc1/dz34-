#include <iostream>
#include <string>

class IPrint {
public:
    virtual void print() const = 0;
    virtual ~IPrint() = default;
};

template <typename T, int Size>
class Array : public IPrint {
private:
    T data[Size];

public:
    Array(const T(&arr)[Size]) {
        for (int i = 0; i < Size; ++i) {
            data[i] = arr[i];
        }
    }

    void print() const override {
        for (int i = 0; i < Size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Team : public IPrint {
private:
    std::string name;
    int score;

public:
    Team(const std::string& teamName, int teamScore) : name(teamName), score(teamScore) {}

    void print() const override {
        std::cout << "Team: " << name << ", Score: " << score << std::endl;
    }
};

class Unit : public IPrint {
private:
    std::string unitName;
    int health;

public:
    Unit(const std::string& name, int hp) : unitName(name), health(hp) {}

    void print() const override {
        std::cout << "Unit: " << unitName << ", Health: " << health << std::endl;
    }
};

int main() {
    int intArray[] = { 1, 2, 3, 4, 5 };
    Array<int, 5> arr(intArray);
    arr.print();

    Team team("Warriors", 100);
    team.print();

    Unit unit("Knight", 75);
    unit.print();
}
