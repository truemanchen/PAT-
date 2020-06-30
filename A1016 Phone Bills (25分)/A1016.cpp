#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1001;
struct record
{
	char name[25];
	int month, day, hour, minute;
	bool flag;
}r[N];
int timeToCost[24] = {},isZero=1;
vector<record> s;
int cmp(record a,record b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0)return s < 0;
	else if (a.flag != b.flag)
	{
		return a.flag > b.flag;
	}
	else if (a.month != b.month) {
		return a.month < b.month;
	}
	else if (a.day != b.day)return a.day < b.day;
	else if (a.hour != b.hour)return a.hour < b.hour;
	else if (a.minute != b.minute)return a.minute < b.minute;
}
int caculateTotalCost(record a,record b) {
	printf("%02d:%02d:%02d ",  a.day, a.hour, a.minute);
	printf("%02d:%02d:%02d ",  b.day, b.hour, b.minute);
	int minDis[24] = {}, total = 0,toMin=0;
	while (a.day < b.day || a.hour < b.hour || a.minute < b.minute) {
		a.minute++;
		minDis[a.hour] ++;
		if (a.minute % 60 == 0&&a.minute!=0) {
			a.minute = 0;
			a.hour++;
		}
		if (a.hour % 24 == 0&&a.hour!=0) {
			a.hour = 0;
			a.day++;
		}
	}
	for (int i = 0; i < 24; i++) {
		total += minDis[i] * timeToCost[i];
		toMin += minDis[i];
	}
	cout << toMin << " $" <<fixed<<setprecision(2)<< total/100.0<<endl;
	return total;
}
int cmpDate(record a, record b) {
	if (a.day != b.day)return a.day>b.day;
	else if (a.hour!=b.hour)return a.hour>b.hour;
	else if (a.minute!=b.minute)return a.minute>b.minute;
	return 0;
}
int main() {
	string a, b;
	char c[10];
	a.resize(1);
	scanf("%s%s", &a[0],c);
	b = "a";
	cout<<a.compare(b);
	for (int i = 0; i < 24; i++) {
		cin >> timeToCost[i];
	}
	int recordNum; cin >> recordNum;
	for (int i = 0; i < recordNum; i++) {
		scanf("%s", r[i].name);
		scanf("%d:%d:%d:%d", &r[i].month, &r[i].day, &r[i].hour, &r[i].minute);
		string temp;
		temp.resize(7);
		scanf("%s", &temp[0]);
		if (temp.compare("on-line") == 0)
			r[i].flag = true;
		else
		{
			r[i].flag = false;
		}
	}
	sort(r, r + recordNum, cmp);
	string curName = r[0].name;
	int all = 0,first=1,flag=0,allMin=0;
	for (int i = 0; i < recordNum; i++) {
		if (r[i].name == curName) {
			if (r[i].flag) {
				s.push_back(r[i]);
			}
			else
			{
				record maxRecord;
				record* t=&maxRecord;
				maxRecord.day = -1;
				maxRecord.flag = -1;
				maxRecord.hour = -1;
				maxRecord.minute = -1;
				maxRecord.month =-1;
				strcpy(maxRecord.name, r[i].name);
				for (auto it = s.begin(); it != s.end(); it++) {
					if (r[i].hour < 24 && r[i].minute < 60) {
						if (cmpDate(r[i], *it) && ((*it).flag) && cmpDate(*it, maxRecord)) {
							if (first) {
								printf("%s %02d\n", r[i].name, r[i].month);
								first = 0;
							}
							maxRecord.day = (*it).day;
							maxRecord.flag = (*it).flag;
							maxRecord.hour = (*it).hour;
							maxRecord.minute = (*it).minute;
							maxRecord.month = (*it).month;
							strcpy(maxRecord.name, (*it).name);
							flag = 1;
							(*it).flag = false;
						}
					}
				}
				if (flag == 1) {
					isZero = 0;
					all += caculateTotalCost(maxRecord, r[i]);
					flag = 0;
				}
			}
		}
		else
		{
			if(isZero==0)
			cout << "Total amount: $" << fixed << setprecision(2) << all / 100.0 << endl;
			first = 1;
			vector<record> s1;
			s1.swap(s);
			curName = r[i].name;
			if (r[i].flag) {
				s.push_back(r[i]);
			}
			all = 0;
			isZero = 1;
		}
	}
	if(isZero==0)
	cout << "Total amount: $" <<fixed<<setprecision(2)<< all / 100.0 << endl;
	return 0;
}