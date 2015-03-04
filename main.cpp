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
 *			 Todd Gibson											  *
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

/********************************************
 * @function: 	printTable					*
 * @params:		2D Vector of ints - "table"	*
 * @purpose: 	Prints the table in the		*
 *				following form:				*
 *				    + | a b c 				*
 *				    ----------				*
 *				    d | 1 2 3				*
 *				    e | 4 5 6				*
 *				    f | 7 8 9				*
 ********************************************/
void printTable(vector< vector<int> > table) {
	char label = 'a';
	cout<<"+ | ";
	int cols = table[0].size();
	for(int i = 0; i <= table.size(); ++i) {
		for(int j = 0; j < cols; ++j) {
			if(i == 0){
				cout<<label++<<" ";
			} else {
				cout<<table[i-1][j]<<" ";
			}
		}
		if(i == 0) {
			cout<<endl;
			for(int k = 0; k <= cols+5; ++k)
				cout<<"-";
		}

		if(i != table.size())
			cout<<endl<<label++<<" | ";
	}
}