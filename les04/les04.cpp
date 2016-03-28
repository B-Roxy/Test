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
void file37() {
	fstream fbnr;
	long pos;
	int numb, count;

	cout << "\nf37\n";
	fbnr.open("dump1.bin", ios::binary | ios::in | ios::out | ios::_Nocreate);
	if (!fbnr.is_open()) {
		cout << "File does not exist" << endl;
		return;
	}
	fbnr.seekg(0, ios::end);
	pos = fbnr.tellg();
	count = pos / sizeof(int);
	for (int i = 1; i <= count; i++) {
		fbnr.seekg(pos - i * sizeof(int), ios::beg);
		fbnr.read((char*)&numb, sizeof(int));
		fbnr.seekg(pos + i * sizeof(int), ios::beg);
		fbnr.write((char*)&numb, sizeof(int));
	}
	
	fbnr.seekg(0, ios::beg);
	while (fbnr.read((char*)&numb, sizeof(int)) && !fbnr.eof())
		cout << numb << endl;
	fbnr.close();
}

/**
*	File39. Дан файл целых чисел. Продублировать в нем все числа, принадлежащие диапазону 5–10. 
*/
void file39() {
	fstream f39;
	int numb;

	cout << "\nf39\n";

	f39.open("f39.bin", ios::binary | ios::in | ios::out | ios::_Nocreate);
	if (!f39.is_open()) {
		cout << "File does not exist" << endl;
		return;
	}
	while (f39.read((char*)&numb, sizeof(int)) && !f39.eof()) 
		if (numb >= 5 && numb <= 10) 
			f39.write((char*)&numb, sizeof(numb));
	f39.seekg(0, ios::beg);
	while (f39.read((char*)&numb, sizeof(int)) && !f39.eof()) 
		cout << numb << "\t";
	f39.close();
}

/**
*	File42. Даны два файла произвольного типа. Поменять местами их содержимое. 
*/
void file42() {
	ifstream f1;
	ofstream f2;
	const short buf = 10;
	char c[buf];
	char n_f1[] = "dump1.bin", n_f2[] = "f39.bin", n_t[] = "temp.bin";

	f1.open(n_f1, ios::binary);
	f2.open(n_t, ios::binary | ios::trunc);

	while (f1.get(c, buf) && !f1.eof()) {
		f2 << c;
	}
	f1.close();
	f2.close();
	rename(n_f2, n_f1);
	rename(n_t, n_f1);
}

/**
*	File44. Даны три файла одного и того же типа, но разного размера. 
*	Заменить содержимое самого длинного файла на содержимое самого короткого. 
*/
void file44() {
	fstream f1, f2, f3;
	
	char nf1[] = "dump1.bin", nf2[] = "dump2.bin", nf3[] = "f39.bin";
/*
	f1.open(nf1, ios::binary | ios::in | ios::out | ios::_Nocreate);
	f2.open(nf1, ios::binary | ios::in | ios::out | ios::_Nocreate);
	f3.open(nf1, ios::binary | ios::in | ios::out | ios::_Nocreate);
	*/

}

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
//	file37();
//	file39();
	file42();
	//binFIleSaveInEnd(A, n);
	
	delete[] A;
}
// EoF