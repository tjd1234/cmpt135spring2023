// shuffle.cpp

//
// Reads words from cin one at a time. Write them all back to cout in random
// order, one per line.
//
// Use file redirection to read, e.g.:
//
//   > ./shuffle < words.txt > shuffled.txt
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Randomly re-arrange the elements of a vector of strings.
void shuffle(vector<string> &words)
{
    for (int i = 0; i < words.size(); i++)
    {
        // choose a random index j
        int j = rand() % words.size();

        // swap words[i] and words[j]
        string temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main()
{
    // set random seed so random numbers are different each time
    srand(time(NULL));

    // read in the words from cin
    vector<string> words;
    string w;
    while (cin >> w)
    {
        words.push_back(w);
    }

    // randomly re-arrange them
    shuffle(words);

    // write them to cout
    for (string w : words)
    {
        cout << w << "\n";
    }
}
