#pragma once
#include<bits/stdc++.h>

#define TL template<I Ln>
#define N BigInt<Ln>
#define A N const&
#define O operator

namespace bign0105 {
	using I = long long; using V = void; using B = bool;
	constexpr I D = 10; // 阐述 
	TL struct BigInt {
		I s[Ln] {};

		BigInt () = default;
		BigInt (I x) { *this += x; }
		BigInt (std::string const& str): BigInt(str.c_str()) { }
		BigInt (char const* const str);

		I& O[](I d)       { return s[d]; }
		I  O[](I d) const { return s[d]; }
		O std::string() const;

		I getl() const;
		V corra(), corrl();
	};
	TL N O +  (A, A);	TL N O -  (A, A); 	TL N O *  (A, A);
	TL N O +  (A, I); 	TL N O -  (A, I); 	TL N O *  (A, I);
	TL N O += (N&, A); 	TL N O -= (N&, A); 	TL N O *= (N&, A);
	TL N O += (N&, I); 	TL N O -= (N&, I); 	TL N O *= (N&, I);
	TL I cmp(A, A);
	TL I getl(A n1) = delete; // 强制修改，下同 
	TL V corra(N& n1) = delete;
	TL V corrl(N& n1) = delete;
	TL std::ostream& O << (std::ostream& f, A n1);
	TL std::istream& O >> (std::istream& f, N& n1);

	TL N O + (A n1, A n2) { N ret = n1; ret += n2; return ret; }
	TL N O - (A n1, A n2) { N ret = n1; ret -= n2; return ret; }
	TL N O * (A n1, A n2) {
		N ret;
		I l1 = n1.getl(), l2 = n1.getl();
		for(I d1 = 0; d1 < l1; ++d1)
			for(I d2 = 0, maxd2 = std::min(l2, Ln - d1);
			        d2 < maxd2; ++d2)
				ret[d1 + d2] += n1[d1] * n2[d2];
		ret.corra();
		return ret;
	}
	TL V O += (N& s, A n1) 
	{ for (I d = 0; d < Ln; ++d) { s[d] += n1[d]; } s.corra(); }
	TL V O -= (N& s, A n1) 
	{ for (I d = 0; d < Ln; ++d) { s[d] -= n1[d]; } s.corra(); }
	TL V O *= (N& s, A n1) { s = s * n1; }

	TL N O +  (A n1, I i1) { N ret = n1; ret += i1; return ret; }
	TL N O -  (A n1, I i1) { N ret = n1; ret -= i1; return ret; }
	TL N O*  (A n1, I i1) { N ret = n1; ret *= i1; return ret; }
	TL V O += (N& s, I i1) { s[0] += i1; s.corrl(); }
	TL V O -= (N& s, I i1) { s[0] -= i1; s.corrl(); }
	TL V O *= (N& s, I i1)
	{ for (I d = 0; d < Ln; ++d) { s[d] *= i1; } s.corra(); }

	TL B O == (A n1, A n2) { return cmp(n1, n2) == 0; }
	TL B O <= (A n1, A n2) { return cmp(n1, n2) <= 0; }
	TL B O >= (A n1, A n2) { return cmp(n1, n2) >= 0; }
	TL B O != (A n1, A n2) { return cmp(n1, n2) != 0; }
	TL B O <  (A n1, A n2) { return cmp(n1, n2) <  0; }
	TL B O >  (A n1, A n2) { return cmp(n1, n2) >  0; }

	TL I N::getl() const
	{ for(I d = Ln; d > 0; --d) { if(s[d - 1]) { return d;}} return 0; }
	TL V N::corra() {
		I tmp;
		for (I d = 0; d < Ln; ++d) {
			if (s[d] >= D) {
				tmp = s[d] / D;
				if(d + 1 < Ln) { s[d + 1] += tmp; }
				s[d] -= tmp * D;
			}
			else if (s[d] < 0) {
				tmp = (-s[d] - 1) / D + 1;
				if(d + 1 < Ln) { s[d + 1] -= tmp; }
				s[d] += tmp * D;
			}
		}
	}
	TL V N::corrl() {
		I tmp;
		for (I d = 0; d < Ln; ++d) {
			if (s[d] >= D) {
				tmp = s[d] / D;
				if(d + 1 < Ln) { s[d + 1] += tmp; }
				s[d] -= tmp * D;
			}
			else if (s[d] < 0) {
				tmp = (-s[d] - 1) / D + 1;
				if(d + 1 < Ln) { s[d + 1] -= tmp; }
				s[d] += tmp * D;
			}
			else { break; }
		}
	}
	TL std::ostream& O << (std::ostream& f, A n1)
	{ f << static_cast<std::string>(n1); return f; }
	TL std::istream& O >> (std::istream& f, N& n1)
	{ std::string s; f >> s; n1 = s; return f; }
}
template<long long Ln> using BigInt0105 = bign0105::BigInt<Ln>;
#undef TL
#undef N
#undef A
#undef O
