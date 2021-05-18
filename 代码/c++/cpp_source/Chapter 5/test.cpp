#include<iostream>
using namespace std;
 
template<class T>
T Max(T x[], int len) {
	T max=x[0];
	for (int i = 1; i < len; i++) {
		if (x[i] > max) {
			max = x[i];
		}
	}
	return max;
}
 
class Time {
public:
	double hours, minutes, seconds;
	Time() { hours = 0; minutes = 0; seconds = 0; }
	void set(double a, double b, double c) {
		hours = a;
		minutes = b;
		seconds = c;
	}
	void print() {
		cout << hours << ":"<<minutes <<":"<< seconds<<endl;
	}
	bool operator>(Time a) {
		if (hours > a.hours) {
			return 1;
		}
		else if(hours<a.hours){
			return 0;
		}
		else {
			if (minutes > a.minutes) {
				return 1;
			}
			else if (minutes < a.minutes) {
				return 0;
			}
			else {
				if (seconds > a.seconds) {
					return 1;
				}
				else{
					return 0;
				}
			}
		}
	}
};
class Date {
public:
	int year, month, day;
	Date() { year = 0; month = 1; day = 1; }
	void set(int a, int b, int c) {
		year = a;
		month = b;
		day = c;
	}
	void print() {
		cout << year <<"/"<< month <<"/"<< day << endl;
	}
	int operator>(Date a) {
		if (year > a.year) {
			return 1;
		}
		else if (year == a.year) {
			if (month > a.month) {
				return 1;
			}
			else if (month == a.month) {
				if (day > a.day) {
					return 1;
				}
				else
					return 0;
			}
			else if (month < a.month) {
				return 0;
			}
		}
		else if (year < a.year) {
			return 0;
		}
	}
};
 
int main() {
	int intArray[100];
	double douArray[100];
	Date dateArray[100];
	Time timeArray[100];
	int oper = -30;
	int end;
	while (oper) {
		cin >> oper;
		if (oper == -1) {
			break;
		}
		if (oper == 1) {
			for (int i = 0; i<100; i++) {
				cin >> intArray[i];
				if (intArray[i] == 0) {
					cout<<Max(intArray, i)<<endl;
					break;
				}
			}
		}
		if (oper == 2) {
			for (int i = 0; i<100; i++) {
				cin >> douArray[i];
				if (douArray[i] == 0) {
					cout<<Max(douArray, i)<<endl;
					break;
				}
			}
		}
		if (oper == 3) {
			for (int i = 0; i<100; i++) {
				cin >> timeArray[i].hours;
				if (timeArray[i].hours==0) {
					Max(timeArray, i).print();
					break;
				}
				cin >> timeArray[i].minutes >> timeArray[i].seconds;
			}
		}
		if (oper == 4) {
			for (int i = 0;i<100; i++) {
				cin >> dateArray[i].year;
				if (dateArray[i].year == 0) {
					Max(dateArray, i).print();
					break;
				}
				cin >> dateArray[i].month >> dateArray[i].day;
			}
		}
	}
	return 0;
}