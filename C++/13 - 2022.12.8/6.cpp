#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
class Dictionary {
    public:
        map<string, string> mp;
        void LoadLibrary() {
            ifstream ifs("Dictionary.txt", ios::in);
            string en, ch;
            while (ifs >> en >> ch)
                mp[en] = ch;
            ifs.close();
        }
        void LookupWord(string a) {
            map<string, string>::iterator ita = mp.begin();
            for (; ita != mp.end(); ++ita) {
                if (ita->first == a) {
                    cout << "find the word \"" << ita->first << "\" -- " << ita->second << endl;
                    return;
                }
                if (ita->first > a) {
                    cout << "find the word \"" << a << "\" -- Maybe you want to look for \"" << ita->first << "\" -- " << ita->second << endl;
                    return;
                }
            }
            map<string, string>::reverse_iterator itb = mp.rbegin();
            cout << "find the word " << a << " -- Maybe you want to look for " << itb->first << " -- " << itb->second << endl;
        }
        void InsertWord(string en, string ch) {
            mp[en] = ch;
        }
        void DeleteWord(string a) {
            map<string, string>::iterator ita = mp.begin();
            for (; ita != mp.end(); ++ita) {
                if (ita->first == a) {
                    mp.erase(ita);
                    return;
                }
                if (ita->second == a) {
                    mp.erase(ita);
                    return;
                }
            }
        }
        void RestoreLibrary() {
            mp.clear();
            ifstream ifs("Dictionary.txt", ios::in);
            string en, ch;
            while (ifs >> en >> ch)
                mp[en] = ch;
            ifs.close();
        }
        void FreeLibrary() {
            ofstream ofs("Dictionary.txt", ios::out);
            map<string, string>::iterator ita = mp.begin();
            for (; ita != mp.end(); ++ita)
                ofs << ita->first << ' ' << ita->second << endl;
            ofs.close();
            mp.clear();
        }
        Dictionary() {
            LoadLibrary();
        }
};

int main() {
    Dictionary dict;
    dict.LoadLibrary();
    dict.InsertWord("TIGER", "老虎");
    dict.InsertWord("DOG", "狗");
    dict.InsertWord("DOT", "点");
    dict.FreeLibrary();
    dict.RestoreLibrary();
    dict.LookupWord("TIGER");
    dict.LookupWord("DOG");
    dict.LookupWord("DOT");
    dict.DeleteWord("DOT");
    dict.FreeLibrary();
    dict.RestoreLibrary();
    dict.LookupWord("TIGER");
    dict.LookupWord("DOT");
    return 0;
}