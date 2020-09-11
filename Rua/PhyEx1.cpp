#include <bits/stdc++.h>
using namespace std;

int main()
{
    double degree[6], digits[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> degree[i] >> digits[i];
        degree[i] += digits[i] / 60.0;
    }

    double angleB = (degree[0] - degree[2]) + (degree[1] - degree[3]);
    angleB /= 2.0;
    if (angleB >= 180.0)
    {
        angleB -= 180.0;
    }

    cout << "Angle B = " << angleB << " with " << ((int)(angleB * 100) % 100 * 0.6) << "\n";
    double n = (degree[0] - degree[4]) + (degree[1] - degree[5]);
    if (n > 180.0) n -= 180.0;
    n /= 2.0;
    n = angleB / n;


    cout << "N = " << n << "\n";
    return 0;
}

/*
359 50
179 18
357 47
177 45
358 24
178 20

359 47
179 16
357 43
177 43
358 22
178 20

359 36
179 10
357 35
177 33
358 15
178 9

359 37
179 21
357 41
177 40
358 23
178 15

359 48
179 34
357 50
177 48
358 33
178 26

359 38
179 42
357 47
177 57
358 54
178 25

 */