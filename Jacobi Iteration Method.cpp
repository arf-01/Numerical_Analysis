#include<bits/stdc++.h>
using namespace std;
  int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o; 

  int flag=-1;

  void setther(float &last_x,  float &last_y, float &last_z)
  {
     float curr_x,curr_y,curr_z;

     curr_x=(float)(d-c*last_z-b*last_y)/a;
     curr_y=(float)(h-g*last_z-e*last_y)/f;
     curr_z=(float)(l-j*last_y-i*last_x)/k;

     if(abs(last_x-curr_x)<0.0001  && abs(last_y-curr_y)<0.0001 && abs(last_z-curr_z<0.0001))
         {
            flag=1;
         }


      last_x=curr_x;
        last_y=curr_y;
         last_z=curr_z;

         

  }
 
  

  void solve(string p, int *a, int *b, int *c, int *d)
{
    int last_sign = 1;
    int x = 1, y = 1, z = 1, k = 0;

    int ans = 0;

    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == ' ' || p[i]=='=')
            continue;

        else if (p[i] == '+')
        {
            last_sign = 1;
            continue;
        }

        else if (p[i] == '-')
        {
            last_sign = -1;
            continue;
        }

        else if (p[i] == 'x')
        {   
              if(ans==0)  x=1 * last_sign;
            else
                {x = ans * last_sign;
            last_sign = 1;}

            ans = 0;
        }
        else if (p[i] == 'y')
        {  
             if(ans==0)  y=1 * last_sign;
            else{y = ans * last_sign;
            ans = 0;
        }
            last_sign = 1;
        }
        else if (p[i] == 'z')
        {  
              if(ans==0)  z=1*last_sign;
              else{
            z = ans * last_sign;
            ans = 0;
        }
            last_sign = 1;
        }
        else
        {
            ans = ans * 10 + (p[i] - '0');

        }
    }
    
    k = ans * last_sign;

    *a = x;
    *b = y;
    *c = z;
    *d = k;
}


 int main()
 {    


         string p= "20x+y-2z=17";
         solve(p,&a,&b,&c,&d);
     string q = "x+20y-z=-18";
        solve(q,&e,&f,&g,&h);
  string r = "2x-3y+20z=25";
          solve(r,&i,&j,&k,&l);

            int count=0;
            float last_x=0,last_y=0,last_z=0;
              while(  flag==-1  &&  count<1000)
              {
                       setther(last_x,last_y,last_z);
                   cout<<last_x<<" "<<last_y<<" "<<last_z<<endl;
                   count++;
              }


             



 } 
