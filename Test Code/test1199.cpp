#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class CVektor {
public:
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getZ() const = 0;
    virtual void setX(double x) = 0;
    virtual void setY(double y) = 0;
    virtual void setZ(double z) = 0;
    virtual double length() const = 0;
    virtual double dot(const CVektor& other) const = 0;
    virtual CVektor& operator+(const CVektor& other) = 0;
    virtual CVektor& operator-(const CVektor& other) = 0;
    virtual CVektor& operator*(double scalar) = 0;
    virtual CVektor& operator/(double scalar) = 0;
    virtual bool operator==(const CVektor& other) const = 0;
    virtual bool operator!=(const CVektor& other) const = 0;
};

class CFabricVektor {
public:
    virtual CVektor* createVektor(double x, double y, double z) = 0;
};

class CFabricVektor0 : public CFabricVektor {
public:
    virtual CVektor* createVektor(double x, double y, double z) {
        return new CVektor0(x, y, z);
    }
};

class CVektor0 : public CVektor {
public:
    CVektor0(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX() const override { return x; }
    double getY() const override { return y; }
    double getZ() const override { return z; }
    void setX(double x) override { this->x = x; }
    void setY(double y) override { this->y = y; }
    void setZ(double z) override { this->z = z; }
    double length() const override { return sqrt(x*x + y*y + z*z); }
    double dot(const CVektor& other) const override {
        const CVektor0& other0 = dynamic_cast<const CVektor0&>(other);
        return x*other0.x + y*other0.y + z*other0.z;
    }
    CVektor& operator+(const CVektor& other) override {
        const CVektor0& other0 = dynamic_cast<const CVektor0&>(other);
        return CVektor0(x + other0.x, y + other0.y, z + other0.z);
    }
    CVektor& operator-(const CVektor& other) override {
        const CVektor0& other0 = dynamic_cast<const CVektor0&>(other);
        return CVektor0(x - other0.x, y - other0.y, z - other0.z);
    }
    CVektor& operator*(double scalar) override {
        return CVektor0(x * scalar, y * scalar, z * scalar);
    }
    CVektor& operator/(double scalar) override {
        return CVektor0(x / scalar, y / scalar, z / scalar);
    }
    bool operator==(const CVektor& other) const override {
        const CVektor0& other0 = dynamic_cast<const CVektor0&>(other);
        return x == other0.x && y == other0.y && z == other0.z;
    }
    bool operator!=(const CVektor& other) const override {
        const CVektor0& other0 = dynamic_cast<const CVektor0&>(other);
        return x != other0.x || y != other0.y || z != other0.z;
    }
private:
    double x, y, z;
};

class CFabricVektor1 : public CFabricVektor {
public:
    virtual CVektor* createVektor(double x, double y, double z) {
        return new CVektor1(x, y, z);
    }
};

class CVektor1 : public CVektor {
public:
    CVektor1(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX() const override { return x; }
    double getY() const override { return y; }
    double getZ() const override { return z; }
    void setX(double x) override { this->x = x; }
    void setY(double y) override { this->y = y; }
    void setZ(double z) override { this->z = z; }
    double length() const override { return sqrt(x*x + y*y + z*z); }
    double dot(const CVektor& other) const override {
        const CVektor1& other1 = dynamic_cast<const CVektor1&>(other);
        return x*other1.x + y*other1.y + z*other1.z;
    }
    CVektor& operator+(const CVektor& other) override {
        const CVektor1& other1 = dynamic_cast<const CVektor1&>(other);
        return CVektor1(x + other1.x, y + other1.y, z + other1.z);
    }
    CVektor& operator-(const CVektor& other) override {
        const CVektor1& other1 = dynamic_cast<const CVektor1&>(other);
        return CVektor1(x - other1.x, y - other1.y, z - other1.z);
    }
    CVektor& operator*(double scalar) override {
        return CVektor1(x * scalar, y * scalar, z * scalar);
    }
    CVektor& operator/(double scalar) override {
        return CVektor1(x / scalar, y / scalar, z / scalar);
    }
    bool operator==(const CVektor& other) const override {
        const CVektor1& other1 = dynamic_cast<const CVektor1&>(other);
        return x == other1.x && y == other1.y && z == other1.z;
    }
    bool operator!=(const CVektor& other) const override {
        const CVektor1& other1 = dynamic_cast<const CVektor1&>(other);
        return x != other1.x || y != other1.y || z != other1.z;
    }
private:
    double x, y, z;
};

void CVektor::Input(const string& filename, vector<CVektor*>& v, const vector<CFabricVektor*>& fabric) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: unable to open file " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ' ');
        if (tokens.size() != 3) {
            cout << "Error: invalid input format" << endl;
            return;
        }
        double x = stod(tokens[0]);
        double y = stod(tokens[1]);
        double z = stod(tokens[2]);
        v.push_back(fabric[0]->createVektor(x, y, z));
    }
}

void CVektor::ParallelTest(const vector<CVektor*>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            double dot = v[i]->dot(*v[j]);
            double dist = v[i]->length() + v[j]->length() - dot;
            if (dist > 1e-6) {
                cout << "Error: vectors " << i << " and " << j << " are not parallel" << endl;
                return;
            }
        }
    }
    cout << "Vectors are parallel" << endl;
}

int main() {
    vector<CVektor*> v;
    vector<CFabricVektor*> fabric;
    fabric.push_back(new CFabricVektor0());
    fabric.push_back(new CFabricVektor1());
    CVektor::Input("input.txt", v, fabric);
    CVektor::ParallelTest(v);
    return 0;
}
