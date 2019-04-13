# My EOS Essentials
## FAQs

1. ### What if BPs pay people to vote for them?
    In EOS, the no. of votes getting count also depends on new/old votes. This is done every 6 months. That is after this period it becomes old.
    So, now the BPs shall have to raise the awareness everytime to EOS users for staying in the top 21 BPs and 100 SPs.

2. ### What else the BPs and SPs can do other than just recording the Blockchain data?
    They can volunteerly educate the people about EOS or decentralisation. This will make them more competent in the EOS producer candidate list.

3. ### Will the EOS BPs number be 21 for lifetime? Can't we configure in the future if required?
    Yes, it can be done.

    The default number is 21, however in the latest (in Jan 2018) development update, they confirmed it would be dynamic/configurable.﻿

4. ### Is EOS Smart Contracts (SCs) upgradeable?
    Yes. Unlike Ethereum, EOS contracts are upgradeable.

    Hence, **Code is NOT the law.**

5. ### Can EOS transaction be reversible like other major blockchains?
    Yes. 

    But, it is possible through arbitration. In future, for dApps' good functioning, one has to hire **competent arbitrators** for getting any form of transaction (money, asset, so on...) back. 

6. ### EOS key terms?
    **Block** - group of transactions.<br/>
    **Transaction** - record of actions.<br/>
    **Action** - behavior of contracts. E.g. - functions like create(), transfer(), etc.
    
    #### NOTE: A Smart Contract can have one or more action.

