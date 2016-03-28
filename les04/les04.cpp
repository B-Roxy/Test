#include <iostream>
#include <fstream>

using namespace std;

void input(int *A, int n)
{
	for (int i = 0; i < n; i++) 
		A[i] = 1 + rand() % 50;
		//A[i] = INT16_MIN/2 + rand() % (INT16_MAX-1);
}
void output(int *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void txtFile(int *A, int n)
{
	ofstream os;
	os.open("text.txt");
	os << n << endl;
	for (int i = 0; i < n; i++)
		os << A[i] << " ";

	os.close();
	delete[] A;

	ifstream is;
	is.open("text.txt");
	is >> n;
	A = new int[n];
	for (int i = 0; i < n; i++)
		is >> A[i];
	is.close();
	for (int i = 0; i < n; i++)
		cout << A[i] << "\t";
}
void binFIleSave(int *A, int n)
{
	ofstream os("f39.bin", ios::binary);
/*
	os.write((char*)&n, sizeof(int));*/
	os.write((char*)A, n*sizeof(int));

	os.close();
}
void binFIleSaveInEnd(int *A, int n)
{
	ofstream os;
	os.open("dump.bin", ios::binary | ios::_Nocreate);
	os.seekp(0, ios::end);
	//os.write((char*)&n, sizeof(int));
	os.write((char*)A, n*sizeof(int));

	os.close();
}
void binFIleLoad(int *A, int n)
{
	ifstream is("dump.bin", ios::binary);

	is.read((char*)&n, sizeof(int));
	is.read((char*)A, n*sizeof(int));

	is.close();
}

/*** file 37, 39, 42, 44, 47, 71*/
/**
*	File37. Дан файл целых чисел. Удвоить его размер, записав в конец файла все его исходные элементы 
*	(в обратном порядке). 
*/
void file37(int n) {
	fstream fbnr;
	long pos;
	int numb;

	fbnr.open("dump1.bin", ios::binary|ios::in|ios::out);
	fbnr.seekg(0, ios::end);
	pos = fbnr.tellg();
	for (int i = 0; i < n; i++) {
		fbnr.seekg(pos - (i + 1) * sizeof(int), ios::beg);
		fbnr.read((char*)&numb, sizeof(int));
		fbnr.seekg(pos + i * sizeof(int), ios::beg);
		fbnr.write((char*)&numb, sizeof(int));
	}
	
	fbnr.seekg(0, ios::beg);
	fbnr.eof();
	while (!fbnr.eof()){
		fbnr.read((char*)&numb, sizeof(int));
		cout << numb << endl;
	}
	fbnr.close();
}

/**
*	File39. Дан файл целых чисел. Продублировать в нем все числа, принадлежащие диапазону 5–10. 
*/
void file39(int n) {
	fstream f39;
	int numb;

	f39.open("f39.bin", ios::binary|ios::in|ios::out);

	for (int i = 0; i < n; i++) {
		f39.read((char*)&numb, sizeof(int));
		if (numb >= 5 && numb <= 10) {
			f39.write((char*)&numb, sizeof(numb));
		}
	}
	/*cout << "\nf39\n";
	f39.seekg(0, ios::beg);
	while (!f39.eof()) {
		f39.read((char*)&numb, sizeof(int));
		cout << numb << "\t";
	}*/
	f39.close();
}

/**
*	File42. Даны два файла произвольного типа. Поменять местами их содержимое. 
*/
void file42() {
	fstream f1, f2, f3;
	char c;

	f1.open("dump1.bin", ios::binary | ios::out);
	f2.open("temp.bin", ios::binary | ios::in);

	while (!f1.eof()) {
		f1.get()
	}

}

/**
*	File44. Даны три файла одного и того же типа, но разного размера. 
*	Заменить содержимое самого длинного файла на содержимое самого короткого. 
*/

/**
*	File47.Даны два файла одного и того же типа.
*	Добавить к первому файлу содержимое второго файла, а ко второму файлу — содержимое первого.
*/

/**
*	File71. Дан строковый файл, содержащий даты в формате, описанном в задании File67. 
*	Найти строку, содержащую самую раннюю весеннюю дату. Если даты с требуемым временем года в файле отсутствуют, то вывести пустую строку. 
*/

void main() {
	int n = 10;
	int *A = new int[n];
	/*input(A, n);
	output(A, n);
	binFIleSave(A, n);*/
	file37(n);
	file39(n);
	//binFIleSaveInEnd(A, n);
	
	delete[] A;
}
// EoF