## Differences between Version 1.2.x and Version 1.3.x

### eosiolib C API
- Removed the following typedefs to `uint64_t`:
  - `account_name`
  - `permission_name`
  - `scope_name`
  - `table_name`
  - `action_name`
- Added a `uint64_t` typedef called `capi_name` to replace the removed typedefs above:
    - These have been replaced by `capi_name` and as a practice should not be used when writing C++ contract code. Instead, the new version of the `eosio::name` type from the eosiolib C++ API should be used to replace these instances. This decision was made because of bad implicit casting issues with `uint64_t` and the new pattern should allow for better type safety.
- Removed `symbol_name` typedef:
    - This has no C equivalent to replace it. When writing C++ contract code, the `eosio::symbol_code` struct should be used instead. As with the previously mentioned named types, this was removed and replaced with `eosio::symbol_code` to allow for better type safety in contracts.  To use a symbol, i.e. symbol name and precision, use the `eosio::symbol` class.
- Removed `time` and `weight_type` typedefs.
- Removed the `transaction_id_type` and `block_id_type` typedefs.
- Removed the `account_permission` struct.
- Renamed the following typedefs:
  - `checksum160` -> `capi_checksum160`
  - `checksum256` -> `capi_checksum256`
  - `checksum512` -> `capi_checksum512`
  - `public_key`  -> `capi_public_key`
  - `signature`   -> `capi_signature`
- Removed the non-existent intrinsics declarations `require_write_lock` and `require_read_lock`.

### eosiolib C++ API
- Removed eosiolib/vector.hpp:
  - Removed alias `eosio::vector` and typedef `bytes`.
  - Going forward contract writers should include `<vector>` from the STL and use `std::vector<char>` instead of bytes.
- Removed eosiolib/types.hpp.
- Removed eosiolib/optional.hpp. Use `std::optional` as a replacement.
- Removed eosiolib/core_symbol.hpp. The contract writer should explicitly specify the symbol.
- Added eosiolib/name.hpp.

#### eosiolib/types.hpp
- Moved the typedef `eosio::extensions_types` to eosiolib/transaction.hpp.
- Removed comparison functions for `checksum` structs.
- Removal of `eosio::char_to_symbol`, `eosio::string_to_name`, `eosio::name_suffix` functions
- Removal of the `N` macro. The `""_n` operator or the `name` constructor should be used as a type safe replacement. Example: `N(foo)` -> `"foo"_n`, or `N(foo)` -> `name("foo")`.
- Moved `eosio::name` struct definition and `""_n` operator to eosiolib/name.hpp.

#### eosiolib/name.hpp
- Removed implicit and explicit conversions to `uint64_t`.
- Added `enum class` `eosio::name::raw` which is implicitly converted from an `eosio::name` (used for template non-type parameters).
- Added `bool` conversion operator for conditionally testing if a name is empty.
- All constructors are now `constexpr`. These take either a `uint64_t`, an `eosio::name::raw` or a `std::string_view`.
- Added `constexpr` methods `eosio::name::length` and `eosio::name::suffix`.
- Added equivalence, inverted equivalence and less than operators to `eosio::name`.

#### eosiolib/symbol.hpp
- Removed `eosio::symbol_type` struct and replaced with `eosio::symbol` class.
- Added struct `eosio::symbol_code`:
  - Added two `constexpr` constructors that take either a raw `uint64_t` or an `std::string_view`.
  - Added `constexpr` methods `is_valid`, `length` and `raw`.
  - Added a print method.
  - Added `bool` conversion operator to test is `symbol_code` is empty.
