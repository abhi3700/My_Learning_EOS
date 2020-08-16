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
		
	[SOURCE](https://developers.eos.io/welcome/latest/getting-started/smart-contract-development/adding-inline-actions)
	
	#### Deferred transaction [DEPRECATED since eosio v2.0]
	- transaction has no guarantee for execution. It gets scheduled to run at `best time`, `later time`, `producer's discretion`. 
	- carries the authority of the contract that sends them.
	- generates notification about the success or failure.
		
	[SOURCE](https://developers.eos.io/manuals/eosio.cdt/latest/best-practices/deferred_transactions)

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
	- a `string` (of 56 bits i.e. a name upto 7 characters) as an input & an [optional] explicit `precision` (of 8 bits i.e. indicate the no. of decimal places.)
	- The symbol field has the symbol (name, precision) form. Its first 56 bits are reserved for the symbol name (name), which allows you to come up with a name of up to 7 characters. The last 8 bits describe the precision (precision) and indicate the number of decimal places. Example: the asset “123.1235 SYS” has symbol (SYS, 4). [Source](https://medium.com/@genesix/exchange-on-eosio-36e43a360398)
	- construct a `symbol` variable
```cpp
eosio::symbol usd("USD", 2);
eosio::symbol vt("VT", 5);
```

* #### EOSIO asset
	- represents `amount` with `symbol`
	- This data structure has the form of asset (amount, symbol), where both fields are uint64_t type. Let’s focus on each of them and start with the symbol. [Source](https://medium.com/@genesix/exchange-on-eosio-36e43a360398)
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
	- The amount field contains the number of assets, but no comma. For example, the number “123.1235” will be stored as “1231235”.
	- E.g. - “123.1235 SYS” will be stored as “1231235 (SYS, 4)” [Source](https://medium.com/@genesix/exchange-on-eosio-36e43a360398)
	
	- When multiplying, we have the risk of overflowing uint64_t, but the asset data structure has an overloaded `*=` operator that automatically performs an overflow check, freeing us from manual work.
	- When dividing a by b, if a < b, for example, a = 3.0, b = 30.0, the result will be 0.1, but since amount is an integer type, the answer will be 0. Therefore, we first explicitly convert amount to double and then bring it to the desired form. It is also necessary to remember that the result always depends on the symbol of the first argument, so for 3.0/30 the result will be 0.1, and for 3/30.0 will be 0.

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

* #### What does `require_auth (get_self())` do in EOS?

  Contracts inherit from eosio::contract, and, if we look in eosiolib/contract.hpp for the base class, we see that the constructor for eosio::contract is as follows:

```cpp
contract( name self, name first_receiver, datastream<const char*> ds ):_self(self),_first_receiver(first_receiver),_ds(ds) {}
```

  Therefore, the account that creates the contract and calls the constructor becomes `get_self()`. Thus, `require_auth(get_self())` ensures that the account executing the function has the authority of the account that created the contract.

* #### Does `[[eosio::on_notify("")]]` attribute only meant for payable actions?
	- no, anything which has require_recipient [Source](https://t.me/c/1139062279/228653)
	- but it is not recommended, better to use inline actions [Source](https://t.me/c/1139062279/228654)

* #### Can a table be instantiated with different scope & ram_payer in different action?
	- [x] `scope` [Source](https://t.me/c/1139062279/228749)
	- [ ] `ram_payer` #todo

* #### How to take the permission of the contract offchain in case of DApp (Android/ios), especially for inline actions, where `get_self()` needs contract's permission.

```cpp
void send_summary(name user, string memo) {
	action(
	    permission_level{get_self(), "active"_n},
	   get_self(),
	   "notify"_n,
	    std::make_tuple(user, memo)
	).send();
}
```
	- Soln: Just add `eosio.code` permission to the contract. [Source](https://t.me/c/1139062279/228752)
	- The same also works for setting `inline` action as well. [Source](https://t.me/c/1139062279/228754)

* #### What about RAM, CPU, NET consumption if the there are contract -to-contract communication when compared to communications within a contract?
	- Similar [Source](https://t.me/c/1139062279/228767)

* #### Can an inline action be fired from within a `[[eosio::on_notify("")]]` annotated function?
	- Yes [Source](https://t.me/c/1139062279/228771)

* #### Can i call a `[[eosio::on_notify("")]]` annotated function from within an action defined in the same contract?
	- Yes, ofcourse it is just a class function [Source](https://t.me/c/1139062279/228987). But not needed especially in case of payable actions.

* Does [this](https://hacken.io/research/education/3-ways-how-you-can-make-your-smart-contract-more-secure/) still hold for current version (eosio.cdt @v1.7.0) of EOSIO in `EOSIO_DISPATCH()`??
	- Yes, but not needed.
	- rather use `eosio::on_notify` annoted function for payable action. [Source](https://t.me/c/1139062279/228184)

* How to use `string` type as secondary index in multi-index table?
	- Yes, can be encoded as a `eosio::name` and store it in a `uint64_t`, but this limits you to the 12 character-style names for eosio accounts. [Source](https://eosio.stackexchange.com/a/3816/167)

* How to read table, defined in another contract?
	- define a table defined in `contracta` in `contractb`, but without `[[eosio::table]]` attribute
	- put the exact items.
	- instantiate the code, scope (same as defined) in table like this:
`table_index table("contracta"_n, "contracta"_n)`
	- [Source](https://eosio.stackexchange.com/a/70/167)

* I know how to read a contract_b's table data from within a contract_a's action. But in order to write to that called table, can i then modify after instantiating the contract_b table?	
	- only by sending an inline action to `contract b` and letting it modify its own table [Source](https://t.me/c/1139062279/228836)
	- Basically i have to create a action there & then a action_wrapper & call that action_wrapper in contract_a's action. [Source](https://t.me/c/1139062279/228840)

* How to ensure single auth?
	- `require_auth()`

* How to ensure multiple auth?
	- `has_auth()` All or Either
	- example
```cpp
check(has_auth(accounta) || has_auth(accountb), "missing required authority of accounta or accountb");
check(has_auth(accounta) && has_auth(accountb), "missing required authority of accounta & accountb");
```

* In a practical dApp, If I want to intimate the user of the action failure, shall I use inline action like send_receipt() for this case, or should I use print()?
	- Print is only a debugging tool. Not recommended for anything else [Source](https://t.me/c/1139062279/229828)

* Is there a working implementation of the eosio.msig contract using inline actions instead of deferred?
	- [EOSIO.Contracts v1.8.3 Inline Multi-Signature Release Notes · EOSIO/eosio.contracts
eosio.msig (#505)](https://github.com/EOSIO/eosio.contracts/releases/tag/v1.8.3-inline-msig)

* Difference b/w `circulating_supply`, `total_supply` & `max_supply`?
	- circulating supply ≤ total supply ≤ max supply
	- __circulating supply:__ total number of tokens that are circulating in the market and are available to be traded or used. 
		+ that means all tokens in total supply except those which are:
			- not circulating in the market, or
			- not available to be traded, or
			- not available to be used
		+ an example would be tokens that have been created but wont be released until they are mined. 
		+ another example would be tokens owned by a project team which aren’t liquid and cannot be sold.
	- __total supply:__ total number of tokens that have been created.
	- __max supply:__ total number of tokens that can ever be created.
	- circulating supply is the hard one. you can’t get it via an API and the very method of figuring it out is subjective and prone to errors. however circulating supply is the most common method for calculating cryptocurrency marketcap.
	- Example: here, __total_supply:__ `"1021502832.0568 EOS"`, __max_supply:__ `"10000000000.0000 EOS"`
```console
$ cleosm get table eosio.token EOS stat
{
  "rows": [{
      "supply": "1021502832.0568 EOS",
      "max_supply": "10000000000.0000 EOS",
      "issuer": "eosio"
    }
  ],
  "more": false,
  "next_key": ""
}
```
	- [Source](https://medium.com/@marketcapone/eos-token-supply-explained-whats-the-difference-between-circulating-supply-total-supply-and-max-e97d4931e7d4)

* What will happen after the EOS reach the max_supply i.e. 10 Billions?
```
$ cleosm get table eosio.token EOS stat
{
  "rows": [{
      "supply": "1021500842.4833 EOS",
      "max_supply": "10000000000.0000 EOS",
      "issuer": "eosio"
    }
  ],
  "more": false,
  "next_key": ""
}
```
	- i guess they would change the code to increase the max supply [Source](https://t.me/c/1139062279/231203)
	- i think we have about 10 years before that happens [Source](https://t.me/c/1139062279/231204)
	- by that time full resync will be impossible and everyone will forget how to change the code [Source](https://t.me/c/1139062279/231211)

* Where is the function defined for inflation of EOS token?
	- it is in the producer pay in the system contract, its not in the token contract because the system contract just issues more tokens [Source](https://t.me/c/1139062279/231212)

* Where & What code to add for controlling EOS Resources - __RAM__, __NET__, __CPU__?
	- __RAM__ --> taken of the param inside `emplace`, `modify` methods of multi_index table
	- Both __NET__ & __CPU__ --> used of the param inside `require_auth()`

* Which one is correct -> M-1 or M-2?
```cpp
static constexpr symbol token_symbol = symbol("TOE", 4);

// M-1
auto it = x_table.find(token_symbol.code().raw());

// M-2
auto it = x_table.find(token_symbol.raw());
```
	- Both are correct, but they have different meanings.
	- M-1: only symbol part 'TOE' encoded as integer
	- M-2: both components - symbol & precision, encoded as integer

* How can we control `[[eosio::on_notify("toe1111token::transfer")]]` based transfers to a contract for different purposes?
	- Based on @param `memo`, the different tasks (e.g. modifying different tables) for different purposes can be controlled. E.g. Follow the "toeridex::sendridex" action in my dApp -  __TOE__.   

* How to convert from checksum256 to string?
	- checksum256 is 32 bytes made up of 8 uint32_t chunks, so the solution would be something like iterating those chunks and building the string. [Source](https://github.com/MitchPierias/advanced-eos-examples/issues/13)
	- Use this custom templated function
```cpp
template<typename CharT>
static std::string to_hex(const CharT* d, uint32_t s) {
  std::string r;
  const char* to_hex="0123456789abcdef";
  uint8_t* c = (uint8_t*)d;
  for( uint32_t i = 0; i < s; ++i ) {
    (r += to_hex[(c[i] >> 4)]) += to_hex[(c[i] & 0x0f)];
  }
  return r;
}
```
	- Example to use:
```cpp
std::string data = "hello";
const char * data_str_c = data.c_str(); 
auto hash_digest = sha256(data_str_c, strlen(data_str_c));

string hash_digest_str = to_hex(&hash_digest, sizeof(hash_digest));
print(hash_digest_str);
// 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824
```

* How many inline actions can be put into an action? Is there any limit to it?
	- There is no limit other then cpu. [Source](https://t.me/c/1139062279/233099)
	- Okay!...is it possible that some part of action is added in different block?
		+ No they are atomic in the same transaction [Source](https://t.me/c/1139062279/233103)
	- So, that means: Right??
		- The inline actions along with the main action will be passed into the same block.
		- If anything like (diff. block addition) happens, then CPU limit error will be shown

	- Yeah if the total transaction time exceeds the max allowed transaction time or max allowed cpu consumption then the full transaction will roll back and you receive an error

* How many levels deep inline actions can be ? (inline action calling other inline action)
```
|
---|
-------|
-----------|
---------------|
-------------------|
```
	- 6 [Source](https://t.me/c/1139062279/233113)
	- that’s it. one action makes an inline action, that’s one level deep. if then the second action makes a new inline action, that’s two levels deep [Source](https://t.me/c/1139062279/233112)

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