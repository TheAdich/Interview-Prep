/**
 * Muhammad Ali, one of my grearrival_Time heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define si(x)           scanf("%d",&x)
#define sl(x)           scanf("%lld",&x)
#define ss(s)           scanf("%s",s)
#define pi(x)           printf("%d\n",x)
#define pl(x)           printf("%lld\n",x)
#define ps(s)           printf("%s\n",s)

#define fi              first
#define se              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mk(arr,n,type)  type *arr=new type[n];

#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << " ";
	}
	return os;
}

int running_Time = 0;

int quantum_Number = 0;

bool isIdle = true;

int has_burst_zero = 0;

class Process {
public:
	string PID;
	int arrival_Time;
	int burst_Time;
	Process(string PID, int arrival_Time, int burst_Time) {
		this->PID = PID;
		this->arrival_Time = arrival_Time;
		this->burst_Time = burst_Time;
	}
};

vector<Process> get_processes() {
	int n;
	cin >> n;

	vector<Process> v;

	for (int i = 0; i < n; i++) {
		string PID;
		int arrival_Time;
		int burst_Time;

		cin >> PID;
		cin >> arrival_Time;
		cin >> burst_Time;

		v.push_back({PID, arrival_Time, burst_Time});
	}

	return v;
}

void schedule(vector<Process> jobs, int quantum) {
	int total_Processes = jobs.size();

	while (has_burst_zero != total_Processes)
	{
		isIdle = true;

		for (int i = 0; i < total_Processes; i++)
		{
			if (jobs[i].arrival_Time < running_Time && jobs[i].burst_Time > 0)
			{
				cout << quantum_Number << ',' << jobs[i].PID << endl;

				jobs[i].burst_Time = jobs[i].burst_Time - quantum;

				running_Time = running_Time + quantum;
				quantum_Number++;

				isIdle = false;

				if (jobs[i].burst_Time <= 0)
					has_burst_zero++;	//Increment size by one
			}
		}

		if (isIdle)
		{
			cout << quantum_Number << ',' << "CPU is Idle" << endl;
			quantum_Number++;
			running_Time = running_Time + quantum;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	vector<Process> v = get_processes();
	schedule(v, 2);
}