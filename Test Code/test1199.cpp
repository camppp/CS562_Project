#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CFabricVektor {
public:
    virtual CVektor* Create() = 0;
};

class CFabricVektor0 : public CFabricVektor {
public:
    CVektor* Create() override {
        return new CVektor0();
    }
};

class CFabricVektor1 : public CFabricVektor {
public:
    CVektor* Create() override {
        return new CVektor1();
    }
};

class CVektor {
public:
    virtual void Print() const = 0;
    static void Input(const string& filename, vector<CVektor*>& v, const vector<CFabricVektor*>& fabric) {
        ifstream file(filename);
        int type;
        double x, y;
        while (file >> type >> x >> y) {
            if (type >= 0 && type < fabric.size()) {
                v.push_back(fabric[type]->Create());
                v.back()->SetCoordinates(x, y);
            }
        }
        file.close();
    }
    static void ParallelTest(const vector<CVektor*>& v) {
        // Perform parallel test on vectors
        // ...
    }
};

class CVektor0 : public CVektor {
public:
    void Print() const override {
        cout << "CVektor0: (" << x << ", " << y << ")" << endl;
    }
    void SetCoordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }
private:
    double x, y;
};

class CVektor1 : public CVektor {
public:
    void Print() const override {
        cout << "CVektor1: (" << x << ", " << y << ")" << endl;
    }
    void SetCoordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }
private:
    double x, y;
};

int main() {
    vector<CFabricVektor*> fabric;
    vector<CVektor*> v;

    fabric.push_back(new CFabricVektor0);
    fabric.push_back(new CFabricVektor1);

    CVektor::Input("input.txt", v, fabric);
    CVektor::ParallelTest(v);

    // Clean up memory
    for (auto& vec : v) {
        delete vec;
    }
    for (auto& fab : fabric) {
        delete fab;
    }

    return 0;
}
