## EOS Bancor Algorithm
* RAM is required to store account info.:
	- keys
	- balances
	- contract state
* Dan Larimer and the Block.One team realized that a more incentivized cryptoeconomics-driven ecosystem needed to be created which will ensure RAM availability. Read the [The RAM Quandary](https://blog.springrole.com/the-mechanics-behind-eosio-ram-allocation-940204bc5b7e): Know the history in EOS Dawn 3.0.
* Each time someone buys or sells RAM, a 0.5% fee is applied on both the buyer’s side and the seller’s side (1% overall).
* This actually gives an economic incentive for users to sell their RAM and also it discourages speculative marketing and inflation as the fees that are collection are promptly burned (removed from the ecosystem).
* Notes on Buy/Sell ram EOSIO functions [Source](https://blog.springrole.com/the-mechanics-behind-eosio-ram-allocation-940204bc5b7e)

## References
* [EOSIO RAM Market & Bancor Algorithm by Daniel Larimer](https://medium.com/@bytemaster/eosio-ram-market-bancor-algorithm-b8e8d4e20c73)
* [What is the Bancor algorithm and how it is used for RAM trading?](https://eosio.stackexchange.com/q/1317/167)
* [“[Beyond The White Paper (Vol.4)] Bancor Algorithm: Mathematical & Economic Analysis” by Huobi Research ](https://link.medium.com/g7Wsm41Xq8)
* [Reddit: EOS RAM price calculation Bancor protocol](https://www.reddit.com/r/eos/comments/8wsdrz/eos_ram_price_calculation_bancor_protocol/)
* [YouTube: How Much Would It REALLY Cost To Run CryptoKitties on EOS?](https://www.youtube.com/watch?v=EBC9MBybsCI)
* [Bancor Help Center: What is RAM, CPU and NET on EOS](https://support.bancor.network/hc/en-us/articles/360018325291-What-is-RAM-CPU-and-NET-on-EOS)
* [The Mechanics Behind EOSIO RAM Allocation](https://blog.springrole.com/the-mechanics-behind-eosio-ram-allocation-940204bc5b7e)
* Code Help
	- [exchange_state.hpp](https://github.com/abhi3700/eosio-playground/blob/master/libs/contracts/eosio.system/include/eosio.system/exchange_state.hpp)
	- [exchange_state.cpp](https://github.com/abhi3700/eosio-playground/blob/master/libs/contracts/eosio.system/src/exchange_state.cpp)
	- [buyram, sellram functions declared](https://github.com/abhi3700/eosio-playground/blob/master/libs/contracts/eosio.system/include/eosio.system/eosio.system.hpp)
	- [buyram, sellram functions defined](https://github.com/abhi3700/eosio-playground/blob/master/libs/contracts/eosio.system/src/eosio.system/eosio.system.cpp)