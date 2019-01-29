#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
 
double entropy(string input) {
	map<char , int> fq ;
   	for ( char c : input )
     	fq[c]++ ;
   	double info = 0 ;
   	for (pair<char , double> p : fq) {
      		double f = p.second/input.length();
      		info = (f*log2(f)) ;
   }
   return info;
}
void display(fstream &file) {
		vector<string> evector;
	vector<string> s;
	while (file){
		string input;
		getline(file, input);
		s.push_back(input);
	}
	cout << "Alignment profile:" << endl << endl;
	vector<int> a, t, c, g, gap;
	for(int i = 0; i < s[i].size(); i++) {
		int count = 0;
		string ev;
		for(int j = 0; j < s.size(); j++) {
			ev += s[j][i];
			if(s[j][i] == 'A') {
				count++;
			}
		}
		a.push_back(count);
		evector.push_back(ev);
	}
	for(int i = 0; i < s[i].size(); i++) {
		int count = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j][i] == 'T') {
				count++;
			}
		}
		t.push_back(count);
	}
	for(int i = 0; i < s[i].size(); i++) {
		int count = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j][i] == 'G') {
				count++;
			}
		}
		g.push_back(count);
	}
	for(int i = 0; i < s[i].size(); i++) {
		int count = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j][i] == 'C') {
				count++;
			}
		}
		c.push_back(count);
	}
	for(int i = 0; i < s[i].size(); i++) {
		int count = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j][i] == '-') {
				count++;
			}
		}
		gap.push_back(count);
	}
	cout << "A ";
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "T ";
	for(int i = 0; i < t.size(); i++){
		cout << t[i] << " ";
	}
	cout << endl;
cout << "G ";
	for(int i = 0; i < g.size(); i++){
		cout << g[i] << " ";
	}
	cout << endl;
cout << "C ";
	for(int i = 0; i < c.size(); i++){
		cout << c[i] << " ";
	}
	cout << endl;
cout << "- ";
	for(int i = 0; i < gap.size(); i++){
		cout << gap[i] << " ";
	}
	cout << endl;
	float eScore = 0;
	for(int i = 0; i < evector.size(); i++){
		eScore += entropy(evector[i]);
	}
	cout << endl << "Entropy score is: " << (eScore + evector[0].length()) << endl;



} 
int main() {
	fstream file1, file2, file3;
	file1.open("testdata1.txt");
	display(file1);
	file1.close();
	file2.open("testdata2.txt");
	display(file2);
	file2.close();
	file3.open("testdata3.txt");
	display(file3);
	file3.close();
	return 0;
}