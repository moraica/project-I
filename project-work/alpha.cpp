#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    char x;

    double cost, rate_of_inflation;
    int years;

loop:
    while(true)
    {
        cout << "Enter the cost of the item: ";
        cin >> cost;

        if (cin.fail() || cost < 0)
        {
            cout << "Invalid Input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter the number of years from now that the item will be purchased: ";
        cin >> years;

        if (cin.fail() || years <= 0)
        {
            cout << "Invalid Input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    
    while (true)
    {
        cout << "Enter the rate of inflation as a percentage: ";
        cin >> rate_of_inflation;

        if (cin.fail())
        {
            cout << "Invalid Input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            if (rate_of_inflation < 0)
                cout << "WARNING: Rate is negative, calculating deflation!" << endl;;
            break;
        }
    }
    
    double inflation_fraction = rate_of_inflation / 100;
    double estimated_cost = cost * pow(1 + inflation_fraction, years);

    cout << fixed << setprecision(2);

    cout << "\nThe estimated cost of the item after " << years << " years is $" << estimated_cost << endl << endl;

    char choice;
    cout << "Do you want to see the cost difference each year? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        cout << "\n Year\t Cost\t\tDifference from previous year" << endl;
        int prev_year_cost = cost;
        for (int i = 1; i <= years; i++) {
            double cost_year = cost * pow(1 + inflation_fraction, i);
            double cost_diff = cost_year - prev_year_cost;
            cout << "  " << i << "\t$" << cost_year << "\t\t$" << cost_diff << endl;
            prev_year_cost = cost_year;
        }
    } else {
        int year_choice;
        cout << "\nEnter the year you want to see the cost for: ";
        cin >> year_choice;
        double cost_year = cost * pow(1 + inflation_fraction, year_choice);
        double cost_diff = cost_year - cost;
        cout << "\nThe estimated cost of the item in year " << year_choice << " is $" << cost_year << " ($" << cost_diff << " difference from current cost)" << endl;
    }
    cout << "\nDo you want to continue (y/n)? ";
    cin >> x;
    cout << endl;
    if (x!='n') goto loop;
    return 0;
}