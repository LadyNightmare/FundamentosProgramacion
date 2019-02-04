// prEx4.cpp
// juanfc 2016-08-31
//

#include <iostream>
#include <array>
using namespace std;


const int NMAXWORDS = 10;
typedef array<string,NMAXWORDS> TWords;

string encodeWord(string s);
bool isIn(TWords ww, string s);

int main()
{
    TWords ww;
    cout << "Input words until 'end': ";
    string s;
    int i = 0;
    cin >> s;
    while (i < NMAXWORDS and s != "end") {
        if (not isIn(ww, s)) {
            ww[i++] = s;
        }
        cin >> s;
    }

    cout << endl << "Original: ";
    i = 0;
    while (i < NMAXWORDS and ww[i].size() != 0) {
        cout << ww[i] << " ";
        ++i;
    }

    cout << endl << "Encoded: ";
    i = 0;
    while (i < NMAXWORDS and ww[i].size() > 0) {
        cout << encodeWord(ww[i]) << " ";
        ++i;
    }

    return 0;
}

string encodeWord(string s)
{
    string r;
    for (int i = 0; i < s.size(); ++i) {
        r += s[i];
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
            r += "p";
            r += s[i];
        }
    }
    return r;
}


bool isIn(TWords ww, string s)
{
    int i = 0;
    while (i < NMAXWORDS and ww[i].size() > 0 and ww[i] != s)
        ++i;
    return i < NMAXWORDS and ww[i].size() > 0;
}

// susie works in a shoeshine shop where she shines she sits and where she sits she shines end
// a skunk sat on a stump and thunk the stump stunk but the stump thunk the skunk stunk end
// better to have loved and lost than never to have loved at all end
// better to ask and appear foolish than to not ask and continue in foolishness end
