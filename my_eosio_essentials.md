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
	- The `emplace function` takes two arguments: 
		+ one payer, and 
		+ one lamada expression. 
		
	This structure is fixed.
	- 


## References
* EOSIO Smart Contract Database Walkthrough - https://blog.csdn.net/yunqishequ1/article/details/80362507



