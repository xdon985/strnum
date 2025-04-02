# 高精度整数

# 1.04

`BigInt` 的构造函数:
- ()
- (string const&)
- (char const*)

实现的运算符： 

- `BigInt` 和 `signed long long`: `+ - * += -= *= [] [](const)`
- `BigInt` 和 `BigInt`: `+ - * += -= *=`
- `std::istream` 和 `BigInt`: `>>`
- `std::ostream` 和 `BigInt`: `<<`

实现的转换: `BigInt` 到 `std::string`

Debug 未完成.

# 1.05

`BigInt<signed long long Length>` 和 1.04 中的 BigInt 基本相同.

- BigInt<>().corra()
- BigInt<>().corrl()
- BigInt<>().getl() -> signed long long

TBD.
