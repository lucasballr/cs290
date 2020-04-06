/********************************************************************* 
** Program Filename: assign5.cpp
** Author: Lucas Ball
** Date: March 6, 2018
** Description: Farkle Game
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>

using namespace std;

/********************************************************************* 
** Function: players()
** Description: asks how many players, returns amount specified
** Parameters: none
** Pre-Conditions: int n
** Post-Conditions: input of user
*********************************************************************/

int players(){
	int n;
	cout << "How many players would you like to play" << endl;
	cin >> n;
	while (n < 2){
		cout << "More players" << endl;
		cin >> n;
	}
	return n;
}	

/********************************************************************* 
** Function: rolldice
** Description: roles a certain amount of dice specified by "d"
** Parameters: *dice, d
** Pre-Conditions: array dice, d cannot be more than 6
** Post-Conditions: each element of *dice has a random value
*********************************************************************/

void rolldice(int *dice, int d){
	srand (time(NULL));
	for (int i = 0; i < d; i++){
		dice[i] = rand() % 6 + 1;
		cout << dice[i];
	}
	cout << endl;
}

/********************************************************************* 
** Function: sixnum() 
** Description: checks for six of a kind in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int sixnum(int *dice){
	int a;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 6){
			cout << "You have a six of a kind" << endl;
			return 1;
		}
	}
	return 0;
}

/********************************************************************* 
** Function: fivenum() 
** Description: checks for five of a kind in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int fivenum(int *dice){
	int a;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 5){
			cout << "You have a five of a kind" << endl;
			return 1;
		}
	}
	return 0;
}

/********************************************************************* 
** Function: twotrip() 
** Description: checks for two three of a kinds in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int twotrip(int *dice){
	int a, b;
	bool flag = false;
	for(int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 3 && flag == false){
			b = a;
			flag = true;
		} else if (a == 3 && flag == true){
			cout << "two triplets" << endl;
			return 1;
		}
	}
	return 0;
}

/********************************************************************* 
** Function: fourtwo() 
** Description: checks for full house in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int fourtwo(int *dice){
	int a;
	bool flag;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 4){
			flag = true;
		}
		if (a == 2 && flag){
			cout << "full house" << endl;
			return 1;
		}
	}
}

/********************************************************************* 
** Function: threepair() 
** Description: checks for three pair in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int threepair(int *dice){
	int a, b;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 2){
			b += 1;
		}
	}
	if (b == 3){
		cout << "three pair" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: straight() 
** Description: checks for straight in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int straight(int *dice){
	int a, b;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a > 1 || a < 1){
			return 0;
		} else {
			b += 1;
		}
	}
	if (b == 6){
		cout << "1-6 straight" << endl;
		return 1;
	}
}

/********************************************************************* 
** Function: fournum() 
** Description: checks for four of a kind in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int fournum(int *dice){
	int a;
	for (int i = 1; i < 7; i++){
		a = 0;
		for (int z = 0; z < 6; z++){
			if (dice[z] == i){
				a += 1;
			}
		}
		if (a == 4){
			cout << "You have a four of a kind" << endl;
			return 1;
		}
	}
	return 0;
}

/********************************************************************* 
** Function: three1() 
** Description: checks for three of a kind of 1's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three1(int *dice){
	int a = 0;
	cout << endl;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 1){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 1s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: three2() 
** Description: checks for three of a kind of 2's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three2(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 2){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 2s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: three3() 
** Description: checks for three of a kind of 3's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three3(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 3){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 3s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: three4() 
** Description: checks for three of a kind of 4's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three4(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 4){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 4s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: three5() 
** Description: checks for three of a kind of 5's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three5(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 5){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 5s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: three1() 
** Description: checks for three of a kind of 1's in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1 or 0 based on result
*********************************************************************/

