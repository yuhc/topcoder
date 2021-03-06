#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class PerfectPermutation {
public:

    bool flagb[50], flagq[50];
    int best = 50;
    int Q[50];
    vector <int> B;

    void dfs(int i, int &n, int now, vector <int> &P) {
        if (i == n || now >= best) {
            if (now < best) best = now;
            //ans = Q;
            return;
        }

        for (int j = 1; j < n; j++) {
            if (!flagb[j] && Q[B[i-1]] == -1) {
                B.push_back(j);
                flagb[j] = true;
                //flagq[Q[B[i-1]]] = true;
                Q[B[i-1]] = j;
                dfs(i+1, n, now + (P[B[i-1]] != j?1:0), P);
                flagb[j] = false;
                //flagq[Q[B[i-1]]] = false;
                Q[B[i-1]] = -1;
                B.pop_back();
            }
        }
    }

	int reorder(vector <int> P) {
		int n = P.size();
        for (int i = 0; i < n; i++) {
            flagb[i] = false;
            flagq[i] = false;
            Q[i] = -1;
        }
        B.push_back(0);
        flagb[0] = true;
        dfs(1, n, 0, P);
        return best;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	PerfectPermutation *obj;
	int answer;
	obj = new PerfectPermutation();
	clock_t startTime = clock();
	answer = obj->reorder(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	vector <int> p0;
	int p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {2,0,1};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {2,0,1,4,3};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {2,3,0,1};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {0,5,3,2,1,4};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {4,2,6,0,3,5,9,7,8,1};
	p1 = 5;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// A permutation A[0], A[1], ..., A[N-1] is a sequence containing each integer between 0 and N-1, inclusive, exactly once.  Each permutation A of length N has a corresponding child array B of the same length, where B is defined as follows:
//
//
// B[0] = 0
// B[i] = A[B[i-1]], for every i between 1 and N-1, inclusive.
//
//
// A permutation is considered perfect if its child array is also a permutation.
//
// Below are given all permutations for N=3 with their child arrays. Note that for two of these permutations ({1, 2, 0} and {2, 0, 1}) the child array is also a permutation, so these two permutations are perfect.
//
//
// Permutation		Child array
// {0, 1, 2}		{0, 0, 0}
// {0, 2, 1}		{0, 0, 0}
// {1, 0, 2}		{0, 1, 0}
// {1, 2, 0}		{0, 1, 2}
// {2, 0, 1}		{0, 2, 1}
// {2, 1, 0}		{0, 2, 0}
//
//
// You are given a vector <int> P containing a permutation of length N.  Find a perfect permutation Q of the same length such that the difference between P and Q is as small as possible, and return this difference.  The difference between P and Q is the number of indices i for which P[i] and Q[i] are different.
//
// DEFINITION
// Class:PerfectPermutation
// Method:reorder
// Parameters:vector <int>
// Returns:int
// Method signature:int reorder(vector <int> P)
//
//
// CONSTRAINTS
// -P will contain between 1 and 50 elements, inclusive.
// -P will contain each integer between 0 and N-1, inclusive, exactly once, where N is the number of elements in P.
//
//
// EXAMPLES
//
// 0)
// {2, 0, 1}
//
// Returns: 0
//
// P is a perfect permutation, so we can use the same permutation for Q.  The difference is then 0 because P and Q are the same.
//
// 1)
// {2, 0, 1, 4, 3}
//
// Returns: 2
//
// Q might be {2, 0, 3, 4, 1}.
//
// 2)
// {2, 3, 0, 1}
//
// Returns: 2
//
// Q might be {1, 3, 0, 2}.
//
// 3)
// {0, 5, 3, 2, 1, 4}
//
// Returns: 3
//
//
//
// 4)
// {4, 2, 6, 0, 3, 5, 9, 7, 8, 1}
//
// Returns: 5
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
