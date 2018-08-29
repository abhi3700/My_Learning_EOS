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
```
Install the project...
-- Install configuration: "Release"
-- Up-to-date: /usr/local/eosio/etc/eosio
-- Installing: /usr/local/eosio/etc/eosio/launcher/testnet.template
-- Up-to-date: /usr/local/eosio/etc/eosio
-- Up-to-date: /usr/local/eosio/etc/eosio/launcher
-- Installing: /usr/local/eosio/include/eosio.version.hpp
-- Installing: /usr/local/eosio/lib/cmake/EosioTester.cmake
-- Installing: /usr/local/eosio/bin/eosio-s2wasm
-- Installing: /usr/local/eosio/lib/libbinaryen.a
-- Installing: /usr/local/eosio/lib/libfc.a
-- Up-to-date: /usr/local/eosio/include/fc
-- Installing: /usr/local/eosio/include/fc/actor.hpp
-- Installing: /usr/local/eosio/include/fc/aligned.hpp
-- Installing: /usr/local/eosio/include/fc/any.hpp
-- Installing: /usr/local/eosio/include/fc/api.hpp
-- Installing: /usr/local/eosio/include/fc/array.hpp
-- Installing: /usr/local/eosio/include/fc/bitutil.hpp
-- Installing: /usr/local/eosio/include/fc/bloom_filter.hpp
-- Up-to-date: /usr/local/eosio/include/fc/compress
-- Installing: /usr/local/eosio/include/fc/compress/smaz.hpp
-- Installing: /usr/local/eosio/include/fc/compress/zlib.hpp
-- Up-to-date: /usr/local/eosio/include/fc/container
-- Installing: /usr/local/eosio/include/fc/container/deque.hpp
-- Installing: /usr/local/eosio/include/fc/container/deque_fwd.hpp
-- Installing: /usr/local/eosio/include/fc/container/flat.hpp
-- Installing: /usr/local/eosio/include/fc/container/flat_fwd.hpp
-- Up-to-date: /usr/local/eosio/include/fc/crypto
-- Installing: /usr/local/eosio/include/fc/crypto/aes.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/base32.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/base36.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/base58.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/base64.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/bigint.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/blowfish.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/city.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/common.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/dh.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/digest.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/elliptic.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/elliptic_r1.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/equihash.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/hex.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/hmac.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/openssl.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/pke.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/private_key.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/public_key.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/rand.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/ripemd160.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/sha1.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/sha224.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/sha256.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/sha512.hpp
-- Installing: /usr/local/eosio/include/fc/crypto/signature.hpp
-- Up-to-date: /usr/local/eosio/include/fc/exception
-- Installing: /usr/local/eosio/include/fc/exception/exception.hpp
-- Installing: /usr/local/eosio/include/fc/filesystem.hpp
-- Installing: /usr/local/eosio/include/fc/fixed_string.hpp
-- Installing: /usr/local/eosio/include/fc/fwd.hpp
-- Installing: /usr/local/eosio/include/fc/fwd_impl.hpp
-- Installing: /usr/local/eosio/include/fc/git_revision.hpp
-- Up-to-date: /usr/local/eosio/include/fc/interprocess
-- Installing: /usr/local/eosio/include/fc/interprocess/container.hpp
-- Installing: /usr/local/eosio/include/fc/interprocess/file_mapping.hpp
-- Installing: /usr/local/eosio/include/fc/interprocess/iprocess.hpp
-- Installing: /usr/local/eosio/include/fc/interprocess/mmap_struct.hpp
-- Installing: /usr/local/eosio/include/fc/interprocess/process.hpp
-- Up-to-date: /usr/local/eosio/include/fc/io
-- Installing: /usr/local/eosio/include/fc/io/buffered_iostream.hpp
-- Installing: /usr/local/eosio/include/fc/io/console.hpp
-- Installing: /usr/local/eosio/include/fc/io/datastream.hpp
-- Installing: /usr/local/eosio/include/fc/io/enum_type.hpp
-- Installing: /usr/local/eosio/include/fc/io/fstream.hpp
-- Installing: /usr/local/eosio/include/fc/io/iobuffer.hpp
-- Installing: /usr/local/eosio/include/fc/io/json.hpp
-- Installing: /usr/local/eosio/include/fc/io/json_relaxed.hpp
-- Installing: /usr/local/eosio/include/fc/io/raw.hpp
-- Installing: /usr/local/eosio/include/fc/io/raw_fwd.hpp
-- Installing: /usr/local/eosio/include/fc/io/raw_unpack_file.hpp
-- Installing: /usr/local/eosio/include/fc/io/raw_variant.hpp
-- Installing: /usr/local/eosio/include/fc/io/sstream.hpp
-- Installing: /usr/local/eosio/include/fc/io/varint.hpp
-- Up-to-date: /usr/local/eosio/include/fc/log
-- Installing: /usr/local/eosio/include/fc/log/appender.hpp
-- Installing: /usr/local/eosio/include/fc/log/console_appender.hpp
-- Installing: /usr/local/eosio/include/fc/log/file_appender.hpp
-- Installing: /usr/local/eosio/include/fc/log/gelf_appender.hpp
-- Installing: /usr/local/eosio/include/fc/log/logger.hpp
-- Installing: /usr/local/eosio/include/fc/log/logger_config.hpp
-- Installing: /usr/local/eosio/include/fc/log/log_message.hpp
-- Installing: /usr/local/eosio/include/fc/make_fused.hpp
-- Up-to-date: /usr/local/eosio/include/fc/network
-- Up-to-date: /usr/local/eosio/include/fc/network/http
-- Installing: /usr/local/eosio/include/fc/network/http/http_client.hpp
-- Installing: /usr/local/eosio/include/fc/network/ip.hpp
-- Installing: /usr/local/eosio/include/fc/network/message_buffer.hpp
-- Installing: /usr/local/eosio/include/fc/network/resolve.hpp
-- Installing: /usr/local/eosio/include/fc/network/udp_socket.hpp
-- Installing: /usr/local/eosio/include/fc/network/url.hpp
-- Installing: /usr/local/eosio/include/fc/noncopyable.hpp
-- Installing: /usr/local/eosio/include/fc/optional.hpp
-- Installing: /usr/local/eosio/include/fc/platform_independence.hpp
-- Installing: /usr/local/eosio/include/fc/real128.hpp
-- Up-to-date: /usr/local/eosio/include/fc/reflect
-- Installing: /usr/local/eosio/include/fc/reflect/reflect.hpp
-- Installing: /usr/local/eosio/include/fc/reflect/typename.hpp
-- Installing: /usr/local/eosio/include/fc/reflect/variant.hpp
-- Up-to-date: /usr/local/eosio/include/fc/rpc
-- Installing: /usr/local/eosio/include/fc/rpc/api_connection.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/binary_api_connection.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/cli.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/http_api.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/json_connection.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/variant_connection.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/variant_stream.hpp
-- Installing: /usr/local/eosio/include/fc/rpc/websocket_api.hpp
-- Installing: /usr/local/eosio/include/fc/safe.hpp
-- Installing: /usr/local/eosio/include/fc/scoped_exit.hpp
-- Installing: /usr/local/eosio/include/fc/shared_ptr.hpp
-- Installing: /usr/local/eosio/include/fc/smart_ref_fwd.hpp
-- Installing: /usr/local/eosio/include/fc/smart_ref_impl.hpp
-- Installing: /usr/local/eosio/include/fc/static_variant.hpp
-- Installing: /usr/local/eosio/include/fc/string.hpp
-- Installing: /usr/local/eosio/include/fc/time.hpp
-- Installing: /usr/local/eosio/include/fc/tuple.hpp
-- Installing: /usr/local/eosio/include/fc/uint128.hpp
-- Installing: /usr/local/eosio/include/fc/unique_ptr.hpp
-- Installing: /usr/local/eosio/include/fc/utf8.hpp
-- Installing: /usr/local/eosio/include/fc/utility.hpp
-- Installing: /usr/local/eosio/include/fc/variant.hpp
-- Installing: /usr/local/eosio/include/fc/variant_object.hpp
-- Installing: /usr/local/eosio/include/fc/vector.hpp
-- Installing: /usr/local/eosio/include/fc/vector_fwd.hpp
-- Installing: /usr/local/eosio/lib/libbuiltins.a
-- Up-to-date: /usr/local/eosio/include/softfloat
-- Installing: /usr/local/eosio/include/softfloat/internals.h
-- Installing: /usr/local/eosio/include/softfloat/opts-GCC.h
-- Installing: /usr/local/eosio/include/softfloat/primitives.h
-- Installing: /usr/local/eosio/include/softfloat/primitiveTypes.h
-- Installing: /usr/local/eosio/include/softfloat/softfloat.h
-- Installing: /usr/local/eosio/include/softfloat/softfloat.hpp
-- Installing: /usr/local/eosio/include/softfloat/softfloat_types.h
-- Installing: /usr/local/eosio/lib/libsoftfloat.a
-- Up-to-date: /usr/local/eosio/include/chainbase
-- Installing: /usr/local/eosio/include/chainbase/chainbase.hpp
-- Installing: /usr/local/eosio/lib/libchainbase.a
-- Up-to-date: /usr/local/eosio/include/wasm-jit
-- Up-to-date: /usr/local/eosio/include/wasm-jit/Emscripten
-- Installing: /usr/local/eosio/include/wasm-jit/Emscripten/Emscripten.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/Inline
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/BasicTypes.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/CMakeLists.txt
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/DenseStaticIntSet.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/Errors.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/Floats.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/Serialization.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/Timing.h
-- Installing: /usr/local/eosio/include/wasm-jit/Inline/UTF8.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/IR
-- Installing: /usr/local/eosio/include/wasm-jit/IR/IR.h
-- Installing: /usr/local/eosio/include/wasm-jit/IR/Module.h
-- Installing: /usr/local/eosio/include/wasm-jit/IR/OperatorPrinter.h
-- Installing: /usr/local/eosio/include/wasm-jit/IR/Operators.h
-- Installing: /usr/local/eosio/include/wasm-jit/IR/Types.h
-- Installing: /usr/local/eosio/include/wasm-jit/IR/Validate.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/Logging
-- Installing: /usr/local/eosio/include/wasm-jit/Logging/Logging.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/Platform
-- Installing: /usr/local/eosio/include/wasm-jit/Platform/Platform.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/Runtime
-- Installing: /usr/local/eosio/include/wasm-jit/Runtime/Intrinsics.h
-- Installing: /usr/local/eosio/include/wasm-jit/Runtime/Linker.h
-- Installing: /usr/local/eosio/include/wasm-jit/Runtime/Runtime.h
-- Installing: /usr/local/eosio/include/wasm-jit/Runtime/TaggedValue.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/WASM
-- Installing: /usr/local/eosio/include/wasm-jit/WASM/WASM.h
-- Up-to-date: /usr/local/eosio/include/wasm-jit/WAST
-- Installing: /usr/local/eosio/include/wasm-jit/WAST/TestScript.h
-- Installing: /usr/local/eosio/include/wasm-jit/WAST/WAST.h
-- Installing: /usr/local/eosio/lib/libIR.a
-- Installing: /usr/local/eosio/lib/libLogging.a
-- Installing: /usr/local/eosio/lib/libPlatform.a
-- Installing: /usr/local/eosio/bin/eosio-wast2wasm
-- Installing: /usr/local/eosio/lib/libRuntime.a
-- Installing: /usr/local/eosio/lib/libWASM.a
-- Installing: /usr/local/eosio/lib/libWAST.a
-- Installing: /usr/local/eosio/lib/libappbase.a
-- Installing: /usr/local/eosio/include/appbase/application.hpp
-- Installing: /usr/local/eosio/include/appbase/channel.hpp
-- Installing: /usr/local/eosio/include/appbase/method.hpp
-- Installing: /usr/local/eosio/include/appbase/plugin.hpp
-- Installing: /usr/local/eosio/include/appbase/version.hpp
-- Up-to-date: /usr/local/eosio/include/appbase
-- Installing: /usr/local/eosio/lib/libeosio_chain.a
-- Up-to-date: /usr/local/eosio/include/eosio/chain
-- Installing: /usr/local/eosio/include/eosio/chain/abi_def.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/abi_serializer.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/account_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/action.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/action_receipt.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/apply_context.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/asset.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/authority.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/authority_checker.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/authorization_manager.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_header.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_header_state.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_log.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_state.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_summary_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/block_timestamp.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/chain_config.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/chain_id_type.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/config.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/contract_table_objects.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/contract_types.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/controller.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/eosio_contract.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/exceptions.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/fixed_key.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/fork_database.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/generated_transaction_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/genesis_state.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/global_property_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/incremental_merkle.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/merkle.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/multi_index_includes.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/name.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/permission_link_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/permission_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/producer_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/producer_schedule.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/protocol.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/resource_limits.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/resource_limits_private.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/reversible_block_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/symbol.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/trace.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/transaction.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/transaction_context.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/transaction_metadata.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/transaction_object.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/types.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_eosio_binary_ops.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_eosio_constraints.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_eosio_injection.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_eosio_validation.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_interface.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wasm_interface_private.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/wast_to_wasm.hpp
-- Installing: /usr/local/eosio/include/eosio/chain/core_symbol.hpp
-- Installing: /usr/local/eosio/lib/libeosio_testing.a
-- Installing: /usr/local/eosio/include/eosio/testing/chainbase_fixture.hpp
-- Installing: /usr/local/eosio/include/eosio/testing/tester.hpp
-- Installing: /usr/local/eosio/include/eosio/testing/tester_network.hpp
-- Up-to-date: /usr/local/eosio/include/eosio/testing
-- Installing: /usr/local/eosio/bin/nodeos
-- Up-to-date: /usr/local/eosio/var/log/eosio
-- Up-to-date: /usr/local/eosio/var/lib/eosio
-- Installing: /usr/local/eosio/bin/cleos
-- Installing: /usr/local/eosio/bin/keosd
-- Installing: /usr/local/eosio/bin/eosio-launcher
-- Installing: /usr/local/eosio/bin/eosio-abigen
-- Installing: /usr/local/eosio/bin/eosiocpp
```
* check for compiling "hello.cpp" using `eosiocpp`
  
