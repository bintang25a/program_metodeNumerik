#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#define MAX 100
#define digit 4

using namespace std;

//3,25x - 5,2y + 2,4z = -12,1
//4,6x - 5,2y + 4,4z = 33,5
//7,5x - 3,6y + 5,7z = 18,4

//2x - 3,2y + 2,4z = 7
//-3x + 4,5y + 2z = 10
//x + 2,5y - 3,4z = 5

float rumusX(float y, float z) {
	
	return (7 + (3.2*y) - (2.4*z))/2;
	//return (12.1 - (5.2*y) + (2.4*z))/-3.25;
	//return (7+y-z)/4;
}

float rumusY(float x, float z) {
	
	return (10 + (3*x) - (2*z))/4.5;
	//return (33.5 - (4.6*x) - (4.4*z))/5.2;
	//return (21+(4*x)+z)/8;
}

float rumusZ(float x, float y) {
	
	return (-5 + x + (2.5*y))/3.4;
	//return (18.4 - (7.5*x) + (3.6*y))/5.7;
	//return (15+(2*x)-y)/5;
}

void printline(int n) {
	
	for (int i=0; i<n; i++) {
		
		cout <<"=";
	}
	
	cout << endl;
}

int isKonvergen(float x0, float x1) {
	
	if (x0 == x1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	
	int iterasi=1, maxIterasi;
	float x[MAX], y[MAX], z[MAX];
	
	cout << " Masukan nilai x[0] : ";
	cin >> x[0];
	cout << " Masukan nilai y[0] : ";
	cin >> y[0];
	cout << " Masukan nilai z[0] : ";
	cin >> z[0];
	
	cout << " Banyak iterasi : ";
	cin >> maxIterasi;
	
	cout << endl;
	cout << setw(25) << "JAWAB" << endl;
	printline(50);
	cout << "\n Max iterasi = " << maxIterasi << endl;
	cout << endl;
	
	while (iterasi <= maxIterasi) {
		
		x[iterasi] = rumusX(y[iterasi-1], z[iterasi-1]);
		y[iterasi] = rumusY(x[iterasi], z[iterasi-1]);
		z[iterasi] = rumusZ(x[iterasi], y[iterasi]);
		
		if (isKonvergen(x[iterasi], x[iterasi-1]) == true) {
			
			system("pause");
			//break;
		}	

		printline(40);
		cout << " Iterasi " << iterasi << ":\n" << endl;		
		cout << setprecision(digit) << " x[" << iterasi << "] = " << x[iterasi] << endl;
		cout << setprecision(digit) << " y[" << iterasi << "] = " << y[iterasi] << endl;
		cout << setprecision(digit) << " z[" << iterasi << "] = " << z[iterasi] << endl;

		iterasi++;
	}
	
	system("pause");
}