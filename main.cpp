#include <iostream>

using namespace std;

int main()
{
  int number [9];
  int i, j;
  for (i=0; i<9; i++)
  {
      cout << "please enter the number : ";
      cin >> number [i];
  }
  for(i=0; i<8 ; i++)
  {
      for (j=i+1;j<9;j++)
      {
          int temp;

          if(number [i]> number[j])
          {
              temp = number[i];
              number [i] = number [j];
              number [j] = temp;
          }
      }
  }
  for (i=0 ;i<  9 ;i++)
  {
      cout << endl << number[i] << endl;
  }
}
