#include<iostream>
using namespace std;

#define MIN_TANK_VOLUME 28
#define MAX_TANK_VOLUME 80

class Tank
{
	const int VOLUME;
	double fuel_level;
public:
	int get_VOLUME() const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	void fill(double fuel)
	{
		if (fuel < 0)return;
		fuel_level += fuel;
		if (fuel_level > VOLUME)fuel_level = VOLUME;
	}
	//               Constructors:
	Tank(int volume=40)
		:VOLUME
		(
			volume< MIN_TANK_VOLUME? MIN_TANK_VOLUME:
		    volume>MAX_TANK_VOLUME? MAX_TANK_VOLUME:
			volume
		)
	{
		fuel_level = 0;
		cout << "Tank is ready" << endl;
	}
	~Tank()
	{
		cout << "Tank is over" << endl;
	}

	// Methods:
	void info()const
	{
		cout << "Volume: " << VOLUME << " liters. \n";
		cout << "Fuel lvl:" << fuel_level << " liters. \n";
	}

};
#define MIN_ENGINE_CONSUPTION 4
#define MAX_ENGINE_CONSUPTION 30
class Engine
{
	double consumption;
	double consumption_per_second;
	bool is_started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	bool started()const
	{
		return is_started;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	void set_consumption(double consumption)
	{
		if (consumption < MIN_ENGINE_CONSUPTION)consumption = MIN_ENGINE_CONSUPTION;
		if (consumption > MAX_ENGINE_CONSUPTION)consumption = MAX_ENGINE_CONSUPTION;
		this->consumption = consumption;
		set_consumption_per_second();
	}
	void set_consumption_per_second()
	{
		consumption_per_second = consumption * 3e-5;
	}
	Engine(double consumption)
	{
		set_consumption(consumption);
		is_started = false;
		cout << "Engine is ready" << endl;
	}
	~Engine()
	{
		cout << "Engine is over" << endl;
	}
	void info()const
	{
		cout << "Consumption per 100 km: " << consumption << " liters. \n";
		cout << "Consumption per second: " << consumption_per_second << " liters. \n";
		cout << "Engine is " << (is_started ? "started" : "stopped") << endl;
	}

};
//#define TANK_CHEK

void main()
{
	setlocale(LC_ALL, "");

#ifdef TANK_CHEK
	Tank tank;
	double fuel;
	do
	{
		cout << "Введите обьем топлива: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (true);
#endif // TANK_CHEK

	Engine engine(10);
	engine.info();

}