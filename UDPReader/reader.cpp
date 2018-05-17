// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <allegro5/allegro.h>

#include "TutorialConfig.h"
 
int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"%s Version %d.%d\n", argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
	
  if(al_init() != true) 
  {
	  std::cerr << "Fatal error, Allegro has not being found!"
	  << std::endl;
	  return 2;
  } else {
	  std::cout << "Allegro was found!" << std::endl;
  }
 
  double inputValue = atof(argv[1]);
 
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif
 
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}