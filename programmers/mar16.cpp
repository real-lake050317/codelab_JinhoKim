#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> makeArray(string a) {
    vector<string> outputArray;

    for (int i = 0; i < a.length() - 1; i++) {
        if (isalpha(a[i]) && isalpha(a[i + 1])) {
            string element = "";
            element += a[i];
            element += a[i + 1];
            outputArray.push_back(element);
        }
    }

    return outputArray;
}


int solution(string str1, string str2) {
    for (int i = 0; i < str1.length(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }

    // make two arrays
    vector<string> arr1 = makeArray(str1);
    vector<string> arr2 = makeArray(str2);

    int intersection = 0;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                intersection++;
                break;
            }
        }
    }

    int unionNum = arr1.size() + arr2.size() - intersection;
    
    double answer = 0;
    if (unionNum != 0) {
        answer = (double)intersection / unionNum;
    } else {
        answer = 1;
    }
    
    cout << (int)(answer * 65536) << "\n";
}

int main() {
    solution("E=M*C^2", "e=m*c^2");
}