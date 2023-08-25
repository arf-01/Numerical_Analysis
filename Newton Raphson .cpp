#include <bits/stdc++.h>
#include <math.h>
using namespace std;

inline float func(float x)
{
      return  3*x - cos(x) -1;
}

inline  float derivative(float x)
  {
      return 3 + sin(x);
  }

int main() {
    float x;
    float error;
    cin >> x >> error;

    float err = 100;
    int count = 0;

    if (derivative(x) == 0) {
        cout << "ERROR" << endl;
        return 0;
    }

    while (err > error && count < 1000) {
        float p = func(x);
        float q = derivative(x);

        float new_root = x - p / q;

        err = abs(new_root - x);

        x = new_root;
        count++;
    }

    cout << "Approximate root: " << x << endl;

    return 0;
}
