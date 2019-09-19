# Contract Logs
The contratolog is a contract developed in C ++ for EOS using Multi Index Tables for persitence.

## Fuctions 
* Insert
This function is responsible for inserting the data into the logs table which has the following structure.
row.player_name = player_name;
row.action = action;
row.time_stampt = time_stampt;
row.location = location;
row.balance_before = balance_before;
row.balance_after = balance_after;

## Build Proccess:
* Create a Struct
	Create a struct which can be stored in the multi index table, and define getters on 
* Compile
    eosio-cpp contraclogs.cpp -o contraclogs.wasm
* Deploy Contract to Jungle testnet 
    cleos -u http://jungle2.cryptolions.io:80 set contract AccountName PathContract/contratoufm -p AccountName@active
* Call Contract
    cleos -u http://jungle2.cryptolions.io:80 push action AccountNameContract FunctionName '["Data"]' -p AccountName@active

* Get table logs
    cleos -u http://jungle2.cryptolions.io:80 get table AccountNameContract AccountNameContract logs