//
//  Project1_2.cpp
//  Project 1_2
//
//  Created by Elena Muñoz Rivas and Alejandro Carballido Mantecón
//

#include "Project1.hpp"
#include <math.h>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>



int main() {
    
    //Set a filename: Problem2
    std::string filename = "Problem2.txt";
    
    std::ofstream ofile;
    ofile.open(filename);
    //Problem 2:
    int n = 10;
    double x2 = 0.;
    double h = 1./n;
    //Defined a vector of x values, v_x:
    std::vector<double> x;
    //Defined a vector of u(x) values, u_x:
    std::vector<double> u_x;
    
    x.push_back(0.);
    u_x.push_back(0.);
    
    for (int i=0; i<=n-2; i++){
        x2 += h;
        x.push_back(x2);
        u_x.push_back(u(x2));
    }
    x.push_back(1.);
    u_x.push_back(0.);
    
    for (int i=0; i<=n; i++){
        ofile << std::setw(10) << std::setprecision(3) << x[i]
        << std::setw(10) << std::setprecision(3) << u_x[i] << std::endl;
    }
    
    ofile.close();
    return 0;
}

