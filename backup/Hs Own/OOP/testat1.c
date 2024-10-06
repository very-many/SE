#include <stdlib.h>		/* malloc, exit, NULL */
#include <stdio.h>		/* printf */

/* Zeichenkette variabler Länge. */
typedef const char* String;

/* Dynamisches Objekt der Größe n Byte erzeugen. */
void* newObject (int n) {
    void* this = malloc(n);
    if (this == NULL) {
	printf("newObject: out of memory\n");
	exit(1);
    }
    return this;
}

/* Funktionszeigersatz für Konten. */
struct AccountOps {
    void (*deposit) ();		/* Funktion für Einzahlung. */
    void (*withdraw) ();	/* Funktion für Abhebung. */
    void (*transfer) ();	/* Funktion für Überweisung. */
};

/* Konto. */
struct Account {
    struct AccountOps* ops;	/* Zeiger auf Funktionszeigersatz. */
    long number;		/* Kontonummer. */
    String holder;		/* Kontoinhaber. */
    long balance;		/* Kontostand in Cent. */
};

/* Zeiger auf Konto. */
typedef void* Account;		/* Achtung: void*! */

/*
 * Funktionen für alle Arten von Konten.
 */

/* Nummer von Konto this liefern. */
long number (struct Account* this) {
    return this->number;
}

/* Inhaber von Konto this liefern. */
String holder (struct Account* this) {
    return this->holder;
}

/* Kontostand von Konto this liefern. */
long balance (struct Account* this) {
    return this->balance;
}

/* Betrag amount auf Konto this einzahlen. */
void deposit (struct Account* this, long amount) {
    this->ops->deposit(this, amount);
}

/* Betrag amount von Konto this abheben. */
void withdraw (struct Account* this, long amount) {
    this->ops->withdraw(this, amount);
}

/* Betrag amount von Konto this auf Konto that überweisen. */
void transfer (struct Account* this, long amount, Account that) {
    this->ops->transfer(this, amount, that);
}

/*
 * Funktionen für gewöhnliche Konten.
 */

/* Implementierung von deposit für Account-Objekte. */
void depositAccount (struct Account* this, long amount) {
    this->balance += amount;
}

/* Implementierung von withdraw für Account-Objekte. */
void withdrawAccount (struct Account* this, long amount) {
    this->balance -= amount;
}

/* Implementierung von transfer für Account-Objekte. */
void transferAccount (struct Account* this, long amount,
					struct Account* that) {
    withdraw(this, amount);
    deposit(that, amount);
}

/* Funktionszeigersatz für gewöhnliche Konten. */
struct AccountOps opsAccount = {
    depositAccount, withdrawAccount, transferAccount
};

/* Nächste zu vergebende Kontonummer. */
long nextNumber = 1;

/* Gewöhnliches Konto this mit Inhaber h initialisieren. */
void initAccount (struct Account* this, String h) {
    this->number = nextNumber++;
    this->holder = h;
    this->balance = 0;
}

/* Gewöhnliches Konto mit Inhaber h erzeugen. */
Account newAccount (String h) {
    struct Account* this = newObject(sizeof(struct Account));
    this->ops = &opsAccount;
    initAccount(this, h);
    return this;
}

/*
 * Funktionen für limitierte Konten.
 */

/* Limitiertes Konto. */
struct LimitedAccount {
    struct Account super;	/* Account-Daten. */
    long limit;			/* Kreditlinie in Cent (positiv). */
};

/* Zeiger auf limitiertes Konto. */
typedef void* LimitedAccount;	/* Achtung: void*! */

/* Kreditlinie des limitierten Kontos this liefern. */
long limit (struct LimitedAccount* this) {
    return this->limit;
}

/* Überprüfen, ob Betrag amount von limitiertem Konto this */
/* abgezogen werden kann, ohne die Kreditlinie zu überschreiten. */
int check (struct LimitedAccount* this, long amount) {
    if (this->super.balance - amount >= -this->limit) return 1;
    printf("Unzulässige Kontoüberziehung!\n");
    return 0;
}

