#include <iostream>
#include <string>

using namespace std;

string longest(string s) {
    string mx;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j + i <= s.size(); j++) {
            string st = s.substr(i, j);

            bool dis = true;

            for (char c : st) {
                if (islower(c)) {
                    if (st.find(toupper(c)) == string::npos) {
                        dis = false;
                        break;
                    }
                } else if (st.find(tolower(c)) == string::npos) {
                    dis = false;
                    break;
                }
            }

            if (dis) {
                if (st.size() > mx.size()) {
                    mx = st;
                }
            }
        }
    }

    return mx;
}

int main() {
    string s ;
    cin >> s;
    string res = longest(s);

    cout<< res<< endl;

    return 0;
}
