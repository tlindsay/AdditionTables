/**********************************************************************
 *     _       _     _ _ _   _           _____     _     _            *
 *    / \   __| | __| (_) |_(_) ___  _ _|_   _|_ _| |__ | | ___  ___  *
 *   / _ \ / _` |/ _` | | __| |/ _ \| '_ \| |/ _` | '_ \| |/ _ \/ __| *
 *  / ___ \ (_| | (_| | | |_| | (_) | | | | | (_| | |_) | |  __/\__ \ *
 * /_/   \_\__,_|\__,_|_|\__|_|\___/|_| |_|_|\__,_|_.__/|_|\___||___/ *
 *                                                                    *
 **********************************************************************
 * @authors: Patrick Lindsay										  *
 *			 Amy Brown												  *
 *			 Seth Putman											  *
 *			 Brianna Hillman										  *
 **********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void printTable(vector< vector<int> >);

int main(int argc, char const *argv[]) {
	vector< vector<int> > table {{2,3},
								 {4,5}};
	printTable(table);
	return 0;
}

void printTable(vector< vector<int> > table) {
	char label = 'a';
	cout<<"+ | ";
	for(vector< vector<int> >::size_type i = 0; i < table.size(); ++i) {
		for(vector<int>::size_type j = 0; j < table[i].size(); ++j) {
			if(i == 0){
				cout<<label<<" ";
				label++;
			} else {
				cout<<table[i-1][j]<<" ";
			}
		}
		if(i == 0)
			cout<<endl<<"-------------------------------------";
		cout<<endl<<label++<<" | ";
	}
}