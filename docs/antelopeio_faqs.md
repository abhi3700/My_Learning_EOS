# FAQs

#### Q: What if BPs pay people to vote for them?

#### A:

In EOS, the no. of votes getting count also depends on new/old votes. This is done every 6 months. That is after this period it becomes old.
So, now the BPs shall have to raise the awareness everytime to EOS users for staying in the top 21 BPs and 100 SPs.

#### Q: What else the BPs and SPs can do other than just recording the Blockchain data?

#### A:

They can volunteerly educate the people about EOS or decentralisation. This will make them more competent in the EOS producer candidate list.

#### Q. Will the EOS BPs number be 21 for lifetime? Can't we configure in the future if required?

#### A.

Yes, it can be done. But min. 5 nodes needed for any entity wanting to use EOSIO software for creating their own Blockchain.

The default number is 21, however in the latest (in Jan 2018) development update, they confirmed it would be dynamic/configurable.

#### Q. Is EOS Smart Contracts (SCs) upgradeable?

#### A.

Yes. Unlike Ethereum, EOS contracts are upgradeable.

Hence, **Code is NOT the law.**

#### Q. Can EOS transaction be reversible like other major blockchains?

#### A.

Yes.

But, it is possible through arbitration. In future, for dApps' good functioning, one has to hire **competent arbitrators** for getting any form of transaction (money, asset, so on...) back.

#### Q. EOS key terms?

#### A.

**Block** - group of transactions.<br/>
**Transaction** - record of actions.<br/>
**Action** - behavior of contracts. E.g. - functions like create(), transfer(), etc.

> NOTE: A Smart Contract can have one or more action.

#### Q. What do I lose by staking my EOS tokens?

#### A.

Nothing in terms of `no. of tokens`. E.g. If you stake 3 EOS, will get exactly 3 EOS after unstaking.

One only makes a loss of inflation (increase, decrease, neutral) only. <br/>
**Explaination:** 3 cases are possible.

- **Profit:** - value of EOS during unstake > stake
- **Loss:** - value of EOS during unstake < stake
- **Neutral:** - value of EOS during unstake = stake

