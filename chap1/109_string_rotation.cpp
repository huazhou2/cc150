#include <iostream>
#include <string>
using namespace std;

//if provided this function
bool is_Sub(const string& orig, const string& sub);
bool is_Rotate(const string& orig, const string& rot);

int main() {
	//test cases;
	string orig("erbottlewat"), rot("waterbottle");
	cout<<rot<<" "<<(is_Rotate(orig,rot)?"is ":"is not ")<<"rotation of "<<orig<<endl;
	orig="erbottlewathua"; 
	rot="waterbottle";
	cout<<rot<<" "<<(is_Rotate(orig,rot)?"is ":"is not ")<<"rotation of "<<orig<<endl;
	}

bool is_Sub(const string& orig, const string& sub) {
	if (sub.size()>orig.size()) return false;
	for (int i=0;i<=orig.size()-sub.size();i++) {
		int j=0;
		for (;j<sub.size();j++) {
			if (orig[i+j]!=sub[j])
				break;}
		if (j==sub.size()) return true;//if success in full run
	}
	return false;
	}
bool is_Rotate(const string& orig, const string& rot) {
	string concat=orig+orig;
	return is_Sub(concat,rot);
}
	
	

