#include "branchslice.h"
using namespace std;

void sortbyvalue (vector<int> &mass, vector<int> &value)
{
	int N = value.size();
	
	// simple sort by value
	// changes order of masses and values
	for (int i = 0; i < N-1; i++)
	{
		int curmax = i;
		for (int j = i+1; j < N; j++)
		{
			if(value[j] > value[curmax])
				curmax = j;
		}
		int tmpvalue = value[i];
		value[i] = value[curmax];
		value[curmax] = tmpvalue;
		int tmpmass = mass[i];
		mass[i] = mass[curmax];
		mass[curmax] = tmpmass;
	}
}

int getmaxsplice (vector<int> &mass, vector<int> &value, vector<bool> inclusion, int limit)
{
	int N = value.size();

	// find own mass
	int ownmass = 0;
	for (int i = 0; i < N; i++)
		if (inclusion[i]) ownmass = ownmass + mass[i];
	if (ownmass > limit) return -1; 
	// if mass is above limit - splice

	// else
	// find own value
	int curvalue = 0;
	for (int i = 0; i < N; i++)
		if (inclusion[i]) curvalue = curvalue + value[i];

	// find descendants
	// save maximum
	int cur = -1;
	for (int i = 0; i < N; i++)
		if (inclusion[i] && cur == -1) cur = i;
	if (cur == -1) cur = 0;
	for (int i = cur; i < N; i++)
		if (!inclusion[i])
		{
			vector<bool> newinclusion = inclusion;
			newinclusion[i] = true;
			int newvalue = getmaxsplice(mass, value, newinclusion, limit);
			if (newvalue > curvalue) curvalue = newvalue;
		}

	// mass is beneath limit
	// return maximum among itself and descendants
	return curvalue;
}

int getnsplice (vector<int> &mass, vector<int> &value, vector<bool> inclusion, int limit, int m)
{
        int N = value.size();

        // find own mass
        int ownmass = 0;
        for (int i = 0; i < N; i++)
                if (inclusion[i]) ownmass = ownmass + mass[i];
        if (ownmass > limit) return -1;
        // if mass is above limit - splice

        // else
        // find own value
        int curvalue = 0;
        for (int i = 0; i < N; i++)
                if (inclusion[i]) curvalue = curvalue + value[i];
	if (m == 0) return curvalue;
	// if reached max level - splice
	
        // find descendants
        // save maximum
        int cur = -1;
        for (int i = 0; i < N; i++)
                if (inclusion[i] && cur == -1) cur = i;
        if (cur == -1) cur = 0;
        for (int i = cur; i < N; i++)
                if (!inclusion[i])
                {
                        vector<bool> newinclusion = inclusion;
                        newinclusion[i] = true;
                        int newvalue = getnsplice(mass, value, newinclusion, limit, m-1);
                        if (newvalue > curvalue) curvalue = newvalue;
                }

        // mass is beneath limit
        // return maximum among itself and descendants
        return curvalue;
}
