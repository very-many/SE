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

struct Account* newAccount (string h){
	struct Account* a = malloc(sizeof(struct Account));

	if(a == NULL){
		printf("Out of Memory\n")
		exit(1);
	}

	a->number = nextNumber++;
	a->holder = h;
	a->balance = 0;
	
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

int main(){
	Account a1 = newAccount("Heinlein");
	Account a2 = newAccount("Maier");
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