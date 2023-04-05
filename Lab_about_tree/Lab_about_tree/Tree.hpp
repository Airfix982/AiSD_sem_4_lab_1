#pragma once
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
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

		void print();//+

		int height(const Node* node) const
		{
			if (node == NULL) return 0;
			return max(height(node->left), height(node->right)) + 1;
		}

		void print_tree( Node* node ) 
		{

			int h = height(node);
			int max_nodes = pow(2, h) - 1;
			queue<Node*> q;
			q.push(node);
			int level = 0;
			while (!q.empty() && level < h)
			{
				int level_nodes = q.size();
				int nodes_to_print = min(level_nodes, max_nodes);
				int indent = pow(2, h - level - 1) - 1;
				cout << setw(indent) << "";
				for (int i = 0; i < nodes_to_print; i++)
				{
					Node* node = q.front();
					q.pop();
					if (node != NULL)
					{
						cout << node->data;
						q.push(node->left);
						q.push(node->right);
					}
					else
					{
						cout << "-";
						q.push(NULL);
						q.push(NULL);
					}
					cout << setw(2 * indent + 1) << "";
				}
				cout << endl;
				level++;

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