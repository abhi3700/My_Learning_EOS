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

* #### EOSIO Transaction
	* it can have multiple actions like, `create` & `notify` happening sequentially.
	* Possibly one action, and for most of the cleos commands this will be only one, but N actions can comprise a transaction.
	* The transaction also contains the set of authorizations that authorized it.


* #### EOSIO name
	- `"foo"_n` is a shortcut for `name{"foo"}` since eosio.cdt 1.3.x
	- a `string` with 64 bit i.e. `uint64_t` variable,
	- max. allowed size = 12
	- chars: `abcdefghijlmnopqrstuvxyz.12345`
	- These are used for 
		+ account names, 
		+ permission names, 
		+ action names, 
		+ table names,
		+ notification handler names, and 
		+ secondary index names.
	- valid names examples: `eosio`, `name`, `bob`, `alice`, `bob15`, `b.ob34` , `cabeos1user1`
	- invalid names examples: `Eosio`, `nAme`, `0bob`, `alicealicealic`
	- construct a `name` variable
```cpp
// M-1
eosio::name account(“bob”);

// M-2
auto account = "bob"_n;
```

* #### EOSIO symbol
	- a `string` as an input & an [optional] explicit `precision`
	- construct a `symbol` variable
```cpp
eosio::symbol usd("USD", 2);
eosio::symbol vt("VT", 5);
```

* #### EOSIO asset
	- represents `amount` with `symbol`
	- So this would be used to create “tokens” and the like, and ensure that calculations and modifications on the asset are done with either scalar values or the same type of symbol.
	- construct a `asset` variable
```cpp
eosio::symbol usd("USD", 2);
eosio::asset my_money(40, usd);
eosio::asset your_money(1000, {"VT", 2});
my_money += your_money		// FAIL
eosio::asset new_token(1000000000, "EOS");
eosio::asset amount1(1000, "EOS");
eosio::asset amount2(500, "EOS");
amount1 += amount2;
print("amount1: ", amount1.amount);			// 1500
```

* #### EOSIO check
	- The eosio::check functions allow you to check whether a predicate is true and assert and halt if it is false. 
	- These are given the predicate and an assertion message if the failure occurs.
	- construct a `check` variable
```cpp
eosio::check("1==1", "unequal no.");
bool definitely_true = false;
eosio::check(definitely_true, "Something bad happened!");
```

* #### EOSIO action
	- This houses our abstractions for an eosio action.
	- Something like this:
```cpp
using transfer_act = eosio::action_wrapper<"transfer"_n, &cabeostoken::transfer>;
transfer_act transfer("cabeostoken"_n, {get_self(), "active"_n});
transfer.send("cabeos1user1"_n, "cabeos1user2"_n, 400);
``` 

* ### What does `require_auth (get_self())` do in EOS?

  Contracts inherit from eosio::contract, and, if we look in eosiolib/contract.hpp for the base class, we see that the constructor for eosio::contract is as follows:

```cpp
contract( name self, name first_receiver, datastream<const char*> ds ):_self(self),_first_receiver(first_receiver),_ds(ds) {}
```

  Therefore, the account that creates the contract and calls the constructor becomes `get_self()`. Thus, `require_auth(get_self())` ensures that the account executing the function has the authority of the account that created the contract.

