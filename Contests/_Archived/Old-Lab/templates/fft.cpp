#include <bits/stdc++.h>
using namespace std;

const long double PI = acos(0.0) * 2.0;
typedef complex<double> CD;

inline void fft(vector<CD> &a, bool inverse)
{
	int n = a.size();
	for (int i = 0, j = 0; i < n; i++)
	{
		if (j > i) swap(a[i], a[j]);
		int k = n;
		while (j & (k >>= 1)) j &= ~k;
		j |= k;
	}

	double pi = inverse? -PI: PI;
	for (int step = 1; step < n; step <<= 1)
	{
		double alpha = pi / step;
		for (int k = 0; k < step; k++)
		{
			CD omegak = exp(CD(0, alpha * k));
			for (int ek = k; ek < n; ek += step << 1)
			{
				int ok = ek + step;
				CD t = omegak * a[ok];
				a[ok] = a[ek] - t;
				a[ek] += t;
			}
		}
	}

	if (inverse)
	{
		for (int i = 0; i < n; i++) a[i] /= n;
	}
}

inline vector<double> operator*(const vector<double> &v1, const vector<double> &v2)
{
	int s1 = v1.size(), s2 = v2.size(), s = 2;
	while (s < s1 + s2) s <<= 1;
	vector<CD> a(s, 0), b(s, 0);
	for (int i = 0; i < s1; i++) a[i] = v1[i];
	fft(a, false);
	for (int i = 0; i < s2; i++) b[i] = v2[i];
	fft(b, false);
	for (int i = 0; i < s; i++) a[i] *= b[i];
	fft(a, true);
	
	vector<double> res(s1 + s2 - 1);
	for (int i = 0; i < s1 + s2 - 1; i++) res[i] = a[i].real();
	return res;
}

int main()
{
	int n, m;
	cin>>n>>m;
	vector<double> a, b;
	for (int i = 0; i <= n; i++)
	{
		double t; cin>>t;
		a.push_back(t);
	}
	for (int i = 0; i <= m; i++)
	{
		double t; cin>>t;
		b.push_back(t);
	}

	vector<double> res = a * b;

	for (auto i : res)
	{
		printf("%.0lf ", res[i]);
	}
	printf("\n");

	return 0;
}

