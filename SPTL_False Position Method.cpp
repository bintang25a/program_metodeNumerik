#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 100

using namespace std;

int digit = 4;
const double e = 2.7182818284590;
double pangkat(double x, double n);
double errorToleransi(int n);
double errorAproximasi(double apSkrng, double apSblm);
double f(double x);

double pangkat(double x, double n) {
	
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

double f(double x) {
	
	return pangkat2(x, 2) + pangkat(e, x) + (2*x);
	//return pangkat(e, -x)-x;
}

double errorToleransi(int n) {

	return (0.5*pangkat(10, 2-n));
}

double errorAproximasi(double apSkrng, double apSblm) {
	
	double hasil;
	
	hasil = (apSkrng-apSblm)/apSkrng;
	
	if (hasil<0) {
		
		hasil*=-1;
	}
	
	hasil *= 100;
	
	return hasil;
}

void printline(int n) {
	
	for (int i=0; i<n; i++) {
		
		cout <<"=";
	}
	
	cout << endl;
}

int main() {
	
	string nString;
	int n, iterasi=1;
	double x1, xu, xr[MAX], X1, Xu, errorT, errorA;
	
	cout << " Masukan x1 : ";
	cin >> x1;
	cout << " Masukan xu : ";
	cin >> xu;
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
	
	X1 = x1;
	Xu = xu;
	
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
		cout << setprecision(digit) << " x1 = " << x1 << endl;
		cout << setprecision(digit) << " xu = " << xu << endl;
		cout << setprecision(digit) << " f(x1) = f(" << x1 << ") = " << f(x1) << endl;
		cout << setprecision(digit) << " f(xu) = f(" << xu << ") = " << f(xu) << endl;
		cout << endl;
		
		//output proses berhitung
		xr[iterasi] = xu - ((f(xu)*(xu-x1))/(f(xu)-f(x1)));
		cout << setprecision(digit) << " xr = xu - ((f(xu) * (xu-x1)) / (f(xu) - f(x1)))" << endl;
		cout << setprecision(digit) << " xr = " << xu << " - (((" << f(xu) << ")(" << xu << " - " << x1 << ")) / (" << f(xu) << " - " << f(x1) << "))" << endl;
		cout << setprecision(digit) << " xr = " << xr[iterasi] << endl;
		cout << setprecision(digit) << " f(xr) = f(" << xr[iterasi] << ") = " << f(xr[iterasi]) << endl;
		
		//output perbandingan nilai
		if ((f(x1)*f(xr[iterasi])) < 0) {
			
			cout << "\n f(x1)f(xr) = f(" << x1 << ")f(" << xr[iterasi] << ") = " << f(x1) << "(" << f(xr[iterasi]) << ") < 0 -> xu = xr" << endl; 
			xu = xr[iterasi];
		}
		else if ((f(xr[iterasi])*f(xu)) < 0) {
			
			cout << "\n f(x1)f(xr) = f(" << x1 << ")f(" << xr[iterasi] << ") = " << f(x1) << "(" << f(xr[iterasi]) << ") > 0" << endl; 
			cout << " f(xr)f(xu) = f(" << xr[iterasi] << ")f(" << xu << ") = " << f(xr[iterasi]) << "(" << f(xu) << ") < 0 -> x1 = xr" << endl;
			x1 = xr[iterasi];
		}
		else {
			
			break;
		}
		
		//output error aproximasi
		if (iterasi > 1) {
			
			errorA = errorAproximasi(xr[iterasi], xr[iterasi-1]);
			cout << setprecision(digit) << "\n Error Aproximasi = " << errorA << "%" << endl;
		}
		else {
			
			errorA = errorAproximasi(100, 1);
		}
		
		iterasi++;
		
	} while (((f(x1)*f(xu)) != 0) && (errorA >= errorT));
	
	printline(100);	
	cout << "\n Dari hasil perhitungan diperoleh solusi untuk f(x) = e pangkat -x dikurang x pada interval: " << endl;
	cout << " x1 = " << X1 << " dan xu = " << Xu << " adalah x " << xr[iterasi-1] << " dengan error aproximasi sebesar " << errorA << "%\n" << endl;
	printline(100);
	system("pause");
}