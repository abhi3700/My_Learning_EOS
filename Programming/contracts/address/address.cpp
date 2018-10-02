#include <eosiolib/eosio.hpp>
#include <string>

using eosio::indexed_by;
using eosio::const_mem_fun;
using std::string;

class addressbook : public eosio::contract {
public:
    // Constructor
    explicit addressbook(action_name self) : contract(self) {}

    // Add contacts
    //@abi action
    void add(const account_name account, const string& name, uint64_t phone) {

        // Get authorization, if there is no authorization, the Action call will be aborted and the transaction will be rolled back
        require_auth(account);

        //eosio::multi_index (multiple index table) can be used to read and modify the EOS database
        //address_index is self-defined eosio::multi_index

        //Instantiate the address data table (multi_index), the parameter is used to establish access to the table
        //If you access your own contract, you have read and write access, and the other person’s contract has read-only access.
        address_index addresses(_self, _self);

        // The multi_index find function queries the data by the primary key (primary_key), returning the iterator itr
        // auto Keywords will automatically match the type
        auto itr = addresses.find(account);
        //If the judgment condition is not true, the execution is terminated and an error message is printed.
        eosio_assert(itr == addresses.end(), "Address for account already exists");

        //adding data
        //Use storage to pay, the first parameter account is a paid account
        addresses.emplace(account, [&](auto& address){
            address.account = account;
            address.name = name;
            address.phone = phone;
        });
    }

    //Edit contact information
    //@abi action
    void update(const account_name account, const string& name, uint64_t phone) {
        require_auth(account);

        address_index addresses(_self, _self);

        auto itr = addresses.find(account);
        //If no account is found, print an error message and terminate
        eosio_assert(itr != addresses.end(), "Address for account not found");

        addresses.modify(itr, account, [&](auto& address){
            address.account = account;
            address.name = name;
            address.phone = phone;
        });
    }

    //Delete contact
    //@abi action
    void remove(const account_name account) {
        require_auth(account);

        address_index addresses(_self, _self);

        auto itr = addresses.find(account);
        eosio_assert(itr != addresses.end(), "Address for account not found");

        //delete
        addresses.erase(itr);
    }

    //Set contacts as special attention
    //@abi action
    void like(const account_name account) {

        //No need to get authorization, everyone can call like Action

        address_index addresses(_self, _self);

        auto itr = addresses.find(account);
        eosio_assert(itr != addresses.end(), "Address for account not found");

        //Modify the corresponding liked field
        addresses.modify(itr, 0, [&](auto& address){
            //Print message
            eosio::print("Liking: ", address.name.c_str(), "\n");
            address.liked++;
        });
    }

    //The function is the same as like(), but the data is queried by phone instead of the primary key.
    //@abi action
    void likebyphone(uint64_t phone) {
        address_index addresses(_self, _self);

        //Get a custom index
        auto phone_index = addresses.get_index<N(phone)>();
        auto itr = phone_index.lower_bound(phone);
        for(; itr != phone_index.end() && itr->phone == phone; ++itr) {
            phone_index.modify(itr, 0, [&](auto& address){
                eosio::print("Liking: ", address.name.c_str(), "\n");
                address.liked++;
            });
        }
    }


private:
    //Define the address table, i64 indicates that the index uses the default uint64_t type
    //@abi table address i64
    struct address {
        uint64_t account;
        string name;
        uint64_t phone;
        uint64_t liked;

        //Define the primary key of the address table, the address table is a multi-index table
        uint64_t primary_key() const { return account; }
        uint64_t get_phone() const {return phone; }

        EOSLIB_SERIALIZE(address, (account)(name)(phone)(liked));
    };

    //By default, the primary key index, using indexed_by, can be indexed by a custom function
    //Here is get_phone, which is indexed by phone field
    typedef eosio::multi_index< N(address), address,
            indexed_by<N(phone), const_mem_fun<address, uint64_t, &address::get_phone>>>
    address_index;
};

EOSIO_ABI(addressbook, (add)(update)(remove)(like)(likebyphone))

---------------------

Blog - https://blog.csdn.net/Leslie_Ran/article/details/80358517
