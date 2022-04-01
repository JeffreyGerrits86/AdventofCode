#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void AddtoCounters();
void binaryStrings();
void CalculateRate();
string readOuts[] = { "00100", "11110", "10110", "10111", "10101", "01111", "00111", "11100", "10000", "11001", "00010", "01010" };
int NumberList[5];
string gamma = "";
string epsilon = "";
int gammaRate = 0;
int epsilonRate = 0;
int powerConsumption;

void main(void)
{
    AddtoCounters();
    binaryStrings();
    cout << gamma << "\n";
    cout << epsilon << "\n";
    CalculateRate();
    cout << gammaRate << "\n";
    cout << epsilonRate << "\n";
    powerConsumption = gammaRate * epsilonRate;
    cout << "The power consumption is " << powerConsumption << "\n";
}

void AddtoCounters()
{
    for (int i = 0; i < 12; i++) {
        string thisBinary = readOuts[i];
        for (int j = 0; j < 5; j++) {
            char thisBit = thisBinary[j];
            if (thisBit == '1') {
                NumberList[j]++;
            }
        }
    }
}

void binaryStrings()
{
    for (int i = 0; i < 5; i++) {
        int numberCount = NumberList[i];
        if (numberCount > 6) {
            gamma.append("1");
            epsilon.append("0");
        }
        else {
            gamma.append("0");
            epsilon.append("1");
        }
    }
}

void CalculateRate()
{
    int deNominator = gamma.length() - 1;
    for (int i = 0; i < 5; i++) {
        if (gamma[i] == '1') {
            gammaRate += pow(2, deNominator);
        }
        if (epsilon[i] == '1') {
            epsilonRate += pow(2, deNominator);
        }
        deNominator--;
    }
}