- Removed `eosio::string_to_symbol`, `eosio::is_valid_symbol`, `eosio::symbol_name_length` functions.
- Removed the `S` macro. The symbol constructor should be used as a type safe replacement. Example: `S(4,SYS)` -> `symbol(symbol_code("SYS"), 4)` (or simply `symbol("SYS", 4)` as of v1.3.1).
- Added struct `eosio::symbol`:
  - Added three `constexpr` constructors that take either a raw `uint64_t`, `symbol_code` and a `uint8_t` precision or an `std::string_view` and a `uint8_t` precision.
  - Added `constexpr` methods `is_valid`, `precision`, `code`, and `raw`. These, respectively, check if the `symbol` is valid, get the `uint8_t` precision, get the `symbol_code` part of the `symbol`, and get the raw `uint64_t` representation of `symbol`.
  - Added equivalence, inverted equivalence and less than operators to `eosio::symbol`.
- Modified struct `eosio::extended_symbol`:
  - Restricted fields to private.
  - Added `constexpr` constructor that takes a `eosio::symbol` and an `eosio::name`.
  - Added `constexpr` methods `get_symbol` and `get_contract`.
  - Made existing comparison operators `constexpr`.

#### eosiolib/asset.hpp
- The main constructor now requires a `int64_t` (quantity) and `eosio::symbol` explicitly.
- The default constructor no longer initializes the instance to a valid zero quantity asset with a symbol equivalent to "core symbol". Instead the default constructed `eosio::asset` is a bit representation of all zeros (which will cause `is_valid` to fail) so that check is bypassed to allow for `multi_index` and `datastream` to work.
- Old contracts that use `eosio::asset()` should be changed to either use the core symbol of the specific chain they are targeting i.e. `eosio::asset(0, symbol(symbol_code("SYS"),4))`. To reduce writing `symbol(symbol_code("SYS"),4)` over and over, a `constexpr` function to return the symbol or `constexpr` global variable should be used.

#### eosiolib/contract.hpp
- The constructor for `eosio::contract` now takes an `eosio::name` for the receiver, an `eosio::name` for the code, and a `eosio::datastream<const char*>` for the datastream used for the contract.  The last argument is for manually unpacking an action, see the section on `eosio::ignore` for a more indepth usage.

#### eosiolib/dispatcher.hpp
- Renamed the macro `EOSIO_ABI` to `EOSIO_DISPATCH` as this is more descriptive of what this macro actually does.
- Modified the definition of `EOSIO_DISPATCH` to work with the new constructor for `eosio::contract`.

#### eosiolib/multi_index.hpp
- The first template parameter for `indexed_by` now requires the argument be convertible to `eosio::name::raw` (replacing `uint64_t`).
- The first template parameter for `multi_index` now requires the argument be convertible to `eosio::name::raw` (replacing `uint64_t`).
- The constructor now takes an `eosio::name` type for the code (replacing `uint64_t`). Scope is still `uint64_t`.
- Various other replacements of `uint64_t` to `eosio::name`.

#### eosiolib/singleton.hpp
- The first template parameter for `eosio::singleton` now requires the argument be convertible to `eosio::name::raw` (replacing `uint64_t`).
- The constructor now takes an `eosio::name` type for the code.
- In the methods `get_or_create` and `set`, the argument `bill_to_account` is now of type `eosio::name` (replacing `uint64_t`).

#### eosiolib/action.hpp
- Added C++ function `eosio::require_auth`.
- Added C++ function `eosio::has_auth`.
- Added C++ function `eosio::is_account`.
- Redefined `eosio::permission_level` to use `eosio::name` in place of `uint64_t`.
- Removed the macro `ACTION`. (The identifier `ACTION` has been reused for another macro described below in the Macros section.)

#### eosiolib/permission.hpp
 - The optional provided_keys argument of the function `eosio::check_transaction_authorization` is now of the type `std::set<eosio::public_key>` rather than the type `std::set<capi_public_key>`. C++ contract code should most likely be using the `eosio::public_key` struct (defined in "eosiolib/public_key.hpp") if they need to deal with EOSIO-compatible public keys rather than the `capi_public_key` struct (now renamed from its original name of `::public_key`) from the eosiolib C API. Note that existing contract code that just referred to the type `public_key` without namespace qualification may have accidentally been using the `capi_public_key` struct and therefore should ideally be modified to use the `eosio::public_key` C++ type.
 - The `account` and `permission` arguments of `eosio::check_transaction_authorization` are both `eosio::name` now instead of `uint64_t`.

