//
//  Project1_9.cpp
//  
//
//  Created by Elena Muñoz Rivas and Alejandro Carballido Mantecón..
//

#include "Project1.hpp"
#include <math.h>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

int main(){
    //Set a filename: Problem7
    std::string filename = "Problem9n10.txt";
    
    std::ofstream ofile;
    ofile.open(filename);
    
    // Start measuring time
    clock_t t1 = clock();
    
    
    
    // The code you want to perform timing on
    //Define the number of discretization steps along the full x axis which is related with the dimensions of the tridiagonal matrix and with the lenght of the steps:
    int n_steps = 10;
    int n = n_steps-1;
    double h = 1./n_steps;
    //Define vector g and boundary conditions (If the boundary conditions weren't 0, you should add the boundary values (g_0 and g_f) at the first and last position of the vector):
    std::vector<double> g(n, h*h);
    double x_0 = 0.;
    double x_f = 1.;
    double g_0 = 0.;
    double g_f = 0.;
    
    //As the values of a, b and c are constant, we don't need to define the vectors just a constant:
    double a = -1.;
    double b = 2.;
    double c= -1.;

    //Define x vector for the values along the x axis:
    std::vector<double> x;
    
    //Create variable for x values in the axis
    double x7 = 0.;
    
    for (int i=0; i<=n-1; i++){
        x7 += h;
        //Add the x values to the vector
        x.push_back(x7);
        //Multiply the already defined vector g by the function f in each point in order to get the real value of g.
        g[i]*=f(x[i]);
    }
    
    //Define vectors b2, g2 and add the initial values:
    //For the special algorithm the elements of the vector always have the same value and we can calculate it just once.
    std::vector<double> b2;
    b2.push_back(b);
    std::vector<double> g2;
    g2.push_back(g[0]);
    
    for (int i=1; i<=n-1; i++){
        b2.push_back(b + (a/b2[i-1]));
        g2.push_back(g[i]-(a/b2[i-1])*g2[i-1]);
    }
    
     //Define the vector of solutions v filled with the initial value:
     std::vector<double> v(n, g2[n-1]/b2[n-1]);
     
     //Change the rest of the values of v using the general algorithm:
     for (int i=1; i<=n-1; i++){
         v[n-1-i] = (g2[n-1-i]+v[n-i])/b2[n-1-i];
     }
    //Writing the solutions with the boundary conditions into a data file.
    ofile << std::setw(10) << std::setprecision(3) << x_0
    << std::setw(10) << std::setprecision(3) << g_0 << std::endl;
        for (int i=0; i<=n-1; i++){
            ofile << std::setw(10) << std::setprecision(3) << x[i]
            << std::setw(10) << std::setprecision(3) << v[i] << std::endl;
    }
    ofile << std::setw(10) << std::setprecision(3) << x_f
    << std::setw(10) << std::setprecision(3) << g_f << std::endl;
    
    ofile.close();
    
    
    // Stop measuring time
    clock_t t2 = clock();
    // Calculate the elapsed time.
    double duration_seconds = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
    std::cout << duration_seconds << std::endl;

    
}
