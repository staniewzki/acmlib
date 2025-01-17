/**
 * Opis: jakiś tam opis, można walnąć latexa: $2+2=5$. ęóąśłżźćńĘÓĄŚŁŻŹĆŃ
 * Czas: O(n \sqrt{n} \log^2 n), gdzie $n$ to jakaś fajna zmienna, O(n \log n) pamięciowo
 * Użycie:
 *  int rd = getRandomValue(0, 5);
 *  int rd01 = ExampleStruct().get();
 *  ęóąśłżźćńĘÓĄŚŁŻŹĆŃ
 */

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

int getRandomValue(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

struct ExampleStruct {
	int random_variable;
	static constexpr int left = 0, right = 1;

	ExampleStruct() {
		random_variable = getRandomValue(left, right);
		if(random_variable == 0) {
			// some random bulls**t to show the style
			++random_variable;
		}
		else
			--random_variable;
	}

	int& get_value() {
		return random_variable;
	}
};
