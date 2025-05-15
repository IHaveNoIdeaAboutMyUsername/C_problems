#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << -1;
			break;
		case 2:
			cout << 1;
			break;
		case 3:
			cout << 7;
			break;
		case 4:
			cout << 4;
			break;
		case 5:
			cout << 2;
			break;
		case 6:
			cout << 6;
			break;
		case 7:
			cout << 8;
			break;
		}
		if (n > 7) {
			int n7 = n % 7;
			switch (n7) {
			case 1:
				cout << 10;
				for (int i = 1; i < n / 7; i++) cout << 8;
				break;
			case 2:
				cout << 18;
				for (int i = 1; i < n / 7; i++) cout << 8;
				break;
			case 3:	
				if (n == 10)cout << 22;
				else {
					cout << 200;
					for (int i = 1; i <= n / 7 - 2; i++)cout << 8;
				}
				break;
			case 4:
				cout << 20;
				for (int i = 1; i < n / 7; i++) cout << 8;
				break;
			case 5:
				cout << 28;
				for (int i = 1; i < n / 7; i++) cout << 8;
				break;
			case 6:
				cout << 68;
				for (int i = 1; i < n / 7; i++) cout << 8;
				break;
			case 0:
				cout << 88;
				for (int i = 2; i < n / 7; i++) cout << 8;
				break;
			}
		}
		cout << endl;
	}
}