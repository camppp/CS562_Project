#include <iostream>
#include <vector>

using namespace std;

class Variable {
public:
    vector<vector<double>> data;
    vector<vector<bool>> masks;

    Variable(vector<vector<double>> data, vector<vector<bool>> masks) {
        this->data = data;
        this->masks = masks;
    }
};

class Masks {
public:
    vector<vector<bool>> masks;

    Masks(vector<vector<bool>> masks) {
        this->masks = masks;
    }
};

double nansum(Variable var, int dim, Masks masks) {
    // Check for irreducible mask along specified dimension
    if (masks.masks[dim].size() > 0) {
        // Exclude elements corresponding to irreducible mask
        vector<vector<double>> updated_data = var.data;
        vector<vector<bool>> updated_masks = var.masks;
        for (int i = 0; i < updated_data[dim].size(); i++) {
            if (updated_masks[dim][i]) {
                updated_data[dim][i] = 0;
            }
        }
        // Recursively call nansum with updated array
        return nansum(Variable(updated_data, updated_masks), dim, masks);
    } else {
        // Calculate sum of non-NaN elements along specified dimension
        double sum = 0;
        for (int i = 0; i < var.data[dim].size(); i++) {
            if (!var.masks[dim][i]) {
                sum += var.data[dim][i];
            }
        }
        return sum;
    }
}

int main() {
    // Test case 1: No masks
    vector<vector<double>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Variable var(data, vector<vector<bool>>());
    int dim = 0;
    Masks masks(vector<vector<bool>>());
    cout << nansum(var, dim, masks) << endl; // Output: 15

    // Test case 2: Masks along dimension 0
    data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    var = Variable(data, vector<vector<bool>>());
    dim = 0;
    masks = Masks(vector<vector<bool>>({{false, false, true}, {true, false, false}, {false, true, false}}));
    cout << nansum(var, dim, masks) << endl; // Output: 12

    // Test case 3: Masks along dimension 1
    data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    var = Variable(data, vector<vector<bool>>());
    dim = 1;
    masks = Masks(vector<vector<bool>>({{false, false, true}, {true, false, false}, {false, true, false}}));
    cout << nansum(var, dim, masks) << endl; // Output: 12

    return 0;
}
