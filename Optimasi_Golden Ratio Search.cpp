#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 100
#define digit 5

using namespace std;

const double e = 2.7182818284590;
const double r = (-1 + sqrt(5))/2;
double pangkat1(double x, double n);
double f(double x);
double rumusC(double a, double b, int n, int k);
double rumusD(double a, double b, int n, int k);
double pangkat1(double x, double n);
double pangkat2(double x, double n);
double errorToleransi(int n);
void printline(int n);

//menghitung pangkat v1
double pangkat1(double x, double n) {
	
	double y;
	y = n*log(x);
	return exp(y);
}

//menghitung pangkat v2
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

//rumus f(x), RUMUS MENYESUAIKAN SOAL
double f(double x) {
	
	//return ((2*sin(x)) - (pangkat1(x, 2)/10));
	return (pangkat1(x, 2) - sin(x));
}

//rumus mencari elemen c
double rumusC(double a, double b) {
	
	return (a + ((1-r) * (b-a)));
	//return ((r*a) + ((1-r) * b));
}

//rumus mencari elemen d
double rumusD(double a, double b) {
	
	return (b - ((1-r) * (b-a)));
	//return (((1-r) * a) + b);
}

//rumus menghitung error toleransi
double errorToleransi(int n) {

	return (0.5*pangkat1(10, 2-n));
}

//mengecek apakah kedua data apakah sama
bool isKonvergen(float x0, float x1) {
	
	if (x0 == x1) {
		return true;
	}
	else {
		return false;
	}
}

//membuat garis
void printline(int n) {
	
	for (int i=0; i<n; i++) {
		
		cout <<"=";
	}
	
	cout << endl;
}

int main() {
	
	string nString;
	int n, iterasi;
	double a[MAX], b[MAX], c[MAX], d[MAX], errorT=0, k;
	
	//input nilai a dan b
	cout << " Input nilai a : ";
	cin >> a[0];
	cout << " Input nilai b : ";
	cin >> b[0];
	
	//mencari nilai c dan d
	c[0] = rumusC(a[0], b[0]);
	d[0] = rumusD(a[0], b[0]);
	
	//mencari error toleransi
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
	
	//mencari nilai k, batas iterasi
	if (errorT != 0) {
		
		k = log(errorT/(b[0]-a[0]))/log(r);
	}
	else {
		
		k = log(pangkat1(10, -4)/(b[0]-a[0]))/log(r);	
	}
	
	//menampilkan jawaban
	cout << endl;
	cout << setw(25) << "JAWAB" << endl;
	printline(50);
	cout << setprecision(digit) << "\n Nilai k > " << k << endl;
	cout << " Banyaknya Iterasi = " << ceil(k) << "\n" << endl;
	
	//menampilkan jawaban per iterasi
	for (iterasi=1; iterasi<=k; iterasi++) {
		
		printline(40);
		cout << " Iterasi " << iterasi << ":\n" << endl;

		//tampilan nilai yang diketahui per iterasi	
		cout << setprecision(digit) << " a[" << iterasi-1 << "] = " << a[iterasi-1] << ", b[" << iterasi-1 << "] = " << b[iterasi-1] << endl;
		if (iterasi == 1) {

			cout << setprecision(digit) << "\n c[" << iterasi-1 << "] = a[" << iterasi-1 << "] + (1-r)*(b[" << iterasi-1 << "]-a[" << iterasi-1 << "])" << endl;
			cout << setprecision(digit) << " c[" << iterasi-1 << "] = " << a[iterasi-1] << " + (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
			cout << setprecision(digit) << " c[" << iterasi-1 << "] = " << c[iterasi-1] << endl;
				
			cout << setprecision(digit) << "\n d[" << iterasi-1 << "] = b[" << iterasi-1 << "] - (1+r)*(b[" << iterasi-1 << "]-a[" << iterasi-1 << "])" << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = " << b[iterasi-1] << " - (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = " << d[iterasi-1] << endl;			
		}
		else if ((f(c[iterasi-2]) <= f(d[iterasi-2])) && (iterasi > 1)) {
			
			cout << setprecision(digit) << "\n c[" << iterasi-1 << "] = a[" << iterasi-1 << "] + (1-r)*(b[" << iterasi-1 << "]-a[" << iterasi-1 << "])" << endl;
			cout << setprecision(digit) << " c[" << iterasi-1 << "] = " << a[iterasi-1] << " + (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
			cout << setprecision(digit) << " c[" << iterasi-1 << "] = " << c[iterasi-1] << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = " << d[iterasi-1] << endl;			
		}
		else if ((f(c[iterasi-2]) > f(d[iterasi-2])) && (iterasi > 1)) {
			
			cout << setprecision(digit) << "\n c[" << iterasi-1 << "] = " << c[iterasi-1] << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = b[" << iterasi-1 << "] - (1+r)*(b[" << iterasi-1 << "]-a[" << iterasi-1 << "])" << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = " << b[iterasi-1] << " - (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
			cout << setprecision(digit) << " d[" << iterasi-1 << "] = " << d[iterasi-1] << endl;
		}
		cout << setprecision(digit) << "\n f(c[" << iterasi-1 << "]) = " << f(c[iterasi-1]) << endl;
		cout << setprecision(digit) << " f(d[" << iterasi-1 << "]) = " << f(d[iterasi-1]) << endl;

		//mengecek apakah f(c) dan f(d) memiliki nilai yang sama
		if (isKonvergen(ceil(f(c[iterasi-1])*1000000), ceil(f(d[iterasi-1])*1000000)) == true) {
			
			system("pause");
			//break;
		}
	
		//kondisi golden ratio search
		if (f(c[iterasi-1]) <= f(d[iterasi-1])) {

			a[iterasi] = a[iterasi-1];
			b[iterasi] = d[iterasi-1];
			c[iterasi] = rumusC(a[iterasi], b[iterasi]);
			d[iterasi] = c[iterasi-1];
			
			cout << " (" << f(c[iterasi-1]) << ") <= (" << f(d[iterasi-1]) << ") maka nilai terletak di interval [a,d]\n" << endl;
			cout << " a[" << iterasi << "] = a[" << iterasi-1 << "]" << endl;
			cout << " b[" << iterasi << "] = d[" << iterasi-1 << "]" << endl;
			cout << " c[" << iterasi << "] = " << a[iterasi-1] << " + (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
			cout << " d[" << iterasi << "] = c[" << iterasi-1 << "]" << endl;
		}
		else if (f(c[iterasi-1]) > f(d[iterasi-1])) {
			
			a[iterasi] = c[iterasi-1];
			b[iterasi] = b[iterasi-1];
			c[iterasi] = d[iterasi-1];
			d[iterasi] = rumusD(a[iterasi], b[iterasi]);
			
			cout << " (" << f(c[iterasi-1]) << ") > (" << f(d[iterasi-1]) << ") maka nilai terletak di interval [c,b]\n" << endl;
			cout << " a[" << iterasi << "] = c[" << iterasi-1 << "]" << endl;
			cout << " b[" << iterasi << "] = b[" << iterasi-1 << "]" << endl;
			cout << " c[" << iterasi << "] = d[" << iterasi-1 << "]" << endl;
			cout << " d[" << iterasi << "] = " << b[iterasi-1] << " - (1-" << r << ")*(" << b[iterasi-1] << "-" << a[iterasi-1] << ")" << endl;
		}
	}
	
	system("pause");
}