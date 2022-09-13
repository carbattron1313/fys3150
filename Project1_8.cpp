//
//  Project1_8.cpp
//  
//
//  Created by Elena Muñoz Rivas and Alejandro Carballido Mantecón.
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
    std::string filename = "Problem7n1000000.txt";
    
    std::ofstream ofile;
    ofile.open(filename);
    
    // Start measuring time
    clock_t t1 = clock();
    
    
    
    // The code you want to perform timing on
    //Define the number of discretization steps along the full x axis which is related with the dimensions of the tridiagonal matrix and with the lenght of the steps:
    int n_steps = 1000000;
    int n = n_steps-1;
    double h = 1./n_steps;
    //Define vector g and boundary conditions (If the boundary conditions weren't 0, you should add the boundary values (g_0 and g_f) at the first and last position of the vector):
    std::vector<double> g(n, h*h);
    double x_0 = 0.;
    double x_f = 1.;
    double g_0 = 0.;
    double g_f = 0.;
    
    //Define a vector of n values, a (subdiagonal):
    std::vector<double> a(n, -1.);
    //Define a vector of n values, b (main diagonal):
    std::vector<double> b(n,2.);
    //Define a vector of n values, c (superdiagonal):
    std::vector<double> c(n, -1.);
    
    
    //Change the vectors a and c so that they represent the subdiagonal and superdiagonal of the matrix:
    a[0] = 0;
    c[n-1] = 0;

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
    std::vector<double> b2;
    b2.push_back(b[0]);
    std::vector<double> g2;
    g2.push_back(g[0]);
    
    //Add the values of the vectors b2 and g2 using the general algorithm:
    for (int i=1; i<=n-1; i++){
        b2.push_back(b[i] - (a[i]/b2[i-1])*c[i-1]);
        g2.push_back(g[i]-(a[i]/b2[i-1])*g2[i-1]);
    }
    
    //Define the vector of solutions v filled with the initial value:
    std::vector<double> v(n, g2[n-1]/b2[n-1]);
    
    //Change the rest of the values of v using the general algorithm:
    for (int i=1; i<=n-1; i++){
        v[n-1-i] = (g2[n-1-i]-c[n-1-i]*v[n-i])/b2[n-1-i];
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
    
    
    //Set a filename: Problem7
    std::string filename_err = "Err1000000.txt";
    
    std::ofstream ofile_err;
    ofile_err.open(filename_err);
    
//Creating the error vectors:
    std::vector<double> abs_err;
    std::vector<double> rel_err;

    for (int i=0; i<=n-1; i++){
    //Absolute error:
        abs_err.push_back(log10(abs(u(x[i])-v[i])));
    //Relative error:
        rel_err.push_back(log10(abs((u(x[i])-v[i])/u(x[i]))));
    //Writing the errors into a data file.
        ofile_err << std::setw(10) << std::setprecision(3) << x[i]
        << std::setw(10) << std::setprecision(3) << abs_err[i]
        << std::setw(10) << std::setprecision(3) << rel_err[i]<< std::endl;
    }
    
    
    ofile_err.close();
}

