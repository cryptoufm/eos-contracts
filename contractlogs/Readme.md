# Contract Logs
The contratolog is a contract developed in C ++ for EOS using Multi Index Tables for persitence.

## Fuctions 

EOS smart contract allows you to create your own token by providing the maximum Supply and the Token's literal.
The User can specify the maximum ammount of Tokens available, and the divisibility of such tokens. The token's symbol must also be specified and may have up to three characters, for instance; SYS.
The user has the ability to Create(Generate) Tokens, Issue(Distribute) Tokens, aswel as Transfer them to other accounts.

Further information on those functions can be found here:

 - Create: Used for creating new currency on this contract. 
	   This basically generates new currency that is specified by the contract owner. They must 
	   specify the Name of the generator, the ammount of 'coins' he wishes to create, followed 
 	   by the Symbol of such coin. The coin's symbol may have up to 3 characters.
	   To do so, the following command should be used:

	   cleos -u http://jungle2.cryptolions.io:80 push action AccountNameContract create 		   '[ "Name_Of_Creator", "<Ammount.Divisibility> <Symbol>"]' -p account@active

 - Issue: Issue the created currency from the creator's account, to other accounts. This allows the 		  person who created the tokens to send them to other accounts. For this to be possible the 
	  issuer must specify the account they wish to issue the Tokens to, the Ammount of Tokens 
	  followed by the token's symbol and lastly, an optional message can be included.
	  To do so, the following command should be used:

	  cleos -u http://jungle2.cryptolions.io:80 push action <contract> issue '[ "<Account>", 	 	  "<Ammount><Symbol>", "<Message>"]' -p account@active

 - Transfer: Transfer specified amount of currency from one account to another.
	     This allows accounts to interact with each other. An account may transfer tokens to 
	     another account. For this to be possible, they must specify the Account from which they 
	     wish to send Tokens from, the Account they wish to transfer Tokens to, The ammount of 
	     Tokens they wish to Transfer, followed by the Token's Symbol, and lastly, an optional 
	     message may be included.
	     To do so, the following command should be used:

	cleos -u http://jungle2.cryptolions.io:80 push action <Contract> transfer 		'[ "<From_Account>", "<To_Account>", "<Ammount><Symbol>", "<Message>" ]' -p 		  	   account@active

Persistent information, such as account balance and currency types are stored in RAM, and is accessed via multi-index tables.

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