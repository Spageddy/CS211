#include "price.h"

Price::Price()
{
  dollar= 0;
  cent = 0;
}
Price::Price (int d, int c)
{
  dollar =d;
  cent =c;
}
Price Price::operator+(const Price another)
{
  dollar  = this->dollar + another.dollar;
  cent = this->cent + another.cent;
  if(cent >= 100)
    {
      dollar += (cent/100);
      cent = (cent%100);
    }
  Price c(dollar, cent);
  
return c;
}
Price Price::operator-(const Price other)
{
  //convert each price to cents
  int p1 = this->dollar * 100 + this->cent;
  int p2 = other.dollar * 100 + other.cent;
  int diff;
  if(p1 >= p2)
    {
      diff = p1 - p2;
      Price diffOb(diff/100, diff%100);
      return diffOb;
    }
  else 
    {
    Price negOb(-9999999, -9999999);//Don't do the math if p2 is less than p1
    return negOb;
    }
}
int Price::getDollar()
{
  return dollar;
}

int Price::getCent()
{
  return cent;
}


