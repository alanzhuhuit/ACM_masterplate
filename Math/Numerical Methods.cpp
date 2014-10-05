#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
const double pi = acos(0) * 2;
template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b) {return a > b ? a : b;}
template <class T> inline T min1(T a, T b) {return a < b ? a : b;}
template <class T> inline T gcd1(T a, T b) {
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return gcd1(b, a % b);
}

const int eps = 1e-8;

template <typename T> struct matrix
{
	const static int maxn = 100;
	int row, col;
	T mat[maxn][maxn];

	matrix(int r = 0, int c = 0)
	{
		row = r; col = c;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = 0;
	}

	matrix(T* mat1, int r = 0, int c = 0)
	{
        row = r; col = c;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = mat1[i*col + j];
	}

	const T * operator[] (int i) const
	{
		return mat[i];
	}

	T * operator[] (int i)
	{
		return mat[i];
	}

	bool I()
	{
		if(row != col) return 0;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = bool (i == j);
		return 1;
	}

	matrix operator * (const matrix& b) const{
		int i, j, k;
		matrix <T> c(row, b.col);
		memset(c.mat, 0, sizeof(c.mat));
		for (i = 0; i < c.row; i++) for (k = 0; k < col; k++)
			if(mat[i][k])
				for (j = 0; j < c.col; j++){
					c.mat[i][j] += mat[i][k] * b.mat[k][j];
				}
		return c;
	}

	matrix operator + (const matrix& b) const
	{
		matrix <T> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++)
		{
			T a = 0; if(i < row && j < col) a = mat[i][j];
			T b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a + b1;
		}
		return c;
	}

	matrix operator - (const matrix& b) const
	{
		matrix <T> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++)
		{
			T a = 0; if(i < row && j < col) a = mat[i][j];
			T b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a - b1;
		}
		return c;
	}

	inline void operator = (const matrix & b)
	{
		memcpy(mat, b.mat, sizeof(mat));
		col = b.col;  row = b.row;
	}

	void swapRow(int x, int y) // 交换x, y行的所有元素
	{
		for (int i = 0; i < col; i++) swap(mat[x][i], mat[y][i]);
	}

	void swapCol(int x, int y) // 交换x, y列的所有元素
	{
		for (int i = 0; i < row; i++) swap(mat[i][x], mat[i][y]);
	}

	void pt(int x, int y, double c) // y行+x行*c
	{
		for (int i = 0; i < col; i++) mat[y][i] += mat[x][i] * c;
	}

	void lineBy(int x, double c) // 将x行同时乘c
	{
		for (int i = 0; i < col; i++) mat[x][i] *= c;
	}

	matrix pow(long long n)
	{
		matrix <T> ans(row, col), temp = *this;

		ans.I();
		while(n)
		{
			if(n & 1) ans = ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans;
	}

	matrix addpow(ll n)
	{// calculate 1 + m + m ^ 2 + ... + m ^ n
		n++;
		matrix <T> ans(row, col), temp = *this, temp1(row, col), ans1(row, col);

		ans.I(); temp1.I();
		while(n)
		{
			if(n & 1)
			{
				ans1 = ans1 + ans * temp1;
				temp1 = temp * temp1;
			}
			ans = ans + ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans1;
	}

	int inv()
	{
		int i, j, k, is[maxn], js[maxn];
		double t1;

		if (row != col) return 0;
		for(k = 0; k < row; k++)
		{
			for(t1 = 0,i = k; i < row; i++) for(j = k; j < row; j++)
				if(fabs(mat[i][j]) > t1)
					t1=fabs(mat[is[k] = i][js[k] = j]);
			if (fabs(t1 - 0) < 1e-9) return 0;
			if (is[k] != k) for(j = 0; j < row; j++)
				t1 = mat[k][j], mat[k][j] = mat[is[k]][j], mat[is[k]][j] = t1;
			if (js[k] != k) for (i = 0; i < row; i++)
				t1 = mat[i][k], mat[i][k] = mat[i][js[k]], mat[i][js[k]] = t1;
			mat[k][k] = 1 / mat[k][k];
			for(j = 0; j < row; j++) if (j != k)
				mat[k][j] *= mat[k][k];
			for (i = 0; i < row; i++)	if (i != k)
				for (j = 0; j < row; j++) if (j != k)
					mat[i][j] -= mat[i][k] * mat[k][j];
			for (i = 0;i < row; i++) if (i != k)
				mat[i][k] *= -mat[k][k];
		}
		for (k = row-1; k >= 0; k--)
		{
			for (j = 0; j < row; j++) if (js[k] != k)
					t1 = mat[k][j], mat[k][j] = mat[js[k]][j], mat[js[k]][j]=t1;
			for (i = 0; i < row; i++) if (is[k] != k)
				t1 = mat[i][k], mat[i][k] = mat[i][is[k]], mat[i][is[k]] = t1;
		}
		return 1;
	}

	double det()
	{
		int i, j, k, sign = 0;
		double b[maxn][maxn], ret = 1, t1;

		if (row != col) return 0;
		for (i = 0; i < row; i++) for (j = 0; j < col; j++)
			b[i][j] = mat[i][j];
		for (i = 0; i < row; i++)
		{
			if (fabs(b[i][i] - 0) < 1e-9)
			{
				for (j = i + 1; j < row; j++)
					if (fabs(b[j][i] - 0) > 1e-9) break;
					if (j == row) return 0;
					for (k = i; k < row; k++)
						t1 = b[i][k], b[i][k] = b[j][k], b[j][k] = t1;
					sign++;
			}
			ret *= b[i][i];
			for (k = i + 1; k < row; k++) b[i][k] /= b[i][i];
			for (j = i + 1; j < row; j++) for (k = i + 1; k < row; k++)
				b[j][k] -= b[j][i] * b[i][k];
		}
		if (sign & 1) ret = -ret;
		return ret;
	}
};

void gauss1(matrix<double> &ab)//最后一列就是解
{
	int h, w;
	h = ab.row, w = ab.col;
	if(h + 1 != w)//要求n阶方阵
		return;
	int n = h;
	int i, j;
 	for(i = 0; i < n; ++i)
 	{
  		//从a[i,i]到a[n,i]找出最大元素所在行
  		int maxi = i;//maxi指向最大列主元素所在行
  		for(j = i+1; j < h; ++j)
  		{
   			if(fabs(ab.mat[j][i]) > fabs(ab.mat[maxi][i]))
    			maxi = j;
  		}
  		ab.swapRow(i, maxi);//交换行
  		if(fabs(ab.mat[i][i]) < eps)//det=0，计算停止
   			return;
  		//消元
  		for(j = i + 1; j < h; ++j)
  		{
   			ab.pt(i, j, -(ab.mat[j][i]/ab.mat[i][i]));
  		}
  		//将a[i,i]化成1.0
		ab.lineBy(i, 1.0/ab.mat[i][i]);
 	}
 	for(i = n - 1; i >= 0; --i)
 	{
	  	//消第i列上三角元素
  		for(j = 0; j < i; ++j)
   			ab.pt(i, j, -ab.mat[j][i]);
 	}
}

int main()
{
    // try Gauss
    //double mat[] = {1, 1, 1, 6, 2, 1, 1, 7, 1, 2, 1, 8};
    //double mat[] = {1, 1, 1, 6, 0, 1, 1, 5, 0, 0, 1, 3};
    matrix<double> ab(mat, 3, 4);
    gauss1(ab);
    for (int i = 0; i < 3; i++, cout << endl)
        for (int j = 0; j < 4; j++) cout << ab.mat[i][j] << '\t';
    return 0;
}

