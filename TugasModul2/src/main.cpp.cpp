#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

vector <float> x;
vector <float> y;
int i = 0;
int bisa_redo = 0;

void lokasi() {
	cout << "Drone sekarang berada di titik koordinat (" << fixed << setprecision(2) << x[i] << ", " << fixed << setprecision(2) << y[i] << ")" << endl;
}

void gerak(float a, float b) {
	i++;
	x.push_back(x[i-1] + a);
	y.push_back(y[i-1] + b);
	bisa_redo = 0;
}

void gerak_2(float v, float t, float theta) {
	i++;
	float a, b;
	a = x[i-1] + v * t * cos(theta * M_PI / 180);
	b = y[i-1] + v * t * sin(theta * M_PI / 180);
	x.push_back(a);
	y.push_back(b);
	bisa_redo = 0;
}

void undo() {
	if (i == 0) {
		cout << "Tidak dapat undo!" << endl;
	} else {
		cout << "Undo berhasil" << endl;
		i--;
		bisa_redo++;
	}
}

void redo() {
	if (bisa_redo == 0) {
		cout << "Tidak dapat redo" << endl;
	} else {
		cout << "Redo berhasil" << endl;
		i++;
		bisa_redo--;
	}
}

int main(){
	cout << "*********************************************" << endl;
	cout << "*Selamat Datang di Drone Penjelajah CaKru 16*" << endl;
	cout << "*********************************************" << endl << endl;
	cout << "Saat ini drone berada pada posisi awal (0,0)" << endl << endl;
	cout << "Silahkan ketik nama fungsi yang ingin Anda jalankan: " << endl;
	cout << "1. lokasi" << endl;
	cout << "2. gerak" << endl;
	cout << "3. gerak_2" << endl;
	cout << "4. undo" << endl;
	cout << "5. redo" << endl;
	cout << "0. exit" << endl << endl;
	string masukan;
	cin >> masukan;
	x.push_back(0);
	y.push_back(0);
	while (masukan != "exit") {
		if (masukan == "lokasi") {
			lokasi();
		}
		else if (masukan == "gerak") {
			float a, b;
			cout << "Masukkan titik koordinat x dan y sebagai gerak dari drone" << endl;
			cin >> a >> b;
			gerak(a, b);
		}
		else if (masukan == "gerak_2") {
			float v, t, theta;
			cout << "Masukkan kecepatan, waktu, dan sudut yang akan ditempuh oleh drone" << endl;
			cin >> v >> t >> theta;
			gerak_2(v, t, theta);
		}
		else if (masukan == "undo") {
			undo();
		}
		else if (masukan == "redo") {
			redo();
		} 
		else {
			cout << "Fungsi tidak ditemukan, silahkan pilih fungsi yang lain" << endl;
		}
		cin >> masukan;
	}
}