/* Implementierung von withdraw für LimitedAccount-Objekte. */
void withdrawLimitedAccount (struct LimitedAccount* this, long amount) {
    if (check(this, amount)) {
	withdrawAccount((struct Account*)this, amount);
    }
}

/* Implementierung von transfer für LimitedAccount-Objekte. */
void transferLimitedAccount (struct LimitedAccount* this,
				   long amount, struct Account* that) {
    if (check(this, amount)) {
	transferAccount((struct Account*)this, amount, that);
    }
}

/* Funktionszeigersatz für limitierte Konten. */
struct AccountOps opsLimitedAccount = {
    depositAccount, withdrawLimitedAccount, transferLimitedAccount
};

/* Limitiertes Konto this mit Inhaber h */
/* und Kreditlinie l initialisieren. */
void initLimitedAccount (struct LimitedAccount* this, String h, long l) {
    initAccount((struct Account*)this, h);
    this->limit = l;
}

/* Limitiertes Konto mit Inhaber h und Kreditlinie l erzeugen. */
LimitedAccount newLimitedAccount (String h, long l) {
    struct LimitedAccount* this =
			    newObject(sizeof(struct LimitedAccount));
    this->super.ops = &opsLimitedAccount;
    initLimitedAccount(this, h, l);
    return this;
}



/* 
 * Funktionen für Gebührenpflichtige Konten 
 */
struct ChargedAccount {
    struct Account super;	/* Account-Daten. */
    long count;			/* Anzahl ausgeführter Buchungen */ // TODO: Anfangswert auf 0 setzen
};

typedef void* ChargedAccount;
/* Zieht pro count amount vom Konto ab (als Gebühr).*/
int charge (struct ChargedAccount* this, long amount) {
    if (this->count <= 0){
        this->count = 0;
        return 0;
    }
    withdrawAccount((struct Account*)this, this->count*amount);
    return 0;
}
/* Gebühren. Konto this mit Inhaber h */
/* und anz. Buchungen initialisieren. */
void initChargedAccount (struct ChargedAccount* this, String h) {
    initAccount((struct Account*)this, h);
    this->count = 0;
}
/* Implementierung von withdraw für ChargedAccount-Objekte. */
/* d.h. count wird um 1 erhöht.*/
void withdrawChargedAccount (struct ChargedAccount* this, long amount) {
	withdrawAccount((struct Account*)this, amount);
    this->count++;
}
void depositChargedAccount (struct ChargedAccount* this, long amount) {
	depositAccount((struct Account*)this, amount);
    this->count++;
}
/* Funktionszeigersatz für gebühren. Konten. */
struct AccountOps opsChargedAccount = {
    depositChargedAccount, withdrawChargedAccount, transferAccount
};
/* gebühren. Konto mit Inhaber h erzeugen. */
ChargedAccount newChargedAccount (String h) {
    struct ChargedAccount* this =
			    newObject(sizeof(struct ChargedAccount));
    this->super.ops = &opsChargedAccount;
    initChargedAccount(this, h);
    return this;
}



/* Testprogramm. */

int main(){
	Account a1 = newAccount("Heinlein");
	LimitedAccount a2 = newLimitedAccount("Winker", 800);
    ChargedAccount a3 = newChargedAccount("Richter");
	deposit (a1, 1000);
    deposit (a2, 1000);
    withdraw(a2, 1000);
    deposit(a3, 1500);
    withdraw(a3, 1000);
    transfer(a3, 100, a2);
    charge(a3, 100);
    charge(a1, 100);
	printf("%ld %s %ld\n", number(a1), holder(a1), balance(a1)); 
    printf("%ld %s %ld\n", number(a2), holder(a2), balance(a2)); 
    printf("%ld %s %ld\n", number(a3), holder(a3), balance(a3));

	return 0;
}