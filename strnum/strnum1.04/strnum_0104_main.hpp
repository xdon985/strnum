//
// @brief: 高精度整数(OI可用)
// @birth: xdon985, 2025-3-30
// @version: 1.04.1
//
#include<bits/stdc++.h>
// @breif: 承载命名空间
namespace strn0104 {
	constexpr long long NL = 100, D = 10;
	struct N; using I = long long;
	using A = N const&; using V = void; using B = bool;
	N operator+  (A, A),	operator-  (A, A),	operator*  (A, A);
	N operator+  (A, I),	operator-  (A, I),	operator*  (A, I);
	V operator+= (N&, A),	operator-= (N&, A),	operator*= (N&, A);
	V operator+= (N&, I),	operator-= (N&, I),	operator*= (N&, I);
	B operator== (A, A),	operator<= (A, A),	operator>= (A, A);
	B operator!= (A, A),	operator<  (A, A),	operator>  (A, A);
	I cmp (A, A), getl (A);
	V corra (N&), corrl (N&);
	std::ostream& operator<< (std::ostream& f, A n1);
	std::istream& operator>> (std::istream& f, N& n1);
	// @breif: 高精度类型
	struct N {
		N () = default;
		N (I x) { *this += x; }
		N (std::string const& str): N(str.c_str()) { }
		N (char const* const str) {
			I l = strlen(str);
			for (I d = 0; d < l; ++d) s[d] = str[l - d - 1] - '0';
		}
		I s[NL] {};
		// @breif: 直接访问数位
		I& operator[](I i1)       { return s[i1]; }
		I  operator[](I i1) const { return s[i1]; }
		operator std::string() const {
			I l = getl(*this);
			if(l == 0) return "0";
			std::string ret(l, 0);
			for (I d = 0; d < l; ++d) ret[l - d - 1] = s[d] + '0';
			return ret;
		}
	};
	N operator+  (A n1, A n2) { N ret = n1; ret += n2; return ret; }
	N operator-  (A n1, A n2) { N ret = n1; ret -= n2; return ret; }
	N operator*  (A n1, A n2) {
		N ret;
		I l1 = getl(n1), l2 = getl(n2);
		for(I d1 = 0; d1 < l1; ++d1)
			for(I d2 = 0, maxd2 = std::min(l2, NL - d1);
			        d2 < maxd2; ++d2)
				ret[d1 + d2] += n1[d1] * n2[d2];
		corra(ret);
		return ret;
	}
	V operator+= (N& s, A n1) {
		for (I d = 0; d < NL; ++d) s[d] += n1[d];
		corra(s);
	}
	V operator-= (N& s, A n1) {
		for (I d = 0; d < NL; ++d) s[d] -= n1[d];
		corra(s);
	}
	V operator*= (N& s, A n1) { s = s * n1; }
	N operator+  (A n1, I i1) { N ret = n1; ret += i1; return ret; }
	N operator-  (A n1, I i1) { N ret = n1; ret -= i1; return ret; }
	N operator*  (A n1, I i1) { N ret = n1; ret *= i1; return ret; }
	V operator+= (N& s, I i1) { s[0] += i1; corrl(s); }
	V operator-= (N& s, I i1) { s[0] -= i1; corrl(s); }
	V operator*= (N& s, I i1) {
		for (I d = 0; d < NL; ++d) s[d] *= i1;
		corra(s);
	}
	B operator== (A n1, A n2) { return cmp(n1, n2) == 0; }
	B operator<= (A n1, A n2) { return cmp(n1, n2) <= 0; }
	B operator>= (A n1, A n2) { return cmp(n1, n2) >= 0; }
	B operator!= (A n1, A n2) { return cmp(n1, n2) != 0; }
	B operator<  (A n1, A n2) { return cmp(n1, n2) <  0; }
	B operator>  (A n1, A n2) { return cmp(n1, n2) >  0; }
	I getl(A n1) {
		for(I d = NL; d > 0; --d) if(n1[d - 1]) return d;
		return 0;
	}
	// @breif: 标准比较接口
	// @ret: -1 0 1
	I cmp(A n1, A n2) {
		for (I d = 0; d < NL; ++d) {
			if (n1[d] < n2[d]) return -1;
			if (n1[d] > n2[d]) return 1;
		}
		return 0;
	}
	// @breif: 所有位的纠正
	V corra(N& s) {
		I tmp;
		for (I d = 0; d < NL; ++d) {
			if (s[d] >= D) {
				tmp = s[d] / D;
				if(d + 1 < NL) s[d + 1] += tmp;
				s[d] -= tmp * D;
			}
			else if (s[d] < 0) {
				tmp = (-s[d] - 1) / D + 1;
				if(d + 1 < NL) s[d + 1] -= tmp;
				s[d] += tmp * D;
			}
		}
	}
	// @brief: 最低位的纠正
	V corrl(N& s) {
		I tmp;
		for (I d = 0; d < NL; ++d) {
			if (s[d] >= D) {
				tmp = s[d] / D;
				if(d + 1 < NL) s[d + 1] += tmp;
				s[d] -= tmp * D;
			}
			else if (s[d] < 0) {
				tmp = (-s[d] - 1) / D + 1;
				if(d + 1 < NL) s[d + 1] -= tmp;
				s[d] += tmp * D;
			}
			else break;
		}
	}
	std::ostream& operator<< (std::ostream& f, A n1) {
		f << static_cast<std::string>(n1); return f;
	}
	std::istream& operator>> (std::istream& f, N& n1) {
		std::string s; f >> s; n1 = s; return f;
	}
}
typedef strn0104::N Strnum;
