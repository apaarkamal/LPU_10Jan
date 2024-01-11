#include<bits/stdc++.h>

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			db(i, j);
			// cout<<"i -> "<<i<<" j -> "<<j<<'\n';
		}
	}


	return 0;
}