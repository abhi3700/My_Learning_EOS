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
  
## MAINNET
## Wallet
The wallet-url is the same as http-server-address i.e. set in the "/home/abhijit/eosio-wallet/config.ini" file.
Also time-out (the wallet remains unlocked without any activity) is 900 sec i.e. 15 mins.
### on Local node
* Create wallet locally using 
  - `cleos wallet create -n test1 --to-console` (display the keys on the terminal)
  - `cleos wallet create -n test1 --file test1.txt` (display the keys on the terminal)
* Lock wallet  
  - All wallets using `cleos wallet lock_all`
  - Lock a particular wallet using `cleos wallet lock -n test1`

### on Mainnet
Like greymass wallet, where the private key is protected using a password.




