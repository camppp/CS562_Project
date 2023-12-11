#include <iostream>
#include <vector>

using namespace std;

int maxQualityOfWine(int n, vector<int> barrels) {
    // Initialize the maximum quality of wine to 0
    int maxQuality = 0;

    // Loop through each barrel
    for (int i = 0; i < n; i++) {
        // Get the current barrel's quality
        int currentQuality = barrels[i];

        // Loop through each barrel that can be poured into
        for (int j = 0; j < n; j++) {
            // If the current barrel is not the same as the barrel being poured into
            if (i != j) {
                // Get the barrel being poured into's current quality
                int pouredInQuality = barrels[j];

                // Calculate the amount of wine that can be poured into the barrel being poured into
                int pouredInAmount = min(currentQuality, 1000 - pouredInQuality);

                // Update the barrel being poured into's quality
                barrels[j] += pouredInAmount;

                // Update the maximum quality of wine
                maxQuality = max(maxQuality, barrels[j]);
            }
        }
    }

    return maxQuality;
}

int main() {
    int n;
    cin >> n;

    vector<int> barrels(n);
    for (int i = 0; i < n; i++) {
        cin >> barrels[i];
    }

    int maxQuality = maxQualityOfWine(n, barrels);

    cout << "Maximum quality of wine: " << maxQuality << endl;

    return 0;
}
