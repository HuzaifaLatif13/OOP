#include <iostream>
using namespace std;
class weatherstatistics
{
private:
    double rainFall;
    double highTemp;
    double lowTemp;
    double averageTemp;

public:
    weatherstatistics(double rainFall = 0, double highTemp = 0, double lowTemp = 0)
    {
        this->rainFall = rainFall;
        this->highTemp = highTemp;
        this->lowTemp = lowTemp;
        averageTemp = (highTemp + lowTemp) / 2;
    }
    void setweather()
    {
        cout << "\nEnter total rainfall: ";
        cin >> rainFall;
        cout << "\nEnter high temperature of month: ";
        cin >> highTemp;
        while (highTemp > 140 || highTemp < -100)
        {
            cout << "\nInvalid temperature-Enter temperature once again: ";
            cin >> highTemp;
        }
        cout << "\nEnter low temperature of month: ";
        cin >> lowTemp;
        while (lowTemp > 140 || lowTemp < -100)
        {
            cout << "\nInvalid temperature-Enter again: ";
            cin >> lowTemp;
        }
    }
    double getRainfall()
    {
        return rainFall;
    }
    double getHighTemp()
    {
        return highTemp;
    }
    double getLowTemp()
    {
        return lowTemp;
    }
    double calculatingAverageTemp()
    {
        averageTemp = (highTemp + lowTemp) / 2;
        return averageTemp;
    }
    void dispaly()
    {
        cout << "\nThe total rainFall is: " << rainFall;
        cout << "\nThe high temperature is: " << highTemp;
        cout << "\nThe low temperature is: " << lowTemp;
        cout << "\nThe average temperature is: " << averageTemp;
    }
};
int main()
{
    int totalrainFall = 0;
    double LowestTemp = 0;
    double highestTemp = 0;
    double averagerainfall = 0.0;
    weatherstatistics w(11, 23.4, 11.7);
    w.dispaly();
    weatherstatistics *w1;
    w1 = new weatherstatistics[2];
    for (int i = 0; i < 2; i++)
    {
        w1[i].setweather();
        totalrainFall += w1[i].getRainfall();
        highestTemp += w1[i].getHighTemp();
        LowestTemp += w1[i].getLowTemp();
    }
    cout << "\nThe total rainFall is: " << totalrainFall;
    averagerainfall = (totalrainFall) / 2;
    cout << "\nThe average rainFall is: " << averagerainfall;
    cout << "\nThe total Highest temperature of the year is: " << highestTemp;
    cout << "\nThe total lowest temperature of the year is: " << LowestTemp;

    delete[] w1;
    return 0;
}