#ifndef SUDOKU_H
#define SUDOKU_H

/**
 * Load a Sudoku board from a file into a 9x9 char array.
 * The file is expected to consist only of the characters
 * '1'-'9' and '.'.
 *
 * This function will throw an assertion error for malformed
 * files. Messages will be printed to the console to confirm
 * success and failure.
 *
 * @param filename The path of the file to be loaded, containing
 * a Sudoku board layout.
 * @param A pre-allocated char array to store the board data.
 */
void load_board(const char* filename, char board[9][9]);

/**
 * Print a formatted Sudoku board to the console.
 *
 * @param board Sudoku board data to be printed.
 */
void display_board(const char board[9][9]);

bool is_complete (char a[9][9]);


bool make_move(std::string position, char digit, char a[9][9]);

bool save_board(std::string filename, char a[9][9]);
#endif
