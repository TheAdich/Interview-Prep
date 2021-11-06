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

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}

class CWH {
protected:
	string title;
	float rating = 0.0;
public:
	CWH(string t, float r) : title(t), rating(r) {}
	void display() {
		cout << "Yeh kahaaaaa aagaye ham?" << endl;
	}
};

class CWHVideo: public CWH {
	float videoLength;
public:
	CWHVideo(string s, float r, int vl) : CWH(s, r), videoLength(vl) {}
	void display() {
		cout << "This is an amazing VIDEO: " << title << endl;
		cout << "Rating: " << rating << endl;
		cout << "Length of VIDEO is: " << videoLength << endl;
		cout << endl;
	}
};

class CWHText: public CWH {
	int words;
public:
	CWHText(string s, float r, int w) : CWH(s, r), words(w) {}
	void display() {
		cout << "This is an amazing TEXT: " << title << endl;
		cout << "Rating: " << rating << endl;
		cout << "Number of words is: " << words << endl;
		cout << endl;
	}
};

int main()
{
	string title;
	float rating, vlen;
	int words;

	//For CWH Video
	title = "PythonTutorialVideo";
	vlen = 4.56;
	rating = 4.33;
	CWHVideo pythonVideo(title, rating, vlen);
	// pythonVideo.display();
	//For CWH Text
	title = "PythonTutorialText";
	vlen = 25;
	rating = 3.4;
	CWHText pythonText(title, rating, vlen);
	// pythonText.display();

	CWH* tuts[2];
	tuts[0] = &pythonVideo;
	tuts[1] = &pythonText;

	tuts[0]->display();
	tuts[1]->display();
}