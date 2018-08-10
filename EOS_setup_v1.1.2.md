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

  **MAINNET** - For checking the installation, 
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
  Now, match the output with the [Jungle block explorer](http://eosnetworkmonitor.io/#) data e.g. last_irreversible_block_num. <br/>
  This shows that cleos command is able to fetch the eos-mainnet info.
  
   **TESTNET** - Now, try for eos-testnet using 
   
   `abhijit@Abhijit:/usr/local/eosio/bin$ ./cleos -u https://jungle.eosio.cr:443 get info`
   
   **Output:**

```
{
"server_version": "40a20769",
"chain_id": "038f4b0fc8ff18a4f0842a8f0564611f6e96e8535901dd45e43ac8691a1c4dca",
"head_block_num": 8104516,
"last_irreversible_block_num": 8104191,
"last_irreversible_block_id": "007ba8ff918947070a83c18957769f5002fd1aeeac66ee1a3b9ce2a03685429f",
"head_block_id": "007baa4446b238ea5e8cd8eca60442c1a32f6dc64f8b4654263359ee2441d7b0",
"head_block_time": "2018-08-03T18:51:01.500",
"head_block_producer": "southafricas",
"virtual_block_cpu_limit": 200000000,
"virtual_block_net_limit": 1048576000,
"block_cpu_limit": 194057,
"block_net_limit": 1048472
}
```

  Now, match the output with the [Jungle-testnet network](http://jungle.cryptolions.io/) data e.g. last_irreversible_block_num.
  
### `eosio-cpp`
Install it from [here](https://github.com/EOSIO/eosio.wasmsdk)

Since v1.1.x eosiocpp has been discontinued from installation via [eos main repo](https://github.com/EOSIO/eos)

Steps:
* `git clone --recursive https://github.com/eosio/eosio.wasmsdk`
* `cd eosio.wasmsdk`
* `git checkout tags/v1.1.1`
* `./build.sh EOS`
* `sudo ./install.sh`
* `eosio-cpp -help`   // check for the command

The cli commands like eosio-cpp, eosio-cc, all are installed in "/usr/local/eosio.wasmsdk/bin/" location.

