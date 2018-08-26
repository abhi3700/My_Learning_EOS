# Understanding eosio.token contract
This contract has 3 actions - create, issue, transfer.

## Create a token
  * The eosio.token contract allows for the creation of many different tokens.
  * Each token is an asset type and looks like - <br/>
      `1000000000.0000 SYS` <br/>
      `1.0000 SYMBOL` <br/>
      `0.10 SYS`
  * `asset` is a number (upto 18 decimal places )
  * `symbol` can be b/w 1-7 uppercase letters.
  

## Issue a token
  * Every token must be issued by an `issuer` account.

## Transfer a token

### REFERENCES
  * https://medium.com/coinmonks/understanding-the-eosio-token-contract-87466b9fdca9 
