#include<string>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
struct node {
	string a;
	int birth;
};
set<node>s1, s2,s3;
bool operator<(node a,node b) {
	return a.birth < b.birth;
}
int main() {
	int n;
	cin >> n;
	string guest = "";
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		node temp;
		temp.birth = stoi(t.substr(6, 8));
		temp.a = t;
		s1.insert(temp);
	}
	int m,count=0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		node temp;
		temp.birth = stoi(t.substr(6, 8));
		temp.a = t;
		auto it = s1.find(temp);
		if (it != s1.end()) {
			s2.insert(temp);
			count++;
		}
		s3.insert(temp);
	}
	if (count != 0) {
		cout << count << endl;
		auto it = s2.begin();
		cout << (*it).a << endl;
	}
	else {
		cout << count << endl;
		cout << (*s3.begin()).a << endl;
	}
	return 0;
}