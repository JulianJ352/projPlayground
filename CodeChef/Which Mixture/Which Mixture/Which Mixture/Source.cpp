//Which Mixture, problem code mixture
//Submission by Julian Johnson

#include <cstdlib>
#include <iostream>

using namespace std;

string mixtureSolver(int a, int b)
{
	if (a == 0)
		return "Liquid";
	else if (b == 0)
		return "Solid";
	else if (a > 0 && b > 0)
		return "Solution";
	else
		return "invalid mixture information";
}

int main()
{
	int iterations, A, B;
	cin >> iterations;
	while (iterations > 0)
	{
		cin >> A >> B;
		cout << mixtureSolver(A, B) << endl;
		iterations--;
	}



	return 0;
}