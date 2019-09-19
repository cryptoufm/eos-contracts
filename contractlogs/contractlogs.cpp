#include <eosio/eosio.hpp>

using namespace eosio;

class [[eosio::contract("contractlogs")]] contractlogs : public eosio::contract {

    
  public:

    contractlogs(name receiver, name code, datastream<const char*> ds):contract(receiver, code, ds) {}
    
    [[eosio::action]]
    void insert(name user, std::string player_name, std::string action, std::string time_stampt, std::string location, std::string balance_before, std::string balance_after) {
        require_auth( user );
        player_logs crudlogs(get_self(), get_first_receiver().value);
        crudlogs.emplace(user, [&]( auto& row ) {
          row.key = user;
          row.player_name = player_name;
          row.action = action;
          row.time_stampt = time_stampt;
          row.location = location;
          row.balance_before = balance_before;
          row.balance_after = balance_after;
        });
    }

    // [[eosio::action]]
    // void erase(name user) {
    //     require_auth(user);
    //     player_logs crudlogs( get_self(), get_first_receiver().value);

    //     auto iterator = crudlogs.find(user.value);
    //     check(iterator != crudlogs.end(), "Player does not exist");
    //     crudlogs.erase(iterator);
    // }


  private:
    struct [[eosio::table]] player {
      name key;
      std::string player_name;
      std::string action;
      std::string time_stampt;
      std::string location;
      std::string balance_before;
      std::string balance_after;
      
    
      uint64_t primary_key() const { return key.value;}
    };
  
    typedef eosio::multi_index<"logs"_n, player> player_logs;
};
