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