[SOURCE](https://eosio.stackexchange.com/questions/824/can-i-stake-back-my-bandwidth-without-cost)

#### Q. How to vote for BP using cleos?

#### A.

[SOURCE](https://eosio.stackexchange.com/questions/725/how-to-vote-using-cleos)

#### Q. In EOS, why 21 BPs?

#### A.

**Reasons**: <br>

- odd no. - to have 66% i.e. `2/3 + 1` i.e. `(14+1) = 15`. So, 15 BPs consent is required for agreement on any decision.
- voting required to maintain irreversibility of EOS blockchain => lesser nodes, the better speed.

  So, 21 is a optimized no.

  > NOTE: initially, Bitshares had nearly `100+` BPs. So, the Block time used to be higher. Now, it is in seconds.

- If more nodes involved, then synchronization would be difficult i.e. ir-reversibility would be maintained with higher block time => less scalable.

  Like in Bitcoin, Ethereum (PoW-based tokens), the irreversibility is maintained using computing power. So, energy can't be recreated. But in EOS, the irreversibility is maintained using voting. For this, the above reasons has to be followed.

#### Q. How much time for getting back my tokens after unstake?

#### A.

3 days.

#### Q. What would happen to my data (on EOS blockchain) if the required tokens condition not met or all the tokens are unstaked?

#### A.

Correspondingly, the data will also be deleted.

#### Q. Once BPs (Active + Standby) get selected through voting, is that list permanent?

#### A.

Actually, No.

Because every week the voting decays by 1%. So, if someone wants its BPs to stand in the list, then one needs to revote (in the same way as previous).

**[Video link](https://www.youtube.com/watch?v=v9h4u1xUASw)**

#### Q. Why 30 stake weighted voting?

#### A.

<!-- TODO: -->

[Article by Thomas Cox](https://medium.com/@thomas.cox_39839/why-30-stake-weighted-approval-votes-for-eosio-1402b994bf20)

#### Q. Difference b/w Active key and Owner key?

#### A.

**Active key** - transfer EOS, vote, stake or unstake, and purchase RAM.

**Owner key** - you can change both the active key and the owner key of any account.

For changing the owner key, link - https://www.youtube.com/watch?v=nyyE05qFc78

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_owner_vs%20_active_key.jpg" width="300" height="290">
</p>

#### Q. Can eos account names be > 12 characters?

#### A.

Yes. To get a premium name, it has to be auctioned on the mainnet.

A/c names like `eosio`, `b1` (created during bios contract at boot time)

#### Q. How to import your existing EOS wallet (already created on Mainnet) into local PC/laptop?

Follow these 2 steps:

1. Edit the "config.ini" file in eosio-wallet in directory - `"/home/pc-name/eosio-wallet"` on Linux OS. <br/>
   change the
   `http-server-address = localhost:8080`
2. Create the wallet locally as mentioned in the source-link <br/>
   `cleos wallet create -n <NAME_OF_WALLET_HERE>` <br/>
   `cleos wallet import <ONWER_PRIVATE_KEY> -n <NAME_OF_WALLET_HERE>` <br/>
   `cleos wallet import <ACTIVE_PRIVATE_KEY> -n <NAME_OF_WALLET_HERE>`

[**SOURCE**](https://eosio.stackexchange.com/questions/1363/wallet-essentials-for-importing-your-existing-eos-wallet)

> NOTE: The password generated is the encryption key for the wallet. I believe keosd makes wallets with .wallet file name. This your_wallet.wallet file name is the encrypted file that your password decrypts.

> **Instruction:**
>
> - Don't connect to an API when dealing with private keys. (RECOMMENDED)
> - NEVER use `cleos --wallet-url`, otherwise it might get sussceptible for your private key getting leaked.

Basically, `--wallet-url` is dangerous.
as mentioned by @michaelyeates, @nsjames in EOS Developer Telegram channel.

#### Q. What do you mean by proxy-voting?

#### A.

    It is basically delegating your voting right to someone.
    If you do this, then you are representing that person to vote 30 BPs on your behalf. Another way - That person votes whoever will be the 30 votes for you as well.

#### Q. Is it possible to run the REST API data onto EOS Smart contract?

#### A.

It is not possible to directly have any communication with the C++ contracts with the HTTP API. Instead try to run through [EOSJS](https://github.com/EOSIO/eosjs) and display on web.

**Sources**:

- From Telegram group **ITAM Network** (group of EOS devs)
  > If you are asking about smart contracts, it's not possible to run outside APIs on C++ smart contract. You can probably use outside APIs like general node projects with eosjs circumstances.
- By Daniel larimer - https://github.com/EOSIO/eos/issues/1483#issuecomment-391930967

#### Q. How to query the EOS database?

#### A.

[SOURCE](https://eosio.stackexchange.com/questions/279/does-eos-db-support-text-based-queries)

#### Q. Are Tables/DBs stored in RAM and held by multiple block producers?

#### A.

[SOURCE](https://eosio.stackexchange.com/questions/6/are-tables-dbs-stored-in-ram-and-held-by-multiple-block-producers)

#### Q. EOS.IO uses the same Graphene engine (used in Bitshares, Steemit) and it was not turing-complete. So, what exactly has been added in EOS.IO?

#### A.

EOS.IO achieves the Turing completeness lacking in Graphene by including deferred transactions, which can be scheduled (and rescheduled) automatically by code.

[SOURCE](https://objectcomputing.com/resources/publications/sett/february-2018-eos-smart-contracts)

#### Q. Difference b/w Action and Transaction?

#### A.

**Action** - a single operation.
**Transaction** - one or more actions.

[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-transactions-vs-actions)

#### Q. Difference b/w Inline and Deferred Communication?

#### A.

**Inline**:

- action guaranteed to execute with the current transaction.
- No notification about the success or failure.

[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-inline-communication)

**Deferred**:

- action has no guarantee for execution. It gets scheduled to run at `best time`, `later time`, `producer's discretion`.
- carries the authority of the contract that sends them.
- generates notification about the success or failure.

[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-deferred-communication)

#### Q. How to store the big data in EOS?

It is not advisable to store the data in EOS blockchain. So, it can be stored in some centralized (AWS, Google, [Demux](https://medium.com/eosio/introducing-demux-deterministic-databases-off-chain-verified-by-the-eosio-blockchain-bd860c49b017),..) or decentralized storage system (IPFS, etc.) and then the link is stored on the chain.

> NOTE: The uniqueness of IPFS is it is hash-based content addressing. Unlike centralized storage system, any change in file content will generate a new link altogether.

2 types of data (to be stored elsewhere):

- Huge size
- Not required frequently

[SOURCE](https://eosio.stackexchange.com/questions/2096/eos-smart-contracts-and-big-data)

#### Q. What is the logic behind 15% voting for the EOS chain?

#### A.

<!-- TODO: -->

[SOURCE](https://medium.com/@thomas.cox_39839/magic-15-unlocking-the-eosio-blockchain-91ec54f7b48d)

#### Q. How to know that the contract file is changed?

#### A.

Contract hash is generated during each deployment onto the blockchain.
E.g.
Contract Hash：01bd013c4f8be142b9cadf511f007c6ac201c068d529f01ed5661803c575befa

Deploy Time：2018-06-09 17:27:59

For details, click [here](https://eospark.com/MainNet/contract/eosio.token)

#### Q. Can I view how a eos block looks like?

#### A.

Click [here](https://scaneos.io/block/13252366/) to view.

#### Q. Can I view how a eos transaction looks like?

#### A.

Click [here](https://scaneos.io/transaction/4edf2d81204ba6ae9c3bd90aa5ec46a613648d20bb305155e7d2fed13b845652/) to view.

#### Q. Can I view how an eos contract looks like?

#### A.

Click [here](https://eospark.com/MainNet/contract/eosiomeetone) to view.

#### Q. Can I view how an eos account looks like?

#### A.

Click [here](https://eospark.com/MainNet/Account/eosiomeetone) to view.

#### Q. What is an EOS wallet?

#### A.

A wallet consists of key pair(s) - public & private. The key-pairs could be any no. e.g. - 1, 2, 3, .. (any no. of pairs)
E.g. key 1 - public & private.
key 2 - public & private.
.....
....

#### Q. Understanding the EOSIO Smart Contract

#### A.

A EOSIO Smart contract has the following properties:-

- Every eosio smart contract belongs to a single eosio account.
- A contract is basically an object that other accounts can interact with.
- Contract contain "actions" that executes code on the blockchain.
- Contracts have direct access to store, remove and update data on the blockchain.
- Pushing an action to a contract requires the authorization of at least one account.
- Further accounts and permissions can be required depending on contract complexity.
- An account can be made of a single, or many, individuals set up in a permission based configuration.
- Smart contracts can only be run by a single account, and a single account can only have a single smart contract.
- It is best practice to give both the account and contract the same (lowercase) name.
- E.g. for eosio.token contract,
  - Before you can interact with the eosio.token contract you will need to make an account with the same name and deploy the contract onto that account.

#### Q. What are the 2 main parts of DPoS?

#### A.

1.  Selecting the Producers
2.  Reaching Consensus

#### Q. On what basis the chain of DPoS goes ahead to attain finality?

#### A.

1.  Currently uses the longest chain.
2.  No Block producer can sign on 2 chains simultaneously i.e. at a time.

#### Q. RAM size of a smart contract

#### A.

Normally, it can be of KBs to MBs.
[Source](https://eosio.stackexchange.com/a/1724/167)

#### Q. Length of Private-Public keypair?

#### A.

- **Private**: start with 5 and contain 51 characters
- **Public**: start with "EOS" and contain 53 characters

#### Q. What is max-transaction-time in mainnet now?

#### A.

- 3.6 sec [Source](https://github.com/CryptoLions/EOS-MainNet/blob/master/genesis.json)

#### Q. What are the sources of income generation for REX users?

#### A.

- RAM Trading fees
- Namebids
- Lending CPU, BW

#### Q. How public key is calculated from a base58 encoded private key?

#### A.

[Source](https://bitcoin.stackexchange.com/a/83398)

#### Q. Can the BP no. of EOSIO Blockchain protocol be increased from `21` to `1000`?

#### A.

- There isn't a hard limit as such. But, every additional active BP adds roughly 8 seconds to the time to irreversibility.
- The max. no. of BPs can be set [here](https://github.com/EOSIO/eos/blob/master/libraries/chain/include/eosio/chain/config.hpp#L135).

#### Q. Is there any config file for EOSIO chain?

#### A.

Yes.

It can be found [here](https://github.com/EOSIO/eos/blob/master/libraries/chain/include/eosio/chain/config.hpp).

#### Q. What will happen after the EOS reach the max_supply i.e. 10 Billions?

#### A.

```console
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

#### Q. What does `require_auth (get_self())` do in EOS?

#### A.

Contracts inherit from eosio::contract, and, if we look in eosiolib/contract.hpp for the base class, we see that the constructor for eosio::contract is as follows:

```cpp
contract( name self, name first_receiver, datastream<const char*> ds ):_self(self),_first_receiver(first_receiver),_ds(ds) {}
```

Therefore, the account that creates the contract and calls the constructor becomes `get_self()`. Thus, `require_auth(get_self())` ensures that the account executing the function has the authority of the account that created the contract.

#### Q. `[[eosio::on_notify("")]]` attribute only meant for payable actions?

#### A.

- no, anything which has require_recipient [Source](https://t.me/c/1139062279/228653)
- but it is not recommended, better to use inline actions [Source](https://t.me/c/1139062279/228654)

#### Can a table be instantiated with different scope & ram_payer in different action?

#### A.

- [x] `scope` [Source](https://t.me/c/1139062279/228749)
- [ ] `ram_payer` #todo

#### Q. How to take the permission of the contract offchain in case of DApp (Android/ios), especially for inline actions, where `get_self()` needs contract's permission.

#### A.

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

#### Q. What about RAM, CPU, NET consumption if the there are contract -to-contract communication when compared to communications within a contract?

#### A.

Similar [Source](https://t.me/c/1139062279/228767)

#### Q. Can an inline action be fired from within a `[[eosio::on_notify("")]]` annotated function?

#### A.

Yes [Source](https://t.me/c/1139062279/228771)

#### Q. Can i call a `[[eosio::on_notify("")]]` annotated function from within an action defined in the same contract?

#### A.

Yes, ofcourse it is just a class function [Source](https://t.me/c/1139062279/228987). But not needed especially in case of payable actions.

#### Q. Does [this](https://hacken.io/research/education/3-ways-how-you-can-make-your-smart-contract-more-secure/) still hold for current version (eosio.cdt @v1.7.0) of EOSIO in `EOSIO_DISPATCH()`??

#### A.

Yes, but not needed.
rather use `eosio::on_notify` annoted function for payable action. [Source](https://t.me/c/1139062279/228184)

#### Q. How to use `string` type as secondary index in multi-index table?

#### A.

Yes, can be encoded as a `eosio::name` and store it in a `uint64_t`, but this limits you to the 12 character-style names for eosio accounts. [Source](https://eosio.stackexchange.com/a/3816/167)

#### Q. How to read table, defined in another contract?

#### A.

Define a table defined in `contracta` in `contractb`, but without `[[eosio::table]]` attribute - put the exact items. - instantiate the code, scope (same as defined) in table like this:

`table_index table("contracta"_n, "contracta"_n)` - [Source](https://eosio.stackexchange.com/a/70/167)

#### Q. I know how to read a contract_b's table data from within a contract_a's action. But in order to write to that called table, can i then modify after instantiating the contract_b table?

#### A.

only by sending an inline action to `contract b` and letting it modify its own table [Source](https://t.me/c/1139062279/228836)

Basically i have to create a action there & then a action_wrapper & call that action_wrapper in contract_a's action. [Source](https://t.me/c/1139062279/228840)

#### Q. How to ensure single auth?

#### A.

`require_auth()`

#### Q. How to ensure single auth with a permission type?

#### A.

`require_auth(permission_level(account_name, "active"_n))` [Recommended]

`require_auth2(account_name, "active"_n)`

> NOTE: in place of `active`, it could be anything else as a permission type (e.g. custom)

#### Q. How to ensure multiple auth?

#### A.

`has_auth()` All or Either

example:

```cpp
check(has_auth(accounta) || has_auth(accountb), "missing required authority of accounta or accountb");
check(has_auth(accounta) && has_auth(accountb), "missing required authority of accounta & accountb");
```

#### Q. In a practical dApp, If I want to intimate the user of the action failure, shall I use inline action like send_receipt() for this case, or should I use print()?

#### A.

Print is only a debugging tool. Not recommended for anything else [Source](https://t.me/c/1139062279/229828)

#### Q. Is there a working implementation of the eosio.msig contract using inline actions instead of deferred?

#### A.

[EOSIO.Contracts v1.8.3 Inline Multi-Signature Release Notes · EOSIO/eosio.contracts

[eosio.msig (#505)](https://github.com/EOSIO/eosio.contracts/releases/tag/v1.8.3-inline-msig)

#### Q. Difference b/w `circulating_supply`, `total_supply` & `max_supply`?

#### A.

- circulating supply ≤ total supply ≤ max supply
- **circulating supply:** total number of tokens that are circulating in the market and are available to be traded or used.
  - that means all tokens in total supply except those which are:
    - not circulating in the market, or
    - not available to be traded, or
    - not available to be used
  - an example would be tokens that have been created but wont be released until they are mined.
  - another example would be tokens owned by a project team which aren’t liquid and cannot be sold.
- **total supply:** total number of tokens that have been created.
- **max supply:** total number of tokens that can ever be created.
- circulating supply is the hard one. you can’t get it via an API and the very method of figuring it out is subjective and prone to errors. however circulating supply is the most common method for calculating cryptocurrency marketcap.
- Example: here, **total_supply:** `"1021502832.0568 EOS"`, **max_supply:** `"10000000000.0000 EOS"`

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

[Source](https://medium.com/@marketcapone/eos-token-supply-explained-whats-the-difference-between-circulating-supply-total-supply-and-max-e97d4931e7d4)

#### Q. Where is the function defined for inflation of EOS token?

#### A.

It is in the producer pay in the system contract, its not in the token contract because the system contract just issues more tokens [Source](https://t.me/c/1139062279/231212)

#### Q. Where & What code to add for controlling EOS Resources - **RAM**, **NET**, **CPU**?

#### A.

- **RAM** --> taken of the param inside `emplace`, `modify` methods of multi_index table
- Both **NET** & **CPU** --> used of the param inside `require_auth()`

#### Q. Which one is correct -> M-1 or M-2?

```cpp
static constexpr symbol token_symbol = symbol("TOE", 4);

// M-1
auto it = x_table.find(token_symbol.code().raw());

// M-2
auto it = x_table.find(token_symbol.raw());
```

#### A.

- Both are correct, but they have different meanings.
- M-1: only symbol part 'TOE' encoded as integer
- M-2: both components - symbol & precision, encoded as integer

#### Q. How can we control `[[eosio::on_notify("toe1111token::transfer")]]` based transfers to a contract for different purposes?

#### A.

Based on @param `memo`, the different tasks (e.g. modifying different tables) for different purposes can be controlled. E.g. Follow the "`toeridex::sendridex`" action in my dApp - **TOE**.

#### Q. How to convert from checksum256 to string?

#### A.

- `checksum256` is 32 bytes made up of 8 `uint32_t` chunks, so the solution would be something like iterating those chunks and building the string. [Source](https://github.com/MitchPierias/advanced-eos-examples/issues/13)
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

Example to use:

```cpp
std::string data = "hello";
const char * data_str_c = data.c_str();
auto hash_digest = sha256(data_str_c, strlen(data_str_c));

string hash_digest_str = to_hex(&hash_digest, sizeof(hash_digest));
print(hash_digest_str);
// 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824
```

#### Q. How many inline actions can be put into an action? Is there any limit to it?

#### A.

> There is no limit other than the CPU. [Source](https://t.me/c/1139062279/233099)

> Okay!...is it possible that some part of action is added in different block?

No they are atomic in the same transaction [Source](https://t.me/c/1139062279/233103)

> So, that means: Right??

- The inline actions along with the main action will be passed into the same block.
- If anything like (diff. block addition) happens, then CPU limit error will be shown

- Yeah if the total transaction time exceeds the max allowed transaction time or max allowed cpu consumption then the full transaction will roll back and you receive an error

#### Q. How many levels deep inline actions can be ? (inline action calling other inline action)

#### A.

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

#### Q. How to push action with vector param via cleos?

- Best way is to use JSON method data inside cleos
- E.g. action is defined as:

```cpp
ACTION initicorate( const name& buyorsell_type,
  const name& phase_type,
  float current_price_pereos,
  const vector<name> vector_admin );
```

The corresponding push action command is as follows:

```console
$ cleost push action vigor1111ico initicorate '{"buyorsell_type": "buy","phase_type": "a","current_price_pereos": 40,"vector_admin": ["vigoradmin11", "vigoradmin12", "vigoradmin13", "vigoradmin14", "vigoradmin15"]}' -p vigor1111ico@active
```

#### Q. Does anyone know of a way to allow a contract to encrypt data with a key only the contract has access to? [Source](https://t.me/c/1139062279/235058)

#### A.

- No, all SC data is public so SC can’t store private key inside it [Source](https://t.me/c/1139062279/235059)

#### Q. How would one generate a secret no other entity can access that can only be revealed to that contracts specific actions? [Source](https://t.me/c/1139062279/235060)

#### A.

You can't [Source](https://t.me/c/1139062279/235061)

#### Q. Is it possible to set up a version of nodeos where you have read-access to the blockchain but no ability to push transactions to the chain? [Source](https://t.me/c/1139062279/234950)

#### A.

- Yes. It was called read-mode=read-only, and now there's two new options that are replacing it. Nodeos prints them at the start if read-only is configured [Source](https://t.me/c/1139062279/234951)
- It saves a great deal of server CPU if you're on EOS [Source](https://t.me/c/1139062279/234952)

#### Q. Can i get action name for using inside an action? [Source](https://t.me/c/1139062279/234654)

#### A.

- The dispatcher knows the action name, but it's hidden for your convenience. It's still possible to replace the default dispatcher. People lost a lot of money on their dispatchers being hacked [Source](https://t.me/c/1139062279/234660)

#### Q. Hey, just a question about structs and tables. What's the difference between declaring a struct and table as public instead of private? [Source](https://t.me/c/1139062279/234631)

#### A.

- No impact on access from outside the contract. Sometimes private can cause the serializers to fail to compile. [Source](https://t.me/c/1139062279/234632)
- Ah thanks. They're always declared under private in the tutorials but never explained why. [Source](https://t.me/c/1139062279/234633)
- It's an ancient idea of Stroustrup that classes would be inherited. [Source](https://t.me/c/1139062279/234634)

#### Q. How to filter only 2 token contracts' transfer to a contract?

#### A.

- You can make an universal handler and check the contract name by get_first_recipient [Source](https://t.me/c/1139062279/235048)
- Also, check the token symbol as well.
- code:

```cpp
[[eosio::on_notify("*::transfer")]]
	void deposit( const name& buyer_ac,
					const name& contract_ac,
					const asset& quantity,
					const string& memo );
```

    - use `get_first_receiver()` inside the action

```cpp
void vigorico::deposit( const name& user,
						const name& contract_ac,
						const asset& quantity,
						const string& memo ) {

	// check for conditions if either or both of these are true for `from` & `to`
	if(contract_ac != get_self() ||  user == get_self()) {		// atleast one of the condition is true
		print("Either money is not sent to the contract or contract itself is the buyer.");
		return;
	}

	check((get_first_receiver() == "eosio.token"_n) || (get_first_receiver() == token_contract_ac),
		"Acceptable token contracts: \'eosio.token\' or \'" + token_contract_ac.to_string() +" \'.");

...
...
}
```

#### Q. In Multi index table, i saw when multiple people involved as ram_payer, the current ram_payer is replaced by the next ram_payer. Is it possible to keep multiple ram_payers for a row in Multi-index table?

#### A.

- [the internal structure has only one payer per row](https://t.me/c/1139062279/235748)
- [Each entry is a byte array](https://t.me/c/1139062279/235752) - per row
- [What you see in the struct is just a convenient way to manipulate the data](https://t.me/c/1139062279/235753)
- [Nodeos just sees an array of bytes, indexed by primary key, and probably secondary](https://t.me/c/1139062279/235754)
- [It's how nodeos handles the data. Each row is an anonymous blob of data, with one payer](https://t.me/c/1139062279/235761)
- [Secondary indexes are somewhat similar, but they have semantics of pointing to the row id](https://t.me/c/1139062279/235764)

#### Q. How to transfer the `ram_payer` from contract to user or viceversa?

#### A.

- it can be done by letting the 'to' party (e.g. user in 1st case) set or update an row field's info via a separate action. This action shall have authority of 'to' party (i.e. user in 1st case).
- This was done in my creation - `gpk.battles` game, where the `ram_payer` was moved from contract to player using a separate action - `finish`. There the authority was player & it set a param called "finish" as name{"done"} - then the `ram_payer` was transferred.
