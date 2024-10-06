#include <stdio.h>
#include <stdlib.h>

typedef const char* string;

struct Account{
	long number;
	string holder;
	long balance; //Kontostand in Cent | long weil in meißten Fällen größer als Int
};

long nextNumber = 1; //Nächste zu vergebene KOntonummer

void* newObject (int n){
	void* obj = malloc(n);
	if(obj == NULL){
		printf("Out of Memory\n");
		exit(1);
	}
    return obj;
}

void initAccount (struct Account* this, string h){
	this->number = nextNumber++;
	this->holder = h;
	this->balance = 0;
}

struct Account* newAccount (string h){
	struct Account* this = newObject(sizeof(struct Account));
	initAccount(this, h);
	return this;
}

long number (struct Account* this){
	return this->number;
}
string holder (struct Account* this){
	return this->holder;
}
long balance (struct Account* this){
	return this->balance;
}

void deposit(struct Account* this, long amount){
	this->balance += amount;
}
void withdraw(struct Account* this, long amount){
	this->balance -= amount;
}
void transfer(struct Account* this, struct Account* that, long amount){
	withdraw(this, amount);
	deposit (that, amount);
}
typedef void* Account;

/* ----------------------------- */

struct LimitedAccount {
    struct Account super; //Erben bzw. Übernehmen von Account
	long limit; //Limit in Cents. (positiv)
};

void initLimitedAccount (struct LimitedAccount* this, string h, long l){
	initAccount((struct Account*)this, h);
	this->limit = l;
	
}

struct LimitedAccount* newLimitedAccount (string h, long l){
	struct LimitedAccount* this = newObject(sizeof(struct LimitedAccount));
    initLimitedAccount(this, h, l);
    return this;
	
}

long limit (struct  LimitedAccount* this){
    return this->limit;
}

typedef void* LimitedAccount;

/* ----------------------------- */

int main(){
	Account a1 = newAccount("Heinlein");
	LimitedAccount a2 = newLimitedAccount("Maier", 1000);
	deposit (a1, 1000);
    withdraw (a2, 500000);
	printf("%ld %s %ld\n", number(a1), holder(a1), balance(a1)); 
	printf("%ld %s %ld\n", number(a2), holder(a2), balance(a2)); 


	
}