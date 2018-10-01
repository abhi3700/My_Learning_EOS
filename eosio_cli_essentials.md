# CLI commands for EOSIO 
Here,
  * For mainnet - `alias cleos='cleos -u https://eos.greymass.com'`
  * For public testnet like Jungle - `alias cleos='cleos -u http://dev.cryptolions.io:38888/'` 
  
These are some of the important cli commands for an EOSIO developer:

* #### [List of Nodes](https://github.com/greymass/eos-voter/blob/master/nodes.md)

* #### `cleos` shortcut in bash-cmd
  `sudo ln -s "/usr/local/eosio/bin/cleos" /usr/local/bin/cleos`

* #### information on EOS blockchain using `cleos get info`
* #### Create a wallet to store keys
  ```
  cleos wallet create -n test1 --to-console
  OR
  cleos wallet create -n test1 --file ../test1.txt
  ```
  when with no name => 'default' wallet.
  
* #### Create key-pair using `cleos create key --to-console` OR `cleos create key --file ../test.txt`

* #### Unlock wallet using `cleos wallet unlock -n test1`

* #### List wallets using `cleos wallet list`. Wallets with asterisk * means that it is unlocked.

* #### Import keys into the wallet using `cleos wallet import -n test1`

* #### Create account 
  - on Testnet/Mainnet `cleos create account drifeoneteam dev111111111 EOS6aD1hj7hcqktskyMtFKLti62MSaQV4vgb1GMES5cvLmj8s8Jip EOS5auLgLhM3uYWaDEeESKUMfqYsnNcUj2G9xSDuLbmEj4PGfBupL`
  - on local node `cleos create account eosio user1 EOS6aD1hj7hcqktskyMtFKLti62MSaQV4vgb1GMES5cvLmj8s8Jip EOS5auLgLhM3uYWaDEeESKUMfqYsnNcUj2G9xSDuLbmEj4PGfBupL`
  - using shell script: click [here](https://github.com/EOS-Nation/create-accounts/blob/master/create-account.sh)
  
    
    #### NOTE: For local node,
    + key-pair of `eosio` has to imported into the wallet being used.
    + The same key-pair can be used for multiple accounts and also can be imported on a single wallet. `cleos get accounts [public_key]`
    + account-name can be of any characters. No min/max.
  
* #### Push a contract 

  Ensure, that the wallet is unlocked.
  #### NOTE: It is not necessary to keep the _`contract name`_ & _`account name`_ same.
  ```
  # for testnet
  $ cleos set contract abhitest1234 ../hello -p abhitest1234@active
  ```
* #### Push an action to a contract
  ```
  $ cleos push action abhitest1234 hi '["abhijit"]' -p abhitest1234@active
  ```
 
* #### Get account
  ```cleos get account jedaaaaaaaaa```
  <p align="center">
    <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_account.png" width="730" height="300">
  </p>


* #### RAM price calculation
  ```cleos get table eosio eosio rammarket```
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_rammarket.png" width="730" height="250">
  </p>
  
   #### ```rate = quote_balance/base_balance```

* set contract
 `$ cleos set contract eosio build/contracts/eosio.bios -p eosio` is equivalent to 
	```
	$ cleos push action eosio setcode '[eosio.bios.wasm]' -p eosio
	$ cleos push action eosio setabi eosio '[eosio.bios.abi] -p eosio
	```
* Buy ram
	`$ cleos system buyram testdauser11 testdauser11 --kbytes 100` Sender: testdauser11, Receiver: testdauser11.

* Compile, Deploy, test contract
	-	compile - 
		+ wasm: `$ eosiocpp -o testdauser11.wast testdauser11.cpp`
		+ abi: `$ eosiocpp -g testdauser11.abi testdauser11.cpp`
	- set contract - 
		+ move out of the contract folder: `$ cd ..`
		+ upload contract: `$ cleos set contract testdauser11 testdauser11`. Account: testdauser11, Folder: testdauser11.
	- test contract - 
		+ push action: `$ cleos push action testdauser11 create '{"user":"testdauser11","title":"first","content":"create a first one"}' -p testdauser11`. Contract account: testdauser11, Action: create, user: testdauser11 (the content creator & also for permission during auth)
		
		+ check the table: `$ cleos get table testdauser11 testdauser11 data`. Contract: testdauser11, Scope: testdauser11, Table name: data (written in `N(data)`). 
		<br/> **Output:**
		```json
		{
			"rows": [{
					"post_id": 0,
					"poster": "testdauser11",
					"title": "first",
					"content": "create a first one"
				}
			],
			"more": false
		}
		```
		
