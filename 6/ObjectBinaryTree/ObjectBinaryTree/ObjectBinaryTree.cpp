#include <iostream>
#include <stack>
#include <string>

// Struktura węzła drzewa binarnego
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
// Klasa drzewa binarnego
class BinaryTree {
private:
	TreeNode* root;
public:
	BinaryTree() : root(nullptr) {}
	// Metoda do dodawania węzła do drzewa
	void insert(int value) {
		root = insertRecursive(root, value);
	}
	// Metoda rekurencyjna do dodawania węzła
	TreeNode* insertRecursive(TreeNode* node, int value) {
		if (node == nullptr) {
			return new TreeNode(value);
		}
		if (value < node->data) {
			node->left = insertRecursive(node->left, value);
		}
		else if (value > node->data) {
			node->right = insertRecursive(node->right, value);
		}
		return node;
	}
	// Metoda do wyświetlania drzewa w porządku inorder
	void inorderTraversal(TreeNode* node) {
		if (node != nullptr) {
			inorderTraversal(node->left);
			std::cout << node->data << " ";
			inorderTraversal(node->right);
		}
	}
	// Metoda publiczna do wyświetlania drzewa w porządku inorder
	void inorderTraversal() {
		inorderTraversal(root);
	}

	// Metoda do wyświetlania drzewa w porządku preorder
	void preorderTraversal(TreeNode* node) {
		if (node == nullptr) {
			return;
		}

		// Tworzymy pusty stos
		std::stack<TreeNode*> stack;
		stack.push(node);

		while (!stack.empty()) {
			node = stack.top(); // pobieramy ze stosu wskazanie węzła
			stack.pop();
			std::cout << node->data << " ";

			if (node->right != nullptr) {
				stack.push(node->right);
			}
			if (node->left != nullptr) {
				stack.push(node->left);
			}
		}
	}

	// Metoda publiczna do wyświetlania drzewa w porządku preorder
	void preorderTraversal() {
		preorderTraversal(root);
	}

	// Metoda do wyświetlania drzewa w porządku postorder
	void postorderTraversal(TreeNode* node) {
		if (node != nullptr) {
			postorderTraversal(node->left);
			postorderTraversal(node->right);
			std::cout << node->data << " ";
		}
	}

	// Metoda publiczna do wyświetlania drzewa w porządku postorder
	void postorderTraversal() {
		postorderTraversal(root);
	}

	// Metoda sprawdzająca czy w drzewie istnieje podany element, przeszukując drzewo metodą inorder
	bool isInTree(TreeNode* node, int value) {
		if (node == nullptr) {
			return false;
		}

		if (node->data == value) {
			return true;
		}

		if (isInTree(node->left, value)) {
			return true;
		}

		return isInTree(node->right, value);

	}

	// Metoda publiczna do wyświetlania drzewa w porządku postorder
	bool isInTree(int value) {
		return isInTree(root, value);
	}

	// Funkcja sprawdzająca, czy drzewo jest BST
	bool isBST(TreeNode* node) {
		if (node == nullptr) {
			return true; // Pusty węzeł jest uznawany za BST
		}

		// Sprawdzenie lewego poddrzewa
		bool left_subtree_valid = isBST(node->left) && node->data > getMaxValue(node->left);

		// Sprawdzenie prawego poddrzewa
		bool right_subtree_valid = isBST(node->right) && node->data < getMinValue(node->right);

		return left_subtree_valid && right_subtree_valid;
	}

	// Metoda publiczna do wyświetlania drzewa w porządku postorder
	bool isBST() {
		return isBST(root);
	}

	// Funkcja pomocnicza zwracająca maksymalną wartość w poddrzewie
	int getMaxValue(TreeNode* node) {
		if (node == nullptr) {
			return INT_MIN; // Wartość domyślna dla pustego poddrzewa
		}

		int max_value = node->data;
		int right_subtree_max = getMaxValue(node->right);

		return std::max(max_value, right_subtree_max);
	}

	// Funkcja pomocnicza zwracająca minimalną wartość w poddrzewie
	int getMinValue(TreeNode* node) {
		if (node == nullptr) {
			return INT_MAX; // Wartość domyślna dla pustego poddrzewa
		}

		int min_value = node->data;
		int left_subtree_min = getMinValue(node->left);

		return std::min(min_value, left_subtree_min);
	}

};
int main() {
	BinaryTree tree;
	// Dodawanie elementów do drzewa
	tree.insert(25);
	tree.insert(15);
	tree.insert(50);
	tree.insert(10);
	tree.insert(22);
	tree.insert(4);
	tree.insert(12);
	tree.insert(18);
	tree.insert(24);
	tree.insert(35);
	tree.insert(70);
	tree.insert(31);
	tree.insert(44);
	tree.insert(66);
	tree.insert(90);
	// Wyświetlanie drzewa w porządku inorder
	std::cout << "Drzewo binarne w porzadku inorder: ";
	tree.inorderTraversal();
	std::cout << std::endl;

	std::cout << "Drzewo binarne w porzadku preorder: ";
	tree.preorderTraversal();
	std::cout << std::endl;

	std::cout << "Drzewo binarne w porzadku postorder: ";
	tree.postorderTraversal();
	std::cout << std::endl;

	int node_value = 80;
	std::string result = tree.isInTree(node_value) ? "" : " nie";
	std::cout << "W drzewie binarnym" << result << " wystepuje wezel o wartosci " << node_value << std::endl;

	std::string is_bst = tree.isBST() ? "Drzewo jest drzewem BST" : "Drzewo nie jest drzewem BST";
	std::cout << is_bst << std::endl;

	return 0;
}