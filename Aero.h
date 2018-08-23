/*
 * Aero.h
 *
 *  Created on: 22 Aug. 2018
 *      Author: Karan
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#ifndef Aero_H_
#define Aero_H_

//const int row = 8, col = 4;

class Aero {
public:
	char plane[8][4];
	int seats = 0;
	char reserve = 'x';
	Aero();
	void displayPlane(char board[][4]);
	bool isValidseat(char board[][4], int row, int col);
	bool getSeat(char board[][4], int noOfSeats, char reserveSymbol);
	void run();

};

void Aero::displayPlane(char board[][4]){
	cout << "    1   2   3   4" << endl << endl;
	for (int row = 0; row < 8; row++) {
		cout << row + 1;
		for (int col = 0; col < 4; col++) {
			cout << setw(4) << board[row][col];
		}
		cout << endl;
		cout << setw(5) << "  ___ ___ ___ ___" << endl;
	}
	cout << endl;
}
bool Aero::isValidseat(char board[][4], int row, int col){
	if ((row < 8 && row >= 0) && (col < 4 && col >= 0)) {
		if (board[row][col] == 'X') {
			cout << "Please pick another seat. This seat is occupied." << endl;
			return false;
		} else
			cout << "Reservation of seat: " << row + 1 << "," << col + 1
					<< " confirmed. " << endl << endl;
		return true;
	} else {
		cout << "Please enter a valid seat number." << endl;
		return false;
	}

}
bool Aero::getSeat(char board[][4], int noOfSeats, char reserveSymbol){
	int row, col;

	do {
		cout
				<< "Please enter the seat number in the format: row followed by column: ";
		cin >> row >> col;
		cout << endl;
	} while (isValidseat(board, row - 1, col - 1));

	row--;
	col--;

	noOfSeats++;

	board[row][col] = reserveSymbol;
	displayPlane(board);

	if (noOfSeats > 31) {
		cout << "All seats have been reserved.";
		return true;
	} else
		return false;
}
Aero::Aero(){
	cout << "hi" << endl;
}
void Aero:: run(){
	displayPlane(plane);
	getSeat(plane, seats, reserve);
}
#endif /* Aero_H_ */
