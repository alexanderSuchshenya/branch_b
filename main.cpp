#include "branchslice.h"
using namespace std;

int main()
{
	vector<int> values;
	vector<int> masses;
	int N; int limit;

	cout << "number of items: ";
	cin >> N;
	cout << "backpack size limit: ";
	cin >> limit;
	cout << "items (pair {value, mass}): " << endl;
	for (int i = 0; i < N; i ++)
	{
		int vin, min;
		cin >> vin >> min;
		values.push_back(vin);
		masses.push_back(min);
	}
	cout << "items initialized" << endl;

	// sort
	sortbyvalue(masses, values);
	cout << "sorted items: " << endl;
	for (int i = 0; i < N; i++) cout << values[i] << ":" << masses[i] << endl;

	// go for a good evaluation
	int m = 0; int eval = 0; int weight = 0; 
	for (int i = 0; i < N; i++)
	{
		if (masses[i] < limit - weight)
		{
			eval = eval + values[i];
			weight = weight + masses[i];
			m = m + 1;
		}
	}

	// if all together fit - leave them be
	if (m == N) cout << "maximum value: " << eval << endl;
	// if not ask about improving
	else
	{
		cout << "maximum evaluated by: " << eval << " (" << m << " items)" << endl;
		cout << "  type 'l' to leave evaluation as an answer" << endl;
		cout << "  type 'i' to try to improve evaluation" << endl;
		cout << "  type 'n' to look for a limited maximum" << endl;
		cout << "  type 'f' to look for real maximum" << endl;
		cout << "  type anything else to exit" << endl;
		char ans;
		cin >> ans;
		if (ans == 'l')
		{
			cout << "maximum evaluated by: " << eval << endl;
		}
		else if (ans == 'i')
		{
			cout << "improving ..." << endl;
			cout << "maximum evaluated by: " << getnsplice(masses, values, vector<bool>(N,false), limit, m+1) << endl;
		}
		else if (ans == 'n')
		{
			int k;
			cout << "limitation on amount of items: " << endl;
			cin >> k;
			cout << "searching ..." << endl;
			cout << "limited maximum value: " << getnsplice(masses, values, vector<bool>(N, false), limit, k) << endl;
		}
		else if (ans == 'f')
		{
			cout << "searching ..." << endl;
			cout << "maximum value: " << getmaxsplice(masses, values, vector<bool>(N,false), limit) << endl;
		}
		else
		{
			cout << "exit" << endl;
		}
	}	
	cout << endl;
}
