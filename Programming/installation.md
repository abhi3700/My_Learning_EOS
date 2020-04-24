## EOS, EOSIO Installation
* [`eosio` @1.7.0](https://github.com/EOSIO/eos)
* [`eosio.cdt` @2.0.5](https://github.com/EOSIO/eosio.cdt)
* Choose Linux (say, Ubuntu) for this.

### EOS (for deploying it to Blockchain)
> NOTE: Prerequisites <br/>
> - Wallet<br/>
> - Account

* __Install:__ For [Ubuntu 18.04 Package](https://github.com/EOSIO/eos#ubuntu-linux)
```console
$ wget https://github.com/eosio/eos/releases/download/v2.0.5/eosio_2.0.5-1-ubuntu-18.04_amd64.deb
$ sudo apt install ./eosio_2.0.5-1-ubuntu-18.04_amd64.deb
```
* __Uninstall:__ 
```console
$ sudo apt remove eosio
```

### EOSIO.CDT (Contract Development Toolkit)
> NOTE: Prerequisites <br/>
> - Contract files (.hpp, .cpp)

* __Install:__ For [Ubuntu 18.04 Package](https://github.com/EOSIO/eosio.cdt#debian-package-install)
```console
$ wget https://github.com/eosio/eosio.cdt/releases/download/v1.7.0/eosio.cdt_1.7.0-1-ubuntu-18.04_amd64.deb
$ sudo apt install ./eosio.cdt_1.7.0-1-ubuntu-18.04_amd64.deb
```
* __Uninstall:__ 
```console
$ sudo apt remove eosio.cdt
```
