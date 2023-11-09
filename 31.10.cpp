#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void replaceFirst20With200(vector<int>& numbers) {
    auto it = find(numbers.begin(), numbers.end(), 20);
    if (it != numbers.end()) {
        *it = 200;
    }
}

void removeEmptyStrings(vector<string>& strings) {
    strings.erase(
        remove_if(strings.begin(), strings.end(),
            [](const string& s) { return s.empty(); }),
        strings.end());
}

void squareNumbers(vector<int>& numbers) {
    transform(numbers.begin(), numbers.end(), numbers.begin(),
        [](int n) { return n * n; });
}

void removeAll20s(vector<int>& numbers) {
    numbers.erase(
        remove(numbers.begin(), numbers.end(), 20),
        numbers.end());
}

template <typename T>
void printInReverse(const vector<T>& vec) {
    for_each(vec.rbegin(), vec.rend(),
        [](const T& item) { cout << item << " "; });
    cout << endl;
}

int main() {
    vector<int> numbers = { 10, 20, 30, 20, 40, 20 };
    vector<string> strings = { "Hello", "", "World", "!", "" };

    cout << "Original numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\n";

    cout << "Original strings: ";
    for (string s : strings) {
        cout << "{" << s << "} ";
    }
    cout << "\n";

    replaceFirst20With200(numbers);
    removeEmptyStrings(strings);

    cout << "Numbers after replacing the first 20 with 200:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Strings after removing empty ones:" << endl;
    for (const auto& s : strings) {
        cout << "'" << s << "' ";
    }
    cout << endl;

    squareNumbers(numbers);

    cout << "Numbers squared:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    removeAll20s(numbers);

    cout << "Numbers after removing all 20s:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    cout << "List in reverse order:" << endl;
    printInReverse(numbers);

    return 0;
}
