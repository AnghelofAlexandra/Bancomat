#include <iostream>
using namespace std;

class ContBancar
{
	string numeProprietar = "Anonim";
	string numarCont = "0000000000000000";
	string pin = "0000";
	double sold = 0;

public:
	ContBancar() {}

	ContBancar(string _numeProprietar, string _numarCont, string _pin, double _sold)
	{
		if (_numeProprietar.size() >= 7)
		{
			this->numeProprietar = _numeProprietar;
		}

		if (_numarCont.size() == 16 )
		{
			this->numarCont = _numarCont;
		}

		if (_pin.size() == 4)
		{
			this->pin = _pin;
		}

		this->sold = _sold;
	}

	bool verificaPin(string _pin)
	{
		if (this->pin == _pin)
		{
			return true;
		}
		else return false;
	}

	void depunereBani(double _suma)
	{
		if (_suma > 0)
		{
			this->sold += _suma;
			cout << "\n         Suma depusa cu succes!";
		}
		else cout << "\n         Suma invalida!";
	}

	void retragereNumerar(double _suma)
	{
		if (_suma <= this->sold && _suma > 0)
		{
			this->sold -= _suma;
			cout << "\n         Retragere efectuata cu succes!";
		}
		else cout << "\n         Suma introdusa nu poate fi retrasa!";
	}

	void consultareSold()
	{
		cout << "\n----------------------------------------------------------------------------------";
		cout << "\n         Sold: " << this->sold;
		cout << "\n----------------------------------------------------------------------------------";
	}

	void afisare()
	{
		cout << "\n----------------------------------------------------------------------------------";
		cout << "\n         Nume: " << this->numeProprietar;
		cout << "\n         Sold: " << this->sold;
		cout << "\n----------------------------------------------------------------------------------";
	}
};

int main()
{
	ContBancar c("Ion Costel", "0490102031488970", "1234", 1000);
	cout << "\n------------------------------------ BANCOMAT ------------------------------------";

	string pinCard;
	cout << "\n         Introduceti PIN: ";
	cin >> pinCard;
	int nrIncercari = 0;
	int x = 0;
	while (nrIncercari < 3 && x!=4)
	{
		if (c.verificaPin(pinCard))
		{
			cout << "\n         1. Consulatre sold\n         2. Retragere numerar\n         3. Depunere numerar\n         4. Incheiere";
			cout << "\n\n         Introduceti optiunea (nr. optiunii): ";
			cin >> x;

			while (x < 4 && x > 0)
			{
				if (x == 1)
				{
					c.consultareSold();

					cout << "\n         Doriti chitanta?\n         Raspuns: ";
					string raspuns;
					cin >> raspuns;
					if (raspuns == "DA" || raspuns == "da" || raspuns == "Da" || raspuns == "dA")
					{
						c.afisare();
					}

					cout << "\n\n\n\n\n\n";

					cout << "\n         1. Consulatre sold\n         2. Retragere numerar\n         3. Depunere numerar\n         4. Incheiere";
					cout << "\n\n         Introduceti optiunea (nr. optiunii): ";
					cin >> x;
				}
				else if (x == 2)
				{
					double suma;
					cout << "\n         Introduceti suma:";
					cin >> suma;

					c.retragereNumerar(suma);

					cout << "\n----------------------------------------------------------------------------------";
					cout << "\n         Doriti chitanta?\n         Raspuns: ";
					string raspuns;
					cin >> raspuns;
					if (raspuns == "DA" || raspuns == "da" || raspuns == "Da" || raspuns == "dA")
					{
						c.afisare();
					}

					cout << "\n\n\n\n\n\n";

					cout << "\n----------------------------------------------------------------------------------";
					cout << "\n         1. Consulatre sold\n         2. Retragere numerar\n         3. Depunere numerar\n         4. Incheiere";
					cout << "\n\n         Introduceti optiunea (nr. optiunii): ";
					cin >> x;
				}
				else if (x == 3)
				{
					double suma;
					cout << "\n         Introduceti suma:";
					cin >> suma;

					c.depunereBani(suma);

					cout << "\n----------------------------------------------------------------------------------";
					cout << "\n         Doriti chitanta?\n         Raspuns: ";
					string raspuns;
					cin >> raspuns;
					if (raspuns == "DA" || raspuns == "da" || raspuns == "Da" || raspuns == "dA")
					{
						c.afisare();
					}

					cout << "\n\n\n\n\n\n";

					cout << "\n----------------------------------------------------------------------------------";
					cout << "\n         1. Consulatre sold\n         2. Retragere numerar\n         3. Depunere numerar\n         4. Incheiere";
					cout << "\n\n         Introduceti optiunea (nr. optiunii): ";
					cin >> x;
				}
			}
		}
		else 
		{
			cout << "----------------------------------------------------------------------------------";
			cout << "\n         PIN invalid!\n         Doua incercari ramase!";
			cout << "\n----------------------------------------------------------------------------------";

			nrIncercari++;

			cout << "\n         Introduceti PIN: ";
			cin >> pinCard;
		}
	}

	cout << "\n----------------------------------------------------------------------------------";
	cout << "\n         PROCES INCHEIAT!";
	cout << "\n----------------------------------------------------------------------------------\n\n";

	return 0;
}