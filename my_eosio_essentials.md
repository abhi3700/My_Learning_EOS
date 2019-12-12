* ### ABI comments
|Types | v1.1.x or less | v1.2.x | v1.3.x or more |
|:----:|:--------------:|:------:|:--------------:|
| Contract | `class` | `class [[eosio::contract]]` | `CONTRACT` |
| Action | `//@abi action` | `[[eosio::action]] void` | `ACTION` |
| Table | `//@abi table` | `struct [[eosio::table]]` | `TABLE` |
| Dispatch | `EOSIO_ABI()` | `EOSIO_ABI()` | `EOSIO_DISPATCH()` |	
	

* ### Code comments
	- Use the [DoxyDoc](https://packagecontrol.io/packages/DoxyDoc) package in ST3 for multi-line comments. <br/>
	// @param balance - the quantity to be sent to a person.

	E.g.
	```cpp
	/**
	 * Subtraction operator
	 *
	 * @brief Subtraction operator
	 * @param a - The asset to be subtracted
	 * @param b - The asset used to subtract
	 * @return asset - New asset as the result of subtraction of a with b
	 */
	inline friend asset operator-( const asset& a, const asset& b ) {
		 asset result = a;
		 result -= b;
		 return result;
	}
	```
	
	- In the `.hpp` file, add this comment `namespace eosio` in the end:
		```cpp
		namespace eosio {
			// class body
		} /// namespace eosio
		```

* ### Action vs Transaction
	**Transaction** - record of actions.<br/>
  **Action** - behavior of contracts. E.g. - functions like create(), transfer(), etc.
    
  #### NOTE: A Smart Contract can have one or more action.

* ### Inline vs Deferred
	#### Inline:
	- action guaranteed to execute with the current transaction.
	- No notification about the success or failure.
		
	[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-inline-communication)
	
	#### Deferred:
	- action has no guarantee for execution. It gets scheduled to run at `best time`, `later time`, `producer's discretion`. 
	- carries the authority of the contract that sends them.
	- generates notification about the success or failure.
		
	[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-deferred-communication)

* ### Understanding the `eosio.token` contract
* ### Understanding the **Table** usage over EOS
* Try using most of the namespaces in `.hpp` file.
	- `using namespace eosio`
	- `using namespace std::string`

* For your own project, create your own namespaces:
	- `namespace drife`
	- `namespace oasis`
* resource ownership of an account:
	- res. ownership status is stored in `resource_limits` object of account.
	- res. usage is stored in `resource_usage` object of account.
	- 

	[Source](https://blog.csdn.net/itleaks/article/details/80743836)
* #### Understanding EOS multi-index table
	- data can be modified while stored on the RAM.
	- New content often uses `emplace` constructors to add database objects.
	- Define the database object, where 
		+ the first parameter is the owner of the contract `_self`, 
		+ the second variable is the database `payer`, that is, who the database is, and under which account the database is stored.
	<br/>**Code snippet:**
	```cpp
	void test_da::create(account_name user, string title, string content) {
			require_auth( user ); // Verify permissions
			das datable( _self, user);　// Defining database objects
			datable.emplace(user, [&]( da & d){
					d.title = title;
					d.content = content;
					d.post_id = datable.primary_key();
					d.poster = user;
			});　//Database content creation
	}
	```
	- The `emplace function` takes two arguments: 
		+ one payer, and 
		+ one lamada expression. <br/>
		This structure is fixed.
	- All smart contracts are inherited from `contract` file added in the `eosio.hpp`.
	```cpp
	.....
		/// @abi table data i64
		struct da
		{
			uint64_t post_id;
			account_name poster;
			string title;
			string content;	

			uint64_t primary_key() const { return post_id; }
			account_name get_poster() const { return poster; }	

			EOSLIB_SERIALIZE( da, (post_id) (poster) (title) (content));
		};	

		typedef multi_index<N(data), da, indexed_by<N(byposter), const_mem_fun<da, account_name, &da::get_poster>>> das;	
	.....
	```
	- Here, we define the data structure `da`
	- `primary_key()` defines the primary key.
	- Next, we define the auxiliary primary key - poster.
	- `EOSLIB_SERIALIZE`: A macro
		+ 1st param - data structure.
		+ other params - data members.
	- `typedef`: a multi_index container definition. Here, we define a database object with a primary key and secondary key.
	- ABI file is imp and the wrong one will cause the contract to fail.

* #### `str()`
	`str()` (exclusively defined for C++ only) function is not acceptable in eos contract programming because not defined. So, use as `title.c_str()`, `content.c_str()`. Otherwise, it willl give compilation error.

* #### action name
	It cannot be like this - `create_com` rather, `createcom`. Basically, don't use underscore (_) symbol.
	
* ### sending an instruction to other contract
	Use this 
	```
	action(
		permission_level{_self,N(active)},
		N(eosio.token),N(transfer),
		std::make_tuple(_self,which->player,price,"payment from buyer")
	).send();
	```
	instead of

	```
	action(
		permission_level{_self,N(active)},
		N(eosio.token),N(transfer),
		std::make_tuple(_self,which->player,price,std::string("payment from buyer"))
	).send();
	```
	
	**REASON:** This is not a bug per se, it is a limitation of make_tuple. The types const char* and std::string are not the same, so make_tuple will treat the const char* as a pointer and will send over that (which is garbage), and the type of the memo field is expecting an std::string, so explicit construction of std::string is needed to make std::make_tuple do the right thing.
	
	[Source](https://github.com/EOSIO/eos/issues/4394)

* ### name
	`"foo"_n` is a shortcut for `name{"foo"}` since eosio.cdt 1.3.x

* ### What does `require_auth (_self)` do in EOS?

  Contracts inherit from eosio::contract, and, if we look in eosiolib/contract.hpp for the base class, we see that the constructor for eosio::contract is as follows:

  `contract( account_name n ):_self(n){}`
  
  Therefore, the account that creates the contract and calls the constructor becomes `_self`. Thus, `require_auth(_self)` ensures that the account executing the function has the authority of the account that created the contract.

* List of available datatypes for action parameter [Source](https://eosio.stackexchange.com/questions/1837/list-of-available-datatypes-for-action-parameter/1932#1932)
```cpp
bool
int8
uint8
int16
uint16
int32
uint32
int64
uint64
int128
uint128
varuint32
varint32
float32
float64
float128
time_point
time_point_sec
block_timestamp_type
name
bytes
string
checksum160
checksum256
checksum512
public_key
private_key
signature
symbol
symbol_code
asset
```
## References
* [EOSIO Smart Contract Database Walkthrough](https://blog.csdn.net/yunqishequ1/article/details/80362507)
* [Utility](https://github.com/abhi3700/My_Learning_EOS/blob/master/Programming/utillity/README.md)



