// Soduku Solver using Brute-Force Search implemted using 
// recursion.
// Written for IE523: Financial Computation by Prof. Sreenivas
// and GE523: Discrete Event Systems
//
// Main file for sodoku all solution version
// Wenbo Zhu
#include <iostream>
#include "sudokuall.h"


int main (int argc, char * const argv[]) 
{
	Sudoku x;

	//Read file in command line
	x.read_puzzle(argc, argv);

	x.print_puzzle();
	
	x.Solve(0,0);
    
	
  
	
	
    return 0;
}
