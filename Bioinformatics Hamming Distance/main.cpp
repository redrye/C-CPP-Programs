#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class dData {
private:
	string kmer;
	string DNA;
	string bMatch;
	int Pos;
public:
	int hDistance;
	dData() {
		Pos = 0;
		hDistance = 0;
	}
	void set_kmer(string &v) {
		kmer = v;
	}
	void set_dna(string &d) {
		DNA = d;
		bMatch = d;
	}
	void hamming(string &v, string &bMatch) {
		int d = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != bMatch[i])
				d++;
		}
		hDistance = d;
	}

	void bruteForce() {

		int d = DNA.size();
		for (int i = 0; i < DNA.size(); i++) {

			string combo = ""; // Temp string to hold a combination, allocated as empty.

			for (int j = 0; j < kmer.size(); j++) {
				combo += DNA[i + j];
			}
			/*
			 If hamming distance of combo is less than previous hamming
			 distance, assign bMatch the combo string and d the combo hamming
			 distance and then find the bMatch string position in the DNA sequence.
			 */
			hamming(kmer, combo);
			if (hDistance < d) {
				bMatch = combo;
				d = hDistance;
			}
			Pos = DNA.find(bMatch);
		}
		hDistance = d; // reassign hDistance as hamming distance of best match.
	}
	int get_hDistance() {
		return hDistance;
	}
	void display_stat() {
		string t;
		if(bMatch.size() < 8) {
			t = "\t\t";
		} else {
			t = "\t";
		}
		cout << bMatch << t << Pos << "\t" << hDistance << endl;
	}
};

/** Driver **/
int main() {		/* The main function contains BOTH the driver and the TotalDistance algorithm */
	dData d, total;
	string v[2] {"TAGATCCGAA", "AAAAAA"};
	string f[] = {"Sequences.fa", "Sequences.txt"};
	int t = 0;
	ifstream ifile;
	ifile.open(f[0]);
	cout << "Bestmatch\tPos\tHamming Distance" << endl;
	while (ifile) {
 		string dna;
		getline(ifile, dna);
			if(dna.size() > 3) {
				d.set_kmer(v[0]);
				d.set_dna(dna);
				d.hamming(v[0], dna);
				d.bruteForce();
				d.display_stat();
				t += d.get_hDistance();
			}
	}
	cout << "Total Distance = " << t << endl;
	system("pause");
	system("cls");
	ifile.close();
	t = 0;
	cout << "Bestmatch\tPos\tHamming Distance" << endl;
	ifile.open(f[1]);
		while (ifile) {
			string dna;
			getline(ifile, dna);
			if(dna.size() > 3) {
			d.set_kmer(v[1]);
			d.set_dna(dna);
			d.hamming(v[1], dna);
			d.bruteForce();
			d.display_stat();
			t += d.get_hDistance();
		}
	}
	cout << "Total Distance = " << t << endl;
	system("pause");
	return 0;
}
