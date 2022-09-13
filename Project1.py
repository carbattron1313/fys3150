#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
September 2022

@author: Elena Muñoz Rivas and Alejandro Carballido
"""
from typing import List
import matplotlib.pyplot as plt


#Problem 2:

#We have create empty Lists, x and ux values to store the values we have obtained
#with C++:

x_values: List[float] = []
ux_values: List[float] = []


with open("Problem2.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_values.append(float(numbers[0]))
        ux_values.append(float(numbers[1]))


#Represent the plot
plt.plot(x_values, ux_values)

# Decoraciones
plt.xlabel("x")
plt.ylabel("u(x)")
plt.title("Exact solution for Poisson eq.")


#Show the plot
plt.show()
plt.savefig("Problem2fig.pdf")



#Problem 7
#We have create empty Lists, x and v values to store the values we have obtained
#with C++. There are multiple .txt and values who corresponds to the different
#n_steps, and then at the end they are represented:

x_10: List[float] = []
v_10: List[float] = []

with open("Problem7n10.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_10.append(float(numbers[0]))
        v_10.append(float(numbers[1]))


x_100: List[float] = []
v_100: List[float] = []

with open("Problem7n100.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_100.append(float(numbers[0]))
        v_100.append(float(numbers[1]))

x_1000: List[float] = []
v_1000: List[float] = []

with open("Problem7n1000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_1000.append(float(numbers[0]))
        v_1000.append(float(numbers[1]))

x_10000: List[float] = []
v_10000: List[float] = []

with open("Problem7n10000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_10000.append(float(numbers[0]))
        v_10000.append(float(numbers[1]))

x_100000: List[float] = []
v_100000: List[float] = []

with open("Problem7n100000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_100000.append(float(numbers[0]))
        v_100000.append(float(numbers[1]))

x_1000000: List[float] = []
v_1000000: List[float] = []

with open("Problem7n1000000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_1000000.append(float(numbers[0]))
        v_1000000.append(float(numbers[1]))


#Represent the plot
plt.plot(x_values, ux_values, "blue")
plt.plot(x_10, v_10, "red")
plt.plot(x_100, v_100, "green")
plt.plot(x_1000, v_1000, "purple")
plt.plot(x_10000, v_10000, "brown")
plt.plot(x_100000, v_100000, "yellow")
plt.plot(x_1000000, v_1000000, "black")



# Decorations
plt.xlabel("x")
plt.ylabel("v(x)")
plt.title("Exact vs numeric sol. for Poisson eq.")
plt.grid(False)

#Show the plot
plt.show()


#Problem 8
#We have create empty Lists, abs_err and rel_err10 values to store the values
#we have obtained with C++. There are multiple .txt and values who corresponds
#to the different n_steps.

#For finding the maximun relative error we need the maximum value of the logarithm

maxrel: List[float] = []

abs_err10: List[float] = []
rel_err10: List[float] = []
#Remove the boundary conditions for all the n_steps
x_10.pop(0)
x_10.pop(-1)


with open("Err10.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err10.append(float(numbers[1]))
        rel_err10.append(float(numbers[2]))

maxrel.append(max(rel_err10))

abs_err100: List[float] = []
rel_err100: List[float] = []
x_100.pop(0)
x_100.pop(-1)

with open("Err100.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err100.append(float(numbers[1]))
        rel_err100.append(float(numbers[2]))

maxrel.append(max(rel_err100))

abs_err1000: List[float] = []
rel_err1000: List[float] = []
x_1000.pop(0)
x_1000.pop(-1)

with open("Err1000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err1000.append(float(numbers[1]))
        rel_err1000.append(float(numbers[2]))

maxrel.append(max(rel_err1000))

abs_err10000: List[float] = []
rel_err10000: List[float] = []
x_10000.pop(0)
x_10000.pop(-1)

with open("Err10000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err10000.append(float(numbers[1]))
        rel_err10000.append(float(numbers[2]))

maxrel.append(max(rel_err10000))

abs_err100000: List[float] = []
rel_err100000: List[float] = []
x_100000.pop(0)
x_100000.pop(-1)

with open("Err100000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err100000.append(float(numbers[1]))
        rel_err100000.append(float(numbers[2]))

maxrel.append(max(rel_err100000))

abs_err1000000: List[float] = []
rel_err1000000: List[float] = []
x_1000000.pop(0)
x_1000000.pop(-1)

with open("Err1000000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        abs_err1000000.append(float(numbers[1]))
        rel_err1000000.append(float(numbers[2]))

maxrel.append(max(rel_err1000000))

abs_err10000000: List[float] = []
rel_err10000000: List[float] = []
x_10000000: List[float] = []

with open("Err10000000.txt", "r") as file:
    # read the file line by line
    for line in file:
        # Split the line into parts
        numbers = line.split()
        x_10000000.append(float(numbers[0]))
        abs_err10000000.append(float(numbers[1]))
        rel_err10000000.append(float(numbers[2]))

maxrel.append(max(rel_err10000000))

#Represent the plot of absoluts errors
plt.plot(x_10, abs_err10, "blue")
plt.plot(x_100, abs_err100, "green")
plt.plot(x_1000, abs_err1000, "red")
plt.plot(x_10000, abs_err10000, "purple")
plt.plot(x_100000, abs_err100000, "yellow")
plt.plot(x_1000000, abs_err1000000, "pink")
plt.plot(x_10000000, abs_err10000000, "orange")

# Decorations
plt.xlabel("x")
plt.ylabel(r"log_10($\Delta$_i)")
plt.title("Absolute errors for n steps")
plt.grid(False)

#Show the plot
plt.show()

#Represent the plot of relative errors
plt.plot(x_10, rel_err10, "blue")
plt.plot(x_100, rel_err100, "green")
plt.plot(x_1000, rel_err1000, "red")
plt.plot(x_10000, rel_err10000, "purple")
plt.plot(x_100000, rel_err100000, "yellow")
plt.plot(x_1000000, rel_err1000000, "pink")
plt.plot(x_10000000, rel_err10000000, "orange")

print(maxrel)

# Decorations
plt.xlabel("x")
plt.ylabel(r"log_10($\epsilon$_i)")
plt.title("Relative errors for n steps")
plt.grid(False)

#Show the plot
plt.show()





























