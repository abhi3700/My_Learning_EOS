### Follow the steps below:
* `git clone https://github.com/EOSIO/eosio.cdt.git --recursive` [NOT NEEDED, Already cloned]
* `cd eos`
* `git pull https://github.com/EOSIO/eosio.cdt.git v1.4.0`
* `git submodule update --init --recursive`
* `git checkout tags/v1.4.0`
* `./build.sh` 

  --Setting up Eosio Wasm Toolchain 1.4.0 at /mnt/e/eosio.cdt/build
* `sudo ./install.sh`

```
-- Installing: /usr/local/eosio.cdt/bin/eosio-cc
-- Installing: /usr/local/eosio.cdt/bin/eosio-cpp
-- Installing: /usr/local/eosio.cdt/bin/eosio-ld
-- Installing: /usr/local/eosio.cdt/bin/eosio-abigen
-- Installing: /usr/local/eosio.cdt/bin/eosio-abidiff

..
..
-- Installing: /usr/local/eosio.cdt/bin/eosio-wast2wasm
-- Installing: /usr/local/eosio.cdt/bin/eosio-wasm2wast
-- Installing: /usr/local/eosio.cdt/bin/eosio-pp
...
...
-- Installing: /usr/local/eosio.cdt/include/libc
-- Installing: /usr/local/eosio.cdt/include/libc/alloca.h
-- Installing: /usr/local/eosio.cdt/include/libc/assert.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits
-- Installing: /usr/local/eosio.cdt/include/libc/bits/alltypes.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/errno.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/float.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/limits.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/locale.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/stddef.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/stdint.h
-- Installing: /usr/local/eosio.cdt/include/libc/bits/wchar.h
-- Installing: /usr/local/eosio.cdt/include/libc/byteswap.h
-- Installing: /usr/local/eosio.cdt/include/libc/crypt.h
-- Installing: /usr/local/eosio.cdt/include/libc/ctype.h

```
