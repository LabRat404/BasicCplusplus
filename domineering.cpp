//Yeung Tang 1155144676 1155144676@link.cuhk.edu.hk
using namespace std;
#include <iostream>
#include <stack>
int gridState(long long grid, int pos) {
	pos = 17 - pos;
	int tmp = 0;
	int i = 1;
	while (grid != 0) {
		tmp = grid % 10;
		grid /= 10;
		if (i == pos) 
			return tmp;
		i++;	
	}
}

void printGrid(long long grid) {
	int length = 17; //length of the grid, which includes the initiate value 1 in front
	for (int i = 1; i < length; i++) {
		int tmp = gridState(grid, i);
		if (tmp > 1)
			cout << 'B';
		else if (tmp == 1)
			cout << 'A';
		else
			cout << '.';
		if (i % 4 == 0)
			cout << '\n';
		else
			cout << ' ';
	}
}

bool isPlaceable(long long grid, int pos, int p) {
	if ((pos < 1 || pos>16) && (p < 1 || p>2)) //falses if the value inputed is incorrect
		return false;
	if (p == 1) {
		if (pos > 12) //fasle if the player 1 value exceeds 12, since theres no next linein grid after 12
			return false;
		if ((gridState(grid, pos) != 0) || (gridState(grid, pos + 4) != 0)) //check if both value x and x+4(next line) is availiable to insert
			return false;
		return true;
	}
	else {
		if (pos % 4 == 0) //false if player2 puts value at the rightest side of the grid
			return false;
		if ((gridState(grid, pos) != 0) || (gridState(grid, pos + 1) != 0)) //check if both value x and x+1 is availiable to insert
			return false;
		return true;
		}
	return false;
}


void putToGrid(long long &grid, int pos, int p) {
	pos = 16 - pos; //Just like stack, but since we cant use stack, we reverse the value for the number we needed
	long long tmp = 1; //the first value to put in grid
	long long tmp2 = 1; //the second value to put in grid
	for (int i = 0; i < pos; i++)
		tmp *= 10; 
	if (p == 1) {
		for (int i = 0; i < pos-4; i++) //put 1 in the grid array
		tmp2 *= 10;
	}
	else {
		for (int i = 0; i < pos - 1; i++) //put 2 in the grid array
		tmp2 *= 10;
		tmp2 *= 2;
		tmp *= 2;
	}
	grid = grid + tmp + tmp2; //Value inserted to grid
}

//extra function for switching players
void change_player(int &player) {
	if (player == 1)
		player = 2;
	else
		player = 1;
}

int main()
{
	long long grid = 10000000000000000;  //initialize the grid value, which is 0000000000000000
	int flag = 1;
	int player = 1;
	int input = 0;
	int sum = 0;
	while (flag > 0) {
		flag = 1;
		printGrid(grid);
		for (int i = 0; i < 16; i++)
			flag += isPlaceable(grid, i, player); //check if the grid have possible place for player to insert
		flag -= 1;
		if (flag <= 0)
			break; //breaks the program when someone wins
		while (1) {
			cout << "Player "<< player <<"'s move: ";
			cin >> input;
			if (isPlaceable(grid, input, player) == false) //helps gets a correct input from player
				cout << "Invalid! Try again.\n";
			else
				break;
		}
		putToGrid(grid, input, player);
		change_player(player);
	}
	change_player(player);
	cout << "Player " << player << " wins!"; //Playerx Wins the game
}