7. ### What do I lose by staking my EOS tokens?
    Nothing in terms of ```no. of tokens```. E.g. If you stake 3 EOS, will get exactly 3 EOS after unstaking.
    
    One only makes a loss of inflation (increase, decrease, neutral) only. <br/>
    **Explaination:** 3 cases are possible.
    
    * **Profit:** - value of EOS during unstake > stake  
    * **Loss:** - value of EOS during unstake < stake
    * **Neutral:** - value of EOS during unstake = stake
    
    [SOURCE](https://eosio.stackexchange.com/questions/824/can-i-stake-back-my-bandwidth-without-cost)
    
8. ### How to vote for BP using cleos?
   
   [SOURCE](https://eosio.stackexchange.com/questions/725/how-to-vote-using-cleos)
   
9. ### In EOS, why 21 BPs?
    **Reasons**: <br>
    
    * odd no. - to have 66% i.e. ```2/3 + 1``` i.e. ```(14+1) = 15```. So, 15 BPs consent is required for agreement on any decision.
    * voting required to maintain irreversibility of EOS blockchain => lesser nodes, the better speed. 
      
      So, 21 is a optimized no. 
        #### NOTE: initially, Bitshares had nearly ```100+``` BPs. So, the Block time used to be higher. Now, it is in seconds.
    * If more nodes involved, then synchronization would be difficult i.e. ir-reversibility would be maintained with higher block time => less scalable.
   
        Like in Bitcoin, Ethereum (PoW-based tokens), the irreversibility is maintained using computing power. So, energy can't be recreated. But in EOS, the irreversibility is maintained using voting. For this, the above reasons has to be followed.
     
10. ### How much time for getting back my tokens after unstake?
    3 days.
    
11. ### What would happen to my data (on EOS blockchain) if the required tokens condition not met or all the tokens are unstaked?
    Correspondingly, the data will also be deleted.
    
12. ### Once BPs (Active + Standby) get selected through voting, is that list permanent?
    Actually, No.
    
    Because every week the voting decays by 1%. So, if someone wants its BPs to stand in the list, then one needs to revote (in the same way as previous).
    
    [**Video link**](https://www.youtube.com/watch?v=v9h4u1xUASw)

13. ### Why 30 stake weighted voting?
    TODO
    [Article by Thomas Cox](https://medium.com/@thomas.cox_39839/why-30-stake-weighted-approval-votes-for-eosio-1402b994bf20)

14. ### Difference b/w Active key and Owner key?
    **Active key** - transfer EOS, vote, stake or unstake, and purchase RAM. 
    
    **Owner key** - you can change both the active key and the owner key of any account. 
    
    For changing the owner key, link - https://www.youtube.com/watch?v=nyyE05qFc78
    
<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_owner_vs%20_active_key.jpg" width="300" height="290">
</p>

    
15. ### Can eos account names be > 12 characters?
    Yes. To get a premium name, it has to be auctioned on the mainnet.
    
    A/c names like `eosio`, `b1` (created during bios contract at boot time)

16. ### How to import your existing EOS wallet (already created on Mainnet) into local PC/laptop?
    Follow these 2 steps: 
    1. Edit the "config.ini" file in eosio-wallet in directory - ```"/home/pc-name/eosio-wallet"``` on Linux OS. <br/>
		change the 
			```http-server-address = localhost:8080```
	2. Create the wallet locally as mentioned in the source-link <br/>
		```cleos wallet create -n <NAME_OF_WALLET_HERE>``` <br/>
		```cleos wallet import <ONWER_PRIVATE_KEY> -n <NAME_OF_WALLET_HERE>``` <br/>
		```cleos wallet import <ACTIVE_PRIVATE_KEY> -n <NAME_OF_WALLET_HERE>```
        
    [**SOURCE**](https://eosio.stackexchange.com/questions/1363/wallet-essentials-for-importing-your-existing-eos-wallet)
    
    #### NOTE: The password generated is the encryption key for the wallet. I believe keosd makes wallets with .wallet file name. This your_wallet.wallet file name is the encrypted file that your password decrypts. 
    
    > **Instruction:**
    >* Don't connect to an API when dealing with private keys. (RECOMMENDED)
    >* NEVER use ```cleos --wallet-url```, otherwise it might get sussceptible for your private key getting leaked.
        Basically, ```--wallet-url``` is dangerous.
        as mentioned by @michaelyeates, @nsjames in EOS Developer Telegram channel.
    
17. ### What do you mean by proxy-voting?
	It is basically delegating your voting right to someone.
	If you do this, then you are representing that person to vote 30 BPs on your behalf. Another way - That person votes whoever will be the 30 votes for you as well.
	
18. ### Is it possible to run the REST API data onto EOS Smart contract?
	It is not possible to directly have any communication with the C++ contracts with the HTTP API. Instead try to run through [EOSJS](https://github.com/EOSIO/eosjs) and display on web.
	
	#### Sources:
	* From Telegram group **ITAM Network** (group of EOS devs)
		> If you are asking about smart contracts, it's not possible to run outside APIs on  C++ smart contract. You can probably use outside APIs like general node projects with eosjs circumstances.
	* By Daniel larimer - https://github.com/EOSIO/eos/issues/1483#issuecomment-391930967
	
19. ### How to query the EOS database?
	[SOURCE](https://eosio.stackexchange.com/questions/279/does-eos-db-support-text-based-queries)
	
20. ### Are Tables/DBs stored in RAM and held by multiple block producers?
	[SOURCE](https://eosio.stackexchange.com/questions/6/are-tables-dbs-stored-in-ram-and-held-by-multiple-block-producers)
	
21. ### EOS.IO uses the same Graphene engine (used in Bitshares, Steemit) and it was not turing-complete. So, what exactly has been added in EOS.IO?
	EOS.IO achieves the Turing completeness lacking in Graphene by including deferred transactions, which can be scheduled (and rescheduled) automatically by code. 
	
	[SOURCE](https://objectcomputing.com/resources/publications/sett/february-2018-eos-smart-contracts)
	
22. ### Difference b/w Action and Transaction?
	**Action** - a single operation.
	**Transaction** - one or more actions.
	
	[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-transactions-vs-actions)
	
23. ### Difference b/w Inline and Deferred Communication?
	#### Inline:
	* action guaranteed to execute with the current transaction.
	* No notification about the success or failure.
		
	[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-inline-communication)
	
	#### Deferred:
	* action has no guarantee for execution. It gets scheduled to run at `best time`, `later time`, `producer's discretion`. 
	* carries the authority of the contract that sends them.
	* generates notification about the success or failure.
		
	[SOURCE](https://developers.eos.io/eosio-cpp/docs/communication-model#section-deferred-communication)

24. ### How to store the big data in EOS?
	It is not advisable to store the data in EOS blockchain. So, it can be stored in some centralized (AWS, Google, [Demux](https://medium.com/eosio/introducing-demux-deterministic-databases-off-chain-verified-by-the-eosio-blockchain-bd860c49b017),..) or decentralized storage system (IPFS, etc.) and then the link is stored on the chain.
	
	#### NOTE: The uniqueness of IPFS is it is hash-based content addressing. Unlike centralized storage system, any change in file content will generate a new link altogether.
	
	2 types of data (to be stored elsewhere):<br/>
		- Huge size <br/>
		- Not required frequently
	
	[SOURCE](https://eosio.stackexchange.com/questions/2096/eos-smart-contracts-and-big-data)
	

25. ### What is the logic behind 15% voting for the EOS chain? - TODO
	[SOURCE](https://medium.com/@thomas.cox_39839/magic-15-unlocking-the-eosio-blockchain-91ec54f7b48d)

26. ### How to know that the contract file is changed?
	Contract hash is generated during each deployment onto the blockchain.
	E.g. 
	Contract Hash：01bd013c4f8be142b9cadf511f007c6ac201c068d529f01ed5661803c575befa

	Deploy Time：2018-06-09 17:27:59

	For details, click [here](https://eospark.com/MainNet/contract/eosio.token)
	
27. ### Can I view how a eos block looks like?
	Click [here](https://scaneos.io/block/13252366/) to view.
	
28. ### Can I view how a eos transaction looks like?
	Click [here](https://scaneos.io/transaction/4edf2d81204ba6ae9c3bd90aa5ec46a613648d20bb305155e7d2fed13b845652/) to view.

29. ### Can I view how an eos contract looks like?
	Click [here](https://eospark.com/MainNet/contract/eosiomeetone) to view.
	
30. ### Can I view how an eos account looks like?
	Click [here](https://eospark.com/MainNet/Account/eosiomeetone) to view.
	
31. ### What is an EOS wallet?
	A wallet consists of key pair(s) - public & private. The key-pairs could be any no. e.g. - 1, 2, 3, .. (any no. of pairs)
	E.g. key 1 - public & private.
			 key 2 - public & private.
			 .....
			 ....
			 
32. ### Understanding the EOSIO Smart Contract
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

33. ### What are the 2 main parts of DPoS?
	1. Selecting the Producers
	2. Reaching Consensus

34. ### On what basis the chain of DPoS goes ahead to attain finality?
	1. Currently uses the longest chain.
	2. No Block producer can sign on 2 chains simultaneously i.e. at a time.
	
35. ### RAM size of a smart contract
  Normally, it can be of KBs to MBs.
  [Source](https://eosio.stackexchange.com/a/1724/167)

36. ### Length of Private-Public keypair?
  Private: start with 5 and contain 51 characters
  Public: start with "EOS" and contain 53 characters

37. ### What is max-transaction-time in mainnet now?
    3.6 sec <br/>
    [Source](https://github.com/CryptoLions/EOS-MainNet/blob/master/genesis.json)

38. ### What are the sources of income generation for REX users?
		- RAM Trading fees
		- Namebids
		- Lending CPU, BW

	
	
	
	
	
	
