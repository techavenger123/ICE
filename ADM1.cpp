#include <iostream>
#include <vector>
using namespace std;

vector<int> adaptiveDeltaModulation(vector<int>& signal, int initialStepSize, int stepAdjustmentFactor) {
    vector<int> modulated;
    int previousValue = 0;
    int stepSize = initialStepSize;

    for (int i = 0; i < signal.size(); i++) {
        if (signal[i] > previousValue) {
            modulated.push_back(1);previousValue += stepSize;
            stepSize += stepAdjustmentFactor;
        } else {
            modulated.push_back(0);
            previousValue -= stepSize;
            stepSize += stepAdjustmentFactor;
        }
        if (i > 0 && modulated[i] != modulated[i-1]) {
            stepSize = max(initialStepSize, stepSize - stepAdjustmentFactor);
        }
    }

    return modulated;
}

int main() {
    vector<int> signal = {0, 1, 4, 8, 12, 18, 15, 10, 5};
    int initialStepSize = 1;
    int stepAdjustmentFactor = 1;
    vector<int> modulatedSignal = adaptiveDeltaModulation(signal, initialStepSize, stepAdjustmentFactor);
    cout << "Adaptive Modulated signal: ";
    for (int i = 0; i < modulatedSignal.size(); i++) {
        cout << modulatedSignal[i] << " ";
    }
    cout << endl;

    return 0;
}
