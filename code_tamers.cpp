#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int biggest_number = 4; // As given in the example
    int height = biggest_number * 2 + 1;

    for (int i = 0; i < height; i++)
    {
        int leading_number = abs(biggest_number - i); // This goes from the biggest number to zero then back to the biggest number.
        int gaps = biggest_number - leading_number;
        
        for (int j = 0; j < gaps; j++)
        {
            cout << " ";
        }

        for (int k = leading_number; k > 0; k--)
        {
            cout << k;
        }

        cout << 0;

        for (int m = 1; m <= leading_number; m++)
        {
            cout << m;
        }

        cout << endl;
    }
}