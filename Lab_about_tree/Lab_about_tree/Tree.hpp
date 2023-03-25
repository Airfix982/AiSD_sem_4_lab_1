#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


class Tree
{

	private:
		struct Node
		{

			int data;
			Node* left;
			Node* right;
			Node( int data = 0 ) : data( data ), left( NULL ), right( NULL ) {};

		};
		Node* root;

	public:

		Node* get_root()
		{
			return root;
		};

		Tree() = default;//+

		Tree( const Tree& copied_tree );//+

		Tree& operator = ( const Tree& copied_tree );//+

		Node* clone( const Node* node )
		{
		
			if ( node == NULL )
			{

				return NULL;

			}
			Node* new_node = new Node( node->data );
			new_node->left = clone( node->left );
			new_node->right = clone( node->right );
			return new_node;
		
		};

		void print() const;//+

		void print_tree( const Node* node ) const
		{

			if (node != NULL)
			{

				cout << node->data << " ";
				print_tree(node->left);
				print_tree(node->right);

			}

		}

		bool insert( int key );//+

		Node* add( Node* root, const int key )
		{

			if( root == NULL )
			{
			
				return new Node(key);
			
			}
			if ( key < root->data )
			{

				root->left = add( root->left, key );

			}
			else
			{

				root->right = add( root->right, key );

			}
			return root;

		};

		bool contains( int key ) const;//+

		bool presence( const Node* root, int key ) const
		{
		
			if (root == NULL) return false;
			else
			{
				if (root->data == key) return true;
				else if (key < root->data)
				{

					return presence(root->left, key);

				}
				else
				{

					return presence(root->right, key);

				}
			}
		
		};

		bool erase( int key );//+

		Node* find_min( Node* node )
		{
		
			while( node->left != NULL )
			{
			
				node = node->left;
			
			}
			return node;
		
		}

		Node* delete_( Node* root, int key )
		{
		
			if( root == NULL )
			{
				
				cout << endl << "Tree doesn't consist any values";
				return NULL; 
			
			}
			else if( key < root->data )
			{
			
				root->left = delete_( root->left, key );
			
			}
			else if ( key > root->data )
			{

				root->right = delete_( root->right, key );

			}
			else
			{

				if ( !root->left && !root->right )
				{

					cout << endl << "element " << key << " has been deleted";
					delete root;
					root = NULL;

				}
				else if ( !root->left )
				{

					cout << endl << "element " << key << " has been deleted";
					Node* tmp = root;
					root = root->right;
					delete tmp;

				}
				else if ( !root->right )
				{

					cout << endl << "element " << key << " has been deleted";
					Node* tmp = root;
					root = root->left;
					delete tmp;

				}
				else
				{

					cout << endl << "element " << key << " has been deleted";
					Node* tmp = find_min(root->right);
					root->data = tmp->data;
					root->right = delete_(root->right, tmp->data);

				}

			}
			return root;
		
		}

		bool clear();//+

		bool clearing( Node* root )
		{
			if (root) {
				if (root->left) clearing(root->left);
				if (root->right) clearing(root->right);
				delete root;
				root = NULL;
			}
			return 1;
		
		};

		~Tree();//+

};