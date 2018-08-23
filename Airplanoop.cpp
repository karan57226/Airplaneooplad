#include <iostream>
#include <string>

#include "Aero.h"

using namespace std;

void displayPlane(char board[][4]){
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

int main() {
	Aero air;
	char plane[8][4];
	int noOfSeats;

	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 8; col++)
			plane[row][col] = ' ';

	noOfSeats = 0;

	bool done = false;
	char reserve = 'X';
	displayPlane(plane);

	while (!done) {
		done = air.getSeat(plane, noOfSeats, reserve);
//		noOfSeats++;
//		if (noOfSeats == 32){
//			cout << "All the seats have been reserved.";
//			done  = true;
//		}
	}

	return 0;
}
