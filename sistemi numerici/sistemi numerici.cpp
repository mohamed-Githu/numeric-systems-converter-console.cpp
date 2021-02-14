#include <iostream>
#include <string>

using namespace std;

//Da binario a decimale
long long int bindec(long long int x) {
	long long int a, b;
	long long int y = 1, sum = 0;
	for (x; x > 0; x /= 10) {
		a = x % 10;
		b = a * y;
		sum += b;
		y *= 2;
	}
	return sum;
}
//Da binario a ottale
long long int binott(long long int p) {
	long long int sum = 0, x = 1, a, b, sum2 = 0, y = 1;
	for (p; p > 0; p /= 10) {
		a = p % 10;
		b = a * x;
		sum += b;
		x *= 2;
		if (x > 4 || p / 10 == 0) {
			sum2 = (sum * y) + sum2;
			sum = 0;
			y *= 10;
			x = 1;
		}
	}
	return sum2;
}
//Da binario a esadecimale
string binesa(long long int p) {
	long long int sum = 0, x = 1, a, b, count = 0, arr[24];
	long long int hex2[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	char hex[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string sum2;
	for (p; p > 0; p /= 10) {
		a = p % 10;
		b = a * x;
		sum += b;
		x *= 2;
		if (x > 8 || p / 10 == 0) {
			arr[count] = sum;
			sum = 0;
			count++;
			x = 1;
		}
	}
	for (count = count - 1; count >= 0; count--) {
		for (int d = 0; d < 16; d++) {
			if (arr[count] == hex2[d])
				sum2 += hex[d];
		}
	}
	return sum2;
}

//Da decimale a binario
long long int decbin(long long int p) {
	long long int a, sum2 = 0, y = 1;
	for (p; p > 0; p /= 2) {
		a = p % 2;
		sum2 = sum2 + (a * y);
		y *= 10;
	}
	return sum2;
}
//Da decimale a ottale
long long int decott(long long int p) {
	long long int sum = 0, a, y = 1;
	for (long long int x = 0; p > 0; x++) {
		a = p % 8;
		p /= 8;
		sum = sum + (a * y);
		y *= 10;
	}
	return sum;
}

//Da ottale a decimale
long long int ottdec(long long int p) {
	long long int sum = 0, x = 1, a, b;
	for (p; p > 0; p /= 10) {
		a = p % 10;
		b = a * x;
		x *= 8;
		sum += b;
	}
	return sum;
}

//Da esadecimale a decimale
long long int esadec(string p) {
	long long int sum = 0, a, y = 1;
	char hex[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int hex2[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	for (long long int x = p.length() - 1; x >= 0; x--) {
		for (int z = 0; z < 16; z++) {
			if (hex[z] == p[x]) {
				sum = sum + (hex2[z] * y);
			}
		}
		y *= 16;
	}
	return sum;
}

void str() {
	cout << "\n-------------------------------------------------------------\n\n";
}
void str2() {
	str();
	cout << "Do you want to try again? \n";
	cout << "If yes please type yes : ";
}
int main(int argc, char** argv) {

	long long int num;
	string tipo, answer = "yes";
	str();
	while (answer == "yes") {
		cout << "\nbinary -------- octal -------- decimal -------- hex \n";
		str();
		cout << "Convert from : ";
		cin >> tipo;
		str();
		if (tipo == "binary") {
			cout << "Binary number = ";
			cin >> num;
			long long int k = num;
			while (k > 0) {
				if (k % 10 > 1) {
					cout << "ERROR....Enter a valid number!!";
					cout << "Binary number = ";
					cin >> k;
					num = k;
				}
				else
					k /= 10;
			}
			str();
			cout << "Decimale = " << bindec(num) << endl;
			cout << "Octal = " << binott(num) << endl;
			cout << "Hex = ";
			cout << binesa(num);
			str2();
			cin >> answer;
		}
		else if (tipo == "octal") {
			cout << "Octal number = ";
			cin >> num;
			long long int k = num;
			while (k > 0) {
				if (k % 10 > 7) {
					cout << "ERROR....Enter a valid number!!";
					cout << "Octal number = ";
					cin >> k;
					num = k;
				}
				else
					k /= 10;
			}
			str();
			long long int bin = ottdec(num);
			cout << "Binary = " << decbin(bin) << endl;
			cout << "Decimal = " << bin << endl;
			cout << "Hex = ";
			cout << binesa(decbin(bin));
			str2();
			cin >> answer;
		}
		else if (tipo == "decimal") {
			long long int num;
			cout << "Decimal number = ";
			cin >> num;
			str();
			cout << "Binary = " << decbin(num) << endl;
			cout << "Octal = " << decott(num) << endl;
			cout << "Hex = ";
			cout << binesa(decbin(num));
			str2();
			cin >> answer;
		}
		else if (tipo == "hex") {
			string num;
			cout << "Hex number = ";
			cin >> num;
			str();
			cout << "Binary = " << decbin(esadec(num)) << endl;
			cout << "Octal = " << decott(esadec(num)) << endl;
			cout << "Decimal = " << esadec(num);
			str2();
			cin >> answer;
		}
		else
			cout << "ENTER A VALID WORD!!!!\n\n";
		//	    system("CLS");
	}
	return 0;
}