* ### Does `[[eosio::on_notify("")]]` attribute only meant for payable actions?
	- no, anything which has require_recipient [Source](https://t.me/c/1139062279/228653)
	- but it is not recommended, better to use inline actions [Source](https://t.me/c/1139062279/228654)

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

* WASM
	- WebAssembly is a platform agnostic assembly language that emphasizes determinism, simplicity and security. 
	- `nodeos` uses WASM as the smart contract language that is executed. 
	- The developer does not need to implement smart contracts in WebAssembly, a toolchain is provided to compile smart contract written in C++ to this binary format.


## since [eosio.contracts v1.9.1](https://github.com/EOSIO/eosio.contracts/releases/tag/v1.9.1) | [eosio.cdt v1.7.x](https://github.com/EOSIO/eosio.cdt/releases/tag/v1.7.0) | [eosio v2.0.x](https://github.com/EOSIO/eos/releases/tag/v2.0.1)

### NOTES
#### EOSIO Basics
* EOSIO is an emerging smart contract architecture that allows application developers to create and deploy decentralized applications that record and manipulate application data using a blockchain, a distributed, immutable, append-only ledger.
* URLs
	- [current guide](https://developers.eos.io/eosio-home/docs)
	- [SmartContract API](https://eosio.github.io/eosio.cdt/latest/modules)
	- [Developer Portal](https://developers.eos.io/)

#### Execution Model
* A C++ class with an annotation `[[eosio::contract("contractname")]]` represents a smart contract with the name `contractname`. 
* Smart contracts execute in bursts called transactions, which are triggered when actions are sent to a smart contract by a client. A transaction may include one or more actions.
* A transaction begins by creating a (transient) instance of a smart contract C++ class, which involves execution of its constructor. The initial dispatched action is then matched to an annotated method of the smart contract class (using an [[eosio::action]] annotation), which is then invoked with the client's arguments.
* Each smart contract has an ABI description that describes the names of the actions it exports along with, for each action, the number and types of the arguments the corresponding method expects.

* EOSIO transactions share 2 of the 4 so-called [ACID](https://en.wikipedia.org/wiki/ACID) properties of traditional transactions: __Atomicity__ and __Isolation__. __Atomicity__ means that any changes to persistent state either occur in their entirety or not at all. __Isolation__ means that multiple transactions cannot interfere with each other even if they refer to the same state. EOSIO transactions do not guarantee __Consistency__ or __Durability__. Providing consistency is the responsibility of the smart contract developer, and durability will be achieved indirectly when a transaction's results are eventually confirmed by the multiple nodes on the blockchain that have replicated the action and have arrived at a distributed consensus regarding its outcome.
	
	> Summary:

	> - __Atomicity__: Execute all or none. Basically, if one of the actions (in a txn) fails, it will not execute. <br/>
			E.g. T1 transfers 10 from A to B: (1. subtracts 10 from A; 2. adds 10 from B ), So, 2 actions, 1 txn.

	> - __Isolation__: No interference b/w txns. Basically, Out of 2 txns (T1, T2), T2 will not interfere in T1. <br/>
			E.g. Consider two transactions: T1 transfers 10 from A to B. T2 transfers 20 from B to A. <br/>
			Combined, there are four actions: <br/>
			- T1 subtracts 10 from A. <br/>
			- T1 adds 10 to B. <br/>
			- T2 subtracts 20 from B. <br/>
			- T2 adds 20 to A. <br/>
			For more, refer to "Isolation failure" section from [here](https://en.wikipedia.org/wiki/ACID)

	> __Consistency__: responsibility of a SC developer.

	> __Durability__: responsibility of Blockchain nodes (mutual agreement i.e. achieving consensus)

* Actions may trigger another actions
	- inline actions are synchronous & become part of the current transaction.
	- deferred actions are asynchronous & may be executed in a later transaction.
* Between transactions, no state is kept other than what is stored in dedicated, persistent tables (multi-index tables).

#### Storage Model - Multi-Index Tables
* Since instances of smart contract classes are transiently instantiated only for the duration of one transaction, EOSIO's blockchain-backed database must be used to store any data that is to persist across transactions. In terms of programming model, it's not possible to store data in instance fields or static fields or even other global variables.
* EOS uses Boost's multi-index container data type.
* A multi-index table stores serializable objects whose struct definition is annotated with `[[eosio::table]]`.
* For efficient lookup, and to ensure uniqueness, each object is required to provide:
	- a primary key (which must be unique),
	- and may provide up to 16 secondary keys which must be ordered, but don't have to be necessarily unique.
* 


## References
* [EOSIO Smart Contract Database Walkthrough](https://blog.csdn.net/yunqishequ1/article/details/80362507)
* [Utility](https://github.com/abhi3700/My_Learning_EOS/blob/master/Programming/utillity/README.md)
* [EOSIO notes by University](https://cpp.cs.cloud.vt.edu/docs-blockchain-eosio-eosio)