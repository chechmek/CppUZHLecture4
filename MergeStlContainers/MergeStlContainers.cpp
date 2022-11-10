#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>

using namespace std;

template<typename con1, typename con2>
con1& merge(const con1& container1, const con2& container2) {
	auto itbeg1 = container1.begin();
	auto itend1 = container1.end();
	auto itbeg2 = container2.begin();
	auto itend2 = container2.end();

	con1 new_con;

	auto new_con_it = new_con.begin();
	while (new_con_it != itend1) {
		new_con_it = itbeg1;
		++new_con_it;
		++itbeg1;
	}
	while (new_con_it != itend2) {
		new_con_it = itbeg2;
		++new_con_it;
		++itbeg2;
	}
	return new_con;
}

int main()
{
	vector<int> v1 = { 1, 2 ,3 };
	vector<int> v2 = { 4, 5, 6 };
	
	vector<int> v3 = merge<vector<int>, vector<int>>(v1, v2);

	for (auto it : v3) {
		cout << it << endl;
	}
	list<int> l;
	
	
	
}


