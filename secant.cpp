#include<bits/stdc++.h>
#include<math.h>
using namespace std;

inline float func(float x)
{
    return  x*x*x + 3*x - 5;
}

int main()
{
      float x0,   x1, error,x2;
      cin>>x0>>x1>>error;

      float err=100;
      int count=0;

      while(err>error && count<10000)
      {
           x2=(func(x1)*x0-func(x0)*x1)/(func(x1)-func(x0));
           err=abs(x2-x1);
           x0=x1; //   x0=x1   must be written before x1=x2//
           x1=x2;

           
           count++;
      }


      cout << fixed << setprecision(5) << x2 << endl;

}
