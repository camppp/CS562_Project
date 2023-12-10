#include <vector>

std::vector<std::vector<bool>> flipGrid(std::vector<std::vector<bool>> &arr) {
    size_t n = arr[0].size();
    for(size_t i = 0; i < arr.size(); ++i){
        for(size_t j = 0; j < (n+1)/2; ++j){
            arr[i][j] = !arr[i][j];
            if(j < n-j-1) arr[i][n-j-1] = !arr[i][n-j-1];
        }
    }
    return arr;
}
