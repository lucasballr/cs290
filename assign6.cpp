/********************************************************************* 
** Program Filename: assign6.cpp
** Author: Lucas Ball
** Date: March 6, 2018
** Description: Checkers Game
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath> 

using namespace std;

/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/

void display_board(char **board, int bnum){
	int rows = bnum;
	int cols = bnum;
	for(int i=0; i<rows; i++){
    	for(int j=0; j<cols; j++) {
			if (i%2 == 0 && j%2 == 0){
				cout << "|\033[30;47m " << board[i][j] << " ";
			}  else if (i%2 == 1 && j%2 == 1) {
				cout << "|\033[30;47m " << board[i][j] << " ";
			} else {
				cout << "|\033[0m " << board[i][j] << " ";
			}
			cout << "\033[0m";
		}
		cout << endl;
	}
}

/********************************************************************* 
** Function: create_board()
** Description: makes board
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


void create_board(char **board, int bnum){
	int rows = bnum;
	int cols = bnum;
	int sides = ((bnum - 1)/2) - 1;
	for (int i = 0; i < bnum; i++){
		board[i] = new char[bnum];
	}
	for(int i=0; i < bnum; i++){
		board[i][0] = i + 48;
		board[0][i] = i + 48;
    }
    for(int i=1; i < bnum; i++){
    	board[sides + 1][i] = ' ';
    	board[sides + 2][i] = ' ';
    }
	for(int i = 1; i < sides + 1; i++){
    	for(int j = 1; j < cols; j++) {
    		if (i % 2 == 0 && j % 2 == 1 ){
    			board[i][j] = 120;
    		} else if (i % 2 == 1 && j % 2 == 0){
    			board[i][j] = 120;
    		} else {
    			board[i][j] = ' ';
    		}
    	}
    }
    for(int i = 0; i < sides; i++){
    	for(int j = 1; j < cols; j++) {
    		if (i % 2 == 0 && j % 2 == 1 ){
    			board[bnum - i - 1][j] = 111;
    		} else if (i % 2 == 1 && j % 2 == 0){
    			board[bnum - i - 1][j] = 111;
    		} else {
    			board[bnum - i - 1][j] = ' ';
    		}		
    	}		
    }

	display_board(board, bnum);
}

/********************************************************************* 
** Function: delete_board()
** Description: deletes board
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


void delete_board(char **board, int bnum){
	for (int i = 0; i < bnum; i++){
		delete[] board[i];
	}
	delete[] board;

}

/********************************************************************* 
** Function: argument_check()
** Description: checks command line argument
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool argument_check(int argc, char **argv){
	if (argc > 2 || argc < 2){
		cout << "Please type one of three options in command line argument: 8, 10, or 12" << endl;
		return true;
	} else if (string(argv[1]) != "8" && string(argv[1]) != "10" && string(argv[1]) != "12"){
		cout << "Please type one of three options in command line argument: 8, 10, or 12" << endl;
		return true;
	} else {
		return false;
	}
}

/********************************************************************* 
** Function: select_check()
** Description: checks if piece good
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool select_check(char **board, int *player, string l, int *x, int *y){
	int u = 0, v = 0;
	if(l[0] == '(' && l[2] == ',' && l[4] == ')'){
		u = l[1] - 48;
		v = l[3] - 48;
	} else {
		return false;
	}
	if ((u < 0 && u > 8)||(v < 0 && v > 8)){
		return false;
	}
	*x = v;
	*y = u;
	if(*player == 1 && (board[*y][*x] == 'x' || board[*y][*x] == 'X')){
		return true;
	} else if (*player == 2 && (board[*x][*y] == 'o' || board[*x][*y] == 'O')){
		return true;
	} else {
		return false;
	}
}

/********************************************************************* 
** Function: coord_syntax()
** Description: checks coords
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool coord_syntax(string l, int *spaces){
	int spot = 0;
	*spaces = 0;
	for(int i = 0; i < l.length(); i++){
		if (l[i] == ' '){
			*spaces += 1;
		}
	}
	*spaces += 1;
	int arr[*spaces][2];
	for (int i = 0; i < *spaces; i++){
		if(l[spot] == '(' && l[spot + 2] == ',' && l[spot + 4] == ')'){
			arr[i][1] = l[spot + 1] - 48;
			arr[i][0] = l[spot + 3] - 48;
			spot += 6;
		} else {
			return false;
		}
	}
	for (int i = 0; i < *spaces; i++){
		if ((arr[i][0] < 0 && arr[i][0] > 8)||(arr[i][1] < 0 && arr[i][1] > 8)){
			return false;
		}
	}
	return true;
}

/********************************************************************* 
** Function: jumpx()
** Description: check if x jumped
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool jumpx(char **board, int arr[][2], int i, int u, int v){
	int x = arr[i][0];
	int y = arr[i][1];

	if (abs(x-u) == 2 && abs(y-v) == 2){
		if (board[x + ((x-u)/2)][y + ((y-v)/2)] == 'o' || board[x + ((x-u)/2)][y + ((y-v)/2)] == 'O'){
			board[x + ((x-u)/2)][y + ((y-v)/2)] = ' ';
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

/********************************************************************* 
** Function: jumpo()
** Description: check if o jumped
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool jumpo(char **board, int arr[][2], int i, int u, int v){
	int x = arr[i][0];
	int y = arr[i][1];

	if (abs(x-u) == 2 && abs(y-v) == 2){
		if (board[x + ((x-u)/2)][y + ((y-v)/2)] == 'x' || board[x + ((x-u)/2)][y + ((y-v)/2)] == 'X'){
			board[x + ((x-u)/2)][y + ((y-v)/2)] = ' ';
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

/********************************************************************* 
** Function: jump_check()
** Description: check jumps
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool jump_check(char **board, int *player, string l, int *spaces, int u, int v){
	int spot = 0;
	int arr[*spaces][2];
	for (int i = 0; i < *spaces; i++){
		arr[i][0] = l[spot + 1] - 48;
		arr[i][1] = l[spot + 3] - 48;
		spot += 6;
	}
	if (*spaces > 1){
		for (int i = 0; i < *spaces; i++){
			if (*player == 1){
				if (jumpx(board, arr, i, u, v)){
					return true;
				} else {
					return false;
				}
			}else if (*player == 2){
				if (jumpo(board, arr, i, u, v)){
					return true;
				} else {
					return false;
				}
			}
			u = arr[i][0];
			v = arr[i][1];
		}
	}
}

/********************************************************************* 
** Function: empty_space()
** Description: checks for empty space
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/



bool empty_space(char **board, string l, int *spaces){
	int spot = 0;
	int arr[*spaces][2];
	for (int i = 0; i < *spaces; i++){
		arr[i][1] = l[spot + 1] - 48;
		arr[i][0] = l[spot + 3] - 48;
		spot += 6;
	}
	for (int i = 0; i < *spaces; i++){
		if (board[arr[i][0]][arr[i][1]] != ' '){
			cout << board[arr[i][0]][arr[i][1]] << endl;
			return false;
		}
	}
	return true;
}


/********************************************************************* 
** Function: check_diag()
** Description: checks if move is diagonal
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool check_diag(char **board, string l, int i, int u, int v, bool jump){
	cout << "HIHIH" << endl;
	int spot = i * 6;
	int x,y;
	x = l[spot + 1] - 48;
	y = l[spot + 3] - 48;
	cout << x -v << y-u << endl;
	cout << v << u << endl;
	if (abs(x - v) == 1 && abs(y - u) == 1){
		if ((x % 2 != v % 2) && (y % 2 != u % 2)){
			return true;
		} 
		return true;
	} else if(abs(x - v) == 2 && abs(y - u) == 2){
		if ((x % 2 == v % 2) && (y % 2 == u % 2)){
			if (jump == false){
				cout << " aasd" << endl;
				return false;
			} else {
			return true;
			}
		}
	} else {
		cout << "asfasdf" << endl;
		return false;
	}
}

/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool check_dir(char **board, int *player, int o, int p, string l, int i){
	int y = l[3+(i*6)] - 48;
	if (board[o][p] == 'x' || board[o][p] == 'o'){
		if (*player == 1 && p > y){
			return false;
		} else if (*player == 2 && p < y){
			return false;
		}
	} else if (board[o][p] == 'X' || board[o][p] == 'O'){
		return true;
	}
	return true;
}


/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


bool move_check(char **board, int *player, string l, int u, int v){
	//player 1 is x player 2 is o
	int spaces = 0, o = u, p = v;
	bool jump = false;

	// check if syntax is correct
	if (coord_syntax(l, &spaces) == false){
		cout << "s" << endl;
		return false;
	}
	
	jump = jump_check(board, player, l, &spaces, u, v);

	// check for empty space
	if (empty_space(board, l, &spaces) == false){
		cout << "e" << endl;
		return false;
	}
	// check if the move is diagonal
	/*for (int i = 0; i < spaces; i++){
		if (check_diag(board, l, i, o, p, jump) == false){
			cout << "d" << endl;
			return false;
		} else if (check_dir(board, player, o, p, l, i) == false){ // check if move is the right direction
			return false;
		}
		p = l[1+(i*6)] - 48;
		o = l[3+(i*6)] - 48;
	}
	*/


	return true;
}


