#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int age;
	Student(const string& aName, int anAge)
	: name(aName), age(anAge)
	{}
};

int main()
{
	vector<Student> group;
	
	group.emplace_back("A", 31);
	group.emplace_back("B", 21);
	group.emplace_back("C", 17);
	group.emplace_back("D", 31);
	
	sort(group.begin(), group.end(),
	            [](Student s1, Student s2)
				{
					return s1.age < s2.age;
				});
	
	for (const auto& s: group)
	{
		cout << s.name << ' ' << s.age << endl;
	}
	
	return 0;
}