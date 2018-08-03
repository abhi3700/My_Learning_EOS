First follow the procedures upto step 5 in this [doc](https://github.com/abhi3700/My_Learning_EOS/blob/master/EOS_setup_v1.0.7.md)

#### NOTE: cleos, nodeos, keosd, eosiocpp is not yet installed.

* In order to install the commands, `sudo make install`
It gets installed in the directory - 
```
-- Installing: /usr/local/eosio/bin/nodeos
-- Installing: /usr/local/eosio/var/log/eosio
-- Installing: /usr/local/eosio/var/lib/eosio
-- Installing: /usr/local/eosio/bin/cleos
-- Installing: /usr/local/eosio/bin/keosd
-- Installing: /usr/local/eosio/bin/eosio-launcher
-- Installing: /usr/local/eosio/bin/eosio-abigen
-- Installing: /usr/local/eosio/bin/eosiocpp
```

  For checking the installation, 
  try this in bash-cmd:
  
  `abhijit@Abhijit:/usr/local/eosio/bin$ ./cleos -u https://api.eosnewyork.io:443 get info`

  **Output:**
  
  ```
  {
  "server_version": "8777d8db",
  "chain_id": "aca376f206b8fc25a6ed44dbdc66547c36c6c33e3a119ffbeaef943642f0e906",
  "head_block_num": 9264602,
  "last_irreversible_block_num": 9264288,
  "last_irreversible_block_id": "008d5ca09c6cebdd775e5f9feca61103c1ab7c04887e052839aff0f172442e0b",
  "head_block_id": "008d5dda3a96854e6a8034bc4f4f025fea60c322c4dc22275e2913a8b4fe8ae3",
  "head_block_time": "2018-08-03T18:06:49.000",
  "head_block_producer": "libertyblock",
  "virtual_block_cpu_limit": 32026462,
  "virtual_block_net_limit": 1048576000,
  "block_cpu_limit": 199900,
  "block_net_limit": 1048576
}
  ```
  
  This shows that everything is installed perfectly.
