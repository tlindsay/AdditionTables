/**********************************************************************
 *     _       _     _ _ _   _           _____     _     _            *
 *    / \   __| | __| (_) |_(_) ___  _ _|_   _|_ _| |__ | | ___  ___  *
 *   / _ \ / _` |/ _` | | __| |/ _ \| '_ \| |/ _` | '_ \| |/ _ \/ __| *
 *  / ___ \ (_| | (_| | | |_| | (_) | | | | | (_| | |_) | |  __/\__ \ *
 * /_/   \_\__,_|\__,_|_|\__|_|\___/|_| |_|_|\__,_|_.__/|_|\___||___/ *
 *                                                                    *
 **********************************************************************
 * @authors: Patrick Lindsay                                          *
 *           Amy Brown                                                *
 *           Seth Putman                                              *
 *           Brianna Hillman                                          *
 *           Todd Gibson                                              *
 **********************************************************************
 * @program: Addition Tables                                          *
 * @notes:   This source has only been tested with the G++ compiler,  *
 *           using the `--std=c++11` flag. No other compilers are     *
 *           supported or recommended.                                *
 **********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void printTable(vector< vector<int> >);
bool hasSolution(vector< vector<int> >);
vector< vector<int> > getMatrix();

int main(int argc, char const *argv[]) {
    ////////////////////////////////////////////
    // This is just a 3x3 test matrix, in case 
    // you don't feel like entering your own
    ////////////////////////////////////////////
    // vector< vector<int> > table {{1,2,3},
    //                           {3,4,5},
    //                           {4,5,6}};

    vector< vector<int> > table = getMatrix();

    cout<<"Solution? (1 : Yes, 0 : No)\n"<<hasSolution(table);
    return 0;
}

/********************************************
 * @function:   printTable                  *
 * @params:     2D Vector of ints - "table" *
 * @purpose:    Prints the table in the     *
 *              following form:             *
 *                  + | a b c               *
 *                  ----------              *
 *                  d | 1 2 3               *
 *                  e | 4 5 6               *
 *                  f | 7 8 9               *
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
            for(int k = 0; k < (cols*2)+4; ++k)
                cout<<"-";
        }

        if(i != table.size())
            cout<<endl<<label++<<" | ";
    }
    cout<<endl;
}

/********************************************
 * For two columns, the difference has to be the same all the way down
 * For two rows, the difference has to be the same all the way across
 ********************************************/
bool hasSolution(vector< vector<int> > table ) {
    int diff1 = 0,
        diff2 = 0;

    for(int i = 0; i < table.size()-1; ++i) {
        for(int j = 0; j < table[i].size()-1; ++j) {
            diff1 = table[i][j+1] - table[i][j];
            diff2 = table[i+1][j+1] - table[i+1][j];
            if(diff1 != diff2)
                return false;
        }
    }
    
    // If we made it through the loop, then the matrix is valid.
    return true;
}

vector< vector <int> > getMatrix() {
    vector< vector <int> > table;
    int height = 0,
        width  = 0;
    char answer;

    cout<<"How large is your matrix?"<<endl;
    cout<<"Width: ";
    cin>>width;
    cout<<"Height: ";
    cin>>height;

    cout<<"Please enter the values of your matrix: "<<endl;

    for(int i = 0; i < height; ++i) {
        vector <int> row;
        
        for(int j = 0; j < width; ++j) {
            int temp;

            cout<<"Matrix("<<i<<","<<j<<"): ";
            cin>>temp;

            row.push_back(temp);
        }

        table.push_back(row);
    }

    printTable(table);
    cout<<"Is this correct? (y/n)"<<endl;
    cin>>answer;

    if(answer == 'n' || answer == 'N')
        table = getMatrix();

    return table;
}