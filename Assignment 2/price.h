#ifndef PRICE_H
#define PRICE_H

class Price
{
 private:
  int dollar;
  int cent;
 public:
  Price();
  Price (int d, int c);

  Price operator+(const Price another);
  int getDollar();
  int getCent();
  Price operator-(const Price other);
};
#endif
