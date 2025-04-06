#include <iostream>
#include <vector>
#include <list>
#include <string>


class HashTable {
public:
    HashTable(int M, double LOAD) : M(M), LOAD(LOAD), size(0) {
        table.resize(M);
    }

    bool insert(int key) {
        if ((double)size / M >= LOAD) {
            return false;
        }
        int index = hash_function(key);
        table[index].push_back(key);
        ++size;
        return true;
    }

    std::string search(int key) const {
        int index = hash_function(key);
        int comparisons = 0;

        for (const auto& k : table[index]) {
            ++comparisons;
            if (k == key) {
                return std::to_string(comparisons);
            }
        }
        return "KHONG";
    }

private:
    int hash_function(int key) const {
        return key % M;
    }

    int M;
    double LOAD;
    int size;
    std::vector<std::list<int>> table;
};

int main() {
    int M, N, N_prime;
    double LOAD;
    std::cin >> M >> LOAD >> N;

    HashTable hashTable(M, LOAD);
    std::vector<int> keys_to_insert(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> keys_to_insert[i];
    }

    for (const auto& key : keys_to_insert) {
        if (!hashTable.insert(key)) {
            std::cerr << "Cannot insert key " << key << " due to load factor limit" << std::endl;
        }
    }

    std::cin >> N_prime;
    std::vector<int> keys_to_search(N_prime);

    for (int i = 0; i < N_prime; ++i) {
        std::cin >> keys_to_search[i];
    }

    for (const auto& key : keys_to_search) {
        std::cout << hashTable.search(key) << std::endl;
    }

    return 0;
}
