# CLI commands for EOSIO 
Here,
  * For mainnet - `alias cleos='cleos -u https://eos.greymass.com'`
  * For testnet - `alias cleos='cleos -u http://dev.cryptolions.io:38888/'` 
  
These are some of the important cli commands for an EOSIO developer:

* ### [List of Nodes](https://github.com/greymass/eos-voter/blob/master/nodes.md)

* ### `cleos` shortcut in bash-cmd
  `sudo ln -s "/usr/local/eosio/bin/cleos" /usr/local/bin/cleos`

* ### `get info` EOS blockchain
 
* ### Get account
  ```cleos get account jedaaaaaaaaa```
  <p align="center">
    <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_account.png" width="730" height="300">
  </p>


* ### RAM price calculation
  ```cleos get table eosio eosio rammarket```
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_rammarket.png" width="730" height="250">
  </p>
  
   #### ```rate = quote_balance/base_balance```
* ### Push a contract 
  ```
  # for testnet
  $ cleos set contract abhitest1234 ../hello -p abhitest1234@active
  ```


