/*
 *  sudoku.h
 *  Sudoku
 *  Created by Prof. Ramavarapu Sreenivas 
 *  Inspired by: http://web.eecs.utk.edu/courses/spring2012/cs140/Notes/Sudoku/index.html
 *  Single solution h file
 *  Wenbo Zhu
*/

#ifndef sudoku
#define sudoku

#include <vector>
#include <fstream>
using std::vector;
using namespace std;
class Sudoku 
{ 
	// Private
	int puzzle[9][9];
	
	// Private member function that checks if the named row is valid
	bool row_valid(int row)
	{
        //Count how many times a number appears, if count goes over 1, meaning fail case. 
		int count;
		for (int k=1; k<=9;k++)
		{
			count=0;
			for (int j = 0; j<9; j++)
			{
				if(k == puzzle[row][j]) 
					count++;
			}
			
			if(count>1) 
				return false;
		}
		return true;

		// write code that checks if "row" is valid
	}
	
	// Private member function that checks if the named column is valid
	//Still using count method
	bool col_valid(int col)
	{
		
		int count;
		for (int k=1; k<=9;k++)
		{
			count=0;
			for (int j = 0; j<9; j++)
			{
				if(k == puzzle[j][col]) 
					count++;
			}
			
			if(count>1) 
				return false;
		}
		return true;
	}
	
	// Private member function that checks if the named 3x3 block is valid
	bool block_valid(int row, int col)
	{
		//Find where the block is
		int blockrow = (row/3)*3;
		int blockcol = (col/3)*3;
        
        //Check if the block is valid or not
        for (int i = 0; i < 3; i++)
        {
        	for (int j = 0; j < 3; j++)
        	{
        		if (puzzle[blockrow + i][blockcol + j] == puzzle[row][col] && 
        			((blockrow + i) != row)&& ((blockcol + j) != col))
        		{
        			return false;
        		}
        	}
        }

        return true;



	}
	
public:
	// Public member function that reads the incomplete puzzle
	// we are not doing any checks on the input puzzle -- that is,
	// we are assuming they are indeed valid
	// void read_puzzle(int argc, char * const argv[])
	void read_puzzle(int argc, char * const argv[])
	{
		ifstream myfile(argv[1]);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				myfile >> puzzle[i][j];
			}
		}
		// write code that reads the input puzzle using the 
		// guidelines of figure 23 of the bootcamp material
	}
	
	// Public member function that prints the puzzle when called
	void print_puzzle()
	{
		std::cout << std::endl << "Board Position" << std::endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				// check if we have a legitimate integer between 1 and 9
				if ((puzzle[i][j] >= 1) && (puzzle[i][j] <= 9))
				{
					// printing initial value of the puzzle with some formatting
					std::cout << puzzle[i][j] << " ";
				}
				else {
					// printing initial value of the puzzle with some formatting
					std::cout << "X ";
				}
			}
			std::cout << std::endl;
		}
	}

	
	// Public member function that (recursively) implements the brute-force 
	// search for possible solutions to the incomplete Sudoku puzzle
	bool Solve(int row, int col)
	{
		for (int i = 0; i < 9; i++)
		{
			

			for (int j = 0; j < 9; j++)
			{
				
				if(puzzle[i][j] == 0)
				{
					for (int k = 1; k <= 9; k++)
					{
						// Recursion starts here
						puzzle[i][j] = k;
						if (row_valid(i) && col_valid(j) && block_valid(i,j) && Solve(i,j))
						{							
							return true;
						}
						else
						{	
							puzzle[i][j] = 0;
						}
							
							
						
					}
					return false;

				}
			}


		}


		return true;

		
		// this part of the code identifies the row and col number of the 
		// first incomplete (i.e. 0) entry in the puzzle.  If the puzzle has
		// no zeros, the variable row will be 9 => the puzzle is done, as 
		// each entry is row-, col- and block-valid...
		
		// use the pseudo code of figure 3 of the description
	}

   
};

#endif