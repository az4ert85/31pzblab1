#include <iostream>
#include"fraction.h"

 using namespace std;

 
int 
main () 
{
  
 
fraction a (1, 2);
  
 
fraction b (1, 2);
  
 
 
cout << "Fraction a:" << endl;
  
 
a.print ();
  
 
cout << "Fraction b:" << endl;
  
 
b.print ();
  
 
 
cout << "a<=b:";
  
 
if (a <= b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
 
cout << "a>=b:";
  
 
if (a >= b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
 
cout << "a<b:";
  
 
if (a < b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
 
cout << "a>b:";
  
 
if (a > b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
cout << "a==b:";
  
 
if (a == b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
cout << "a!=b:";
  
if (a != b)
    
cout << "true" << endl;
  
 
  else
    
cout << "false" << endl;
  
 
 
 
cout << "a*b:";
  
 
(a * b).print ();
  
 
 
cout << "a-b:";
  
 
(a - b).print ();
  
 
cout << "a+=b:";
  
a += b;
  
a.print ();
  
 
cout << "a-=b:";
  
a -= b;
  
a.print ();
  
 
cout << "a*=b:";
  
a *= b;
  
a.print ();
  
 
cout << "a/=b:";
  
a /= b;
  
a.print ();

 
 
}


