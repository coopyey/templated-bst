//bst.hpp

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

namespace Tree {
	template<typename T>
	class BST {
	public:
		BST();
		BST(T);
		~BST();

		class Node {
		public:
			Node();
			Node(T a) : data(a), parent(NULL), left_link(NULL), right_link(NULL) {}
			~Node();

			T get_data() const;
			Node * get_parent() const;
			Node * get_left() const;
			Node * get_right() const;

			void print() const;

			void set_data(const T&);
			void set_parent(Node * p);
			void set_left(Node * l);
			void set_right(Node * r);

			bool operator< (T &thing) { return (data < thing); }
			bool operator== (T &thing) { return (data == thing); }
			bool operator!= (T &thing) { return (data != thing); }
		private:
			T data;
			Node * parent;
			Node * left_link;
			Node * right_link;
		}; //end node

		bool insert(const T&);
		bool full() const;
		bool empty() const;
		void traverse() const;
		void inorder_traverse(Node *) const;
		void postorder_traverse(Node *) const;
		void preorder_traverse(Node *) const;

	private:
		Node * root;
		int count;
		void destroy(Node*);
	}; //end bst

//Inline file chosen to help with readability.
#include "bst.inl"
}; //end tree namespace

#endif
