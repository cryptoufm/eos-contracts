#include <eosio/eosio.hpp>

using namespace eosio;

class [[eosio::contract("contractplayer")]] contractplayer : public eosio::contract {

    
  public:

    contractplayer(name receiver, name code, datastream<const char*> ds):contract(receiver, code, ds) {}
    
    [[eosio::action]]
    void insert(name user, std::string player_name, std::string balance, std::string email) {
        require_auth( user );
        player_index crudplayer(get_self(), get_first_receiver().value);
        auto iterator = crudplayer.find(user.value);
        if( iterator == crudplayer.end() )
        {
            crudplayer.emplace(user, [&]( auto& row ) {
            row.key = user;
            row.player_name = player_name;
            row.balance = balance;
            row.email = email;
            });
        }
        else {
            crudplayer.modify(iterator, user, [&]( auto& row ) {
            row.key = user;
            row.player_name = player_name;
            row.balance = balance;
            row.email = email;
            });
        }
    }


    [[eosio::action]]
    void erase(name user) {
        require_auth(user);
        player_index crudplayer( get_self(), get_first_receiver().value);

        auto iterator = crudplayer.find(user.value);
        check(iterator != crudplayer.end(), "Player does not exist");
        crudplayer.erase(iterator);
    }


  private:
    struct [[eosio::table]] player {
      name key;
      std::string player_name;
      std::string balance;
      std::string email;

      uint64_t primary_key() const { return key.value;}
    };
  
    typedef eosio::multi_index<"players"_n, player> player_index;
};
