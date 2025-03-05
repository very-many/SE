## 3.1
Klassen **Sensor** und **TempSensor**:

```C++
class Sensor{
public:
	Sensor (string stadt);
	virtual ~Sensor();
	virtual void print() = 0;

protected:
	string stadt;
};

class TempSensor : public Sensor{
public:
	TempSensor(string stadt);
	double getTemp();
	voud print();
};

Sensor :: Sensor(string stadt){
	this -> stadt = stadt;
}
TempSensor(string stadt) : Sensor(stadt) {}

void Tempsensor :: print() {
	cout << "Temperatur in " << stadt << ": " << getTemp() << endl;
}
```

## 3.2
```C++
class StromNetz
list<Sensor*> sensoren;
public:
	Sensornetz() {};
	~Sensornetz();
	void print();
	void neuerWindSensor(string stadt);
	void neuerDruckSensor(string stadt);
};

Sensornetz :: ~Sensornetz(){
	while (!sensoren.empty()){
		delete *sensoren.begin();
		sensoren.pop_front;
	}
}

void Sensornetz :: neuerWindSensor(string stadt){
	//gibt noch keinen Windsensor, aber analog zu ds
}
void Sensornetz :: neuerDruckSensor(string stadt){
	DruckSensor *ds = new Drucksensor(stadt);
	sensoren.push_back(ds);
}

void Sensornetz :: print(){
	list<sensor *>::iterator pos = sensoren.begin();
	while (pos != sensoren.end()){
		(*pos) -> print();
	}
}
```
