#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

void flipColunm(vector<vector<int>>& matrix, int idexColumn) {
    for(int i = 0; i < matrix.size(); i++) {
        int temp = matrix[i][idexColumn];
        matrix[i][idexColumn] = matrix[i][matrix.size() - 1 - idexColumn];
        matrix[i][matrix.size() - 1 - idexColumn] = temp;
    }
}

void flipRow(vector<vector<int>>& matrix, int idexRow) {
    for(int i = 0; i < matrix.size(); i++) {
        int temp = matrix[idexRow][i];
        matrix[idexRow][i] = matrix[matrix.size() - 1 - idexRow][i];
        matrix[matrix.size() - 1 - idexRow][i] = temp;
    }
}

int computeUpperLeftSubmatrixSum(vector<vector<int>>& matrix) {
    int sum = 0;
    for(int i = 0; i < matrix.size()/2; i++) {
        for(int j = 0; j < matrix.size()/2; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int flippingMatrix(vector<vector<int>> matrix) {
    int count = 0;
    
    return count;
}

int main()
{
    // TODO: Write test cases here

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
