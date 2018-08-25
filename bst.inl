// NODE FUNCTIONS
template<typename T>
BST<T>::Node::Node() : parent(NULL), left_link(NULL), right_link(NULL) {}

template<typename T>
BST<T>::Node::~Node() {}

template<typename T>
T BST<T>::Node::get_data() const { return data; }

template<typename T>
typename BST<T>::Node * BST<T>::Node::get_parent() const { return parent; }

template<typename T>
typename BST<T>::Node * BST<T>::Node::get_left() const { return left_link; }

template<typename T>
typename BST<T>::Node * BST<T>::Node::get_right() const { return right_link; }

template<typename T>
void BST<T>::Node::set_data(const T& d) { data = d; }

template<typename T>
void BST<T>::Node::set_parent(Node * p) { parent = p; }

template<typename T>
void BST<T>::Node::set_left(Node * l) { left_link = l; }

template<typename T>
void BST<T>::Node::set_right(Node * r) { right_link = r; }

template<typename T>
void BST<T>::Node::print() const {
	T a = get_data();
	std::cout << a << std::endl;
}

//BST FUNCTIONS
template<typename T>
BST<T>::BST() : root(NULL), count(0) {}

template<typename T>
BST<T>::BST(T a) {
	Node * n = new Node(a);
	root = n;
	count++;
}

template<typename T>
BST<T>::~BST() { destroy(root); }

template<typename T>
void BST<T>::destroy(Node * a) {
	if (a) {
		destroy(a->get_left());
		destroy(a->get_right());
		delete a;
	}
}

template<typename T>
bool BST<T>::full() const {
	Node * n = new Node;

	if (n) {
		delete n;
		return false;
	}
	else
		return true;
}

template<typename T>
bool BST<T>::empty() const {
	return count == 0;
}

template<typename T>
bool BST<T>::insert(const T& a) {
	Node * n = new Node(a);
	Node * current = root;
	Node * temp = NULL;

	if (full())
		return false;

	if (empty()) {
		root = n;
		count++;
		return true;
	}
	else {
		current->set_parent(NULL);

		while (current && a != current->get_data()) {
			current->set_parent(current);
			temp = current->get_parent();

			if (a < current->get_data())
				current = current->get_left();
			else
				current = current->get_right();
		}

		if (current) {
			delete n;
			return false;
		}
		else {
			if (a < temp->get_data())
				temp->set_left(n);
			else
				temp->set_right(n);

			count++;
			return true;
		}
	}
}

template<typename T>
void BST<T>::traverse() const {
	inorder_traverse(root);
	std::cout << "Inorder done.\n\n";
	preorder_traverse(root);
	std::cout << "Preorder done.\n\n";
	postorder_traverse(root);
	std::cout << "Postorder done.\n\n";
}

template<typename T>
void BST<T>::inorder_traverse(Node * a) const {
	if (a) {
		inorder_traverse(a->get_left());
		std::cout << a->get_data() << std::endl;
		inorder_traverse(a->get_right());
	}
}

template<typename T>
void BST<T>::preorder_traverse(Node * a) const {
	if(a) {
		std::cout << a->get_data() << std::endl;
		preorder_traverse(a->get_left());
		preorder_traverse(a->get_right());
	}
}

template<typename T>
void BST<T>::postorder_traverse(Node * a) const {
	if(a) {
		postorder_traverse(a->get_left());
		postorder_traverse(a->get_right());
		std::cout << a->get_data() << std::endl;
	}
}