/**
 * Muhammad Ali, one of my great heroes, had a great line
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

class Site {
  int j = 1;
public:
  string site_id;
  vector<string> process_id;

  Site() {}
  Site(int no_of_process, int id) {
    site_id = "S";
    site_id += (char)(id + '0');
    process_id.resize(no_of_process);
    for (int i = 0; i < no_of_process; i++) {
      process_id[i] = "p";
      process_id[i] += (char)(j + '0');
      ++j;
    }
  }
  void display() {
    cout << "No. of processes in Site :" << site_id << " are :";
    for (string s : process_id) {
      cout << s << "  ";
    }
    cout << endl;
  }
};

class PathInfo {
public:
  string sender_site, receiver_site;
  PathInfo() {
    sender_site = "xxxx";
    receiver_site = "xxxx";
  }
};

class ProbeMsg {
public:
  string i, j, k;
  ProbeMsg() {
    i = j = k = "xx";
  }
};



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);
#endif

  PathInfo path[5];

  for (int i = 0; i < 5; i++) {
    path[i].sender_site = "Y";
    cout << path[i].sender_site << endl;
  }


}