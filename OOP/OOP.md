# 11.03.24
``` C
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

/* Testprogramm. */

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

```Java
// Klasse: Konto.
class Account {
	// Objektvariablen:
	private int number; // Kontonummer.
	private String holder; // Kontoinhaber.
	private int balance; // Kontostand in Cent.
	// Klassenvariable: Nächste zu vergebende Kontonummer.
	private static int nextNumber = 1;
	// Konstruktor:
	// Konto mit Inhaber h, eindeutiger Nummer
	// und Anfangsbetrag 0 initialisieren.
	public Account (String h) {
		this.number = nextNumber++;
		this.holder = h;
		this.balance = 0;
	}
// Objektmethoden: Kontonummer/-inhaber/-stand abfragen.
	public int number () {
		return this.number;
	}
	public String holder () {
		return this.holder;
	}
	public int balance () {
		return this.balance;
	}
	// Objektmethoden: Betrag amount einzahlen/abheben/überweisen.
	public void deposit (int amount) {
		this.balance += amount;
	}
	public void withdraw (int amount) {
		this.balance -= amount;
	}
	public void transfer (int amount, Account that) {
		this.withdraw(amount);
		that.deposit(amount);
	}
}
// Unterklasse von Account: Limitiertes Konto.
class LimitedAccount extends Account {
	// Zusätzliche Objektvariable:
	private int limit; // Kreditlinie in Cent.
	// Konstruktor:
	// Limitiertes Konto mit Inhaber h, Kreditlinie l,
	// eindeutiger Nummer und Anfangsbetrag 0 initialisieren.
	public LimitedAccount (String h, int l) {
		// Konstruktor der Oberklasse Account aufrufen,
		// um deren Objektvariablen zu initialisieren.
		super(h);
		limit = l;
	}
	// Zusätzliche Objektmethode: Kreditlinie abfragen.
	public int limit () { 
		return limit; 
	}
	// Hilfsmethode: Kann Betrag amount abgezogen werden,
	// ohne die Kreditlinie zu überschreiten?
	private boolean check (int amount) {
		if (balance() - amount >= -limit) return true;
		System.out.println("Unzulässige Kontoüberziehung!");
		return false;
	}
	// Überschreiben geerbter Objektmethoden:
	// Betrag amount abheben/überweisen.
	public void withdraw (int amount) {
		if (check(amount)) {
			// Überschriebene Methode aufrufen.
			super.withdraw(amount);
		}
	}
	public void transfer (int amount, Account that) {
		if (check(amount)) {
			// Überschriebene Methode aufrufen.
			super.transfer(amount, that);
		}
	}
}

class Test {
	// Hauptprogramm.
	public static void main (String [] args) {
		// Objekte erzeugen und durch Konstruktoraufrufe initialisieren.
		LimitedAccount a = new LimitedAccount("Max Mustermann", 500);
		Account b = new Account("Erika Mustermann");
		// Methoden auf Objekten aufrufen.
		a.deposit(1000);
		a.transfer(300, b);
		a.withdraw(2000);
		b.withdraw(2000);
		// Ausgabe.
		System.out.println("Konto a: " +
		a.number() + " " + a.holder() + " " + a.balance());
		System.out.println("Konto b: " +
		b.number() + " " + b.holder() + " " + b.balance());
	}
}