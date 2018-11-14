# IDE
## Sublime Text - Editor
Install all the packages (ticked ones) in the ST3 following [this](https://github.com/abhi3700/my_coding_toolkit/blob/master/sublime_all.md).

Now, follow this steps:
* And now, open a workspace inside which all the libs, other example contracts are available. 
* Import any ext. files using this - 
  - All folder suggestions appear. 
  ```cpp
  #include <../>
  ```
  - Goto the folder say eosiolib and now again files inside appear as suggestions.
  ```cpp
  #include <../eosiolib/>
  ```
  - Goto the desired file.
  ```cpp
  #include <../eosiolib/eosio.hpp>
  ```
  ```cpp
  #include "eosiolib/"
  ```
  - DONE!
 
 * Now, carry on with the eosio_coding_essentials, following [this](https://github.com/abhi3700/My_Learning_EOS/blob/master/my_eosio_essentials.md)
 * After the code is written, `right-click` on the folder and click `Open terminal here`.
## Compiler, Debugger
* In the terminal - `bash` on Ubuntu, type 
  1. `alias cleos='cleos -u http://jungle.cryptolions.io:18888'` (NOT required, if added in [~/.profile file](https://github.com/abhi3700/My_Learning_Linux_essentials/blob/master/commands_all.md#bash-profile))
  2. `$eoscc` (EOS Contract Compiler). [Click here to install](https://github.com/abhi3700/My_Learning_EOS/blob/master/EOSIO_contract_setup.md#follow-this-steps--)

## Deploy
### TESTNET (Local)
Follow these steps:
* [OPTIONAL] Modify the config.ini file: (/home/abhijit/.local/share/eosio/nodeos/config/config.ini
) for nodeos
  - edit using `sudo nano /home/abhijit/.local/share/eosio/nodeos/config/config.ini`
  - these parameters are (optional) - 
    + http-server-address = 127.0.0.1:8888 (& for wallet-url set http-server-address= 127.0.0.1:8900 in keosd `config.ini` )
    + genesis-json = /mnt/e/eos/tutorials/bios-boot-tutorial/genesis.json
    + enable-stale-production = true (set it to true)
    + plugins: add all
* start block auto-production in a terminal using <br/>
  `$ nodeos --delete-all-blocks -e -p eosio --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --contracts-console`
  
  NOTE: `--contracts-console` has been added in order to show the output on the console both on nodeos terminal & cleos terminal.
  
* If any error, follow these steps:
  - `cd /home/abhijit/.local/share/eosio/nodeos/`
  - `rm -rf data` (delete the data folder)
  - `$ nodeos --delete-all-blocks -e -p eosio --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin`
  - If any error still persists, repeat these 3 procedures (deleting the data & start again).
* Check if working correctly,
  - `cleos get info`
  - `cleos get account eosio`
  - `cleos get account eosio -j` in JSON format.
* Load the bios contract
  ```
  cleos set contract eosio ../eosio.bios -p eosio@active
  ```
* Create accounts

  Ensure the wallet is unlocked.
  ```
  cleos create account eosio user1 [user1's Owner public key] [user1's Active public key]
  ```
* Push contract
  ```
  cleos set contract user1 .../hello -p user1@active 
  ```
* Push action
  ```
  cleos push action hi '["abhijit"]' user1@active
  ```
  
### TESTNET (Public)
Follow these steps: 
* Join the testnet - http://jungle.cryptolions.io/#home
* Create account - http://jungle.cryptolions.io/#account
* Create the keys from `cleos` on the bash-cmd using 
  `cleos create key --to-console` (saving keys onto a file is not required for testnet)
* All the keys are saved in a file into a local directory.
* Also, `alias cleos='cleos -u http://dev.cryptolions.io:38888/'` <br/>
  Now, you can use cleos and easy going while adding other commands 
  
  NOTE: valid for that session only. When closed, it will have to be recreated.
  
* To check if cleos is connected with a testnet node -
  ```
  $ cleos get info
  ```
* Create an account on the testnet for uploading a contract. Use step no. 2
* Now, import the account into a wallet (say default) using `$ cleos wallet import` -->
  ```
  private key: imported private key for: EOS5SKc12RwksCWkK9e2rzNJkQfZ27BGxTFdm5v8fDrLvkrawaJK9
  ```

  Hence, the wallet is unlocked.
* Go to the contract directory `$ cd /mnt/f/contracts/hello`
* 2 Methods to create .wast & .wasm files and set contract into the account using -
    - ```
      $ eosiocpp -o hello.wast hello.cpp
      $ eosiocpp -g hello.abi hello.cpp
      $ cleos set contract abhitest1234 ../hello -p abhitest1234@active  (ensure that the wallet is unlocked for this step)
      ```
    - `eoscc.sh` (follow [this](https://github.com/abhi3700/My_Learning_EOS/blob/master/EOSIO_contract_setup.md#follow-this-steps--) how to create one)
* Now, push a action `hi`(say) in this contract - 
  ```
  cleos push action abhitest1234 hi '["abhijit"]' -p abhitest1234@active
  ```
 
  
  
### MAINNET
### Wallet
The wallet-url is the same as http-server-address i.e. set in the "/home/abhijit/eosio-wallet/config.ini" file.
Also time-out (the wallet remains unlocked without any activity) is 900 sec i.e. 15 mins.
#### on Local node
NOTE: If (without any wallet name):
        this means that it is a `default` wallet
        
* Create wallet locally using 
  - `cleos wallet create -n test1 --to-console` (display the keys on the terminal)
  - `cleos wallet create -n test1 --file test1.txt` (display the keys on the terminal)
* List all wallets using `cleos wallet list`
* Lock wallet  
  - All wallets using `cleos wallet lock_all`
  - Lock a particular wallet using `cleos wallet lock -n test1`
* Import an account (already created) into a wallet - `default` (say) using `$ cleos wallet import` -->
  ```
  private key: imported private key for: EOS5SKc12RwksCWkK9e2rzNJkQfZ27BGxTFdm5v8fDrLvkrawaJK9
  ```


#### on Mainnet
Like greymass wallet, where the private key is protected using a password.

## Summary
Follow these steps:
1. **Sublime Text:** as Editor
2. **eoscc**: as Compiler and deploy
3. **Testnet** or **Mainnet**: choose accordingly, `alias cleos='cleos -u https://api.eosnewyork.io'` & `alias cleos='cleos -u http://jungle.cryptolions.io:18888'` respectively define in `~/.profile` beforehand.

## References
* #### Follow this steps - 
  - `$ cd ~`
  - `$ mkdir scripts`
  - `$ cd scripts`
  - `$ nano eoscc.sh`
  - copy and paste the content below:
    ```
    #!/bin/bash

    if [[ $# -ne 2 ]]; then
        echo "USAGE: eoscc.sh <ACCOUNT NAME> <Contract Name> from within the directory"
        exit 1
    fi

    ACCOUNT=$1
    CONTRACT=$2

    eosiocpp -o ${CONTRACT}.wast ${CONTRACT}.cpp && 
    eosiocpp -g ${CONTRACT}.abi ${CONTRACT}.cpp && 
    cleos -u http://dev.cryptolions.io:38888/ set contract ${ACCOUNT} ../${CONTRACT}
    ```
  - `$ chmod +x eoscc.sh` (making a file executable, chmod- change mode)
  - Add `export PATH=$PATH:~/scripts` to the end of your `~/.profile` file
  - `export PATH=$PATH:~/scripts`

