#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct ForwardCall {
	int source, time, duration, target;
	bool checked;
	
	ForwardCall(int aSource, int aTime, int aDuration, int aTarget)
	: source(aSource), time(aTime), duration(aDuration), target(aTarget)
	{
		checked = false;
	}
};

void callForwarding(map<int, vector<ForwardCall>>& m, int atTime, int extension, int& res) {
	bool b = true;
	
	if (m[extension].empty()) {
		res = extension;
	} else {
		for (int i = 0; i < m[extension].size(); ++i) {
			if (m[extension][i].time <= atTime and atTime <= m[extension][i].duration + m[extension][i].time) {
				if (m[extension][i].checked) {
					b = false;
					res = 9999;
					break;
				}
				res = m[extension][i].target;
				m[extension][i].checked = true;
				b = false;
				callForwarding(m, atTime, m[extension][i].target, res);
				m[extension][i].checked = false;
			}
			if (b) res = extension;
		}
	}
}

int main () {
	
	int t; cin >> t;
	cout << "CALL FORWARDING OUTPUT" << endl;
	for (int i = 1; i <= t; ++i) {
		cout << "SYSTEM " << i << endl;
		
		map<int, vector<ForwardCall>> m;
		int source, time, duration, target;
		while (cin >> source) {
			if (source == 0) break;
			cin >> time >> duration >> target;
			
			m[source].push_back(ForwardCall(source, time, duration, target));
		}
		
		int atTime, extension, res;
		while (cin >> atTime) {
			if (atTime == 9000) break;
			cin >> extension;
			
			callForwarding(m, atTime, extension, res);
			
			cout << "AT " << setfill('0') << setw(4) << atTime << " CALL TO " << setfill('0') << setw(4) << extension << " RINGS " << setfill('0') << setw(4) << res << endl;
		} 
	}
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}