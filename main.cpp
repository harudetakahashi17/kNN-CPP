#include "header.h"

int main()
{
    List dtr; // variable list dataTrain
    List2 dte; // variable list dataTest
    List3 dis; // variable list top 5 nearest distance


    ifstream train("train.csv"); // input file CSV data Training to variable data
    ifstream test("test.csv"); // input file CSV data Testing

    createList(dtr);
    createList2(dte);
    createList3(dis);

    if (!train.is_open()) cout<<"ERROR: File Open\n"; // check if data is not in use by other program
    if (!test.is_open()) cout<<"ERROR: File Open\n";

    scanDataTrain(dtr, train);
    scanDataTest(dte, test);
    calcDistance(dtr,dte,dis,k);

    cout<<"To check result please open the output file result.csv\n";
    getch();
    return 0;
}
