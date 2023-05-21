#include <bits/stdc++.h>
using namespace std;

// To find the closest pair of points
long closestPair(vector<pair<int, int> > coordinates, int n)
{
	int i;
	// Vector pair to store points on plane
	vector<pair<int, int> > v;
	for (i = 0; i < n; i++)
		v.push_back({ coordinates[i].first,
					coordinates[i].second });

	// Sort them according to their
	// x-coordinates
	sort(v.begin(), v.end());

	// Minimum distance b/w points
	// seen so far
	long d = INT_MAX;

	// Keeping the points in
	// increasing order
	set<pair<int, int> > st;
	st.insert({ v[0].first, v[0].second });

	/*If the current point is (x, y) and there is a point to the left within a distance of less than d,  
          the x coordinate of such a point must be between [x − d, x] and the y coordinate must be between [y− d, y+ d]. 
          Thus, it suffices to only consider points that are located in those ranges. We can achieve this search in O(logN) time by using set st.
          The efficiency of the algorithm is based on the fact that the region always contains only O(1) points.
          Return distance d as a final result.*/
	
	for (i = 1; i < n; i++) {
		auto l = st.lower_bound(
			{ v[i].first - d, v[i].second - d });
		auto r = st.upper_bound(
			{ v[i].first, v[i].second + d });
		if (l == st.end())
			continue;

		for (auto p = l; p != r; p++) {
			pair<int, int> val = *p;
			long dis = (v[i].first - val.first)
						* (v[i].first - val.first)
					+ (v[i].second - val.second)
							* (v[i].second - val.second);

			// Updating the minimum
			// distance dis
			if (d > dis)
				d = dis;
		}
		st.insert({ v[i].first, v[i].second });
	}

	return d;
}

// Driver code
int main()
{

	// Points on a plane P[i] = {x, y}
	vector<pair<int, int> > P = {
		{ 1, 2 }, { 2, 3 }, { 3, 4 }, { 5, 6 }, { 2, 1 }
	};
	int n = P.size();

	// Function call
	cout << "The smallest distance is "
		<< closestPair(P, n);
	return 0;
}

