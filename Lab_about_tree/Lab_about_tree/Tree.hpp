#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#pragma once

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

		Tree();//+

		Tree( const Tree& copied_tree );//+

		Tree& operator = ( const Tree& copied_tree );//+

		Node* clone( Node* node )
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

			if (node)
			{

				cout << node->data << " ";

			}
			print_tree(node->left);
			print_tree(node->right);

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
		
			if( root->data == key ) return true;
			else if( root->left )
			{

				if( presence( root->left, key ) ) return true;

			}
			else if ( root->right )
			{

				if ( presence( root->right, key ) ) return true;

			}
			else return false;
		
		};

		bool erase( int key );

		bool clear();

		~Tree();

};