int three6(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 6){
			a++;
		}
	}
	if (a == 3){
		cout << "Three 6s" << endl;
		return 1;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: ones() 
** Description: checks for ones in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1, 2, or 0 based on result
*********************************************************************/

int ones(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 1){
			a++;
		}
	}
	if (a > 0 && a < 3){
		return a;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: fives() 
** Description: checks for fives in *dice
** Parameters: *dice
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: 1, 2, or 0 based on result
*********************************************************************/

int fives(int *dice){
	int a = 0;
	for (int z = 0; z < 6; z++){
		if (dice[z] == 5){
			a++;
		}
	}
	if (a > 0 && a < 3){
		return a;
	} else {
		return 0;
	}
}

/********************************************************************* 
** Function: interpret_big() 
** Description: interprets scorable dice based on large scoring checks
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big, *holds = 0 
** Post-Conditions: *holds has a certain amount added based on result
*********************************************************************/


void interpret_big(int *dice, int *score, int i, int *holds){
	if (sixnum(dice) == 1){
		*holds += 6;
	} else if (fivenum(dice) == 1){
		*holds += 5;
	} else if (fourtwo(dice) == 1){
		*holds += 6;
	} else if (twotrip(dice) == 1){
		*holds += 6;
	} else if (threepair(dice) == 1){
		*holds += 6;
	} else if (straight(dice) == 1){
		*holds += 6;
	} else if (fournum(dice) == 1){
		*holds += 4;
	} else {
		*holds += 0;
	}
}

/********************************************************************* 
** Function: score_big() 
** Description: scores based on inputs
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *score has a certain amount added based on result
*********************************************************************/

void score_big(int *dice, int *score, int i, int *holds){
	if (sixnum(dice) == 1){
		score[i] += 3000;
	} else if (fivenum(dice) == 1){
		score[i] += 2000;
	} else if (fourtwo(dice) == 1){
		score[i] += 1500;
	} else if (twotrip(dice) == 1){
		score[i] += 2500;
	} else if (threepair(dice) == 1){
		score[i] += 1500;
	} else if (straight(dice) == 1){
		score[i] += 1500;
	} else if (fournum(dice) == 1){
		score[i] += 1000;
	}
}

/********************************************************************* 
** Function: interpret_med() 
** Description: interprets scorable dice based on medium scoring checks
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *holds has a certain amount added based on result
*********************************************************************/

void interpret_med(int *dice, int *score, int i, int *holds){
	if (three1(dice) == 1){
		*holds += 3;
	}
	if (three2(dice) == 1){
		*holds += 3;
	}
	if (three3(dice) == 1){
		*holds += 3;
	}
	if (three4(dice) == 1){
		*holds += 3;
	}
	if (three5(dice) == 1){
		*holds += 3;
	}
	if (three6(dice) == 1){
		*holds += 3;
	} 
}

/********************************************************************* 
** Function: score_med() 
** Description: scores based on inputs
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *score has a certain amount added based on result
*********************************************************************/

void score_med(int *dice, int *score, int i, int *holds){
	if (three1(dice) == 1){
		score[i] += 300;
	}
	if (three2(dice) == 1){
		score[i] += 200;
	}
	if (three3(dice) == 1){
		score[i] += 300;
	}
	if (three4(dice) == 1){
		score[i] += 400;
	}
	if (three5(dice) == 1){
		score[i] += 500;
	}
	if (three6(dice) == 1){
		score[i] += 600;
	}
}

/********************************************************************* 
** Function: interpret_holds() 
** Description: interprets scorable dice based on large scoring checks
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *holds has a certain amount added based on result
*********************************************************************/

void interpret_holds(int *dice, int *score, int i, int *holds){
	if (ones(dice) == 1){
		cout << "1 one" << endl;
		*holds += 1;
	} else if (ones(dice) == 2){
		cout << "2 ones" << endl;
		*holds += 2;
	}
	if (fives(dice) == 1){
		cout << "1 five" << endl;
		*holds += 1;
	} else if (fives(dice) == 2){
		cout << "2 fives" << endl;
		*holds += 2;
	}
}

/********************************************************************* 
** Function: score_holds() 
** Description: scores based on inputs
** Parameters: *dice, *score, i, *holds
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *score has a certain amount added based on result
*********************************************************************/

void score_holds(int *dice, int *score, int i, int *holds){
	if (ones(dice) == 1){
		score[i] += 100;
	} else if (ones(dice) == 2){
		score[i] += 200;
	}
	if (fives(dice) == 1){
		score[i] += 50;
	} else if (fives(dice) == 2){
		score[i] += 100;
	}
}

/********************************************************************* 
** Function: dice_reset()
** Description: resets *dice to 0
** Parameters: *dice
** Pre-Conditions: *dice is 6 big
** Post-Conditions: every element of *dice is 0
*********************************************************************/

void dice_reset(int *dice){
	for (int i = 0; i < 6; i++){
		dice[i] = 0;
	}
}

/********************************************************************* 
** Function: get_roll() 
** Description: error handle for rolling dice
** Parameters: x 
** Pre-Conditions: x is int
** Post-Conditions: returns user input
*********************************************************************/

int get_roll(int x){
	cout << "Press 1 to roll the dice, Press 0 to end turn" << endl;
	cin >> x;
	while (x != 1 && x != 0){
		cout << "Please enter a 1 or a 0" << endl;
		cin >> x;
	}
	return x;
}

/********************************************************************* 
** Function: check_500() 
** Description: checks if player hit 500 points in turn
** Parameters: *score, *scoret, i
** Pre-Conditions: score is a pointer
** Post-Conditions: *scoret is changed if *score is larger than 500
*********************************************************************/

int check_500(int *score, int *scoret, int i){
	if (score[i] >= 500){
			scoret[i] += score[i];
		} else {
			cout << "You did not hit 500" << endl;
		}
}

/********************************************************************* 
** Function: set_dice_roll() 
** Description: asks for user input for how many dice to roll again
** Parameters: *dice, o, u, p
** Pre-Conditions: *dice is p big
** Post-Conditions: element in *dice changed based on user input
*********************************************************************/

int set_dice_roll(int *dice, int o, int u, int p){
	cout << "Please enter which dice you would like to roll again" << endl;
	for (int y = 0; y < p-u; y++){
		cin >> o;
		dice[o] = 0;
	}
	for (int y = 0; y < 6; y++){
		cout << dice[y];
	}
}
/********************************************************************* 
** Function: turn() 
** Description: implements player turn
** Parameters: *dice, *score, i, p, *scoret
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: scoret is changed if score reaches 500
*********************************************************************/

int turn(int *dice, int *score, int i, int p, int *scoret){
	score[i] = scoret[i];
	int x, u, o;
	int *holds = new int;
	*holds = 0;
	dice_reset(dice);
	cout << "Your score: " << score[i] << endl;
	x = get_roll(x);
	if (x == 1){
		rolldice(dice, p);	
	} else if (x == 0){
		check_500(score, scoret, i);
		return 0;
	}
	interpret_big(dice, score, i, holds);
	interpret_med(dice, score, i, holds);
	interpret_holds(dice, score, i, holds);
	cout << "You have " << *holds << " scorable dice" << endl;
	if (*holds == 0){
		check_500(score, scoret, i);
		cout << "farkle! Next player!" << endl;
		return 0;
	}
	cout << "How many dice would you like to score?" << endl;
	cin >> u;
	while (u > *holds){
		cout << "You cannot score that many dice. Please enter new amount" << endl;
		cin >> u;
	}
	set_dice_roll(dice, o, u, p);
	score_big(dice, score, i, holds);
	score_med(dice, score, i, holds);
	score_holds(dice, score, i, holds);
	if (p == 6){
		p = 6-u;
	} else {
		p = p-u;
	}
	turn(dice, score, i, p, scoret);
	delete holds;
	holds = NULL;
}

/********************************************************************* 
** Function: special() 
** Description: if score of player hits 10000 run the rest of the turns
** Parameters: *dice, *score, i, *scoret, pl, k
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: winner is decided based on best score
*********************************************************************/


int special(int *dice, int *score, int i, int *scoret, int pl, int k){
	for (i = 0; i < pl; i++){
			if (i == k){
				i++;
			}
			score[i] = 0;
			cout << "Player " << i + 1 << " it's your turn" << endl;
			turn(dice, score, i, 6, scoret);
			cout << "Your score: " << scoret[i] << endl;
			if (scoret[i] > scoret[k]){
				k = i;
			}
	}
	cout << "Player " << k + 1 << " is the winner" << endl;
}

/********************************************************************* 
** Function: main() 
** Description: scores based on inputs
** Parameters: none
** Pre-Conditions: *dice is 6 big 
** Post-Conditions: *score has a certain amount added based on result
*********************************************************************/

int main(){
	int pl = players();
	int dice[6], score[pl], player, scoret[pl], k;
	bool flag = false;
		for (int i = 0; i < pl; i++){
		score[i] = 0;
		scoret[i] = 0;
		}
	while (flag == false){
		for (int i = 0; i < pl; i++){
			score[i] = 0;
			cout << "Player " << i + 1 << " it's your turn" << endl;
			turn(dice, score, i, 6, scoret);
			cout << "Your score: " << scoret[i] << endl;
			if (scoret[i] >= 10000){
				k = i;
				special(dice, score, i, scoret, pl, k);
				flag == true;
			}
		}
	}
}



