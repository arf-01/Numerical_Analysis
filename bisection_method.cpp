#include <bits/stdc++.h>
using namespace std;

 vector<double>v;

  vector<double>extract(string & eqn)
{


       int ans=1;
       int flag=1;
    cout<<   eqn<<endl;

       string term;

          for(int i=0;i<eqn.length();i++)
          {

              if(eqn[i]=='=')   break;

              else if(isdigit(eqn[i]))
              {

                      term+=eqn[i];
              }


              else if(   eqn[i]=='+')
              {
                      continue;

              }


                else if(eqn[i]=='-')
                {

                    flag=-1;
                }

                else if(eqn[i]=='^')
                {

                    i++;

                }

                else if(eqn[i]=='x')
                {
                  if(term.empty()){
                    v.push_back(flag);
                    flag=1;
                }

                else

                {




                    double ans=stod(term);
                    v.push_back(ans*flag);
                    flag=1;
                    term.clear();

                }
                }



          }

             v.push_back(stod(term)*flag);

           return v;



}


double f(double x) {

    //cout<<v[0]<<" "<<v[1]<<endl;

    return v[0]*x*x*x+v[1]*x+v[2];

}


double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
          return -1;
    }

    double c = a;

    while ((b - a) >= tol) {

        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        }

        // Update the interval [a, b]
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {



    //
     string eqn="x^3-3x-5=0";

        vector<  double>v  = extract(eqn);
          for(auto it:v)
          {

                 cout<<it<<endl;
          }
//
    double a, b, tol;
    cout << "Enter the left endpoint (a): ";
    cin >> a;
    cout << "Enter the right endpoint (b): ";
    cin >> b;
    cout << "Enter the tolerance (tol): ";
    cin >> tol;

    double root = bisection(a, b, tol);

    cout << "The approximate root is: " << root << endl;

    return 0;
}
