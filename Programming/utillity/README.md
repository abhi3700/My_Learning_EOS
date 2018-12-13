* [char_to_value()](https://github.com/abhi3700/My_Learning_EOS/blob/master/Programming/utillity/char_to_value.cpp) in `name.hpp`
* name literal operator
<details>
  <summary><b>Code - </b></summary>
<p>
```
/**
 * name literal operator
 *
 * @brief "foo"_n is a shortcut for name{"foo"}
 */
template <typename T, T... Str>
inline constexpr eosio::name operator""_n() {
   constexpr auto x = eosio::name{std::string_view{eosio::detail::to_const_char_arr<Str...>::value, sizeof...(Str)}};
   return x;
}
```
</p>
</details>
