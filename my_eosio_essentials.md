* ### ABI comments
	**Action** - Write above the method `/// @abi action [method_name]` <br/>
	**Table** - Write above the struct `/// @abi table [primary_key_type]`
	

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
	
	
## References
* [EOSIO Smart Contract Database Walkthrough](https://blog.csdn.net/yunqishequ1/article/details/80362507)



