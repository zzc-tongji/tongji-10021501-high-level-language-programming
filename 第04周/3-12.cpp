#include <iostream>

using namespace std;

int main()
{
    int x=0;
    cout << "Input x (0-99999): ";
    cin >> x;
    int e0=0,e1=0,e2=0,e3=0,e4=0;
    e4=x/10000;
    e3=(x-10000*e4)/1000;
    e2=(x-10000*e4-1000*e3)/100;
    e1=(x-10000*e4-1000*e3-100*e2)/10;
    e0=(x-10000*e4-1000*e3-100*e2-10*e1)/1;
    
    if (e4!=0)
    {
              cout << "place=5" << endl;
              cout << "original order is: ";
              cout << e4 << "," << e3 << "," << e2 << "," << e1 << "," << e0 << endl;
              cout << "reverse order is: ";
              cout << e0 << "," << e1 << "," << e2 << "," << e3 << "," << e4 << endl;
    }
    else
    {
        if (e3!=0)
        {
                  cout << "place=4" << endl;
                  cout << "original order is: ";
                  cout << e3 << "," << e2 << "," << e1 << "," << e0 << endl;
                  cout << "reverse order is: ";
                  cout << e0 << "," << e1 << "," << e2 << "," << e3 << endl;
        }
        else
        {
            if (e2!=0)
            {
                      cout << "place=3" << endl;
                      cout << "original order is: ";
                      cout << e2 << "," << e1 << "," << e0 << endl;
                      cout << "reverse order is: ";
                      cout << e0<< "," << e1 << "," << e2 << endl;
            }
            else
            {
                if (e1!=0)
                {
                          cout << "place=2" << endl;
                          cout << "original order is: ";
                          cout << e1 << "," << e0 << endl;
                          cout << "reverse order is: ";
                          cout << e0 << "," << e1 << endl;
                }
                else
                {
                    cout << "place=1" << endl;
                    cout << "original order is: ";
                    cout << e0 << endl;
                    cout << "reverse order is: ";
                    cout << e0 << endl;
                }
            }
        }
    }
    
    return(0);
} 
