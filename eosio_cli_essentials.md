# CLI commands for EOSIO 
These are some of the important cli commands for an EOSIO developer:

* ### [List of Nodes](https://github.com/greymass/eos-voter/blob/master/nodes.md)

* ### `cleos` shortcut in bash-cmd
  `sudo ln -s "/usr/local/eosio/bin/cleos" /usr/local/bin/cleos`

* ### `get info` EOS blockchain
 
* ### Get account
  ```cleos -u https://api.eosnewyork.io/ get account jedaaaaaaaaa```
  <p align="center">
    <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_account.png" width="730" height="300">
  </p>


* ### RAM price calculation
  ```cleos -u http://publicapi-mainnet.eosauthority.com/ get table eosio eosio rammarket```
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eosio_rammarket.png" width="730" height="250">
  </p>
  
   #### ```rate = quote_balance/base_balance```
   
