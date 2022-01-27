#include <iostream>
#include <math.h>

struct Range
    {
      int m_range;
      int m_max, m_min;

      Range()
      {
        m_range = 0;
        m_max = 0;
        m_min = 0;
        std::cout << "Construction Done";
      }
    };

int main()
{
    int integer, character, floating, doub, longdub, srtint;
    Range R;

    integer = sizeof(int);
    std::cout << "Size of Integer is: " << integer << std::endl;
    R.m_range = integer*8;
    R.m_max = pow(2, (R.m_range - 1)) - 1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Integer is from " << R.m_min
              << " to " << R.m_max << std::endl << std::endl;

    character = sizeof(char);
    std::cout << "Size of Character is: " << character << std::endl;
    R.m_range = character*8;
    R.m_max = pow(2, (R.m_range - 1)) -1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Character is from " << R.m_min
              << " to " << R.m_max << std::endl << std:: endl;

    floating = sizeof(float);
    std::cout << "Size of Float is: " << floating << std::endl;
    R.m_range = floating*8;
    R.m_max = pow(2, (R.m_range - 1)) -1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Float is from " << R.m_min
              << " to " << R.m_max << std::endl << std::endl;

    doub = sizeof(double);
    std::cout << "Size of Double is: " << doub << std::endl;
    R.m_range = doub*8;
    R.m_max = pow(2, (R.m_range - 1)) -1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Double is from " << R.m_min
              << " to " << R.m_max << std::endl << std::endl;

    longdub = sizeof(long double);
    std::cout << "Size of Long Double is: " << longdub << std::endl;
    R.m_range = longdub*8;
    R.m_max = pow(2, (R.m_range - 1)) -1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Long Double is from " << R.m_min
              << " to " << R.m_max << std::endl <<std:: endl;

    srtint = sizeof(short int);
    std::cout << "Size of Short Integer is: " << srtint << std::endl;
    R.m_range = srtint*8;
    R.m_max = pow(2, (R.m_range - 1)) -1;
    R.m_min = -1 * (pow(2, (R.m_range -1))) ;
    std::cout << "Range of Short Integer is from " << R.m_min
              << " to " << R.m_max << std::endl << std::endl;

    return 0;
}