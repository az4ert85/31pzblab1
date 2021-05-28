class fraction 
{

private:
float numer, denum;

public: 
fraction ();
   
fraction (int n, int d);
   
fraction operator* (fraction & DR2);
   
fraction operator- (fraction & DR2);
   

bool operator> (fraction & DR2);
   
bool operator>= (fraction & DR2);
   
bool operator< (fraction & DR2);
   
bool operator<= (fraction & DR2);
   

bool operator!= (fraction & DR2);
   
bool operator== (fraction & DR2);
   


fraction operator+= (fraction & DR2);
   
fraction operator-= (fraction & DR2);
   
fraction operator*= (fraction & DR2);
   
fraction operator/= (fraction & DR2);
   


double getnum ();
   
double getden ();
   
double number ();
   
void print ();
 
};
