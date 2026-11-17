#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class HuffmanNode {
	public:
		char key;
		int freq;
		HuffmanNode *left;
		HuffmanNode *right;

		HuffmanNode(char k, int f) : key(k), freq(f), left(nullptr), right(nullptr) {}
};

class CompareNode {
	public:
		bool operator()(HuffmanNode *a, HuffmanNode *b) {
			return a->freq > b->freq;
		}
};

class KeyEncoding {
	public:
		char key;
		string encoding;

		KeyEncoding(char k, string e) : key(k), encoding(e) {}

		static bool compareByKey(const KeyEncoding &a, const KeyEncoding &b) {
			return a.key < b.key;
		}
};

class Huffman {
	private:
		HuffmanNode *root;

		void generateCodes(HuffmanNode *node, const string &prefix, vector<KeyEncoding> &codes) {
			if (!node)
				return;

			if (!node->left && !node->right) {
				codes.emplace_back(node->key, prefix);
			}

			generateCodes(node->left, prefix + "0", codes);
			generateCodes(node->right, prefix + "1", codes);
		}

		void clearTree(HuffmanNode *node) {
			if (!node)
				return;
			clearTree(node->left);
			clearTree(node->right);
			delete node;
		}

	public:
		Huffman() : root(nullptr) {}

		~Huffman() {
			clearTree(root);
		}

		void buildTree(const vector<char> &keys, const vector<int> &freqs) {
			priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNode> pq;

			for (size_t i = 0; i < keys.size(); ++i) {
				pq.push(new HuffmanNode(keys[i], freqs[i]));
			}

			while (pq.size() > 1) {
				HuffmanNode *left = pq.top();
				pq.pop();
				HuffmanNode *right = pq.top();
				pq.pop();

				HuffmanNode *sum = new HuffmanNode('\0', left->freq + right->freq);
				sum->left = left;
				sum->right = right;

				pq.push(sum);
			}

			root = pq.empty() ? nullptr : pq.top();
		}

		vector<KeyEncoding> getCodes() {
			vector<KeyEncoding> codes;
			generateCodes(root, "", codes);
			sort(codes.begin(), codes.end(), KeyEncoding::compareByKey);
			return codes;
		}
};

int main() {
	int N;
	cin >> N;

	vector<char> keys(N);
	vector<int> freqs(N);

	for (int i = 0; i < N; ++i) {
		cin >> keys[i];
	}

	for (int i = 0; i < N; ++i) {
		cin >> freqs[i];
	}

	Huffman huffman;
	huffman.buildTree(keys, freqs);
	vector<KeyEncoding> codes = huffman.getCodes();

	for (const auto &code : codes) {
		cout << code.key << ":=" << code.encoding << endl;
	}

	return 0;
}