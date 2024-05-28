#include <iostream>
#include <vector>
#include <string>
using namespace std;

int UniqueWolf(int n,vector <int>& dizi){
	if (n < 5 || n > 200000) {
		cerr << "Hatali giris: n 5 ile 200000 arasýnda olmalidir!" << endl;
		return -1; // hata durumunda -1 return ediliyor
	}
	vector <int> cntIndex(6, 0); // id numaralarý 1-5 arasi oldugu icin 6 elemanli bir vektor olusturuldu
	for (int i = 0; i < n; i++) {
		if (dizi[i] < 1 || dizi[i] > 5) {
			cerr << "Hatali giris: dizi elemanlari 1 ile 5 arasinda olmalidir!" << endl;
			return -1; // hata durumunda -1 return ediliyor
		}
		cntIndex[dizi[i]]++; // dizi elemanlarinin sayilarini tutan vektörde indexin deðeri arttiriliyor
	}

	int max = 0; // en fazla tekrar eden id sayisini tutan deðiþken
	int minIdMaxCnt = INT_MAX; // en fazla tekrar eden idyi tutan deðiþken
	for (int id = 1; id <= 5; id++) { // id numaralarý 1-5 arasi oldugu icin 1-5 arasinda dönülüyor
		int count = cntIndex[id]; 
		if (count > max) { // en fazla tekrar eden id bulunuyor
			max = count;
			minIdMaxCnt = id;
		}
		else if (count == max && id < minIdMaxCnt) { // en fazla tekrar eden idler arasindan en kucuk id bulunuyor
			minIdMaxCnt = id; 
		}
	}
	return minIdMaxCnt; 
}
int main()
{
	int n;
	cout << "dizi boyutunu giriniz: ";
	cin >> n;
	cout << "dizi elemanlarini giriniz: ";
	vector <int> dizi(n);
	for (int i = 0; i < n; i++) {
		cin >> dizi[i];
	}
	int result = UniqueWolf(n, dizi);
	if(result != -1) {
		cout << result << endl;
	}
	return 0;
}