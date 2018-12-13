* `char_to_value()` in **`name.hpp`**
  <details>
    <summary><b>Code - </b></summary>
  <p>

  ```cpp
  /**
   *  Converts a (eosio::name style) Base32 symbol into its corresponding value
   *
   *  @brief Converts a (eosio::name style) Base32 symbol into its corresponding value
   *  @param c - Character to be converted
   *  @return constexpr char - Converted value
   */
  static constexpr uint8_t char_to_value( char c ) {
     if( c == '.')
        return 0;
     else if( c >= '1' && c <= '5' )
        return (c - '1') + 1;
     else if( c >= 'a' && c <= 'z' )
        return (c - 'a') + 6;
     else
        eosio_assert( false, "character is not in allowed character set for names" );

     return 0; // control flow will never reach here; just added to suppress warning
  }
  ```
</p>
</details>

* `""_n` in **`name.hpp`**
  <details>
    <summary><b>Code - </b></summary>
  <p>

  ```cpp
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
