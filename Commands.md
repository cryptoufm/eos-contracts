*** Note that the contract name and the Folder it's in must have the same name ***

Create Wallet 

```cleos wallet create -n <WalletName> -f Doc.txt```

Open Wallet

```cleos wallet open -n <WalletName>```

Unlock Wallet

```cleos wallet unlock -n <WalletName> --password <KeyPrivate>```

Import Private Key

```cleos wallet import -n <WalletName>```

```cleos -u http://jungle2.cryptolions.io:80 get account <YourAccount>```

Buy RAM

```cleos -u http://jungle2.cryptolions.io:80 system buyram <YourAccount> <YourAccount> <AmmountInEOS>```

Compile Contract

```eosio-cpp <contract>.cpp -o <contract>.wasm```

Deploy Contract

```cleos -u http://jungle2.cryptolions.io:80 set contract <YourAccount> <../ContractDir> -p account@active```

executed transaction: 4bbc4b90dcceb115a6e7a1b3ff30522460a2897f643608e08ed1bcfa9035fa76  712 

Check if your contract has been succesfully deployed at: https://jungle.bloks.io/ (Look for your account)

Call Contract

```cleos -u http://jungle2.cryptolions.io:80 push action <Contract> hi '["XXX"]' -p account@active```

Create Private/public kbytes

```cleos -u http://jungle2.cryptolions.io:80 create key -f KeysUser.txt```

Create account to Jungle Testnet

```cleos -u http://jungle2.cryptolions.io:80 system newaccount --stake-net "<AmmountInEOS>" --stake-cpu "<AmmountInEOS>" --buy-ram-kbytes 4 <AccountOwner> <NewAccountName> <OwnerPublicKey> <ActivePublicKey>```

Send EOS

```cleos -u http://jungle2.cryptolions.io:80 transfer <YourAccount> AccountToSend "<AmmountInEOS>" "<Message>"```
