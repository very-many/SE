Das hier ist der vorgegebene Code für gewöhnliche und limitierte Konten, der erweitert werden soll.
``` C
#include <stdlib.h>		/* malloc, exit, NULL */
#include <stdio.h>		/* printf */

/* Zeichenkette variabler LÃ¤nge. */
typedef const char* String;

/* Dynamisches Objekt der GrÃ¶ÃŸe n Byte erzeugen. */
void* newObject (int n) {
    void* this = malloc(n);
    if (this == NULL) {
	printf("newObject: out of memory\n");
	exit(1);
    }
    return this;
}

/* Funktionszeigersatz fÃ¼r Konten. */
struct AccountOps {
    void (*deposit) ();		/* Funktion fÃ¼r Einzahlung. */
    void (*withdraw) ();	/* Funktion fÃ¼r Abhebung. */
    void (*transfer) ();	/* Funktion fÃ¼r Ãœberweisung. */
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
 * Funktionen fÃ¼r alle Arten von Konten.
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

/* Betrag amount von Konto this auf Konto that Ã¼berweisen. */
void transfer (struct Account* this, long amount, Account that) {
    this->ops->transfer(this, amount, that);
}

/*
 * Funktionen fÃ¼r gewÃ¶hnliche Konten.
 */

/* Implementierung von deposit fÃ¼r Account-Objekte. */
void depositAccount (struct Account* this, long amount) {
    this->balance += amount;
}

/* Implementierung von withdraw fÃ¼r Account-Objekte. */
void withdrawAccount (struct Account* this, long amount) {
    this->balance -= amount;
}

/* Implementierung von transfer fÃ¼r Account-Objekte. */
void transferAccount (struct Account* this, long amount,
					struct Account* that) {
    withdraw(this, amount);
    deposit(that, amount);
}

/* Funktionszeigersatz fÃ¼r gewÃ¶hnliche Konten. */
struct AccountOps opsAccount = {
    depositAccount, withdrawAccount, transferAccount
};

/* NÃ¤chste zu vergebende Kontonummer. */
long nextNumber = 1;

/* GewÃ¶hnliches Konto this mit Inhaber h initialisieren. */
void initAccount (struct Account* this, String h) {
    this->number = nextNumber++;
    this->holder = h;
    this->balance = 0;
}

/* GewÃ¶hnliches Konto mit Inhaber h erzeugen. */
Account newAccount (String h) {
    struct Account* this = newObject(sizeof(struct Account));
    this->ops = &opsAccount;
    initAccount(this, h);
    return this;
}

/*
 * Funktionen fÃ¼r limitierte Konten.
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

/* ÃœberprÃ¼fen, ob Betrag amount von limitiertem Konto this */
/* abgezogen werden kann, ohne die Kreditlinie zu Ã¼berschreiten. */
int check (struct LimitedAccount* this, long amount) {
    if (this->super.balance - amount >= -this->limit) return 1;
    printf("UnzulÃ¤ssige KontoÃ¼berziehung!\n");
    return 0;
}

/* Implementierung von withdraw fÃ¼r LimitedAccount-Objekte. */
void withdrawLimitedAccount (struct LimitedAccount* this, long amount) {
    if (check(this, amount)) {
	withdrawAccount((struct Account*)this, amount);
    }
}

/* Implementierung von transfer fÃ¼r LimitedAccount-Objekte. */
void transferLimitedAccount (struct LimitedAccount* this,
				   long amount, struct Account* that) {
    if (check(this, amount)) {
	transferAccount((struct Account*)this, amount, that);
    }
}

/* Funktionszeigersatz fÃ¼r limitierte Konten. */
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
```