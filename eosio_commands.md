# EOSIO Commands
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