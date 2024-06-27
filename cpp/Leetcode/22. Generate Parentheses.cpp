#include <string>
#include <vector>
using namespace std;

void backtrack(vector<string> &result, string value, int countOpened,
               int countClosed, int n) {
  if (countOpened == countClosed && countOpened == n) {
    result.push_back(value);
    return;
  }

  if (countOpened < n)
    backtrack(result, value + '(', countOpened + 1, countClosed, n);
  if (countClosed < countOpened)
    backtrack(result, value + ')', countOpened, countClosed + 1, n);
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  backtrack(result, "", 0, 0, n);
  return result;
}

int main() {}
