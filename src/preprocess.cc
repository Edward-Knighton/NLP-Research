#include "preprocess.h"

using namespace std;

//Open file
void preprocessFile() {
  ifstream fin;
  fin.open("ALLDATA.txt");
  if (!fin.is_open())
    cout << "File did not open correctly\n";
  string fullEntry;
  ofstream out("trade.preprocessed.txt", ios_base::app);
  while (getline(fin, fullEntry)) {
      string::size_type found = fullEntry.find('<');
      if (found != string::npos) {
          if (fullEntry.at(found+1) == '*' && fullEntry[found+2] != '*') {
              changeLabels(fullEntry, found, out);
          }
      }
  }
  fin.close();
  out.close();
}

void changeLabels(string line, int start, ostream &out) {

    string base = " __label__";
    line.replace(start,2,base);
    string::size_type end = line.find("*>");
    string::size_type found = line.find_first_of(",;");
    while (found < end -1 && found != string::npos) {
        line.replace(found,1,base);
        end = line.find("*>",found);
        found = line.find_first_of(",;", found+1);
    }

    line.replace(end,2,"  ");

    out << line << endl;
    return;
}
//Delete all text until first <*

//Make string inbetween <* and *>
//Delete that stuff


//Function for handling strings in between <* and *>


// search chars until find "<" if next char is "!" delete all chars until "<"
//if next char is "*" do label thing
