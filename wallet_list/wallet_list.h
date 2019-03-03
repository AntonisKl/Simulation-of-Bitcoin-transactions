#ifndef WALLET_LIST_H
#define WALLET_LIST_H

#include "../utils/utils.h"
#include "../bitcoin_tree_list/bitcoin_tree_list.h"

typedef struct Wallet {
    char* walletId;
    unsigned int balance;
    BitcoinList* bitcoinList; // bitcoins owned by this user
    struct Wallet* nextWallet;
} Wallet;

typedef struct WalletList {
    Wallet* firstWallet;
    unsigned int size;
} WalletList;

WalletList* initWalletList();

Wallet* initWallet(char* walletId, unsigned int balance, BitcoinList* bitcoinList);

void freeWallet(Wallet** wallet);

void freeWalletRec(Wallet** wallet);

void freeWalletList(WalletList** walletList);

Wallet* findWalletInWalletList(WalletList* walletList, char* walletId);

Wallet* addWalletToWalletList(WalletList* walletList, char* walletId, unsigned int balance, BitcoinList* bitcoinList);

#endif