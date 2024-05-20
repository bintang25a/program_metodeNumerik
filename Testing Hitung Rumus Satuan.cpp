#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#define MAX 50

using namespace std;

double e = 2.7182818284590;

double pangkat(double x, double n) {
	
	double y;
	y = n*log(x);
	return exp(y);
}

double f(double x) {

	return pangkat(e, -x)-x;
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
	
	string pilih;
	double a[MAX], b[MAX], n[MAX], x[MAX];
	double memAp[MAX], memTl[MAX], memFx[MAX];
	int batas1=0, batas2=0, batas3=0;
	
	do {
		
		system("cls");
		printline(25);
		cout << " [1]\tError Aproximasi" << endl;
		cout << " [2]\tError Toleransi" << endl;
		cout << " [3]\tNilai f(x)" << endl;
		cout << " [exit]\tKeluar" << endl;
		printline(25);
		cout << " PILIH MENU : ";
		cin >> pilih;
		
		if (pilih == "1") {
			
			system("cls");
			
			do {
					
				if (batas1>0) {
					
					printline(35);
					for(int i=0; i<batas1; i++) {
						
						cout << " now = " << a[i] << " & then = " << b[i] << " = " << memAp[i] << "%" << endl;
					}
					printline(35);
				}
					
				cout << " Masukan nilai Aproximasi Sekarang\t: ";
				cin >> a[batas1];
				cout << " Masukan nilai Aproximasi Sebelumnya\t: ";
				cin >> b[batas1];
				system("cls");
				
				if (a[batas1] <= 100) {
					
					memAp[batas1] = errorAproximasi(a[batas1], b[batas1]);
					batas1++;
				}
				
			} while (a[batas1] <= 100);
		}
		else if (pilih == "2") {
			
			system("cls");
			
			do {
				
				if (batas2>0) {
					
					printline(35);
					for (int i=0; i<batas2; i++) {
						
						cout << " n = " << n[i] << " = " << memTl[i] << "%" << endl;
					}
					printline(35);
				}
				
				cout << " Masukan jumlah angka signifikan : ";
				cin >> n[batas2];
				system("cls");
				
				if (n[batas2] <= 100) {
				
					memTl[batas2] = errorToleransi(n[batas2]);
					batas2++;
				}
			} while (n[batas2] <= 100);	
		}
		else if (pilih == "3") {
			
			system("cls");
			
			do {
				
				if (batas3>0) {
					
					printline(35);
					for (int i=0; i<batas3; i++) {
						
						cout << " f(x) = f(" << x[i] << ") = " << memFx[i] << endl;
					}
					printline(35);
				}
				
				cout << " Masukan nilai x : ";
				cin >> x[batas3];
				system("cls");
				
				if (x[batas3] <= 100) {
					
					memFx[batas3] = f(x[batas3]);
					batas3++;
				}
			} while (x[batas3] <= 100);
		}
	} while (pilih != "exit");
}