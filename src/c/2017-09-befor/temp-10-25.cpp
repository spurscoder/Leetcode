#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {

	}

	int countDigitOne(int n) {
		int ones = 0;
		for (long long m = 1; m <= n; m *= 10)
			ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n%m + 1);
		return ones;
	}
};

int main() {
	Solution A = Solution();



	return 0;
}






//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//struct Item {
//	double latitude;
//	double longitude;
//	double height;
//	double T;
//	double v;
//};
//
//istream &operator >> (istream &strm, Item &e) {
//	return strm >> e.latitude >> e.longitude >> e.height >> e.T >> e.v;
//}
//
//ostream &operator << (ostream &strm, Item &e) {
//#define SP << setw(12) << setprecision(9) <<
//	return strm SP e.latitude SP e.longitude SP e.height SP e.T SP e.v;
//}
//
//void readData(string filename, vector<Item> &V);
//
//int main() {
//	vector <Item> V;
//	readData("data.txt", V);
//
//	cout << "All data:\n";
//	for (Item e : V) cout << e << '\n';
//
//	cout << "\nFirst column onlu:\n";
//	for (Item e : V) cout << e.latitude << '\n';
//}
//
//void readData(string filename, vector<Item>& V) {
//	Item thing;
//	fstream in(filename);
//	while (in >> thing) V.push_back(thing);
//	in.close();
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Pokemon {
//public:
//	string name;
//	string type1;
//	string type2;
//	int HP;
//	int Atk;
//	int Def;
//	int Speed;
//};
//
//struct attack{
//	string name;
//	int power;
//	int pp;
//	int accuracy;
//	string type;
//} att1, att2, att3, att4;
//
//struct attack_ember :public attack {
//	attack_ember() // constructor
//	{
//		name = "Ember";
//		power = 40;
//		pp = 30;
//		accuracy = 95;
//		type = "Fire";
//	}
//} ember;
//
//struct attack_hydropump : public attack {
//	attack_hydropump() // constructor
//	{
//		name = "HydroPump";
//		power = 120;
//		pp = 5;
//		accuracy = 75;
//		type = "water";
//	}
//} hydropump;
//
//struct attack_tbolt :public attack {
//	attack_tbolt() {
//		name = "Thunderbolt";
//		power = 100;
//		pp = 10;
//		accuracy = 100;
//		type = "Electric";
//	}
//} tbolt;
//
//struct attack_electroball : public attack {
//	attack_electroball() {
//		name = "Electro Ball";
//		power = 150;
//		pp = 10;
//		accuracy = 100;
//		type = "electric";
//	}
//} electroball;
//
//struct attack_fireblast : public attack {
//	attack_fireblast() {
//		name = "Fire Blast";
//		power = 150;
//		pp = 5;
//		accuracy = 80;
//		type = "Fire";
//	}
//} fireblast;
//
//// Pokemon!
//Pokemon Shedninja{ "Shedninja", "Ghost", "Grass", 1, 0, 0, 100 };
//Pokemon Golem{ "Golem", "Rock", "Ground", 126, 102, 200, 78 };
//
//void StatPg() {
//	cout << "###################################################\n";
//	cout << Shedninja.name << ": " << Shedninja.type1 << "/" << Shedninja.type2 << " type" << "\t" << Golem.name << ": " << Golem.type1 << "/"
//		<< Golem.type2 << " type" << endl;
//
//	cout << "\t" << Shedninja.HP << " HP" << "\t \t \t \t" << Golem.HP << " HP" << endl;
//	cout << "\t" << Shedninja.Atk << " ATK" << "\t \t \t \t" << Golem.Atk << " ATK" << endl;
//	cout << "\t" << Shedninja.Def << " DEF" << "\t \t \t \t" << Golem.Def << " DEF" << endl;
//	cout << "\t" << Shedninja.Speed << " Speed" << "\t \t \t \t" << Golem.Speed << " Speed" << endl;
//	cout << endl;
//	cout << att1.name << " | " << att1.pp << " PP" << endl;
//	cout << att2.name << " | " << att2.pp << " PP" << endl;
//	cout << att3.name << " | " << att3.pp << " PP" << endl;
//	cout << att4.name << " | " << att4.pp << " PP" << endl;
//	cout << "###################################################\n";
//}
//
//int main() {
//	att1 = ember;
//	att2 = hydropump;
//	att3 = tbolt;
//	att4 = electroball;
//
//	StatPg();
//
//	att4 = fireblast;
//
//	StatPg();
//}

