#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct Person {
	int age;
	string name;
	int join;
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Person> v(n);
	
	for (int i = 0; i < n; i++) {
		//scanf("%d", &age);
		//scanf("%s", &name);
		//v[i].age = age;
		//v[i].name = name;
		//v[i].join = i;
		cin >> v[i].age >> v[i].name;
		v[i].join = i;
	}
	sort(v.begin(), v.end(), [](Person a, Person b) {
		return (a.age < b.age) || (a.age == b.age && a.join < b.join);
	});
	for (int i = 0; i < n; i++) {
		//printf("%d %s\n",v[i].age, v[i].name);
		cout << v[i].age << " " << v[i].name << "\n";
	}
	return 0;
}
