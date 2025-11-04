#include <iostream>;
#include <unordered_map>;
#include <unordered_set>;
#include <string>;
#include <array>;

using namespace std;

int main() {
	unordered_map<string, array<unordered_set<string>, 3>> typeLookup;

	// types are stored in the format:
	// type name : [(super effective against), (not very effective against), (no effect against)]

	// where super effective, not very effective, and no effect are hashmaps accesses as
	// typeLookup[typeName][0]
	// typeLookup[typeName][1]
	// typeLookup[typeName][2]

	typeLookup.insert({ "normal", { unordered_set<string>{ "" }, unordered_set<string>{ "steel", "rock" }, unordered_set<string>{ "ghost" }} });
	typeLookup.insert({ "water", { unordered_set<string>{ "fire", "ground", "rock" }, unordered_set<string>{ "grass", "dragon", "water" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "fire", { unordered_set<string>{ "grass", "bug", "ice", "steel" }, unordered_set<string>{ "water", "fire", "rock", "dragon" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "grass", { unordered_set<string>{ "water", "rock", "ground" }, unordered_set<string>{ "fire", "grass", "dragon", "poison", "flying", "bug", "steel" }, unordered_set<string>{" "}}});
	typeLookup.insert({ "electric", { unordered_set<string>{ "water", "flying" }, unordered_set<string>{ "grass", "electric", "dragon" }, unordered_set<string>{ "ground" }}});
	typeLookup.insert({ "ice", { unordered_set<string>{ "grass", "ground", "flying", "dragon" }, unordered_set<string>{ "fire", "water", "ice", "steel" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "fighting", { unordered_set<string>{ "normal", "ice", "rock", "dark", "steel" }, unordered_set<string>{ "poison", "flying", "psychic", "bug", "fairy" }, unordered_set<string>{ "ghost" }}});
	typeLookup.insert({ "poison", { unordered_set<string>{ "grass", "fairy" }, unordered_set<string>{ "poison", "ground", "rock", "ghost" }, unordered_set<string>{ "steel" }}});
	typeLookup.insert({ "ground", { unordered_set<string>{ "fire", "electric", "poison", "rock", "steel" }, unordered_set<string>{ "grass", "bug" }, unordered_set<string>{ "flying" }}});
	typeLookup.insert({ "flying", { unordered_set<string>{ "grass", "fighting", "bug" }, unordered_set<string>{ "steel", "rock", "electric" }, unordered_set<string>{ " " }} });
	typeLookup.insert({ "psychic", { unordered_set<string>{ "fighting", "poison" }, unordered_set<string>{ "steel", "psychic" }, unordered_set<string>{ "dark" }}});
	typeLookup.insert({ "bug", { unordered_set<string>{ "grass", "psychic", "dark" }, unordered_set<string>{ "fire", "fighting", "poison", "flying", "ghost", "steel", "fairy" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "rock", { unordered_set<string>{ "fire", "ice", "flying", "bug" }, unordered_set<string>{ "fighting", "ground", "steel" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "ghost", { unordered_set<string>{ "psychic", "ghost" }, unordered_set<string>{ "dark" }, unordered_set<string>{ "normal" }}});
	typeLookup.insert({ "dragon", { unordered_set<string>{ "dragon" }, unordered_set<string>{ "steel" }, unordered_set<string>{ "fairy" }} });
	typeLookup.insert({ "dark", { unordered_set<string>{ "psychic", "ghost" }, unordered_set<string>{ "dark" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "steel", { unordered_set<string>{ "ice", "rock", "fairy" }, unordered_set<string>{ "steel", "fire", "water", "electric" }, unordered_set<string>{ " " }}});
	typeLookup.insert({ "fairy", { unordered_set<string>{ "fighting", "dragon", "dark" }, unordered_set<string>{ "fire", "steel", "poison" }, unordered_set<string>{ " " }}});

	string types[18] = { "normal", "water", "fire", "grass", "electric", "ice", "fighting", "poison", "ground", "flying", "psychic", "bug", "rock", "ghost", "dragon", "dark", "steel", "fairy"};

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 18; j++) {
			if (typeLookup[types[i]][0].find(types[j]) != typeLookup[types[i]][0].end()) {
				cout << types[j] << " is weak to " << types[i] << endl;
			}
		}
		for (int j = 0; j < 18; j++) {
			if (typeLookup[types[i]][1].find(types[j]) != typeLookup[types[i]][1].end()) {
				cout << types[j] << " is resistant to " << types[i] << endl;
			}
		}
		for (int j = 0; j < 18; j++) {
			if (typeLookup[types[i]][2].find(types[j]) != typeLookup[types[i]][2].end()) {
				cout << types[j] << " is immune to " << types[i] << endl;
			}
		}
	}
}