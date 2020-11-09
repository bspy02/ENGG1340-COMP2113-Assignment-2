#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Search for a word w in a file named fn
// word: word to search for
// fn: name of file to search
// nLines: (output) number of lines w appear in fn
// total: (output) total number of occurrences of w in fn
// return 0 if file operation is successful
// return 1 otherwise
int SearchWord(string word, string fn, int &nLines, int &total)
{
  ifstream fin(fn.c_str());
  string line;
  int w = word.length();
	if ( fin.fail() )
  {
		return 1;
  }
  while(getline(fin,line))
  {
      int count = 0;
      //cout <<  fn << "  "<< total<<"  "<< nLines << endl;
      stringstream sin(line);
      string one;
      while(sin >> one)
      {
          //cout << "     " <<one << equal(one,word) << endl;
          bool same = (one.length() == w);
          for(int i= 0; i<w; i++)
          {
              same = same && (tolower(one[i]) == tolower(word[i]));
              if(!same) break;
          }
          count += same;
      }
      if(count > 0)
      {
          total += count;
          nLines ++;
      }

  }
  return 0;
}



// argc is the number of arguments from the command line
// argv[0] == program name
// argv[1..argc-1] are the arguments
// e.g., if this program's name is "prog" and the following command is run
// at the command prompt:
// > ./prog word file1 file2
// then in the main function, argc is 4, and argv[0] is "./prog",
// argv[1] is "word", argv[2] = "file1", argv[3] = "file2"
//
// usage: ./wordsearch word_to_search file1 file2 files3 ...
//
int main(int argc, char* argv[])
{
  if (argc < 3) {
    cout << "usage: " << argv[0] << " [word_to_search] [file1] [file2] [file3]...\n";
    exit(1);
  }

  string word = argv[1];  // word to search for

  // loop through all the filenames in the command line argument
  for (int i = 2; i < argc; ++i) {
    string filename = argv[i];
    int lineCount=0, totalCount=0;
    // search word in file
    if (SearchWord(word, filename, lineCount, totalCount))
      cout << filename << ": error opening file" << endl;
    else
      cout << filename << ": " << lineCount << " " << totalCount << endl;
  }


  return 0;

}