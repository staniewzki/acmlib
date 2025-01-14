/* 
 * Opis: Wzór na całkę z zasady Simpsona - zwraca całkę na przedziale [a, b]
 * Czas: O(n)
 * Użycie: integral([](T x) { return 3 * x * x - 8 * x + 3; }, a, b)
 * Daj asserta na błąd, ewentualnie zwiększ n (im większe n, tym mniejszy błąd)
 */

using T = double;
T integral(function<T(T)> f, T a, T b) {
	const int n = 1000;
	T delta = (b - a) / n, sum = f(a) + f(b);
	FOR(i, 1, n - 1)
		sum += f(a + i * delta) * (i & 1 ? 4 : 2);
	return sum * delta / 3;
}
