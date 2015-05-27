#include <iostream>
using namespace std;
#include <locale.h>
/** функция алгоритма Д.
входные данные
матрица смежности
колличество узлов

*/
void Dijkstra(int **a, int n)
{
	setlocale(0, "Russian");
	int count, index, i, u;
	int *distance = new int[n]; /// создаем массив для кратчайших путей
	bool *visited = new bool[n]; ///  массив булевских переменных для хранения информации о посещениях вершин 
	for (i = 0; i < n; i++)
	{
		distance[i] = 32500; /// заполняем численный массив с заведомо максимальными числами
		visited[i] = false; /// В булевским массиве каждую из вершин отмечаем как не посещенную
	}
	distance[0] = 0; /// Исходная вершина
	for (count = 0; count < n - 1; count++) /// ищем наименьшее расстояние 
	{
		int min = INT_MAX;
		for (i = 0; i < n; i++)
		if (!visited[i] && distance[i] <= min) /// пересматриваем расстояния
		{
			min = distance[i]; index = i;
		}
		u = index;
		visited[u] = true; /// отмечаем посещен
		for (i = 0; i < n; i++)
		if (!visited[i] && a[u][i] && distance[u] != INT_MAX && distance[u] + a[u][i] < distance[i]) /// вычичление расстояния 
			distance[i] = distance[u] + a[u][i];
	}

	cout << "Кратчайшее расстояние от 1 узла до остальных"; ///< ввод кратчайш растоян 
	for (i = 1; i < n; i++)
		cout << distance[i] << " ";
	cout << endl<< endl;
}
/**
function main()

*/
int main(void)
{

	int n;
	cout << "Введите колличество узлов"; /// ввод кол-ва узлов
	cin >> n;
	/// создание матрицы смежности
	int **a = new int *[n];
	for (int i = 0; i < n; i++) 
		a[i] = new int[n];
	/// ввод матрицы смежности
	cout << "\n введите матрицу смежности, если не существует пути введите 32000 \n \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl;
	Dijkstra(a, n); /// вызов функции, реализ. алгоритм Д.
	return 0;
	system("pause");
}