/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


void doit(char **board, int *player, string l, int x, int y){
	int spaces = 0, spot = 0;
	for (int i = 0; i < l.length(); i++){
		if (l[i] == ' '){
			spaces += 1;
		}
	}
	spaces += 1;
	int arr[spaces][2];
	for (int i = 0; i < spaces; i++){
		arr[i][1] = l[spot + 3] - 48;
		arr[i][0] = l[spot + 1] - 48;
		spot += 6;
	}
	cout << x << y << endl;
	if (*player == 1){
		if (arr[spaces-1][1] == 8){
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'X';
			board[x][y] = ' ';
		}
		if (board[x][y] == 'X'){
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'X';
			board[x][y] = ' ';
		} else {
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'x';
			board[x][y] = ' ';
		}
	} else if (*player == 2) {
		if (arr[spaces-1][1] == 1){
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'O';
			board[x][y] = ' ';
		}
		if (board[x][y] == 'O'){
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'O';
			board[x][y] = ' ';
		} else {
			board[arr[spaces-1][1]][arr[spaces-1][0]] = 'o';
			board[x][y] = ' ';
		}
	}

}

/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


void move(char **board, int *player){
	string l, p;
	int x,y;
	cout << "Please specify the coordinates your desired piece. ex: (2,3)" << endl;
	getline(cin, l);
	while (select_check(board, player, l, &x, &y) == false){
		cout << "Those coordinates are not available, please enter coordinates of your piece" << endl;
		getline(cin, l);
	}
	x = l[3] -48;
	y = l[1] -48;
	cout << "Select the coordinates that you would like to move your piece to separated by a space. ex: (2,3) (4,5)" << endl;
	getline(cin, p);
	while(move_check(board, player, p, x, y) == false){
		cout << "These coordinates do not work, please type in coordinates for a valid move" << endl;
		getline(cin, p);
	}
	doit(board, player, p, x, y);


}


/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/


void turn(char **board, int *player, int bnum){
	if (*player == 2){
		*player = 1;
	} else {
		*player = 2;
	}
	move(board, player);
	cout << "what" << endl;
	display_board(board, bnum);
	turn(board, player, bnum);

}


/********************************************************************* 
** Function: display board()
** Description: display
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/

int main(int argc, char **argv){
	if (argument_check(argc, argv)){
		return 0;
	}
	int player = 2;
	int bnum = atoi(argv[1]) + 1;
	char **board = new char*[bnum];
	create_board(board, bnum);
	turn(board, &player, bnum);
	delete_board(board, bnum);

}