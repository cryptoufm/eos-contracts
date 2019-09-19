# Contract Token
The contracct is a contract developed in C ++ for EOS using the standar eosio.token

## Fuctions 
* Insert
This function is responsible for inserting the data into the player table which has the following structure.
row.key = user;
row.player_name = player_name;
row.balance = balance;
row.email = email;

* Modify
Modify the actual row of the account name player and update values.

* Erase
Erase row by accountname.

## Build Proccess:
* Create a Struct
	Create a struct of multi index table, and define getters on. 
* Compile
    eosio-cpp contracplayer.cpp -o contracplayer.wasm
* Deploy Contract to Jungle testnet 
    cleos -u http://jungle2.cryptolions.io:80 set contract AccountName PathContract/contractplayer -p AccountName@active
* Call Contract
    cleos -u http://jungle2.cryptolions.io:80 push action AccountNameContract FunctionName '["Data"]' -p AccountName@active

* Get table players
    cleos -u http://jungle2.cryptolions.io:80 get table AccountNameContract AccountNameContract players
