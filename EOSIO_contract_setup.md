## TESTNET
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
    - `comptract.sh` (follow [this]() how to create one)
 
  
  
## MAINNET
## Wallet
The wallet-url is the same as http-server-address i.e. set in the "/home/abhijit/eosio-wallet/config.ini" file.
Also time-out (the wallet remains unlocked without any activity) is 900 sec i.e. 15 mins.
### on Local node
NOTE: If (without any wallet name):
        this means that it is a `default` wallet
        
* Create wallet locally using 
  - `cleos wallet create -n test1 --to-console` (display the keys on the terminal)
  - `cleos wallet create -n test1 --file test1.txt` (display the keys on the terminal)
* List all wallets using `cleos wallet list`
* Lock wallet  
  - All wallets using `cleos wallet lock_all`
  - Lock a particular wallet using `cleos wallet lock -n test1`
* Import account into a wallet using `$ cleos wallet import` -->
  ```
  private key: imported private key for: EOS5SKc12RwksCWkK9e2rzNJkQfZ27BGxTFdm5v8fDrLvkrawaJK9
  ```


### on Mainnet
Like greymass wallet, where the private key is protected using a password.



## References
* #### Follow this steps - 
  - `$ cd ~`
  - `$ mkdir scripts`
  - `$ cd scripts`
  - `$ nano comptract.sh`
  - copy and paste the content below:
    ```
    #!/bin/bash

    if [[ $# -ne 2 ]]; then
        echo "USAGE: comptract.sh <ACCOUNT NAME> <Contract Name> from within the directory"
        exit 1
    fi

    ACCOUNT=$1
    CONTRACT=$2

    eosiocpp -o ${CONTRACT}.wast ${CONTRACT}.cpp && 
    eosiocpp -g ${CONTRACT}.abi ${CONTRACT}.cpp && 
    cleos -u http://dev.cryptolions.io:38888/ set contract ${ACCOUNT} ../${CONTRACT}
    ```
  - `$ chmod +x comptract.sh` (making a file executable, chmod- change mode)
  - Add `export PATH=$PATH:~/scripts` to the end of your `~/.profile` file
  - `export PATH=$PATH:~/scripts`

