#include <iostream>
#include <vector>
using namespace std;

class IShape { 
public: 
    virtual void draw() const = 0; // pure virtual function
    virtual ~IShape() {} 
};

class Button : public IShape { 
public: 
    ~Button() {} 
    void draw() const override { 
        cout << "Button is drawn!" << endl; 
    }
};

class Image : public IShape { 
public: 
    ~Image() {} 
    void draw() const override { 
        cout << "Image is drawn!" << endl; } 
};

class Table : public IShape { 
public: 
    ~Table() {} 
    void draw() const override { 
        cout << "Table is drawn!" << endl; 
    }
};

class GroupShape : public IShape {
public:
    GroupShape(string name) : _name{name} {}
    ~GroupShape() {}
    void add(IShape* shape) {
        shapes.emplace_back(shape);
    }
    void draw() const override {
        cout << "Group Name: " << _name << endl;
        for(const auto& s : shapes)
            (*s).draw();
    }

private:
    string _name;
    vector<IShape*> shapes;
};

int main() {
    GroupShape root("root");
    auto button1 = Button{};
    root.add(&button1);

    auto sub1 = GroupShape("sub1");
    auto button2 = Button{}; sub1.add(&button2);
    auto image1 = Image{}; sub1.add(&image1);
    auto table1 = Table{}; sub1.add(&table1);

    root.add(&sub1);
    root.draw();

    return 0;
}
