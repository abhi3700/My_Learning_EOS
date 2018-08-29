### Follow the steps below:
* `git clone https://github.com/EOSIO/eos.git --recursive` [NOT NEEDED, Already cloned]
* `cd eos`
* `git pull https://github.com/EOSIO/eos.git v1.2.0`
* `git submodule update --init --recursive`
* `git checkout tags/v1.2.0`
* `./eosio_build.sh`
```
        Checking boost library installation.
        Boost found at /home/abhijit/opt/boost.

        Checking MongoDB installation.
        MongoDB configuration found at /home/abhijit/opt/mongodb/mongod.conf.

        Checking MongoDB C++ driver installation.
        Mongo C++ driver found at /usr/local/lib/libmongocxx-static.a.

        Checking secp256k1-zkp installation.
        secp256k1 found @ /usr/local/lib.

        Checking for LLVM with WASM support.
        WASM found at /home/abhijit/opt/wasm/bin.


>>>>>>>> ALL dependencies sucessfully found or installed . Installing EOSIO
......
......
.....
```
* `./eosio_install.sh`(created some error) => use <br/>
  `cd build` & then `sudo make install`
* check for compiling "hello.cpp" usind `eosiocpp`
  
