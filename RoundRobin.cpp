#include <stdio.h>
#include <iostream>
#include <fstream>
#include <String>
#include <vector>
#include <sstream>

using namespace std;
int main(void) {
	
	int arrival[1001];
	int burst[1001];
	
	int quantum = 5;
	
	ifstream file("job.txt");
	
	string str;
	
	while (getline(file, str)) {
		stringstream ss(str);
		vector<string> result;
		
		while( ss.good() ) {
			string substr;
			getline( ss, substr, ',' );
			result.push_back( substr );
		}
	
		int jobid = atoi(result.at(0).c_str());
		int rt = atoi(result.at(1).c_str());
		int bt = atoi(result.at(2).c_str());
		
		arrival[jobid] = rt;
		burst[jobid] = bt;
		
	}
	
	int cpuTime = 0;
	int incomplete = 1001;
	
	while (incomplete > 0) {
		for (int i = 0; i < 1001; i++) {
			if (arrival[i] <= cpuTime) {
				burst[i] -= quantum;
				cpuTime += quantum;
				cout << "Job " << i << " requested for " << quantum << " miliseconds." << endl;
			}
		}
		for (int i = 0; i < 1001; i++) {
			if (burst[i] == 0) {
				incomplete--;
				cout << "Job " << i << " requested for " << quantum << " miliseconds; completed." << endl;
			}
		}
	}
}
