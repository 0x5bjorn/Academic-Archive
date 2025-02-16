#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "HashSetStr"

using namespace std;

size_t bad(const string& s) {
	return 42;
}

size_t goodHF(const string& s) {
	size_t r = 7;
	for (auto c: s) {
		r = r * 31 + c;
	}
	
	return r;
}

void print() {
	for (size_t i = 0; i < names.bucket_count(); ++i) {
		cout << setw(4) << i << ": ";
		for (auto it = names.begin(); it != names.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	typedef size_t (*HF)(const string&);		//address of func
	
	HashSetStr names(badHF);
	
	HashSetStr::HashFunc hf = names.hashFunction();
	string line;
	while (getline(cin, line)) {
		istringstream sinp(line);
		
		string cmd; sinp >> cmd;
		if (cmd == "#") {
			cout << "number of buckets: " << names.bucketCount() << endl;
			
			names.print();
			
		} else if (cmd == "+") {
			string name; sinp >> name;
			cout << "hash: " << hf(name) << endl;
			cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
			cout << (names.insert(name).second ? "OK": "already exist") << endl;
		} else if (cmd == "-") {
			string name; sinp >> name;
			cout << "hash: " << hf(name) << endl;
			cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
			cout << (names.erase(name) != 0 ? "OK": "does not exist") << endl;
		} else if (cmd == "?") {
			string name; sinp >> name;
			cout << "hash: " << hf(name) << endl;
			cout << "hash % size: " << hf(name) % names.bucketCount() << endl;
			cout << (it != names.end() ? "Found": "Not found") << endl;
		}
	}	
	
	return 0;
}