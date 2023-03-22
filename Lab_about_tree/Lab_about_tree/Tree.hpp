#include <stdio.h>
#include <stdlib.h>
#pragma once
struct Node
{

	int data;
	Node* left;
	Node* right;
	Node( int data = 0, Node* left = NULL, Node*right = NULL ): data( data ), left( left ), right( right ) {};

};


class Tree
{

	private:
		Node leaf;

	public:

		Tree( int data = 0 );

		Tree( const Tree& copied_tree );

		Tree& operator = ( const Tree& copied_tree );

		void print() const;

		bool insert( int key );

		bool contains( int key ) const;

		bool erase( int key );

		~Tree();

};