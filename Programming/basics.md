### Understanding the EOSIO Smart Contract
A EOSIO Smart contract has the following properties:-
* Every eosio smart contract belongs to a single eosio account.
* A contract is basically an object that other accounts can interact with.
* Contract contain "actions" that executes code on the blockchain.
* Contracts have direct access to store, remove and update data on the blockchain.
* Pushing an action to a contract requires the authorization of at least one account.
* Further accounts and permissions can be required depending on contract complexity.
* An account can be made of a single, or many, individuals set up in a permission based configuration.
* Smart contracts can only be run by a single account, and a single account can only have a single smart contract.
* It is best practice to give both the account and contract the same (lowercase) name.
* E.g. for eosio.token contract,
  + Before you can interact with the eosio.token contract you will need to make an account with the same name and deploy the contract onto that account.
