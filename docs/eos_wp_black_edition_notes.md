## EOS Whitepaper (Black edition) Notes
  **Paper** - http://iang.org/papers/EOS_An_Introduction-BLACK-EDITION.pdf
  
* > We propose EOS, a performance-based and self-governing blockchain that provides an operating system for building large-scale consumer facing distributed applications.
* Paper's motives - 
  * today's market for DLTs,
  * end user's needs & how to meet them
  * review an architecture to meet the market demands.
  * comparison with the known system & conclusion
* ### Consensus: 
  solving the ```Byzantine's Generals problem```. 
  **Bitcoin** - solves the issue using PoW by SHA2 puzzle. Using energy, one who wins becomes the General and gets a fixed amount of Bitcoin. 
          Basically, anyone can become the General.
          
    > Following Generals can choose to accept that plan or block, or reject if invalid.
* ```Permissioned ledgers``` - 
  > Permissioned ledgers (Swanson 2015) were proposed to not only block those we want to exclude from enjoying the benefits of our ledger, but also to bring us back to the computer science roots of efficient consensus - practical but centralised designs well known in database science.
  
  E.g. **R3's Corda** established this using PoS consensus method. They say that giving everyone (selected ones) a chance to validate the block of transactions.
  > By allowing interchangeability of servers called notaries that can mediate the consensus by any of the above means, Corda reduces the
network operating cost to a level comparable to today’s IT infrastructure.
 They have attained **decentralisation** but not **distributed**.
* 
