//
// @brief: 高精度整数(OI可用)
// @birth: xdon985, 2025-3-30
// @version: 1.04.1
//
#error 1.04/main.h is not finished.
#include<bits/stdc++.h>
// @breif: 承载命名空间
namespace strn0104 {
	// @breif: NL 表示长度, D 表示进制
	constexpr long long NL = 100, D = 10;
	struct N; using I = long long;
	using A = N const&; using V = void; using B = bool;
	N operator+  ( A, A ), 	operator-  ( A, A ),  operator*  ( A, A );
	N operator+  ( A, I ), 	operator-  ( A, I ),  operator*  ( A, I );
	V operator+= ( N&, A ), operator-= ( N&, A ), operator*= ( N&, A );
	V operator+= ( N&, I ), operator-= ( N&, I ), operator*= ( N&, I );
	B operator== ( A, A ), 	operator<= ( A, A ),  operator>= ( A, A );
	B operator!= ( A, A ), 	operator<  ( A, A ),  operator>  ( A, A );
	I cmp ( A, A ); V corra ( N& ), corrl ( N& );
	std::ostream& operator<< ( std::ostream& f, A n1 );
	std::istream& operator>> ( std::istream& f, N& n1 );
	// @breif: 高精度类型
	struct N {
		N () = default;
		N ( I x ) { *this += x; }
		I s[NL] {};
		// @breif: 直接访问数位
		I& operator[] ( I i1 )       { return this->s[i1]; }
		// @breif: 直接访问数位
		I  operator[] ( I i1 ) const { return this->s[i1]; }
	};
	N operator+  ( A n1, A n2 ) { N ret = n1; ret += n2; return ret; };
	N operator-  ( A n1, A n2 ) { N ret = n1; ret -= n2; return ret; };
	N operator*  ( A n1, A n2 );
	V operator+= ( N& s, A n1 ) {
		for ( I d = 0; d < NL; ++d ) { s[d] += n1[d]; }
		corra ( s );
	}
	V operator-= ( N& s, A n1 ) {
		for ( I d = 0; d < NL; ++d ) { s[d] -= n1[d]; }
		corra ( s );
	}
	V operator*= ( N& s, A n1 ) { s = s * n1; }
	N operator+  ( A n1, I i1 ) { N ret = n1; return ret += i1, ret; }
	N operator-  ( A n1, I i1 ) { N ret = n1; return ret -= i1, ret; }
	N operator*  ( A n1, I i1 ) { N ret = n1; return ret *= i1, ret; }
	V operator+= ( N& s, I i1 ) { s[0] += i1; corrl ( s ); }
	V operator-= ( N& s, I i1 ) { s[0] -= i1; corrl ( s ); }
	V operator*= ( N& s, I i1 ) { for ( I d = 0; d < NL; ++d ) { s[d] *= i1; } corra ( s ); }
	B operator== ( A n1, A n2 ) { return cmp ( n1, n2 ) == 0; }
	B operator<= ( A n1, A n2 ) { return cmp ( n1, n2 ) <= 0; }
	B operator>= ( A n1, A n2 ) { return cmp ( n1, n2 ) >= 0; }
	B operator!= ( A n1, A n2 ) { return cmp ( n1, n2 ) != 0; }
	B operator<  ( A n1, A n2 ) { return cmp ( n1, n2 ) <  0; }
	B operator>  ( A n1, A n2 ) { return cmp ( n1, n2 ) >  0; }
	// @breif: 标准比较接口
	// @ret: -1 0 1
	I cmp 		 ( A n1, A n2 ) {
		for ( I d = 0; d < NL; ++d ) {
			if ( n1[d] < n2[d] ) {return -1;}
			if ( n1[d] > n2[d] ) {return 1;}
		}
		return 0;
	}
	// @breif: 所有位的纠正 
	V corra 	 ( N& s ) {
		for ( I d = 0; d < NL; ++d ) {
			// TODO(xdon985): finish corra(N&)
		}
	}
	// @brief: 最低位的纠正 
	V corrl 	 ( N& s ) {
		for ( I d = 0; d < NL; ++d ) {
			// TODO(xdon985): finish corrl(N&)
		}
	}
}
typedef strn0104::N bigint0104;
