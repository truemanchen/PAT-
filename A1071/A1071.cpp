#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string, int>mp;
string change(string a){
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] -= 'A' - 'a';
		}
	}
	return a;
}
int main() {
	string a;
	getline(cin, a);
	a = change(a);
	string temp;
	int i = 0, max = 0;
	string maxString = "";
	while(i<a.size()){
		while (!isdigit(a[i]) && !isalpha(a[i])&&i<a.size()) {
			i++;
		}
		while (isdigit(a[i]) || isalpha(a[i])&&i<a.size()) {
			temp.push_back(a[i]);
			i++;
		}
		if (!temp.empty()) {
			if (mp.count(temp) == 0)
				mp[temp] = 1;
			else
			{
				mp[temp]++;
			}
			if (mp[temp] != max) {
				if (mp[temp] > max) {
					max = mp[temp];
					maxString = temp;
				}
			}
			else if (temp < maxString) {
				max = mp[temp];
				maxString = temp;
			}
		}
		temp.clear();
	}
	cout << maxString << " " << max;
    return 0;
}