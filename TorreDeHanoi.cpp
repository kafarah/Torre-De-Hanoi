#include <iostream>
#include<stack>
#include <string>
#include<string.h>
using namespace std;

int Menu(int discos)
{
	int menu;

	cout << " TORRE DE HANOI\n " << endl;

	cout << " Digite 1 para jogar ou 2 para ler as regras: " << endl;
	cin >> menu;

	switch (menu)
	{
	case 1:
		cout << "Com quantos discos deseja jogar? " << endl;
		cin >> discos;
		break;

	case 2:
		cout << "O objetivo é passar todos os discos para a terceira torre\nDeve ser movido apenas um disco de cada vez \nSoh eh possivel mover os discos que estiverem no topo\nUm disco maior nao pode ficar em cima de um menor" << endl;

		cout << "Quanto maior o numero de discos, maior a dificuldade e o numero de movimentos necessarios" << endl;
		break;

	default:
		cout << "valor invalido" << endl;

	}
	return discos;
}

int main()
{
	//Variaveis auxiliares
	int discos = 0;
	bool fim = false;
	int cont = 0;
	int asteriscos = 0;
	int contadorMov = 0;
	string espacos = "";
	string disco = "";

	//Torres
	stack <string> pilha1;
	stack <string> pilha2;
	stack <string> pilha3;
	stack <string> pilhaTemp;

	//Menu do jogo
	discos = Menu(discos);
	//	  *
	//   ***
	//  *****

	//Inicialização
	for (int i = discos; i > 0; i--)
	{
		espacos = "";
		disco = "";
		if (cont > 0)
		{
			for (int j = cont; j > 0; j--)
			{
				espacos += " ";
			}

		}
		asteriscos = ((i - 1) * 2) + 1;
		for (int i = asteriscos; i > 0; i--)
		{
			disco += "*";
		}
		pilha1.push(espacos + disco);
		cont++;
	}

	//Impressão da torre 1
	for (int i = discos; i > 0; i--)
	{
		cout << pilha1.top() << endl;
		pilhaTemp.push(pilha1.top());
		pilha1.pop();
	}
	for (int i = discos / 2; i > 0; i--)
	{
		cout << " ";
	}
	cout << "T1" << endl << endl;

	for (int i = discos; i > 0; i--)
	{
		pilha1.push(pilhaTemp.top());
		pilhaTemp.pop();
	}

	//Impressão das torres 2 e 3
	for (int i = 2; i <= 3; i++)
	{
		for (int i = discos; i > 0; i--)
		{
			cout << " " << endl;
		}
		for (int i = discos / 2; i > 0; i--)
		{
			cout << " ";
		}
		cout << "T" << i << endl << endl;
	}

	//Jogo
	while (!fim)
	{
		//Variaveis auxiliares
		int remove, coloca;
		int tam1, tam2 = 0;

		//Movimentar os discos
		cout << "De qual torre quer remover? ";
		cin >> remove;
		cout << "Mover para qual torre? ";
		cin >> coloca;

		switch (remove)
		{
			//Tirar da torre 1
		case 1:
			if (!pilha1.empty())
			{
				tam1 = pilha1.top().length();
				//Colocar na 2
				if (coloca == 2)
				{
					if (!pilha2.empty())
					{
						tam2 = pilha2.top().length();
					}
					if (pilha2.empty() || tam2 > tam1)
					{
						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha2.push(pilha1.top());
						pilha1.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}
				}
				//Colocar na 3
				if (coloca == 3)
				{
					if (!pilha3.empty())
					{
						tam2 = pilha3.top().length();
					}
					if (pilha3.empty() || tam2 > tam1)
					{
						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha3.push(pilha1.top());
						pilha1.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}
				}
				//Se for digitado um valor invalido
				else
				{
					cout << endl << "Opcao invalida!" << endl << endl;
					break;
				}
			}
			//Caso a pilha escolhida para remover um disco esteja vazia
			else
			{
				cout << endl << "Pilha vazia!" << endl << endl;
				break;

			}
			break;
			//Tirar da torre 2
		case 2:
			if (!pilha2.empty())
			{
				tam1 = pilha2.top().length();
				if (coloca == 1)
				{
					if (!pilha1.empty())
					{
						tam2 = pilha1.top().length();
					}
					if (pilha1.empty() || tam2 > tam1)
					{

						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha1.push(pilha2.top());
						pilha2.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}
				}
				if (coloca == 3)
				{
					if (!pilha3.empty())
					{
						tam2 = pilha3.top().length();
					}
					if (pilha3.empty() || tam2 > tam1)
					{
						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha3.push(pilha2.top());
						pilha2.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}
				}
				else
				{
					cout << endl << "Opcao invalida!" << endl << endl;
					break;
				}
			}
			else
			{
				cout << endl << "Pilha vazia!" << endl << endl;
				break;

			}
			break;
			//Tirar da torre 3
		case 3:
			if (!pilha3.empty())
			{
				tam1 = pilha3.top().length();
				if (coloca == 2)
				{
					if (!pilha2.empty())
					{
						tam2 = pilha2.top().length();
					}
					if (pilha2.empty() || tam2 > tam1)
					{
						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha2.push(pilha3.top());
						pilha3.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}

				}
				if (coloca == 1)
				{
					if (!pilha1.empty())
					{
						tam2 = pilha1.top().length();
					}
					if (pilha1.empty() || tam2 > tam1)
					{
						cout << endl << "Disco da torre " << remove << " para a torre " << coloca << endl << endl;
						pilha1.push(pilha3.top());
						pilha3.pop();
						contadorMov += 1;
						break;
					}
					else
					{
						cout << endl << "Disco da pilha " << remove << " maior do que o disco da pilha " << coloca << endl << endl;
					}
				}
				else
				{
					cout << endl << "Opcao invalida!" << endl << endl;
					break;
				}
			}
			else
			{
				cout << endl << "Opcao invalida!" << endl << endl;
				break;

			}
			break;
		default:
			cout << endl << "Pilha vazia!" << endl << endl;
			;
		}

		//Impressão da torre 1
		int tamPilha = pilha1.size();
		for (int i = tamPilha; i > 0; i--)
		{
			cout << pilha1.top() << endl;
			pilhaTemp.push(pilha1.top());
			pilha1.pop();
		}
		for (int i = discos / 2; i > 0; i--)
		{
			cout << " ";
		}
		cout << "T1" << endl << endl;

		tamPilha = pilhaTemp.size();

		for (int i = tamPilha; i > 0; i--)
		{
			pilha1.push(pilhaTemp.top());
			pilhaTemp.pop();
		}

		//Impressão da torre 2
		tamPilha = pilha2.size();
		for (int i = tamPilha; i > 0; i--)
		{
			cout << pilha2.top() << endl;
			pilhaTemp.push(pilha2.top());
			pilha2.pop();
		}
		for (int i = discos / 2; i > 0; i--)
		{
			cout << " ";
		}
		cout << "T2" << endl << endl;

		for (int i = tamPilha; i > 0; i--)
		{
			pilha2.push(pilhaTemp.top());
			pilhaTemp.pop();
		}
		//Impressão da torre 3
		tamPilha = pilha3.size();
		for (int i = tamPilha; i > 0; i--)
		{
			cout << pilha3.top() << endl;
			pilhaTemp.push(pilha3.top());
			pilha3.pop();
		}
		for (int i = discos / 2; i > 0; i--)
		{
			cout << " ";
		}
		cout << "T3" << endl << endl;

		for (int i = tamPilha; i > 0; i--)
		{
			pilha3.push(pilhaTemp.top());
			pilhaTemp.pop();
		}

		//Condição de vitória
		if (pilha3.size() == discos)fim = true;
	}



	cout << "PARABENS!!!" << endl;
	cout << "Voce terminou o desafio em " << contadorMov << " movimentos" << endl;

	return 0;
}
