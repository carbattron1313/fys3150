//
//  Project1.hpp
//  Project 1
//
//  Created by Elena Muñoz Rivas on 6/9/22.
//

#ifndef Project1_hpp
#define Project1_hpp

#include <math.h>
#include <stdio.h>

double f(double x){
    //Provide definition of function here:
    return 100*exp(-10.*x);
}

//Check analytically that an exact solution to the Poisson Equation is given by u(x)=1-():
double u(double x){
    //Provide definition of function here:
    return 1-(1-exp(-10.))*x-exp(-10.*x);
}

#endif /* Project1_hpp */


