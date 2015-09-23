#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//     sin(x) = x^1/1! - x^3/3! + x^5/5! ...... do n


  double sinx (double x);
  int main (){

  int xgr;
  double xrad;

  printf ("Input x  ");
  scanf ("%d", &xgr);

  xrad = xgr / 180.*M_PI; // Tochkata e za da ne e celochisleno delene!!

  printf ("sin(x) = %g \n", sinx (xrad));

  return 0;
  }

  double sinx (double x){

  double sum = x;
  double ch = x;
  int i, n = 2;

    for (i = 1; i <=100; i++){

        ch = ch * (x * x * (-1)) / (n * (n+1));
         n += 2;
         sum += ch;
    }
  return sum;

}


