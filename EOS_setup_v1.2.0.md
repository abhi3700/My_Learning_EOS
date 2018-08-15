### Follow the steps below:
* `git clone https://github.com/EOSIO/eos.git --recursive` [NOT NEEDED, Already cloned]
* `cd eos`
* `git pull https://github.com/EOSIO/eos.git v1.2.0`
* `git submodule update --init --recursive`
* `git checkout tags/v1.2.0`
* `./eosio_build.sh`
* `./eosio_install.sh`(created some error) => use <br/>
  `cd build` & then `sudo make install`
* 
  
