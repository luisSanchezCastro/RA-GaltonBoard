# RA-GaltonBoard

To do this practice I create two codes. The first one "Galton - Board.cpp" is the simulation of a Galton Board and I use it to compare the galton board results with the binomial distribution results. the other code, the "MSE_N_B.cpp" is use it to get the mean square error of the binomial distribution and the normal distribution, necessary for the last part of the report.

When execute the "Galton - Board.cpp" it ask you first the number of balls (n) just enter a number, and then the number of levels of the galton board (N). Then the program throw the output of the numbre of balls in each k-column.

When execute the "MSE_N_B.cpp" it ask you first the number of trials of the binomial distribution (n for galton board) and then the mean of the nomal distribution (Introdcue: n/2) and the variance (Introduce n/4). Then the program throw the output of the MSE of each distributions.

To compile and execute the codes:
  1- Install the compilator g++ on linux with instructions:
    >> sudo apt install g++
  2- compile the code
    >> g++ -o Galton_Board Galton\ -\ Board.cpp
    >> g++ -o MSE_N_B MSE_N_B.cpp
  3 - execute the code
    >> ./Galton_Board
    >> ./MSE_N_B
