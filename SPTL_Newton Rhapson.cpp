#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#define MAX 100

using namespace std;

int digit = 5;
double e = 2.7182818284590;
double pangkat1(double x, double n);
double pangkat2(double x, double n);
double errToleransi(int n);
double errAproximasi(double apSkrng, double apSblm);
double f(double x);

double pangkat1(double x, double n) {
	
	double y;
	y = n*log(x);
	return exp(y);
}

double pangkat2(double x, int n) {
	
	double hasil=1;
	for (int i=0; i<n; i++) {
		hasil*=x;
	}
	
	if (x < 0) {
		if (hasil > 0) {
			return hasil*-1;
		}
		else {
			return hasil;
		}
	}
	else if (x = 0) {
		return 1;
	}
	else {
		return hasil;
	}
}

//Menyesuaikan soal
double f(double x) {

	return pangkat2(x, 2) + pangkat1(e, x) + (2*x);
	//return ((3*pangkat1(e, 2*x)) - pangkat2(x, 5) - 2);
	//return (4800 * (1-pangkat1(e, -x/10))) - (320*x);
}

//Menyesuaikan soal
double fTurunan(double x) {
	
	return (x + pangkat1(e, x) + 2);
	//return ((2*3*pangkat1(e, 2*x)) - (5*pangkat2(x, 4)));
	//return (480 * pangkat1(e, -x/10) - 320);
}

double errorToleransi(int n) {

	return (0.5*pangkat1(10, 2-n));
}

double errorAproximasi(double apSkrng, double apSblm) {
	
	double hasil;
	
	hasil = (apSkrng-apSblm)/apSkrng;
	
	if (hasil<0) {
		
		hasil*=-1;
	}
	
	hasil *= 1;
	
	return hasil;
}

void printline(int n) {
	
	for (int i=0; i<n; i++) {
		
		cout <<"=";
	}
	
	cout << endl;
}

int main() {
	
	stringstream convert;
	string nString;
	int n, iterasi=1;
	double x[MAX], errorA=1, errorT=0;

	cout << " Masukan taksiran awal : ";
	cin >> x[0];	
	cout << " Masukan angka signifikan : ";
	cin >> nString;
	
	if (nString == "-") {
		cout << " Masukan Error Toleransi : ";
		cin >> errorT;
	}
	else {
		n = stoi(nString);
		errorT = errorToleransi(n);
	}
	
	cout << endl;
	cout << setw(25) << "JAWAB" << endl;
	printline(50);
	
	if (errorT != 0) {
		cout << "\n Error Toleransi = " << errorT << "%" << endl;
	}
	else {
		cout << "\n Error Toleransi = -" << endl;
	}
	
	cout << endl;
	
	do {
		
		//output nilai yang diketahui
		printline(40);
		cout << " Iterasi " << iterasi << ":\n" << endl;
		cout << setprecision(digit) << " x[" << iterasi-1 << "] = " << x[iterasi-1] << endl;
		cout << setprecision(digit) << " f(x[" << iterasi-1 << "])  = " << f(x[iterasi-1]) << endl;
		cout << setprecision(digit) << " f'(x[" << iterasi-1 << "]) = " << fTurunan(x[iterasi-1]) << endl;
		cout << endl;
		
		//output proses perhitungan
		x[iterasi] = x[iterasi-1] - (f(x[iterasi-1])/fTurunan(x[iterasi-1]));
		cout << setprecision(digit) << " x[" << iterasi << "] = x[" << iterasi-1 << "] - (f(x[" << iterasi-1 << "]) / f'(x[" << iterasi-1 << "]))" << endl;
		cout << setprecision(digit) << " x[" << iterasi << "] = " << x[iterasi-1] << " - (" << f(x[iterasi-1]) << " / " << fTurunan(x[iterasi-1]) << ")" << endl;
		cout << setprecision(digit) << " x[" << iterasi << "] = " << x[iterasi] << endl;
		
		if (iterasi > 1) {
			//if (x[iterasi]-x[iterasi-1] < -0.00000001) {
				
				errorA = errorAproximasi(x[iterasi], x[iterasi-1]);
				cout << setprecision(digit) << fixed << "\n Error Aproximasi = " << errorA << "%" << endl;			
			//}
			/*else {
				
				errorA = 0;
				cout << setprecision(0) << fixed << "\n Error Aproximasi = " << errorA << "%" << endl;
			}*/
		}
		else {
			
			errorA = errorAproximasi(100, 1);
		}
	
		iterasi++;
		
	} while ((errorA != 0) && (errorA >= errorT));
	
	system("pause");
}