# EOSIO Commands
## Current version (for this doc.)
```
`eosio` version: 2.0.3
`eosio.cdt` version: 1.7.0
``` 

## Network commands
* Get the client's version: `$ cleos version client`
* Create key: `$ cleos create key --to-console` OR `$ cleos create key --file <filename-with-extension>`
* Create wallet: `$ cleos wallet create -n mywallet --to-console`
* Import private key into wallet: `$ cleos wallet import -n mywallet --private-key 5JQoJQizgxC2qrtWy8CCgoAp8zJhbZmE2pzFdBGa5Ab2MKjW3qs`
* List wallets: `$ cleos wallet list`
```console
Wallets:
[
  "mywallet *"
]
```
* List keys (imported): `$ cleos wallet keys`
```console
[
  "EOS6sdskMiMTPmZja7TGLQ6iEcJKNMzPYaLkJnePSkwnTYkWUrgvz"
]
```
* Get chain info: `$ cleos -u https://eos.greymass.com/ get info`
```console
{
  "server_version": "cc752d7c",
  "chain_id": "aca376f206b8fc25a6ed44dbdc66547c36c6c33e3a119ffbeaef943642f0e906",
  "head_block_num": 108950721,
  "last_irreversible_block_num": 108950389,
  "last_irreversible_block_id": "067e7375d96c7421c7bdbb0924acf32f10f20cb729db15e7312fce3cef817fd2",
  "head_block_id": "067e74c12cf85416a578096bcd5a4c84f8ac5638dfe2dc7aa2d36cf804fd00b4",
  "head_block_time": "2020-03-07T18:15:39.500",
  "head_block_producer": "helloeoscnbp",
  "virtual_block_cpu_limit": 200000,
  "virtual_block_net_limit": 1048576000,
  "block_cpu_limit": 200000,
  "block_net_limit": 1048576,
  "server_version_string": "v2.0.0-rc3",
  "fork_db_head_block_num": 108950721,
  "fork_db_head_block_id": "067e74c12cf85416a578096bcd5a4c84f8ac5638dfe2dc7aa2d36cf804fd00b4",
  "server_full_version_string": "v2.0.0-rc3-cc752d7c7996587247db7373b89f6a8c683aa9fc"
}
```
* Get account info: `$ cleos -u https://eos.greymass.com/ get account rhf34h5ndfji`
```console
created: 2018-06-09T12:25:26.000
permissions:
     owner     1:    1 EOS8dfYdkGKDb8ZaKhshgaAQZa3NZ4SHNbEThRTJRhEWN8TVssUz
        active     1:    1 EOS8dfdkprUQFnDgEMGA6kANdJdwkqaz3MmwvBmFJNt7YiTsDAcz17
memory:
     quota:     9.099 KiB    used:     3.028 KiB

net bandwidth:
     staked:          0.3000 EOS           (total stake delegated from account to self)
     delegated:       0.0000 EOS           (total staked delegated to account from others)
     used:               354 bytes
     available:          202 KiB
     limit:            200.4 KiB

cpu bandwidth:
     staked:         37.0000 EOS           (total stake delegated from account to self)
     delegated:       0.0000 EOS           (total staked delegated to account from others)
     used:             1.511 ms
     available:        2.056 ms
     limit:            6.587 ms

EOS balances:
     liquid:            5.3613 EOS
     staked:           43.2000 EOS
     unstaking:         0.0000 EOS
     total:            48.5613 EOS

REX balances:
     balance:     8958631.2985 REX
     staked:          913.7502 EOS

producers:
     rrgentinaeos    bitepacenode    blockgenesys
     cryptolions1    cypherglasss    eos42freedom
     eosauthority    eosbeaneosbp    eoscafeblock
     eoscanadacom    eosdacserver    eosdublinwow
     eosflareiobp    eoshenzhenio    eosiomeetone
     eosiosg11111    eosnairobike    eosnationftw
     eosnewyorkio    eosnigeriago    eospaceioeos
     eosphereiobp    eostribeprod    eosyskoreabp
     hkeoshkeosbp    oraclegogogo    sheos21sheos
     swedencornet    teamgreymass    ookenika4eos
```

## Build commands
* Compile `.cpp` to `.wasm`, `.abi`: `$ eosio-cpp -o test.wasm test.cpp --abigen`