#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own
 * function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

	cout << "Loading Sudoku board from file '" << filename << "'... ";

	ifstream in(filename);
	if (!in) {
		cout << "Failed!\n";
	}
	assert(in);

	char buffer[512];

	int row = 0;
	in.getline(buffer,512);
	while (in && row < 9) {
		for (int n=0; n<9; n++) {
			assert(buffer[n] == '.' || isdigit(buffer[n]));
			board[row][n] = buffer[n];
		}
		row++;
		in.getline(buffer,512);
	}

	cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
	assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
	if (!(row % 3)) {
		cout << "  +===========+===========+===========+\n";
	} else {
		cout << "  +---+---+---+---+---+---+---+---+---+\n";
	}
}

/* internal helper function */
void print_row(const char* data, int row) {
	cout << (char) ('A' + row) << " ";
	for (int i=0; i<9; i++) {
		cout << ( (i % 3) ? ':' : '|' ) << " ";
		cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
	}
	cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
	cout << "    ";
	for (int r=0; r<9; r++) {
		cout << (char) ('1'+r) << "   ";
	}
	cout << '\n';
	for (int r=0; r<9; r++) {
		print_frame(r);
		print_row(board[r],r);
	}
	print_frame(9);
}

/* add your functions here */

// function to see if board complete (all numbers no '.')

  bool is_complete (char a[9][9])
  {

  bool incomplete = false;
    
  for (int i =0; i< 9 && !incomplete; i++)
  {

    int j =0;         // resets j each row
    while (j < 9)
      {

	if (a[i][j] == '.')
	  {
	    incomplete = true;    // escapes both loops as found '.' so not complete (false)o
	    break;
	  }
	j++;

      }

  }

  
  if (incomplete)
    return false;

  else
    return true;
    

  }


// function to check if move is valid
  
bool make_move(std::string position, char digit, char a[9][9])
  {

  int  row = position [0]-'A';
  int column = position [1]-'1';


 // check valid digit

  if(digit < '1' || digit > '9')
    return false;

  // check if position in range for row (between A - I) for 1st character of position

  if (row < 0|| row > 9)
    return false;


  // check if position in range for column (between 1 - 9) for 2nd charater of position
  if (column < 0 || column > 9 )
    return false; 
  
  // check if any dups on row (noting board data is in char)
  
  int horizontal_count =0;
  while (horizontal_count < 9)
    if (digit == a[row][horizontal_count])
      {
	return false;
      break;
      }
    else
      horizontal_count ++;
  
  // check if column any dups

  int vertical_count =0;
  while (vertical_count <9)
    if (digit == a[vertical_count][column])
      {
        return false;
	break;
      }
    else
      vertical_count++;


  // check for mini 3x3 squares (by identifying start of which mini square)

  int mini_square_row_start = (row/3) * 3;
  int mini_square_column_start = (column/3) * 3;
  int mini_square_row_counter;
  int mini_square_column_counter;
  int column_reset = mini_square_column_start;


  // loop through mini square row by row
  while (mini_square_column_counter < mini_square_column_start + 3)
    {
      mini_square_row_counter = mini_square_row_start;   // reset counter for row

	
  for (mini_square_row_counter = mini_square_row_start; mini_square_row_counter < mini_square_row_start +3; mini_square_row_counter ++)

    if (a[mini_square_row_start][mini_square_column_start]== digit)
      {
	return false;
	break;
      }

      mini_square_column_counter ++; // increment column 
    }



  a[row][column]= digit;
  return true;
    
  }


// function which saves board in new file

bool save_board(std::string filename, char a [9][9])
{
 
  ofstream out_stream;
  out_stream.open(filename);
  if(out_stream.fail())
    return false;

  for (int row =0; row <9; row++)
    {

      for (int column =0; column <9; column ++)
	{
	  out_stream.put(a[row][column]);
	}
      out_stream.put('\n');// new line after each line
	
		     
    }
    
    
  out_stream.close();
  return true;

  
  }
  
