#include <stdio.h>
#include <stdlib.h>
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

		Tree();

		Tree( const Tree& copied_tree );

		Tree& operator = ( const Tree& copied_tree );

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

		void print() const;

		bool insert( int key );

		bool contains( int key ) const;

		bool erase( int key );

		bool clear();

		~Tree();

};