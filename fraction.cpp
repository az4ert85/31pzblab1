#include"fraction.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

 fraction::fraction ()
{
  
numer = 1;
  
denum = 1;

}


fraction::fraction (int n, int d)
{
  
if (d == 0)
    
throw std::runtime_error ("zero division error");
  
numer = n;
  
denum = d;

}


 
fraction fraction::operator* (fraction & DR2) 
{
  
fraction result ((this->numer * DR2.numer), (this->denum * DR2.denum));
  
return result;

}


 
fraction fraction::operator- (fraction & DR2) 
{
  
 
if (this->denum != DR2.denum)
    {
      
fraction
	result (((this->numer * DR2.denum) - (this->denum * DR2.numer)),
		(this->denum * DR2.denum));
      
return result;
    
}
  
  else
    {
      
fraction result ((this->numer - DR2.numer), this->denum);
      
return result;
    
}

 
}


 
bool fraction::operator> (fraction & DR2) 
{
  
if ((this->numer / this->denum) > (DR2.numer / DR2.denum))
    return true;
  
  else
    return false;

}


bool fraction::operator>= (fraction & DR2) 
{
  
if ((this->numer / this->denum) >= (DR2.numer / DR2.denum))
    return true;
  
  else
    return false;

}


bool fraction::operator< (fraction & DR2) 
{
  
if ((this->numer / this->denum) < (DR2.numer / DR2.denum))
    return true;
  
  else
    return false;

}


bool fraction::operator<= (fraction & DR2) 
{
  
if ((this->numer / this->denum) <= (DR2.numer / DR2.denum))
    return true;
  
  else
    return false;

}


 
fraction fraction::operator+= (fraction & DR2)
{
  
if (this->denum != DR2.denum)
    {
      
this->numer = ((this->numer * DR2.denum) + (this->denum * DR2.numer));
      
this->denum *= DR2.denum;
      
return *this;
    
}
  
  else
    {
      
this->numer += DR2.numer;
      
return *this;
    
}

}


 
fraction fraction::operator*= (fraction & DR2)
{
  
this->numer *= DR2.numer, this->denum *= DR2.denum;
  
return *this;

}


 
fraction fraction::operator/= (fraction & DR2)
{
  
 
float
    bufer;
  
 
bufer = DR2.numer;
  
DR2.numer = DR2.denum;
  
DR2.denum = bufer;
  
 
this->numer *= DR2.numer, this->denum *= DR2.denum;
  
return *this;

}


 
fraction fraction::operator-= (fraction & DR2)
{
  
if (this->denum != DR2.denum)
    {
      
this->numer = ((this->numer * DR2.denum) - (this->denum * DR2.numer));
      
this->denum *= DR2.denum;
      
return *this;
    
}
  
  else
    {
      
this->numer -= DR2.numer;
      
return *this;
    
}

}


 
bool fraction::operator!= (fraction & DR2)
{
  
if ((this->numer / this->denum) != (DR2.numer / DR2.denum))
    return true;
  
return false;

}


 
bool fraction::operator== (fraction & DR2)
{
  
if ((this->numer / this->denum) == (DR2.numer / DR2.denum))
    return true;
  
return false;

}


 
double
fraction::getnum () 
{
  
return this->numer;

}


double
fraction::getden () 
{
  
return this->denum;

}


double
fraction::number () 
{
  
return numer / (double) denum;

} 
 
void

fraction::print ()
{
  
std::cout << numer << "/" << denum << std::endl;

}
