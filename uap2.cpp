#include <iostream>
using namespace std;

char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8','9'}};
int baris;
int kolom;
char token = 'X';
bool tie = false;
string kata1 = "";
string kata2 = "";

void functionOne()
{	
	cout << "    |     |   \n";
	cout << "  "<< arr[0][0] << " |  " << arr[0][1] << "  | " << arr[0][2] << "  \n";
	cout << "____|_____|____\n";
	cout << "    |     |   \n";
	cout << "  "<< arr[1][0] << " |  " << arr[1][1] << "  | " << arr[1][2] << "  \n";
	cout << "____|_____|____\n";
	cout << "    |     |   \n";
	cout << "  "<< arr[2][0] <<" |  " << arr[2][1] << "  | " << arr[2][2] << "  \n";
	cout << "    |     |   \n"; 
	cout << "\n";
}

void functionTwo()
{
	int digit;
	
	if(token == 'X')
	{
		cout << kata1 << " silakan masukkan digit";
		cin >> digit;
	}
	if(token == 'O')
	{
		cout << kata2 << " silakan masukkan digit";
		cin >> digit;
	}
	if(digit == 1)
	{
		baris = 0;
		kolom = 0;
	}
	if(digit == 2)
	{
		baris = 0;
		kolom = 1;
	}
	if(digit == 3)
	{
		baris = 0;
		kolom = 2;
	}
	if(digit == 4)
	{
		baris = 1;
		kolom = 0;
	}
	if(digit == 5)
	{
		baris = 1;
		kolom = 1;
	}
	if(digit == 6)
	{
		baris = 1;
		kolom = 2;
	}
	if(digit == 7)
	{
		baris = 2;
		kolom = 0;
	}
	if(digit == 8)
	{
		baris = 2;
		kolom = 1;
	}
	if(digit == 9)
	{
		baris = 2;
		kolom = 2;
	}
	else if(digit < 1 || digit > 9) {
		cout << "Tidak ada ruang kosong!" << endl;
	}
	
	if(token == 'X' && arr[baris][kolom] != 'X' && arr[baris][kolom] !='O')
	{
		arr[baris][kolom] = 'X';
		token = 'O';
	}
	else if(token == 'O' && arr[baris][kolom] != 'X' && arr[baris][kolom] != 'O')
	{
		arr[baris][kolom] = 'O';
		token = 'X';
	}
	else {
		cout << " Ini hasil imbang " << endl;
		functionTwo();
	}
	functionOne();
}
	bool functionThree()
	{
		for(int i = 0; i < 3; i++)
		{
			if(arr[i][0] == arr[i][1] && arr[i][2] || arr[0][i]== arr[1][i] && arr[0][i] == arr[2][i])
			return true;
		}
		if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] || arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
		{
			return true;
		}
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(arr[i][j] != 'X' && arr[i][j] != 'O')
				{
					return false;
				}
			}
		}
		tie = true;
		return false;
		}
		
		int main()
		{
			cout << "Masukkan nama pemain pertama :  \n";
			getline(cin, kata1);
			cout << "Masukkan nama pemain kedua :  \n";
			getline(cin, kata2);
			cout << kata1 << " adalah pemain 1 jadi dia akan bermain terlebih dahulu \n";
			cout << kata2 << " adalah pemain 2 jadi dia akan bermain kedua \n";
			
			while(!functionThree())
			{
				functionOne();
				functionTwo();
				functionThree();
			}
			
			if(token == 'X' && tie == false)
			{
				cout << kata2 << " adalah PEMENANGNYA !!! <3" << endl;
			}
			else if(token == 'O' && tie == false)
			{
				cout << kata1 << " adalah PEMENANGNYA !!! <3" << endl; 
			}
		}
