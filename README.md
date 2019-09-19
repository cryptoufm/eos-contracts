# EOS-Contracts

## Introduction
The idea behind this project is to create a Game that has it's backend based purely off BlockChain.
We wanted to create a Game that would be fun to play and that would simmulate how real transactions work.

To achieve this, we decided to use EOS because the response time is quite fast (less than 5 seconds). 

We based the game on the Jungle TestNet as they provide the ability to claim 100 EOS every 6 hours. With this, we could buy as much RAM as needed, and could also deploy our Contracts in it for the game to run in.

We also wanted to leave the game as Open Source, so anyone could come into this Repositoy and run the commands, while also having the ability to change the parameters for the game to adapt to their own needs.

## Objectives
To understand how BlockChain and EOS in specific work. 
The concepts we want to expand our knowledge in are: 
  - Contracts
  - Tokens
  - Multi Index Tables
  - BlockChains

Based on what we learned, the final objective was to create a Treasure-Hunt like game, where the backend would be solely based in BlockChain.

## Tools Used
  - EOS Jungle Test Net
  - EOSIO (version=1.7.0.1 ubuntu-18.04_amd)
  - Eosio.cdt (version=1.6.1)
  - Eosio.contracts
  - Visual Code (To program C++ programs)
  - Eosi ToolKits (Abigen, keosd, nodeos, Cpp, Hpp, Wasm)
  
## What did we do
  Next, we sill describe step by step how we did it
  
  1. Install Eosio version 1.7.0.1-ubuntu-18.04_amd
  2. Let us start keosd
  3. Start the nodeos
  4. Install the eosio.cdt version 1.6.1
  5. Build the sh
  6. Create a Cleos Wallet
  7. Create a Jungle Test Net account at https://monitor.jungletestnet.io/#home
  8. Claim your first 100 EOS and Buy More RAM
  9. Create Account and Import your Private Key
  10. Create a key and sabe it (Public key)
  11. Run 'Cleos wallet import' and insert the development key: 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
  12. Create Account for Contract
  13. Compile the Contract
  14. Deploy the Contract
  15. Call the contract
  16. Check if your contract is deployed here: https://jungle.bloks.io (Search for your Jungle account)
  17. Create a Multi Index Table with the desired types(Parameters)
  18. Deploy your Multi Index Table with an account different to that where you have your contract.
  19. Check if your table has been deployed here: https://jungle.bloks.io (Search for your Jungle account)
  20. Call the contract with the table to check it works properly
  
## Multi Index Table
Multi Index Tables are a way to cache state and/or data in RAM for fast access. 
They suppoert Create, Read, Update and Delete (CRUD) operations.
Conceptually they are stored on the EOSIO RAM cache. Each smart contract using a multi index  		table reserves a partition of the RAM cache.

Multi Index Tables provide a fast way to access data store and are a practical way to store 		data for use in your smart contract.

They are called Multi Index Tables as they support using multiple indexes on the data. 
The primary index type must be uint64_t and must be unique. However, secondary indexes may 		have duplicates.

If you want to index on a string you will need to convert this to an integer type, and store the results in a field that you then index.
  
## What's the reason behind the project
We wanted to learn about BlockChain, expanding our knowledge in how it works and develop the ability to create a game using a backend based purely off BlockChain.
The idea was to create a game that would be fun to play and would emulate how real transactions work.

## How did we do it
Firstly, we completed the EOS Developer Tutorial on the EOS website that can be found here: https://developers.eos.io/eosio-home/docs/10-big-picture

Secondly, after doing the tutorial we had a very good idea of how the Contracts, Tokens and Tables worked, so we simply had to look for more advanced help while implementing our own Contracts.
For that, we used several links, all of them can be found here: 

https://developers.eos.io/eosio-cleos/reference
https://hackernoon.com/how-to-create-and-deploy-your-own-eos-token-1f4c9cc0eca1
https://www.academiablockchain.com/2019/08/27/tutorial-como-crear-un-hello-world-contract-en-eos/
https://blog.springrole.com/the-mechanics-behind-eosio-ram-allocation-940204bc5b7e
https://docs.jungletestnet.io/docs/qa
https://medium.com/eos-new-york/managing-your-eos-owner-active-permissions-c76bdaf24e6b

https://steemit.com/eos/@eos-asia/deploying-your-first-production-eos-dapp
https://medium.com/infinitexlabs/the-ultimate-end-to-end-eos-dapp-development-tutorial-part-1-2f99c512086c
https://developers.eos.io/eosio-home/docs


https://jungle.bloks.io/
https://github.com/CryptoLions/EOS-Jungle-Testnet

## Playable Game
The final product is a Treasure Hunt Game where players start with a fixed ammount of Money. The objective of the game is to find 6 hidden 'Treasures' (in our case, QR Codes). For each of this treasures, the played has the ability to buy 2 hints. The first hint is the cheaper one, but is also quite vague. The second hint is more expensive, but will lead you directly to the treasure.
The Reward given when the player finds a Treasure would vary depending on how much time they take to find it, and depending on how many hints they have used.
