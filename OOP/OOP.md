# 11.03.24
``` C
#include <stdio.h>
#include <stdlib.h>

typedef const char* string
struct Account{
	long number;
	string holder;
	long balance; //Kontostand in Cent | long weil in meißten Fällen größer als Int
};

long nextNumber = 1; //Nächste zu vergebene KOntonummer

void* newObject (int n){
	void* obj = malloc(n);
	if(a == NULL){
		printf("Out of Memory\n")
		exit(1);
	}
}

void initAccount (struct Account* this, string h){
	this->number = nextNumber++;
	this->holder = h;
	this->balance = 0;
}

struct Account* newAccount (string h){
	struct Account* this = newObjet(sizeof(struct Account));
	initAccount(this, h);
	return a;
}

long number (struct Account* this){
	return this->number;
}
long holder (struct Account* this){
	return this->holder;
}
long balance (struct Account* this){
	return this->balance;
}

void deposit(struct Account* this, long amount){
	this->balance += Amount;
}
void withdraw(struct Account* this, long amount){
	this->balance -= Amount;
}
void transfer(struct Account* this, struct Account* that, long amount){
	withdraw(this, amount);
	deposit (that, amount);
}
typedef struct Account* Account;

/* ----------------------------- */

struct LimitedAccount {
struct Account super; //Erben bzw. Übernehmen von Account
	long limit = 1000; //Limit in Cents. (positiv)
};

void initLimitedAccount (struct LimitedAccount* this, string h, long l){
	initAccount((struct Account*)this, h);
	this->limit = l;
	
}

struct LimitedAccount* newLimitedAccount (string h, long l){
	struct Limited Account* this = newObject(sizeof(struct LimitedAccount);
	
}

/* ----------------------------- */

int main(){
	Account a1 = newAccount("Heinlein");
	Account a2 = newAccount("Maier");
	deposit (a1, 1000);
	printf("%ld %s %ld\n", number(a1), holder(a1), balance(a1)); 
	
}
```

## Datenkapselung/Geheimnisprinzip

Benutzer sehen / verwenden nur Dinge am rand der Kapsel (Public)

**Public**
- newAccount
- deposit
- withdraw
- transfer
- Account
- number
- holder
- balance

**Private**
- nextNumber
- struct Account
- malloc
- printf
- exit