#### eosiolib/ignore.hpp
- Added new type `ignore`:
  - This type acts as a placeholder for actions that don't want to deserialize their fields but want the types to be reflected in the ABI.
    ```c
    ACTION action(ignore<some_type>) { some_type st; _ds >> st; }
    ```
- Added new type `ignore_wrapper`:
  - This allows for calling `SEND_INLINE_ACTION` with `ignore_wrapper(some_value)` against an action with an `ignore` of matching types.

### Macros
- Added `ACTION` macro which is simply a shortcut for `[[eosio::action]] void`.
- Added `TABLE` macro which is simply a shortcut for `struct [[eosio::table]]`.
- Added `CONTRACT` macro which is simply a shortcut for `class [[eosio::contract]]`.

### CMake
- Added `eosio.cdt-config.cmake` to allow for `find_package(eosio.cdt)`. See eosio.cdt/examples/hello or eosio.cdt/examples/template for an example.
- Added new macro `add_contract`. This new contract takes a contract name, cmake target, then any normal arguments you would give to `add_executable`. See eosio.cdt/examples/hello or eosio.cdt/examples/template.
- New version checking mechanism is included. See eosio.contracts/CMakeLists.txt to see this in use.

### libc
- Replaced `printf`, `sprintf`, and `snprintf` with new minimal variants. This allows contracts to use these functions without causing stack overflow issues.

### libcxx
- Removed `sstream` with the intent to return this after more has been done.
- Added `__cxa_pure_virtual` to allow for pure virtual methods in contract classes.
- `std::to_string` now works without the issues of stack overflows.

### attributes
- Added `[[eosio::ignore]]` attribute to flag a type as being ignored by the deserializer. This attribute is primarily only used for internal use within eosiolib.
- Added `[[eosio::contract]]` attribute. This new attribute is used to mark a contract class as "contract" with the name being either the C++ name of the class or a user specified name (i.e. `[[eosio::contract("somecontract")]]`). This attribute can also be used in conjunction with the `eosio::action` and `eosio::table` attributes for tables that you would like to define outside of the `eosio::contract` class.  This is used in conjunction with either the raw `eosio-cpp` option `--contract <name>`, `-o <name>.wasm` or with CMake `add_contract`.  It acts as a filter enabling contract developers to include a header file with attributes from another contract (e.g. eosio.token) while generating an ABI devoid of those actions and tables.
  ```c++
  #include <eosiolib/eosio.hpp>
  using namespace eosio;
  CONTRACT test : public eosio::contract {
  public:
     using contract::contract;
     ACTION acta(){}
     TABLE taba {
        uint64_t a;
        float b;
        uint64_t primary_key() const { return a; }
     };
  };
  struct [[eosio::table, eosio::contract("test")]]
  tabb {
     uint64_t a;
     int b;
  };
  typedef eosio::multi_index<"testtaba"_n, test::taba> table_a;
  typedef eosio::multi_index<"testtabb"_n, tabb> table_b;
  EOSIO_DISPATCH( test, (acta) )
  ```
  The above code will produce the tables `testtaba` and `testtabb` in your ABI. Example: `eosio-cpp -abigen test.cpp -o test.wasm` will mark this compilation and ABI generation for the `eosio::contract` `test`. The same thing can be done with `eosio-cpp -abigen test.cpp -o test_contract.wasm --contract test` or with the CMake command `add_contract( test, test_contract, test.cpp )`. Either of the previous two approaches will produce a test_contract.wasm and test_contract.abi generated under the context of the contract name of `test`.

### Boost
- Boost is now part of the library. No more external dependence on Boost and all system inclusion are within it's `sysroot`. (Boost will be removed in a future release.)

## References
* https://github.com/EOSIO/eosio.cdt/blob/master/README.md
