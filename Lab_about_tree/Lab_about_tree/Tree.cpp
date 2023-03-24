#include"Tree.hpp"

Tree::Tree()
{

	this->root = NULL;

}

Tree::Tree( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );

}

void Tree::print() const
{

	cout << endl;
	print_tree( this->root );

}

Tree& Tree::operator = ( const Tree& copied_tree )
{

	this->root = clone( copied_tree.root );

}
 
bool Tree::insert( const int key )
{

	this->root = add( this->root, key );

}

bool Tree::contains( int key ) const
{

	presence( this->root, key ) ? cout << endl << "yes" : cout << endl << "no";

}

bool Tree::erase( int key )
{

	this->root = delete_( this->root, key );

}